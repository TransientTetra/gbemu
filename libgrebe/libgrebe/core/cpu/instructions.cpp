#include <libgrebe/core/cpu/instructions.hpp>
#include <libgrebe/utils.hpp>

void Instructions::Undefined(State& state)
{
	throw UndefinedOpcodeException();
}

void Instructions::NOP(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
}

void Instructions::LD_BC_d16(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.registers.setC(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});

	state.cpuQueue.push([](State& state) {
		state.registers.setB(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});
}

void Instructions::LD_MEM_AT_BC_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.mmu.write(state.registers.getBC(), state.registers.getA()); });
}

void Instructions::INC_BC(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
		if (((state.registers.getC() + 1) & 0xff) < state.registers.getC())
			state.tmp.push(1);
		else
			state.tmp.push(0);
		state.registers.incC();
	});
	state.cpuQueue.push([](State& state) {
		state.registers.setB(state.registers.getB() + state.tmp.top());
		state.tmp.pop();
	});
}

void Instructions::INC_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.getB() & 0xf) + 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.incB();
		if (state.registers.getB() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::DEC_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.setSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.getB() & 0xf) - 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.decB();
		if (state.registers.getB() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::LD_B_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.registers.setB(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});
}

void Instructions::RLCA(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		if (state.registers.getA() & 0b10000000)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() << 1 | (state.registers.getA() >> 7));
	});
}

void Instructions::LD_MEM_AT_a16_SP(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});

	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});

	state.cpuQueue.push([](State& state) {
		std::uint8_t tmp2 = state.tmp.top();
		state.tmp.pop();
		std::uint8_t tmp1 = state.tmp.top();
		state.tmp.push(tmp2);
		state.mmu.write(toWord(tmp1, tmp2), lsb(state.registers.getSP()));
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t tmp2 = state.tmp.top();
		state.tmp.pop();
		std::uint8_t tmp1 = state.tmp.top();
		state.tmp.pop();
		state.mmu.write(toWord(tmp1, tmp2) + 1, msb(state.registers.getSP()));
	});
}

void Instructions::ADD_HL_BC(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		state.registers.resetCarryFlag();
		if (((state.registers.getL() & 0xf) + (state.registers.getC() & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getL() & 0xff) + (state.registers.getC() & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setL(state.registers.getL() + state.registers.getC());
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t carry = state.registers.getCarryFlag();
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		state.registers.resetCarryFlag();
		if (((state.registers.getH() & 0xf) + (state.registers.getB() & 0xf) + (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getH() & 0xff) + (state.registers.getB() & 0xff) + (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setH(state.registers.getH() + state.registers.getB() + carry);
	});
}

void Instructions::LD_A_MEM_AT_BC(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.setA(state.mmu.read(state.registers.getBC())); });
}

void Instructions::DEC_BC(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
		if (((state.registers.getC() - 1) & 0xff) >= state.registers.getC())
			state.tmp.push(1);
		else
			state.tmp.push(0);
		state.registers.decC();
	});
	state.cpuQueue.push([](State& state) {
		state.registers.setB(state.registers.getB() - state.tmp.top());
		state.tmp.pop();
	});
}

void Instructions::INC_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.getC() & 0xf) + 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.incC();
		if (state.registers.getC() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::DEC_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.setSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.getC() & 0xf) - 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.decC();
		if (state.registers.getC() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::LD_C_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.registers.setC(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});
}

void Instructions::RRCA(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		if (state.registers.getA() & 1)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() >> 1 | (state.registers.getA() << 7));
	});
}

void Instructions::STOP_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.controlUnitState = LIBGREBE_CONTROL_UNIT_STATE_STOP;
		state.registers.incPC();
	});
}

void Instructions::LD_DE_d16(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.registers.setE(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});

	state.cpuQueue.push([](State& state) {
		state.registers.setD(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});
}

void Instructions::LD_MEM_AT_DE_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.mmu.write(state.registers.getDE(), state.registers.getA()); });
}

void Instructions::INC_DE(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
		if (((state.registers.getE() + 1) & 0xff) < state.registers.getE())
			state.tmp.push(1);
		else
			state.tmp.push(0);
		state.registers.incE();
	});
	state.cpuQueue.push([](State& state) {
		state.registers.setD(state.registers.getD() + state.tmp.top());
		state.tmp.pop();
	});
}

void Instructions::INC_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.getD() & 0xf) + 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.incD();
		if (state.registers.getD() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::DEC_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.setSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.getD() & 0xf) - 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.decD();
		if (state.registers.getD() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::LD_D_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.registers.setD(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});
}

void Instructions::RLA(State& state)
{
	state.cpuQueue.push([](State& state) {
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (state.registers.getA() & 0b10000000)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() << 1 | carry);
	});
}

void Instructions::JR_r8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.registers.setPC(state.registers.getPC() +
							  static_cast<std::int8_t>(state.mmu.read(state.registers.getPC())));
		state.registers.incPC();
	});

	state.cpuQueue.push([](State& state) {
		// NOP
	});
}

void Instructions::ADD_HL_DE(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		state.registers.resetCarryFlag();
		if (((state.registers.getL() & 0xf) + (state.registers.getE() & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getL() & 0xff) + (state.registers.getE() & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setL(state.registers.getL() + state.registers.getE());
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t carry = state.registers.getCarryFlag();
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		state.registers.resetCarryFlag();
		if (((state.registers.getH() & 0xf) + (state.registers.getD() & 0xf) + (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getH() & 0xff) + (state.registers.getD() & 0xff) + (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setH(state.registers.getH() + state.registers.getD() + carry);
	});
}

void Instructions::LD_A_MEM_AT_DE(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.setA(state.mmu.read(state.registers.getDE())); });
}

void Instructions::DEC_DE(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
		if (((state.registers.getE() - 1) & 0xff) >= state.registers.getE())
			state.tmp.push(1);
		else
			state.tmp.push(0);
		state.registers.decE();
	});
	state.cpuQueue.push([](State& state) {
		state.registers.setD(state.registers.getD() - state.tmp.top());
		state.tmp.pop();
	});
}

void Instructions::INC_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.getE() & 0xf) + 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.incE();
		if (state.registers.getE() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::DEC_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.setSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.getE() & 0xf) - 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.decE();
		if (state.registers.getE() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::LD_E_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.registers.setE(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});
}

void Instructions::RRA(State& state)
{
	state.cpuQueue.push([](State& state) {
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (state.registers.getA() & 1)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() >> 1 | carry << 7);
	});
}

void Instructions::JR_NZ_r8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		std::int8_t e = static_cast<std::int8_t>(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
		if (!state.registers.getZeroFlag())
		{
			state.registers.setPC(state.registers.getPC() + e);
			state.cpuQueue.push([](State& state) {
				// NOP
			});
		}
	});
}

void Instructions::LD_HL_d16(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.registers.setL(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});

	state.cpuQueue.push([](State& state) {
		state.registers.setH(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});
}

void Instructions::LDI_MEM_AT_HL_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.getHL(), state.registers.getA());
		state.registers.incHL();
	});
}

void Instructions::INC_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
		if (((state.registers.getL() + 1) & 0xff) < state.registers.getL())
			state.tmp.push(1);
		else
			state.tmp.push(0);
		state.registers.incL();
	});
	state.cpuQueue.push([](State& state) {
		state.registers.setH(state.registers.getH() + state.tmp.top());
		state.tmp.pop();
	});
}

void Instructions::INC_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.getH() & 0xf) + 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.incH();
		if (state.registers.getH() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::DEC_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.setSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.getH() & 0xf) - 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.decH();
		if (state.registers.getH() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::LD_H_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.registers.setH(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});
}

void Instructions::DAA(State& state)
{
	state.cpuQueue.push([](State& state) {
		if (state.registers.getSubtractFlag())
		{
			// after subtraction
			if (state.registers.getCarryFlag())
				state.registers.setA(state.registers.getA() - 0x60);
			if (state.registers.getHalfCarryFlag())
				state.registers.setA(state.registers.getA() - 0x6);
		}
		else
		{
			// after addition
			if (state.registers.getCarryFlag() || state.registers.getA() > 0x99)
			{
				state.registers.setA(state.registers.getA() + 0x60);
				state.registers.setCarryFlag();
			}
			if (state.registers.getHalfCarryFlag() || (state.registers.getA() & 0x0f) > 0x09)
				state.registers.setA(state.registers.getA() + 0x6);
		}
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
		state.registers.resetHalfCarryFlag();
	});
}

void Instructions::JR_Z_r8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		std::int8_t e = static_cast<std::int8_t>(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
		if (state.registers.getZeroFlag())
		{
			state.registers.setPC(state.registers.getPC() + e);
			state.cpuQueue.push([](State& state) {
				// NOP
			});
		}
	});
}

void Instructions::ADD_HL_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		state.registers.resetCarryFlag();
		if (((state.registers.getL() & 0xf) + (state.registers.getL() & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getL() & 0xff) + (state.registers.getL() & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setL(state.registers.getL() + state.registers.getL());
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t carry = state.registers.getCarryFlag();
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		state.registers.resetCarryFlag();
		if (((state.registers.getH() & 0xf) + (state.registers.getH() & 0xf) + (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getH() & 0xff) + (state.registers.getH() & 0xff) + (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setH(state.registers.getH() + state.registers.getH() + carry);
	});
}

void Instructions::LDI_A_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.registers.setA(state.mmu.read(state.registers.getHL()));
		state.registers.incHL();
	});
}

void Instructions::DEC_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
		if (((state.registers.getL() - 1) & 0xff) >= state.registers.getL())
			state.tmp.push(1);
		else
			state.tmp.push(0);
		state.registers.decL();
	});
	state.cpuQueue.push([](State& state) {
		state.registers.setH(state.registers.getH() - state.tmp.top());
		state.tmp.pop();
	});
}

void Instructions::INC_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.getL() & 0xf) + 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.incL();
		if (state.registers.getL() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::DEC_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.setSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.getL() & 0xf) - 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.decL();
		if (state.registers.getL() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::LD_L_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.registers.setL(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});
}

void Instructions::CPL(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.setA(~state.registers.getA());
		state.registers.setSubtractFlag();
		state.registers.setHalfCarryFlag();
	});
}

void Instructions::JR_NC_r8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		std::int8_t e = static_cast<std::int8_t>(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
		if (!state.registers.getCarryFlag())
		{
			state.registers.setPC(state.registers.getPC() + e);
			state.cpuQueue.push([](State& state) {
				// NOP
			});
		}
	});
}

void Instructions::LD_SP_d16(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});

	state.cpuQueue.push([](State& state) {
		state.registers.setSP(toWord(state.tmp.top(), state.mmu.read(state.registers.getPC())));
		state.registers.incPC();
		state.tmp.pop();
	});
}

void Instructions::LDD_MEM_AT_HL_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.getHL(), state.registers.getA());
		state.registers.decHL();
	});
}

void Instructions::INC_SP(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
		std::uint8_t s = msb(state.registers.getSP());
		std::uint8_t p = lsb(state.registers.getSP());
		if (((p + 1) & 0xff) < p)
			state.tmp.push(1);
		else
			state.tmp.push(0);
		p += 1;
		state.registers.setSP(toWord(p, s));
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t s = msb(state.registers.getSP());
		std::uint8_t p = lsb(state.registers.getSP());
		s += state.tmp.top();
		state.tmp.pop();
		state.registers.setSP(toWord(p, s));
	});
}

void Instructions::INC_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.getHL())); });
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.tmp.top() & 0xf) + 1) > 0xf)
			state.registers.setHalfCarryFlag();
		state.mmu.write(state.registers.getHL(), state.tmp.top() + 1);
		if (((state.tmp.top() + 1) & 0xff) == 0)
			state.registers.setZeroFlag();
		state.tmp.pop();
	});
}

void Instructions::DEC_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.getHL())); });
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.setSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if ((((state.tmp.top() & 0xf) - 1) & 0xf) >= (state.tmp.top() & 0xf))
			state.registers.setHalfCarryFlag();
		state.mmu.write(state.registers.getHL(), state.tmp.top() - 1);
		if (((state.tmp.top() - 1) & 0xff) == 0)
			state.registers.setZeroFlag();
		state.tmp.pop();
	});
}

void Instructions::LD_MEM_AT_HL_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});

	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.getHL(), state.tmp.top());
		state.tmp.pop();
	});
}

void Instructions::SCF(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		state.registers.setCarryFlag();
	});
}

void Instructions::JR_C_r8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		std::int8_t e = static_cast<std::int8_t>(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
		if (state.registers.getCarryFlag())
		{
			state.registers.setPC(state.registers.getPC() + e);
			state.cpuQueue.push([](State& state) {
				// NOP
			});
		}
	});
}

void Instructions::ADD_HL_SP(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t p = lsb(state.registers.getSP());
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		state.registers.resetCarryFlag();
		if (((state.registers.getL() & 0xf) + (p & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getL() & 0xff) + (p & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setL(state.registers.getL() + p);
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t s = msb(state.registers.getSP());
		std::uint8_t carry = state.registers.getCarryFlag();
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		state.registers.resetCarryFlag();
		if (((state.registers.getH() & 0xf) + (s & 0xf) + (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getH() & 0xff) + (s & 0xff) + (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setH(state.registers.getH() + s + carry);
	});
}

void Instructions::LDD_A_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.registers.setA(state.mmu.read(state.registers.getHL()));
		state.registers.decHL();
	});
}

void Instructions::DEC_SP(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
		std::uint8_t s = msb(state.registers.getSP());
		std::uint8_t p = lsb(state.registers.getSP());
		if (((p - 1) & 0xff) >= p)
			state.tmp.push(1);
		else
			state.tmp.push(0);
		p -= 1;
		state.registers.setSP(toWord(p, s));
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t s = msb(state.registers.getSP());
		std::uint8_t p = lsb(state.registers.getSP());
		s -= state.tmp.top();
		state.tmp.pop();
		state.registers.setSP(toWord(p, s));
	});
}

void Instructions::INC_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.getA() & 0xf) + 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.incA();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::DEC_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.setSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.getA() & 0xf) - 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.decA();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::LD_A_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.registers.setA(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});
}

void Instructions::CCF(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (state.registers.getCarryFlag())
			state.registers.resetCarryFlag();
		else
			state.registers.setCarryFlag();
	});
}

void Instructions::LD_B_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setB(state.registers.getB()); });
}

void Instructions::LD_B_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setB(state.registers.getC()); });
}

void Instructions::LD_B_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setB(state.registers.getD()); });
}

void Instructions::LD_B_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setB(state.registers.getE()); });
}

void Instructions::LD_B_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setB(state.registers.getH()); });
}

void Instructions::LD_B_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setB(state.registers.getL()); });
}

void Instructions::LD_B_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.setB(state.mmu.read(state.registers.getHL())); });
}

void Instructions::LD_B_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setB(state.registers.getA()); });
}

void Instructions::LD_C_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setC(state.registers.getB()); });
}

void Instructions::LD_C_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setC(state.registers.getC()); });
}

void Instructions::LD_C_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setC(state.registers.getD()); });
}

void Instructions::LD_C_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setC(state.registers.getE()); });
}

void Instructions::LD_C_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setC(state.registers.getH()); });
}

void Instructions::LD_C_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setC(state.registers.getL()); });
}

void Instructions::LD_C_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.setC(state.mmu.read(state.registers.getHL())); });
}

void Instructions::LD_C_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setC(state.registers.getA()); });
}

void Instructions::LD_D_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setD(state.registers.getB()); });
}

void Instructions::LD_D_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setD(state.registers.getC()); });
}

void Instructions::LD_D_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setD(state.registers.getD()); });
}

void Instructions::LD_D_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setD(state.registers.getE()); });
}

void Instructions::LD_D_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setD(state.registers.getH()); });
}

void Instructions::LD_D_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setD(state.registers.getL()); });
}

void Instructions::LD_D_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.setD(state.mmu.read(state.registers.getHL())); });
}

void Instructions::LD_D_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setD(state.registers.getA()); });
}

void Instructions::LD_E_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setE(state.registers.getB()); });
}

void Instructions::LD_E_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setE(state.registers.getC()); });
}

void Instructions::LD_E_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setE(state.registers.getD()); });
}

void Instructions::LD_E_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setE(state.registers.getE()); });
}

void Instructions::LD_E_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setE(state.registers.getH()); });
}

void Instructions::LD_E_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setE(state.registers.getL()); });
}

void Instructions::LD_E_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.setE(state.mmu.read(state.registers.getHL())); });
}

void Instructions::LD_E_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setE(state.registers.getA()); });
}

void Instructions::LD_H_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setH(state.registers.getB()); });
}

void Instructions::LD_H_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setH(state.registers.getC()); });
}

void Instructions::LD_H_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setH(state.registers.getD()); });
}

void Instructions::LD_H_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setH(state.registers.getE()); });
}

void Instructions::LD_H_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setH(state.registers.getH()); });
}

void Instructions::LD_H_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setH(state.registers.getL()); });
}

void Instructions::LD_H_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.setH(state.mmu.read(state.registers.getHL())); });
}

void Instructions::LD_H_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setH(state.registers.getA()); });
}

void Instructions::LD_L_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setL(state.registers.getB()); });
}

void Instructions::LD_L_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setL(state.registers.getC()); });
}

void Instructions::LD_L_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setL(state.registers.getD()); });
}

void Instructions::LD_L_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setL(state.registers.getE()); });
}

void Instructions::LD_L_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setL(state.registers.getH()); });
}

void Instructions::LD_L_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setL(state.registers.getL()); });
}

void Instructions::LD_L_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.setL(state.mmu.read(state.registers.getHL())); });
}

void Instructions::LD_L_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setL(state.registers.getA()); });
}

void Instructions::LD_MEM_AT_HL_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.mmu.write(state.registers.getHL(), state.registers.getB()); });
}

void Instructions::LD_MEM_AT_HL_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.mmu.write(state.registers.getHL(), state.registers.getC()); });
}

void Instructions::LD_MEM_AT_HL_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.mmu.write(state.registers.getHL(), state.registers.getD()); });
}

void Instructions::LD_MEM_AT_HL_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.mmu.write(state.registers.getHL(), state.registers.getE()); });
}

void Instructions::LD_MEM_AT_HL_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.mmu.write(state.registers.getHL(), state.registers.getH()); });
}

void Instructions::LD_MEM_AT_HL_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.mmu.write(state.registers.getHL(), state.registers.getL()); });
}

void Instructions::HALT(State& state)
{
	state.cpuQueue.push([](State& state) {
		const std::uint8_t& IE = state.mmu.read(LIBGREBE_REG_IE);
		const std::uint8_t& IF = state.mmu.read(LIBGREBE_REG_IF);
		if (state.ime)
		{
			state.controlUnitState = ControlUnitState::LIBGREBE_CONTROL_UNIT_STATE_HALT;
		}
		else
		{
			if (!(IE & IF & 0x1f)) // no interrupt pending
				state.controlUnitState = ControlUnitState::LIBGREBE_CONTROL_UNIT_STATE_HALT;
			else
				state.controlUnitState = ControlUnitState::LIBGREBE_CONTROL_UNIT_STATE_HALT_BUG;
		}
	});
}

void Instructions::LD_MEM_AT_HL_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.mmu.write(state.registers.getHL(), state.registers.getA()); });
}

void Instructions::LD_A_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setA(state.registers.getB()); });
}

void Instructions::LD_A_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setA(state.registers.getC()); });
}

void Instructions::LD_A_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setA(state.registers.getD()); });
}

void Instructions::LD_A_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setA(state.registers.getE()); });
}

void Instructions::LD_A_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setA(state.registers.getH()); });
}

void Instructions::LD_A_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setA(state.registers.getL()); });
}

void Instructions::LD_A_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.setA(state.mmu.read(state.registers.getHL())); });
}

void Instructions::LD_A_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setA(state.registers.getA()); });
}

void Instructions::ADD_A_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		if (((state.registers.getA() & 0xf) + (state.registers.getB() & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) + (state.registers.getB() & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() + state.registers.getB());
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADD_A_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		if (((state.registers.getA() & 0xf) + (state.registers.getC() & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) + (state.registers.getC() & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() + state.registers.getC());
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADD_A_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		if (((state.registers.getA() & 0xf) + (state.registers.getD() & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) + (state.registers.getD() & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() + state.registers.getD());
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADD_A_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		if (((state.registers.getA() & 0xf) + (state.registers.getE() & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) + (state.registers.getE() & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() + state.registers.getE());
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADD_A_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		if (((state.registers.getA() & 0xf) + (state.registers.getH() & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) + (state.registers.getH() & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() + state.registers.getH());
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADD_A_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		if (((state.registers.getA() & 0xf) + (state.registers.getL() & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) + (state.registers.getL() & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() + state.registers.getL());
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADD_A_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		if (((state.registers.getA() & 0xf) + (state.mmu.read(state.registers.getHL()) & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) + (state.mmu.read(state.registers.getHL()) & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() + state.mmu.read(state.registers.getHL()));
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADD_A_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		if (((state.registers.getA() & 0xf) + (state.registers.getA() & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) + (state.registers.getA() & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() + state.registers.getA());
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADC_A_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (((state.registers.getA() & 0xf) + (state.registers.getB() & 0xf) + (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) + (state.registers.getB() & 0xff) + (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() + state.registers.getB() + carry);
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADC_A_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (((state.registers.getA() & 0xf) + (state.registers.getC() & 0xf) + (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) + (state.registers.getC() & 0xff) + (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() + state.registers.getC() + carry);
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADC_A_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (((state.registers.getA() & 0xf) + (state.registers.getD() & 0xf) + (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) + (state.registers.getD() & 0xff) + (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() + state.registers.getD() + carry);
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADC_A_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (((state.registers.getA() & 0xf) + (state.registers.getE() & 0xf) + (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) + (state.registers.getE() & 0xff) + (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() + state.registers.getE() + carry);
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADC_A_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (((state.registers.getA() & 0xf) + (state.registers.getH() & 0xf) + (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) + (state.registers.getH() & 0xff) + (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() + state.registers.getH() + carry);
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADC_A_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (((state.registers.getA() & 0xf) + (state.registers.getL() & 0xf) + (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) + (state.registers.getL() & 0xff) + (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() + state.registers.getL() + carry);
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADC_A_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (((state.registers.getA() & 0xf) + (state.mmu.read(state.registers.getHL()) & 0xf) + (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) + (state.mmu.read(state.registers.getHL()) & 0xff) + (carry & 0xff)) &
			0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() + state.mmu.read(state.registers.getHL()) + carry);
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADC_A_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (((state.registers.getA() & 0xf) + (state.registers.getA() & 0xf) + (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) + (state.registers.getA() & 0xff) + (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() + state.registers.getA() + carry);
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SUB_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.getA() & 0xf) - (state.registers.getB() & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (state.registers.getB() & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() - state.registers.getB());
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SUB_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.getA() & 0xf) - (state.registers.getC() & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (state.registers.getC() & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() - state.registers.getC());
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SUB_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.getA() & 0xf) - (state.registers.getD() & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (state.registers.getD() & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() - state.registers.getD());
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SUB_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.getA() & 0xf) - (state.registers.getE() & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (state.registers.getE() & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() - state.registers.getE());
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SUB_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.getA() & 0xf) - (state.registers.getH() & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (state.registers.getH() & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() - state.registers.getH());
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SUB_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.getA() & 0xf) - (state.registers.getL() & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (state.registers.getL() & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() - state.registers.getL());
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SUB_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.getA() & 0xf) - (state.mmu.read(state.registers.getHL()) & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (state.mmu.read(state.registers.getHL()) & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() - state.mmu.read(state.registers.getHL()));
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SUB_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.getA() & 0xf) - (state.registers.getA() & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (state.registers.getA() & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() - state.registers.getA());
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SBC_A_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getB();
		std::uint8_t carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.getA() & 0xf) - (operand & 0xf) - (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (operand & 0xff) - (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() - (operand + carry));
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SBC_A_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getC();
		std::uint8_t carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.getA() & 0xf) - (operand & 0xf) - (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (operand & 0xff) - (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() - (operand + carry));
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SBC_A_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getD();
		std::uint8_t carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.getA() & 0xf) - (operand & 0xf) - (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (operand & 0xff) - (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() - (operand + carry));
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SBC_A_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getE();
		std::uint8_t carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.getA() & 0xf) - (operand & 0xf) - (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (operand & 0xff) - (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() - (operand + carry));
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SBC_A_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getH();
		std::uint8_t carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.getA() & 0xf) - (operand & 0xf) - (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (operand & 0xff) - (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() - (operand + carry));
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SBC_A_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getL();
		std::uint8_t carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.getA() & 0xf) - (operand & 0xf) - (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (operand & 0xff) - (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() - (operand + carry));
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SBC_A_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.mmu.read(state.registers.getHL());
		std::uint8_t carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.getA() & 0xf) - (operand & 0xf) - (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (operand & 0xff) - (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() - (operand + carry));
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SBC_A_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getA();
		std::uint8_t carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.getA() & 0xf) - (operand & 0xf) - (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (operand & 0xff) - (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() - (operand + carry));
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::AND_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getB();
		state.registers.setA(state.registers.getA() & operand);
		state.registers.clearFlags();
		state.registers.setHalfCarryFlag();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::AND_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getC();
		state.registers.setA(state.registers.getA() & operand);
		state.registers.clearFlags();
		state.registers.setHalfCarryFlag();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::AND_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getD();
		state.registers.setA(state.registers.getA() & operand);
		state.registers.clearFlags();
		state.registers.setHalfCarryFlag();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::AND_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getE();
		state.registers.setA(state.registers.getA() & operand);
		state.registers.clearFlags();
		state.registers.setHalfCarryFlag();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::AND_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getH();
		state.registers.setA(state.registers.getA() & operand);
		state.registers.clearFlags();
		state.registers.setHalfCarryFlag();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::AND_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getL();
		state.registers.setA(state.registers.getA() & operand);
		state.registers.clearFlags();
		state.registers.setHalfCarryFlag();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::AND_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.mmu.read(state.registers.getHL());
		state.registers.setA(state.registers.getA() & operand);
		state.registers.clearFlags();
		state.registers.setHalfCarryFlag();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::AND_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getA();
		state.registers.setA(state.registers.getA() & operand);
		state.registers.clearFlags();
		state.registers.setHalfCarryFlag();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::XOR_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getB();
		state.registers.setA(state.registers.getA() ^ operand);
		state.registers.clearFlags();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::XOR_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getC();
		state.registers.setA(state.registers.getA() ^ operand);
		state.registers.clearFlags();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::XOR_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getD();
		state.registers.setA(state.registers.getA() ^ operand);
		state.registers.clearFlags();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::XOR_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getE();
		state.registers.setA(state.registers.getA() ^ operand);
		state.registers.clearFlags();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::XOR_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getH();
		state.registers.setA(state.registers.getA() ^ operand);
		state.registers.clearFlags();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::XOR_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getL();
		state.registers.setA(state.registers.getA() ^ operand);
		state.registers.clearFlags();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::XOR_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.mmu.read(state.registers.getHL());
		state.registers.setA(state.registers.getA() ^ operand);
		state.registers.clearFlags();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::XOR_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getA();
		state.registers.setA(state.registers.getA() ^ operand);
		state.registers.clearFlags();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::OR_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getB();
		state.registers.setA(state.registers.getA() | operand);
		state.registers.clearFlags();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::OR_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getC();
		state.registers.setA(state.registers.getA() | operand);
		state.registers.clearFlags();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::OR_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getD();
		state.registers.setA(state.registers.getA() | operand);
		state.registers.clearFlags();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::OR_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getE();
		state.registers.setA(state.registers.getA() | operand);
		state.registers.clearFlags();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::OR_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getH();
		state.registers.setA(state.registers.getA() | operand);
		state.registers.clearFlags();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::OR_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getL();
		state.registers.setA(state.registers.getA() | operand);
		state.registers.clearFlags();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::OR_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.mmu.read(state.registers.getHL());
		state.registers.setA(state.registers.getA() | operand);
		state.registers.clearFlags();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::OR_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getA();
		state.registers.setA(state.registers.getA() | operand);
		state.registers.clearFlags();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::CP_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getB();
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.getA() & 0xf) - (operand & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (operand & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		if (state.registers.getA() - operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::CP_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getC();
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.getA() & 0xf) - (operand & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (operand & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		if (state.registers.getA() - operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::CP_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getD();
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.getA() & 0xf) - (operand & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (operand & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		if (state.registers.getA() - operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::CP_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getE();
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.getA() & 0xf) - (operand & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (operand & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		if (state.registers.getA() - operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::CP_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getH();
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.getA() & 0xf) - (operand & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (operand & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		if (state.registers.getA() - operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::CP_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getL();
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.getA() & 0xf) - (operand & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (operand & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		if (state.registers.getA() - operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::CP_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.mmu.read(state.registers.getHL());
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.getA() & 0xf) - (operand & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (operand & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		if (state.registers.getA() - operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::CP_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getA();
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.getA() & 0xf) - (operand & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (operand & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		if (state.registers.getA() - operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RET_NZ(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		// NOP
		if (!state.registers.getZeroFlag())
		{
			state.cpuQueue.push([](State& state) {
				state.tmp.push(state.mmu.read(state.registers.getSP()));
				state.registers.incSP();
			});
			state.cpuQueue.push([](State& state) {
				state.registers.setPC(toWord(state.tmp.top(), state.mmu.read(state.registers.getSP())));
				state.registers.incSP();
				state.tmp.pop();
			});
			state.cpuQueue.push([](State& state) {
				// NOP
			});
		}
	});
}

void Instructions::POP_BC(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getSP()));
		state.registers.incSP();
	});
	state.cpuQueue.push([](State& state) {
		state.registers.setBC(toWord(state.tmp.top(), state.mmu.read(state.registers.getSP())));
		state.registers.incSP();
		state.tmp.pop();
	});
}

void Instructions::JP_NZ_a16(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});

	state.cpuQueue.push([](State& state) {
		std::uint8_t d = state.mmu.read(state.registers.getPC());
		state.registers.incPC();
		if (!state.registers.getZeroFlag())
		{
			state.registers.setPC(toWord(state.tmp.top(), d));
			state.tmp.pop();
			state.cpuQueue.push([](State& state) {
				// NOP
			});
		}
		else
			state.tmp.pop();
	});
}

void Instructions::JP_a16(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});

	state.cpuQueue.push([](State& state) {
		state.registers.setPC(toWord(state.tmp.top(), state.mmu.read(state.registers.getPC())));
		// state.registers.incPC(); // should we increase pc after jump? current unit test says no
		state.tmp.pop();
	});
	state.cpuQueue.push([](State& state) {
		// NOP
	});
}

void Instructions::CALL_NZ_a16(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});

	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
		if (!state.registers.getZeroFlag())
		{
			state.cpuQueue.push([](State& state) {
				// NOP
			});
			state.cpuQueue.push([](State& state) {
				state.registers.decSP();
				state.mmu.write(state.registers.getSP(), msb(state.registers.getPC()));
			});
			state.cpuQueue.push([](State& state) {
				state.registers.decSP();
				state.mmu.write(state.registers.getSP(), lsb(state.registers.getPC()));
				std::uint8_t tmp2 = state.tmp.top();
				state.tmp.pop();
				std::uint8_t tmp1 = state.tmp.top();
				state.tmp.pop();
				state.registers.setPC(toWord(tmp1, tmp2));
			});
		}
		else
		{
			state.tmp.pop();
			state.tmp.pop();
		}
	});
}

void Instructions::PUSH_BC(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		// NOP
	});
	state.cpuQueue.push([](State& state) {
		state.registers.decSP();
		state.mmu.write(state.registers.getSP(), msb(state.registers.getBC()));
	});
	state.cpuQueue.push([](State& state) {
		state.registers.decSP();
		state.mmu.write(state.registers.getSP(), lsb(state.registers.getBC()));
	});
}

void Instructions::ADD_A_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.mmu.read(state.registers.getPC());
		state.registers.clearFlags();
		if (((state.registers.getA() & 0xf) + (operand & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) + (operand & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() + operand);
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
		state.registers.incPC();
	});
}

void Instructions::RST_00H(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		// NOP
	});
	state.cpuQueue.push([](State& state) {
		state.registers.decSP();
		state.mmu.write(state.registers.getSP(), msb(state.registers.getPC()));
	});
	state.cpuQueue.push([](State& state) {
		state.registers.decSP();
		state.mmu.write(state.registers.getSP(), lsb(state.registers.getPC()));
		state.registers.setPC(0);
	});
}

void Instructions::RET_Z(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		// NOP
		if (state.registers.getZeroFlag())
		{
			state.cpuQueue.push([](State& state) {
				state.tmp.push(state.mmu.read(state.registers.getSP()));
				state.registers.incSP();
			});
			state.cpuQueue.push([](State& state) {
				state.registers.setPC(toWord(state.tmp.top(), state.mmu.read(state.registers.getSP())));
				state.registers.incSP();
				state.tmp.pop();
			});
			state.cpuQueue.push([](State& state) {
				// NOP
			});
		}
	});
}

void Instructions::RET(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getSP()));
		state.registers.incSP();
	});
	state.cpuQueue.push([](State& state) {
		state.registers.setPC(toWord(state.tmp.top(), state.mmu.read(state.registers.getSP())));
		state.registers.incSP();
		state.tmp.pop();
	});
	state.cpuQueue.push([](State& state) {
		// NOP
	});
}

void Instructions::JP_Z_a16(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});

	state.cpuQueue.push([](State& state) {
		std::uint8_t d = state.mmu.read(state.registers.getPC());
		state.registers.incPC();
		if (state.registers.getZeroFlag())
		{
			state.registers.setPC(toWord(state.tmp.top(), d));
			state.tmp.pop();
			state.cpuQueue.push([](State& state) {
				// NOP
			});
		}
		else
			state.tmp.pop();
	});
}

void Instructions::PREFIX_CB(State& state)
{
	state.cpuQueue.push([](State& state) { state.extendedOpcodeSet = true; });
}

void Instructions::CALL_Z_a16(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});

	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
		if (state.registers.getZeroFlag())
		{
			state.cpuQueue.push([](State& state) {
				// NOP
			});
			state.cpuQueue.push([](State& state) {
				state.registers.decSP();
				state.mmu.write(state.registers.getSP(), msb(state.registers.getPC()));
			});
			state.cpuQueue.push([](State& state) {
				state.registers.decSP();
				state.mmu.write(state.registers.getSP(), lsb(state.registers.getPC()));

				std::uint8_t tmp2 = state.tmp.top();
				state.tmp.pop();
				std::uint8_t tmp1 = state.tmp.top();
				state.tmp.pop();
				state.registers.setPC(toWord(tmp1, tmp2));
			});
		}
		else
		{
			state.tmp.pop();
			state.tmp.pop();
		}
	});
}

void Instructions::CALL_a16(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});

	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});

	state.cpuQueue.push([](State& state) {
		// NOP
	});
	state.cpuQueue.push([](State& state) {
		state.registers.decSP();
		state.mmu.write(state.registers.getSP(), msb(state.registers.getPC()));
	});
	state.cpuQueue.push([](State& state) {
		state.registers.decSP();
		state.mmu.write(state.registers.getSP(), lsb(state.registers.getPC()));

		std::uint8_t tmp2 = state.tmp.top();
		state.tmp.pop();
		std::uint8_t tmp1 = state.tmp.top();
		state.tmp.pop();
		state.registers.setPC(toWord(tmp1, tmp2));
	});
}

void Instructions::ADC_A_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t carry = state.registers.getCarryFlag();
		std::uint8_t operand = state.mmu.read(state.registers.getPC());
		state.registers.clearFlags();
		if (((state.registers.getA() & 0xf) + (operand & 0xf) + (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) + (operand & 0xff) + (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() + operand + carry);
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
		state.registers.incPC();
	});
}

void Instructions::RST_08H(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		// NOP
	});
	state.cpuQueue.push([](State& state) {
		state.registers.decSP();
		state.mmu.write(state.registers.getSP(), msb(state.registers.getPC()));
	});
	state.cpuQueue.push([](State& state) {
		state.registers.decSP();
		state.mmu.write(state.registers.getSP(), lsb(state.registers.getPC()));
		state.registers.setPC(0x08);
	});
}

void Instructions::RET_NC(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		// NOP
		if (!state.registers.getCarryFlag())
		{
			state.cpuQueue.push([](State& state) {
				state.tmp.push(state.mmu.read(state.registers.getSP()));
				state.registers.incSP();
			});
			state.cpuQueue.push([](State& state) {
				state.registers.setPC(toWord(state.tmp.top(), state.mmu.read(state.registers.getSP())));
				state.registers.incSP();
				state.tmp.pop();
			});
			state.cpuQueue.push([](State& state) {
				// NOP
			});
		}
	});
}

void Instructions::POP_DE(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getSP()));
		state.registers.incSP();
	});
	state.cpuQueue.push([](State& state) {
		state.registers.setDE(toWord(state.tmp.top(), state.mmu.read(state.registers.getSP())));
		state.registers.incSP();
		state.tmp.pop();
	});
}

void Instructions::JP_NC_a16(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});

	state.cpuQueue.push([](State& state) {
		std::uint8_t d = state.mmu.read(state.registers.getPC());
		state.registers.incPC();
		if (!state.registers.getCarryFlag())
		{
			state.registers.setPC(toWord(state.tmp.top(), d));
			state.tmp.pop();
			state.cpuQueue.push([](State& state) {
				// NOP
			});
		}
		else
			state.tmp.pop();
	});
}

void Instructions::CALL_NC_a16(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});

	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
		if (!state.registers.getCarryFlag())
		{
			state.cpuQueue.push([](State& state) {
				// NOP
			});
			state.cpuQueue.push([](State& state) {
				state.registers.decSP();
				state.mmu.write(state.registers.getSP(), msb(state.registers.getPC()));
			});
			state.cpuQueue.push([](State& state) {
				state.registers.decSP();
				state.mmu.write(state.registers.getSP(), lsb(state.registers.getPC()));

				std::uint8_t tmp2 = state.tmp.top();
				state.tmp.pop();
				std::uint8_t tmp1 = state.tmp.top();
				state.tmp.pop();
				state.registers.setPC(toWord(tmp1, tmp2));
			});
		}
		else
		{
			state.tmp.pop();
			state.tmp.pop();
		}
	});
}

void Instructions::PUSH_DE(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		// NOP
	});
	state.cpuQueue.push([](State& state) {
		state.registers.decSP();
		state.mmu.write(state.registers.getSP(), msb(state.registers.getDE()));
	});
	state.cpuQueue.push([](State& state) {
		state.registers.decSP();
		state.mmu.write(state.registers.getSP(), lsb(state.registers.getDE()));
	});
}

void Instructions::SUB_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		std::uint8_t operand = state.mmu.read(state.registers.getPC());
		if (((state.registers.getA() & 0xf) - (operand & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (operand & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() - operand);
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
		state.registers.incPC();
	});
}

void Instructions::RST_10H(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		// NOP
	});
	state.cpuQueue.push([](State& state) {
		state.registers.decSP();
		state.mmu.write(state.registers.getSP(), msb(state.registers.getPC()));
	});
	state.cpuQueue.push([](State& state) {
		state.registers.decSP();
		state.mmu.write(state.registers.getSP(), lsb(state.registers.getPC()));
		state.registers.setPC(0x10);
	});
}

void Instructions::RET_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		// NOP
		if (state.registers.getCarryFlag())
		{
			state.cpuQueue.push([](State& state) {
				state.tmp.push(state.mmu.read(state.registers.getSP()));
				state.registers.incSP();
			});
			state.cpuQueue.push([](State& state) {
				state.registers.setPC(toWord(state.tmp.top(), state.mmu.read(state.registers.getSP())));
				state.registers.incSP();
				state.tmp.pop();
			});
			state.cpuQueue.push([](State& state) {
				// NOP
			});
		}
	});
}

void Instructions::RETI(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getSP()));
		state.registers.incSP();
	});
	state.cpuQueue.push([](State& state) {
		state.registers.setPC(toWord(state.tmp.top(), state.mmu.read(state.registers.getSP())));
		state.registers.incSP();
		state.tmp.pop();
		state.ime = true;
	});
	state.cpuQueue.push([](State& state) {
		// NOP
	});
}

void Instructions::JP_C_a16(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});

	state.cpuQueue.push([](State& state) {
		std::uint8_t d = state.mmu.read(state.registers.getPC());
		state.registers.incPC();
		if (state.registers.getCarryFlag())
		{
			state.registers.setPC(toWord(state.tmp.top(), d));
			state.tmp.pop();
			state.cpuQueue.push([](State& state) {
				// NOP
			});
		}
		else
			state.tmp.pop();
	});
}

void Instructions::CALL_C_a16(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});

	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
		if (state.registers.getCarryFlag())
		{
			state.cpuQueue.push([](State& state) {
				// NOP
			});
			state.cpuQueue.push([](State& state) {
				state.registers.decSP();
				state.mmu.write(state.registers.getSP(), msb(state.registers.getPC()));
			});
			state.cpuQueue.push([](State& state) {
				state.registers.decSP();
				state.mmu.write(state.registers.getSP(), lsb(state.registers.getPC()));

				std::uint8_t tmp2 = state.tmp.top();
				state.tmp.pop();
				std::uint8_t tmp1 = state.tmp.top();
				state.tmp.pop();
				state.registers.setPC(toWord(tmp1, tmp2));
			});
		}
		else
		{
			state.tmp.pop();
			state.tmp.pop();
		}
	});
}

void Instructions::SBC_A_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.mmu.read(state.registers.getPC());
		std::uint8_t carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.getA() & 0xf) - (operand & 0xf) - (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (operand & 0xff) - (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.setA(state.registers.getA() - (operand + carry));
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
		state.registers.incPC();
	});
}

void Instructions::RST_18H(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		// NOP
	});
	state.cpuQueue.push([](State& state) {
		state.registers.decSP();
		state.mmu.write(state.registers.getSP(), msb(state.registers.getPC()));
	});
	state.cpuQueue.push([](State& state) {
		state.registers.decSP();
		state.mmu.write(state.registers.getSP(), lsb(state.registers.getPC()));
		state.registers.setPC(0x18);
	});
}

void Instructions::LDH_MEM_AT_a8_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});

	state.cpuQueue.push([](State& state) {
		state.mmu.write(0xff00 | state.tmp.top(), state.registers.getA());
		state.tmp.pop();
	});
}

void Instructions::POP_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getSP()));
		state.registers.incSP();
	});
	state.cpuQueue.push([](State& state) {
		state.registers.setHL(toWord(state.tmp.top(), state.mmu.read(state.registers.getSP())));
		state.registers.incSP();
		state.tmp.pop();
	});
}

void Instructions::LD_MEM_AT_C_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.mmu.write(0xff00 | state.registers.getC(), state.registers.getA()); });
}

void Instructions::PUSH_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		// NOP
	});
	state.cpuQueue.push([](State& state) {
		state.registers.decSP();
		state.mmu.write(state.registers.getSP(), msb(state.registers.getHL()));
	});
	state.cpuQueue.push([](State& state) {
		state.registers.decSP();
		state.mmu.write(state.registers.getSP(), lsb(state.registers.getHL()));
	});
}

void Instructions::AND_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.mmu.read(state.registers.getPC());
		state.registers.setA(state.registers.getA() & operand);
		state.registers.clearFlags();
		state.registers.setHalfCarryFlag();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
		state.registers.incPC();
	});
}

void Instructions::RST_20H(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		// NOP
	});
	state.cpuQueue.push([](State& state) {
		state.registers.decSP();
		state.mmu.write(state.registers.getSP(), msb(state.registers.getPC()));
	});
	state.cpuQueue.push([](State& state) {
		state.registers.decSP();
		state.mmu.write(state.registers.getSP(), lsb(state.registers.getPC()));
		state.registers.setPC(0x20);
	});
}

void Instructions::ADD_SP_r8(State& state)
{
	// todo sus
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.tmp.push(static_cast<std::int8_t>(state.mmu.read(state.registers.getPC())));
		state.registers.incPC();
	});
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		const std::int8_t& e = static_cast<std::int8_t>(state.tmp.top());
		if (e >= 0)
		{
			if (((state.registers.getSP() & 0xf) + (e & 0xf)) > 0xf)
				state.registers.setHalfCarryFlag();
			if ((state.registers.getSP() & 0xff) + e > 0xff)
				state.registers.setCarryFlag();
		}
		else
		{
			if (((state.registers.getSP() + e) & 0xf) >= (state.registers.getSP() & 0xf))
				state.registers.setHalfCarryFlag();
			if (((state.registers.getSP() + e) & 0xff) >= (state.registers.getSP() & 0xff))
				state.registers.setCarryFlag();
		}
		state.registers.setSP(state.registers.getSP() + e);
		state.tmp.pop();
	});
	state.cpuQueue.push([](State& state) {
		// NOP
	});
}

void Instructions::JP_HL(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setPC(state.registers.getHL()); });
}

void Instructions::LD_MEM_AT_a16_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});

	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});

	state.cpuQueue.push([](State& state) {
		std::uint8_t tmp2 = state.tmp.top();
		state.tmp.pop();
		std::uint8_t tmp1 = state.tmp.top();
		state.tmp.pop();
		state.mmu.write(toWord(tmp1, tmp2), state.registers.getA());
	});
}

void Instructions::XOR_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.mmu.read(state.registers.getPC());
		state.registers.setA(state.registers.getA() ^ operand);
		state.registers.clearFlags();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
		state.registers.incPC();
	});
}

void Instructions::RST_28H(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		// NOP
	});
	state.cpuQueue.push([](State& state) {
		state.registers.decSP();
		state.mmu.write(state.registers.getSP(), msb(state.registers.getPC()));
	});
	state.cpuQueue.push([](State& state) {
		state.registers.decSP();
		state.mmu.write(state.registers.getSP(), lsb(state.registers.getPC()));
		state.registers.setPC(0x28);
	});
}

void Instructions::LDH_A_MEM_AT_a8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});

	state.cpuQueue.push([](State& state) {
		state.registers.setA(state.mmu.read(0xff00 | state.tmp.top()));
		state.tmp.pop();
	});
}

void Instructions::POP_AF(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getSP()));
		state.registers.incSP();
	});
	state.cpuQueue.push([](State& state) {
		state.registers.setAF(toWord(state.tmp.top(), state.mmu.read(state.registers.getSP())));
		state.registers.incSP();
		state.tmp.pop();
	});
}

void Instructions::LD_A_MEM_AT_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.setA(state.mmu.read(0xff00 | state.registers.getC())); });
}

void Instructions::DI(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.ime = false;
		state.imeScheduled = false;
	});
}

void Instructions::PUSH_AF(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		// NOP
	});
	state.cpuQueue.push([](State& state) {
		state.registers.decSP();
		state.mmu.write(state.registers.getSP(), msb(state.registers.getAF()));
	});
	state.cpuQueue.push([](State& state) {
		state.registers.decSP();
		state.mmu.write(state.registers.getSP(), lsb(state.registers.getAF()));
	});
}

void Instructions::OR_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.mmu.read(state.registers.getPC());
		state.registers.setA(state.registers.getA() | operand);
		state.registers.clearFlags();
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
		state.registers.incPC();
	});
}

void Instructions::RST_30H(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		// NOP
	});
	state.cpuQueue.push([](State& state) {
		state.registers.decSP();
		state.mmu.write(state.registers.getSP(), msb(state.registers.getPC()));
	});
	state.cpuQueue.push([](State& state) {
		state.registers.decSP();
		state.mmu.write(state.registers.getSP(), lsb(state.registers.getPC()));
		state.registers.setPC(0x30);
	});
}

void Instructions::LD_HL_SP_r8(State& state)
{
	// todo this is highly sus
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.tmp.push(static_cast<std::int8_t>(state.mmu.read(state.registers.getPC())));
		state.registers.incPC();
	});

	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		const std::int8_t& e = static_cast<std::int8_t>(state.tmp.top());
		if (e >= 0)
		{
			if (((state.registers.getSP() & 0xf) + (e & 0xf)) > 0xf)
				state.registers.setHalfCarryFlag();
			if ((state.registers.getSP() & 0xff) + e > 0xff)
				state.registers.setCarryFlag();
		}
		else
		{
			if (((state.registers.getSP() + e) & 0xf) >= (state.registers.getSP() & 0xf))
				state.registers.setHalfCarryFlag();
			if (((state.registers.getSP() + e) & 0xff) >= (state.registers.getSP() & 0xff))
				state.registers.setCarryFlag();
		}
		state.registers.setHL(state.registers.getSP() + e);
		state.tmp.pop();
	});
}

void Instructions::LD_SP_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.setSP((state.registers.getSP() & 0xff00) | (state.registers.getHL() & 0xff));
	});
	state.cpuQueue.push([](State& state) {
		state.registers.setSP((state.registers.getSP() & 0xff) | (state.registers.getHL() & 0xff00));
	});
}

void Instructions::LD_A_MEM_AT_a16(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});

	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.getPC()));
		state.registers.incPC();
	});

	state.cpuQueue.push([](State& state) {
		std::uint8_t tmp2 = state.tmp.top();
		state.tmp.pop();
		std::uint8_t tmp1 = state.tmp.top();
		state.tmp.pop();
		state.registers.setA(state.mmu.read(toWord(tmp1, tmp2)));
	});
}

void Instructions::EI(State& state)
{
	state.cpuQueue.push([](State& state) { state.imeScheduled = true; });
}

void Instructions::CP_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.mmu.read(state.registers.getPC());
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.getA() & 0xf) - (operand & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.getA() & 0xff) - (operand & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		if (state.registers.getA() - operand == 0)
			state.registers.setZeroFlag();
		state.registers.incPC();
	});
}

void Instructions::RST_38H(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		// NOP
	});
	state.cpuQueue.push([](State& state) {
		state.registers.decSP();
		state.mmu.write(state.registers.getSP(), msb(state.registers.getPC()));
	});
	state.cpuQueue.push([](State& state) {
		state.registers.decSP();
		state.mmu.write(state.registers.getSP(), lsb(state.registers.getPC()));
		state.registers.setPC(0x38);
	});
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Instructions::RLC_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getB();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		state.registers.setB(operand << 1 | (operand >> 7));
		if (state.registers.getB() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RLC_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getC();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		state.registers.setC(operand << 1 | (operand >> 7));
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RLC_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getD();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		state.registers.setD(operand << 1 | (operand >> 7));
		if (state.registers.getD() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RLC_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getE();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		state.registers.setE(operand << 1 | (operand >> 7));
		if (state.registers.getE() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RLC_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getH();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		state.registers.setH(operand << 1 | (operand >> 7));
		if (state.registers.getH() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RLC_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getL();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		state.registers.setL(operand << 1 | (operand >> 7));
		if (state.registers.getL() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RLC_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.getHL())); });
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		std::uint8_t& operand = state.tmp.top();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand = operand << 1 | (operand >> 7);
		state.mmu.write(state.registers.getHL(), operand);
		if (operand == 0)
			state.registers.setZeroFlag();
		state.tmp.pop();
	});
}

void Instructions::RLC_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getA();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		state.registers.setA(operand << 1 | (operand >> 7));
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RRC_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getB();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setB(operand >> 1 | (operand << 7));
		if (state.registers.getB() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RRC_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getC();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setC(operand >> 1 | (operand << 7));
		if (state.registers.getC() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RRC_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getD();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setD(operand >> 1 | (operand << 7));
		if (state.registers.getD() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RRC_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getE();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setE(operand >> 1 | (operand << 7));
		if (state.registers.getE() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RRC_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getH();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setH(operand >> 1 | (operand << 7));
		if (state.registers.getH() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RRC_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getL();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setL(operand >> 1 | (operand << 7));
		if (state.registers.getL() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RRC_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.getHL())); });
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		std::uint8_t& operand = state.tmp.top();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | (operand << 7);
		state.mmu.write(state.registers.getHL(), operand);
		if (operand == 0)
			state.registers.setZeroFlag();
		state.tmp.pop();
	});
}

void Instructions::RRC_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getA();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setA(operand >> 1 | (operand << 7));
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RL_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getB();
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		state.registers.setB(operand << 1 | carry);
		if (state.registers.getB() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RL_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getC();
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		state.registers.setC(operand << 1 | carry);
		if (state.registers.getC() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RL_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getD();
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		state.registers.setD(operand << 1 | carry);
		if (state.registers.getD() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RL_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getE();
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		state.registers.setE(operand << 1 | carry);
		if (state.registers.getE() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RL_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getH();
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		state.registers.setH(operand << 1 | carry);
		if (state.registers.getH() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RL_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getL();
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		state.registers.setL(operand << 1 | carry);
		if (state.registers.getL() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RL_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.getHL())); });
	state.cpuQueue.push([](State& state) {
		bool carry = state.registers.getCarryFlag();
		std::uint8_t& operand = state.tmp.top();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand = operand << 1 | carry;
		state.mmu.write(state.registers.getHL(), operand);
		if (operand == 0)
			state.registers.setZeroFlag();
		state.tmp.pop();
	});
}

void Instructions::RL_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getA();
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		state.registers.setA(operand << 1 | carry);
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RR_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getB();
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setB(operand >> 1 | carry << 7);
		if (state.registers.getB() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RR_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getC();
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setC(operand >> 1 | carry << 7);
		if (state.registers.getC() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RR_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getD();
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setD(operand >> 1 | carry << 7);
		if (state.registers.getD() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RR_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getE();
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setE(operand >> 1 | carry << 7);
		if (state.registers.getE() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RR_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getH();
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setH(operand >> 1 | carry << 7);
		if (state.registers.getH() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RR_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getL();
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setL(operand >> 1 | carry << 7);
		if (state.registers.getL() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RR_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.getHL())); });
	state.cpuQueue.push([](State& state) {
		bool carry = state.registers.getCarryFlag();
		std::uint8_t& operand = state.tmp.top();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | carry << 7;
		state.mmu.write(state.registers.getHL(), operand);
		if (operand == 0)
			state.registers.setZeroFlag();
		state.tmp.pop();
	});
}

void Instructions::RR_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getA();
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setA(operand >> 1 | carry << 7);
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SLA_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getB();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		state.registers.setB(operand << 1);
		if (state.registers.getB() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SLA_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getC();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		state.registers.setC(operand << 1);
		if (state.registers.getC() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SLA_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getD();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		state.registers.setD(operand << 1);
		if (state.registers.getD() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SLA_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getE();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		state.registers.setE(operand << 1);
		if (state.registers.getE() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SLA_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getH();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		state.registers.setH(operand << 1);
		if (state.registers.getH() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SLA_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getL();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		state.registers.setL(operand << 1);
		if (state.registers.getL() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SLA_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.getHL())); });
	state.cpuQueue.push([](State& state) {
		std::uint8_t& operand = state.tmp.top();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand <<= 1;
		state.mmu.write(state.registers.getHL(), operand);
		if (operand == 0)
			state.registers.setZeroFlag();
		state.tmp.pop();
	});
}

void Instructions::SLA_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getA();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		state.registers.setA(operand << 1);
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRA_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getB();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setB(operand >> 1 | operand & 0b10000000);
		if (state.registers.getB() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRA_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getC();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setC(operand >> 1 | operand & 0b10000000);
		if (state.registers.getC() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRA_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getD();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setD(operand >> 1 | operand & 0b10000000);
		if (state.registers.getD() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRA_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getE();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setE(operand >> 1 | operand & 0b10000000);
		if (state.registers.getE() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRA_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getH();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setH(operand >> 1 | operand & 0b10000000);
		if (state.registers.getH() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRA_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getL();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setL(operand >> 1 | operand & 0b10000000);
		if (state.registers.getL() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRA_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.getHL())); });
	state.cpuQueue.push([](State& state) {
		std::uint8_t& operand = state.tmp.top();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | operand & 0b10000000;
		state.mmu.write(state.registers.getHL(), operand);
		if (operand == 0)
			state.registers.setZeroFlag();
		state.tmp.pop();
	});
}

void Instructions::SRA_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getA();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setA(operand >> 1 | operand & 0b10000000);
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SWAP_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getB();
		state.registers.clearFlags();
		state.registers.setB(operand >> 4 | operand << 4);
		if (state.registers.getB() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SWAP_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getC();
		state.registers.clearFlags();
		state.registers.setC(operand >> 4 | operand << 4);
		if (state.registers.getC() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SWAP_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getD();
		state.registers.clearFlags();
		state.registers.setD(operand >> 4 | operand << 4);
		if (state.registers.getD() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SWAP_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getE();
		state.registers.clearFlags();
		state.registers.setE(operand >> 4 | operand << 4);
		if (state.registers.getE() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SWAP_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getH();
		state.registers.clearFlags();
		state.registers.setH(operand >> 4 | operand << 4);
		if (state.registers.getH() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SWAP_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getL();
		state.registers.clearFlags();
		state.registers.setL(operand >> 4 | operand << 4);
		if (state.registers.getL() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SWAP_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.getHL())); });
	state.cpuQueue.push([](State& state) {
		std::uint8_t& operand = state.tmp.top();
		operand = operand >> 4 | operand << 4;
		state.registers.clearFlags();
		state.mmu.write(state.registers.getHL(), operand);
		if (operand == 0)
			state.registers.setZeroFlag();
		state.tmp.pop();
	});
}

void Instructions::SWAP_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getA();
		state.registers.clearFlags();
		state.registers.setA(operand >> 4 | operand << 4);
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRL_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getB();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setB(operand >> 1);
		if (state.registers.getB() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRL_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getC();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setC(operand >> 1);
		if (state.registers.getC() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRL_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getD();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setD(operand >> 1);
		if (state.registers.getD() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRL_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getE();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setE(operand >> 1);
		if (state.registers.getE() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRL_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getH();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setH(operand >> 1);
		if (state.registers.getH() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRL_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getL();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setL(operand >> 1);
		if (state.registers.getL() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRL_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.getHL())); });
	state.cpuQueue.push([](State& state) {
		std::uint8_t& operand = state.tmp.top();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand >>= 1;
		state.mmu.write(state.registers.getHL(), operand);
		if (operand == 0)
			state.registers.setZeroFlag();
		state.tmp.pop();
	});
}

void Instructions::SRL_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getA();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		state.registers.setA(operand >> 1);
		if (state.registers.getA() == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::BIT_0_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getB();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 0))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_0_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getC();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 0))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_0_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getD();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 0))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_0_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getE();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 0))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_0_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getH();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 0))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_0_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getL();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 0))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_0_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.mmu.read(state.registers.getHL());
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 0))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_0_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getA();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 0))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_1_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getB();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 1))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_1_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getC();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 1))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_1_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getD();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 1))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_1_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getE();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 1))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_1_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getH();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 1))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_1_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getL();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 1))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_1_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.mmu.read(state.registers.getHL());
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 1))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_1_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getA();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 1))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_2_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getB();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 2))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_2_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getC();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 2))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_2_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getD();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 2))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_2_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getE();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 2))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_2_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getH();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 2))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_2_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getL();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 2))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_2_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.mmu.read(state.registers.getHL());
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 2))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_2_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getA();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 2))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_3_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getB();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 3))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_3_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getC();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 3))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_3_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getD();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 3))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_3_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getE();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 3))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_3_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getH();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 3))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_3_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getL();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 3))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_3_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.mmu.read(state.registers.getHL());
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 3))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_3_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getA();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 3))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_4_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getB();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 4))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_4_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getC();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 4))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_4_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getD();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 4))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_4_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getE();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 4))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_4_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getH();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 4))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_4_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getL();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 4))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_4_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.mmu.read(state.registers.getHL());
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 4))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_4_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getA();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 4))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_5_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getB();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 5))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_5_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getC();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 5))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_5_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getD();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 5))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_5_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getE();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 5))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_5_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getH();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 5))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_5_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getL();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 5))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_5_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.mmu.read(state.registers.getHL());
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 5))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_5_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getA();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 5))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_6_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getB();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 6))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_6_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getC();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 6))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_6_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getD();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 6))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_6_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getE();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 6))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_6_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getH();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 6))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_6_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getL();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 6))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_6_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.mmu.read(state.registers.getHL());
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 6))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_6_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getA();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 6))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_7_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getB();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 7))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_7_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getC();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 7))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_7_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getD();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 7))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_7_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getE();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 7))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_7_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getH();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 7))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_7_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getL();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 7))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_7_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.mmu.read(state.registers.getHL());
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 7))
			state.registers.resetZeroFlag();
	});
}

void Instructions::BIT_7_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		std::uint8_t operand = state.registers.getA();
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 7))
			state.registers.resetZeroFlag();
	});
}

void Instructions::RES_0_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setB(state.registers.getB() & ~(1 << 0)); });
}

void Instructions::RES_0_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setC(state.registers.getC() & ~(1 << 0)); });
}

void Instructions::RES_0_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setD(state.registers.getD() & ~(1 << 0)); });
}

void Instructions::RES_0_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setE(state.registers.getE() & ~(1 << 0)); });
}

void Instructions::RES_0_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setH(state.registers.getH() & ~(1 << 0)); });
}

void Instructions::RES_0_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setL(state.registers.getL() & ~(1 << 0)); });
}

void Instructions::RES_0_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.getHL())); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.getHL(), state.tmp.top() & ~(1 << 0));
		state.tmp.pop();
	});
}

void Instructions::RES_0_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setA(state.registers.getA() & ~(1 << 0)); });
}

void Instructions::RES_1_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setB(state.registers.getB() & ~(1 << 1)); });
}

void Instructions::RES_1_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setC(state.registers.getC() & ~(1 << 1)); });
}

void Instructions::RES_1_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setD(state.registers.getD() & ~(1 << 1)); });
}

void Instructions::RES_1_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setE(state.registers.getE() & ~(1 << 1)); });
}

void Instructions::RES_1_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setH(state.registers.getH() & ~(1 << 1)); });
}

void Instructions::RES_1_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setL(state.registers.getL() & ~(1 << 1)); });
}

void Instructions::RES_1_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.getHL())); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.getHL(), state.tmp.top() & ~(1 << 1));
		state.tmp.pop();
	});
}

void Instructions::RES_1_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setA(state.registers.getA() & ~(1 << 1)); });
}

void Instructions::RES_2_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setB(state.registers.getB() & ~(1 << 2)); });
}

void Instructions::RES_2_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setC(state.registers.getC() & ~(1 << 2)); });
}

void Instructions::RES_2_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setD(state.registers.getD() & ~(1 << 2)); });
}

void Instructions::RES_2_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setE(state.registers.getE() & ~(1 << 2)); });
}

void Instructions::RES_2_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setH(state.registers.getH() & ~(1 << 2)); });
}

void Instructions::RES_2_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setL(state.registers.getL() & ~(1 << 2)); });
}

void Instructions::RES_2_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.getHL())); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.getHL(), state.tmp.top() & ~(1 << 2));
		state.tmp.pop();
	});
}

void Instructions::RES_2_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setA(state.registers.getA() & ~(1 << 2)); });
}

void Instructions::RES_3_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setB(state.registers.getB() & ~(1 << 3)); });
}

void Instructions::RES_3_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setC(state.registers.getC() & ~(1 << 3)); });
}

void Instructions::RES_3_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setD(state.registers.getD() & ~(1 << 3)); });
}

void Instructions::RES_3_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setE(state.registers.getE() & ~(1 << 3)); });
}

void Instructions::RES_3_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setH(state.registers.getH() & ~(1 << 3)); });
}

void Instructions::RES_3_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setL(state.registers.getL() & ~(1 << 3)); });
}

void Instructions::RES_3_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.getHL())); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.getHL(), state.tmp.top() & ~(1 << 3));
		state.tmp.pop();
	});
}

void Instructions::RES_3_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setA(state.registers.getA() & ~(1 << 3)); });
}

void Instructions::RES_4_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setB(state.registers.getB() & ~(1 << 4)); });
}

void Instructions::RES_4_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setC(state.registers.getC() & ~(1 << 4)); });
}

void Instructions::RES_4_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setD(state.registers.getD() & ~(1 << 4)); });
}

void Instructions::RES_4_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setE(state.registers.getE() & ~(1 << 4)); });
}

void Instructions::RES_4_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setH(state.registers.getH() & ~(1 << 4)); });
}

void Instructions::RES_4_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setL(state.registers.getL() & ~(1 << 4)); });
}

void Instructions::RES_4_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.getHL())); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.getHL(), state.tmp.top() & ~(1 << 4));
		state.tmp.pop();
	});
}

void Instructions::RES_4_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setA(state.registers.getA() & ~(1 << 4)); });
}

void Instructions::RES_5_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setB(state.registers.getB() & ~(1 << 5)); });
}

void Instructions::RES_5_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setC(state.registers.getC() & ~(1 << 5)); });
}

void Instructions::RES_5_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setD(state.registers.getD() & ~(1 << 5)); });
}

void Instructions::RES_5_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setE(state.registers.getE() & ~(1 << 5)); });
}

void Instructions::RES_5_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setH(state.registers.getH() & ~(1 << 5)); });
}

void Instructions::RES_5_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setL(state.registers.getL() & ~(1 << 5)); });
}

void Instructions::RES_5_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.getHL())); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.getHL(), state.tmp.top() & ~(1 << 5));
		state.tmp.pop();
	});
}

void Instructions::RES_5_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setA(state.registers.getA() & ~(1 << 5)); });
}

void Instructions::RES_6_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setB(state.registers.getB() & ~(1 << 6)); });
}

void Instructions::RES_6_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setC(state.registers.getC() & ~(1 << 6)); });
}

void Instructions::RES_6_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setD(state.registers.getD() & ~(1 << 6)); });
}

void Instructions::RES_6_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setE(state.registers.getE() & ~(1 << 6)); });
}

void Instructions::RES_6_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setH(state.registers.getH() & ~(1 << 6)); });
}

void Instructions::RES_6_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setL(state.registers.getL() & ~(1 << 6)); });
}

void Instructions::RES_6_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.getHL())); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.getHL(), state.tmp.top() & ~(1 << 6));
		state.tmp.pop();
	});
}

void Instructions::RES_6_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setA(state.registers.getA() & ~(1 << 6)); });
}

void Instructions::RES_7_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setB(state.registers.getB() & ~(1 << 7)); });
}

void Instructions::RES_7_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setC(state.registers.getC() & ~(1 << 7)); });
}

void Instructions::RES_7_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setD(state.registers.getD() & ~(1 << 7)); });
}

void Instructions::RES_7_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setE(state.registers.getE() & ~(1 << 7)); });
}

void Instructions::RES_7_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setH(state.registers.getH() & ~(1 << 7)); });
}

void Instructions::RES_7_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setL(state.registers.getL() & ~(1 << 7)); });
}

void Instructions::RES_7_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.getHL())); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.getHL(), state.tmp.top() & ~(1 << 7));
		state.tmp.pop();
	});
}

void Instructions::RES_7_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setA(state.registers.getA() & ~(1 << 7)); });
}

void Instructions::SET_0_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setB(state.registers.getB() | 1 << 0); });
}

void Instructions::SET_0_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setC(state.registers.getC() | 1 << 0); });
}

void Instructions::SET_0_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setD(state.registers.getD() | 1 << 0); });
}

void Instructions::SET_0_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setE(state.registers.getE() | 1 << 0); });
}

void Instructions::SET_0_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setH(state.registers.getH() | 1 << 0); });
}

void Instructions::SET_0_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setL(state.registers.getL() | 1 << 0); });
}

void Instructions::SET_0_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.getHL())); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.getHL(), state.tmp.top() | (1 << 0));
		state.tmp.pop();
	});
}

void Instructions::SET_0_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setA(state.registers.getA() | 1 << 0); });
}

void Instructions::SET_1_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setB(state.registers.getB() | 1 << 1); });
}

void Instructions::SET_1_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setC(state.registers.getC() | 1 << 1); });
}

void Instructions::SET_1_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setD(state.registers.getD() | 1 << 1); });
}

void Instructions::SET_1_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setE(state.registers.getE() | 1 << 1); });
}

void Instructions::SET_1_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setH(state.registers.getH() | 1 << 1); });
}

void Instructions::SET_1_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setL(state.registers.getL() | 1 << 1); });
}

void Instructions::SET_1_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.getHL())); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.getHL(), state.tmp.top() | (1 << 1));
		state.tmp.pop();
	});
}

void Instructions::SET_1_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setA(state.registers.getA() | 1 << 1); });
}

void Instructions::SET_2_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setB(state.registers.getB() | 1 << 2); });
}

void Instructions::SET_2_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setC(state.registers.getC() | 1 << 2); });
}

void Instructions::SET_2_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setD(state.registers.getD() | 1 << 2); });
}

void Instructions::SET_2_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setE(state.registers.getE() | 1 << 2); });
}

void Instructions::SET_2_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setH(state.registers.getH() | 1 << 2); });
}

void Instructions::SET_2_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setL(state.registers.getL() | 1 << 2); });
}

void Instructions::SET_2_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.getHL())); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.getHL(), state.tmp.top() | (1 << 2));
		state.tmp.pop();
	});
}

void Instructions::SET_2_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setA(state.registers.getA() | 1 << 2); });
}

void Instructions::SET_3_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setB(state.registers.getB() | 1 << 3); });
}

void Instructions::SET_3_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setC(state.registers.getC() | 1 << 3); });
}

void Instructions::SET_3_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setD(state.registers.getD() | 1 << 3); });
}

void Instructions::SET_3_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setE(state.registers.getE() | 1 << 3); });
}

void Instructions::SET_3_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setH(state.registers.getH() | 1 << 3); });
}

void Instructions::SET_3_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setL(state.registers.getL() | 1 << 3); });
}

void Instructions::SET_3_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.getHL())); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.getHL(), state.tmp.top() | (1 << 3));
		state.tmp.pop();
	});
}

void Instructions::SET_3_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setA(state.registers.getA() | 1 << 3); });
}

void Instructions::SET_4_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setB(state.registers.getB() | 1 << 4); });
}

void Instructions::SET_4_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setC(state.registers.getC() | 1 << 4); });
}

void Instructions::SET_4_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setD(state.registers.getD() | 1 << 4); });
}

void Instructions::SET_4_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setE(state.registers.getE() | 1 << 4); });
}

void Instructions::SET_4_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setH(state.registers.getH() | 1 << 4); });
}

void Instructions::SET_4_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setL(state.registers.getL() | 1 << 4); });
}

void Instructions::SET_4_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.getHL())); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.getHL(), state.tmp.top() | (1 << 4));
		state.tmp.pop();
	});
}

void Instructions::SET_4_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setA(state.registers.getA() | 1 << 4); });
}

void Instructions::SET_5_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setB(state.registers.getB() | 1 << 5); });
}

void Instructions::SET_5_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setC(state.registers.getC() | 1 << 5); });
}

void Instructions::SET_5_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setD(state.registers.getD() | 1 << 5); });
}

void Instructions::SET_5_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setE(state.registers.getE() | 1 << 5); });
}

void Instructions::SET_5_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setH(state.registers.getH() | 1 << 5); });
}

void Instructions::SET_5_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setL(state.registers.getL() | 1 << 5); });
}

void Instructions::SET_5_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.getHL())); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.getHL(), state.tmp.top() | (1 << 5));
		state.tmp.pop();
	});
}

void Instructions::SET_5_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setA(state.registers.getA() | 1 << 5); });
}

void Instructions::SET_6_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setB(state.registers.getB() | 1 << 6); });
}

void Instructions::SET_6_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setC(state.registers.getC() | 1 << 6); });
}

void Instructions::SET_6_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setD(state.registers.getD() | 1 << 6); });
}

void Instructions::SET_6_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setE(state.registers.getE() | 1 << 6); });
}

void Instructions::SET_6_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setH(state.registers.getH() | 1 << 6); });
}

void Instructions::SET_6_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setL(state.registers.getL() | 1 << 6); });
}

void Instructions::SET_6_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.getHL())); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.getHL(), state.tmp.top() | (1 << 6));
		state.tmp.pop();
	});
}

void Instructions::SET_6_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setA(state.registers.getA() | 1 << 6); });
}

void Instructions::SET_7_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setB(state.registers.getB() | 1 << 7); });
}

void Instructions::SET_7_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setC(state.registers.getC() | 1 << 7); });
}

void Instructions::SET_7_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setD(state.registers.getD() | 1 << 7); });
}

void Instructions::SET_7_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setE(state.registers.getE() | 1 << 7); });
}

void Instructions::SET_7_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setH(state.registers.getH() | 1 << 7); });
}

void Instructions::SET_7_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setL(state.registers.getL() | 1 << 7); });
}

void Instructions::SET_7_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.getHL())); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.getHL(), state.tmp.top() | (1 << 7));
		state.tmp.pop();
	});
}

void Instructions::SET_7_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.setA(state.registers.getA() | 1 << 7); });
}
