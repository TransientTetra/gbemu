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
	state.cpuQueue.push([](State& state) { state.registers.c = state.mmu.read(state.registers.pc++); });
	state.cpuQueue.push([](State& state) { state.registers.b = state.mmu.read(state.registers.pc++); });
}

void Instructions::LD_MEM_AT_BC_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.mmu.write(state.registers.bc, state.registers.a); });
}

void Instructions::INC_BC(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
		if (((state.registers.c + 1) & 0xff) < state.registers.c)
			state.tmp.push(1);
		else
			state.tmp.push(0);
		state.registers.c += 1;
	});
	state.cpuQueue.push([](State& state) {
		state.registers.b += state.tmp.top();
		state.tmp.pop();
	});
}

void Instructions::INC_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.b & 0xf) + 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.b += 1;
		if (state.registers.b == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::DEC_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.setSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.b & 0xf) - 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.b -= 1;
		if (state.registers.b == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::LD_B_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.b = state.mmu.read(state.registers.pc++); });
}

void Instructions::RLCA(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		if (state.registers.a & 0b10000000)
			state.registers.setCarryFlag();
		state.registers.a = state.registers.a << 1 | (state.registers.a >> 7);
	});
}

void Instructions::LD_MEM_AT_a16_SP(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.pc++)); });
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.pc++)); });
	state.cpuQueue.push([](State& state) {
		Byte tmp2 = state.tmp.top();
		state.tmp.pop();
		Byte tmp1 = state.tmp.top();
		state.tmp.push(tmp2);
		state.mmu.write(toWord(tmp1, tmp2), lsb(state.registers.sp));
	});
	state.cpuQueue.push([](State& state) {
		Byte tmp2 = state.tmp.top();
		state.tmp.pop();
		Byte tmp1 = state.tmp.top();
		state.tmp.pop();
		state.mmu.write(toWord(tmp1, tmp2) + 1, msb(state.registers.sp));
	});
}

void Instructions::ADD_HL_BC(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		state.registers.resetCarryFlag();
		if (((state.registers.l & 0xf) + (state.registers.c & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.l & 0xff) + (state.registers.c & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.l += state.registers.c;
	});
	state.cpuQueue.push([](State& state) {
		Byte carry = state.registers.getCarryFlag();
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		state.registers.resetCarryFlag();
		if (((state.registers.h & 0xf) + (state.registers.b & 0xf) + (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.h & 0xff) + (state.registers.b & 0xff) + (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.h += state.registers.b + carry;
	});
}

void Instructions::LD_A_MEM_AT_BC(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.a = state.mmu.read(state.registers.bc); });
}

void Instructions::DEC_BC(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
		if (((state.registers.c - 1) & 0xff) >= state.registers.c)
			state.tmp.push(1);
		else
			state.tmp.push(0);
		state.registers.c -= 1;
	});
	state.cpuQueue.push([](State& state) {
		state.registers.b -= state.tmp.top();
		state.tmp.pop();
	});
}

void Instructions::INC_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.c & 0xf) + 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.c += 1;
		if (state.registers.c == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::DEC_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.setSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.c & 0xf) - 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.c -= 1;
		if (state.registers.c == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::LD_C_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.c = state.mmu.read(state.registers.pc++); });
}

void Instructions::RRCA(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		if (state.registers.a & 1)
			state.registers.setCarryFlag();
		state.registers.a = state.registers.a >> 1 | (state.registers.a << 7);
	});
}

void Instructions::STOP_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.cpuState = LIBGREBE_CPU_STATE_STOP;
		state.registers.pc += 1;
	});
}

void Instructions::LD_DE_d16(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.e = state.mmu.read(state.registers.pc++); });
	state.cpuQueue.push([](State& state) { state.registers.d = state.mmu.read(state.registers.pc++); });
}

void Instructions::LD_MEM_AT_DE_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.mmu.write(state.registers.de, state.registers.a); });
}

void Instructions::INC_DE(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
		if (((state.registers.e + 1) & 0xff) < state.registers.e)
			state.tmp.push(1);
		else
			state.tmp.push(0);
		state.registers.e += 1;
	});
	state.cpuQueue.push([](State& state) {
		state.registers.d += state.tmp.top();
		state.tmp.pop();
	});
}

void Instructions::INC_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.d & 0xf) + 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.d += 1;
		if (state.registers.d == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::DEC_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.setSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.d & 0xf) - 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.d -= 1;
		if (state.registers.d == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::LD_D_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.d = state.mmu.read(state.registers.pc++); });
}

void Instructions::RLA(State& state)
{
	state.cpuQueue.push([](State& state) {
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (state.registers.a & 0b10000000)
			state.registers.setCarryFlag();
		state.registers.a = state.registers.a << 1 | carry;
	});
}

void Instructions::JR_r8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push(
		[](State& state) { state.registers.pc += static_cast<SignedByte>(state.mmu.read(state.registers.pc++)); });
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
		if (((state.registers.l & 0xf) + (state.registers.e & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.l & 0xff) + (state.registers.e & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.l += state.registers.e;
	});
	state.cpuQueue.push([](State& state) {
		Byte carry = state.registers.getCarryFlag();
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		state.registers.resetCarryFlag();
		if (((state.registers.h & 0xf) + (state.registers.d & 0xf) + (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.h & 0xff) + (state.registers.d & 0xff) + (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.h += state.registers.d + carry;
	});
}

void Instructions::LD_A_MEM_AT_DE(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.a = state.mmu.read(state.registers.de); });
}

void Instructions::DEC_DE(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
		if (((state.registers.e - 1) & 0xff) >= state.registers.e)
			state.tmp.push(1);
		else
			state.tmp.push(0);
		state.registers.e -= 1;
	});
	state.cpuQueue.push([](State& state) {
		state.registers.d -= state.tmp.top();
		state.tmp.pop();
	});
}

void Instructions::INC_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.e & 0xf) + 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.e += 1;
		if (state.registers.e == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::DEC_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.setSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.e & 0xf) - 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.e -= 1;
		if (state.registers.e == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::LD_E_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.e = state.mmu.read(state.registers.pc++); });
}

void Instructions::RRA(State& state)
{
	state.cpuQueue.push([](State& state) {
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (state.registers.a & 1)
			state.registers.setCarryFlag();
		state.registers.a = state.registers.a >> 1 | carry << 7;
	});
}

void Instructions::JR_NZ_r8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		SignedByte e = static_cast<SignedByte>(state.mmu.read(state.registers.pc++));
		if (!state.registers.getZeroFlag())
		{
			state.registers.pc += e;
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
	state.cpuQueue.push([](State& state) { state.registers.l = state.mmu.read(state.registers.pc++); });
	state.cpuQueue.push([](State& state) { state.registers.h = state.mmu.read(state.registers.pc++); });
}

void Instructions::LDI_MEM_AT_HL_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.mmu.write(state.registers.hl++, state.registers.a); });
}

void Instructions::INC_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
		if (((state.registers.l + 1) & 0xff) < state.registers.l)
			state.tmp.push(1);
		else
			state.tmp.push(0);
		state.registers.l += 1;
	});
	state.cpuQueue.push([](State& state) {
		state.registers.h += state.tmp.top();
		state.tmp.pop();
	});
}

void Instructions::INC_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.h & 0xf) + 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.h += 1;
		if (state.registers.h == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::DEC_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.setSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.h & 0xf) - 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.h -= 1;
		if (state.registers.h == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::LD_H_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.h = state.mmu.read(state.registers.pc++); });
}

void Instructions::DAA(State& state)
{
	state.cpuQueue.push([](State& state) {
		if (state.registers.getSubtractFlag())
		{
			// after subtraction
			if (state.registers.getCarryFlag())
				state.registers.a -= 0x60;
			if (state.registers.getHalfCarryFlag())
				state.registers.a -= 0x6;
		}
		else
		{
			// after addition
			if (state.registers.getCarryFlag() || state.registers.a > 0x99)
			{
				state.registers.a += 0x60;
				state.registers.setCarryFlag();
			}
			if (state.registers.getHalfCarryFlag() || (state.registers.a & 0x0f) > 0x09)
				state.registers.a += 0x6;
		}
		if (state.registers.a == 0)
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
		SignedByte e = static_cast<SignedByte>(state.mmu.read(state.registers.pc++));
		if (state.registers.getZeroFlag())
		{
			state.registers.pc += e;
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
		if (((state.registers.l & 0xf) + (state.registers.l & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.l & 0xff) + (state.registers.l & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.l += state.registers.l;
	});
	state.cpuQueue.push([](State& state) {
		Byte carry = state.registers.getCarryFlag();
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		state.registers.resetCarryFlag();
		if (((state.registers.h & 0xf) + (state.registers.h & 0xf) + (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.h & 0xff) + (state.registers.h & 0xff) + (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.h += state.registers.h + carry;
	});
}

void Instructions::LDI_A_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.a = state.mmu.read(state.registers.hl++); });
}

void Instructions::DEC_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
		if (((state.registers.l - 1) & 0xff) >= state.registers.l)
			state.tmp.push(1);
		else
			state.tmp.push(0);
		state.registers.l -= 1;
	});
	state.cpuQueue.push([](State& state) {
		state.registers.h -= state.tmp.top();
		state.tmp.pop();
	});
}

void Instructions::INC_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.l & 0xf) + 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.l += 1;
		if (state.registers.l == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::DEC_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.setSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.l & 0xf) - 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.l -= 1;
		if (state.registers.l == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::LD_L_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.l = state.mmu.read(state.registers.pc++); });
}

void Instructions::CPL(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.a = ~state.registers.a;
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
		SignedByte e = static_cast<SignedByte>(state.mmu.read(state.registers.pc++));
		if (!state.registers.getCarryFlag())
		{
			state.registers.pc += e;
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
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.pc++)); });
	state.cpuQueue.push([](State& state) {
		state.registers.sp = toWord(state.tmp.top(), state.mmu.read(state.registers.pc++));
		state.tmp.pop();
	});
}

void Instructions::LDD_MEM_AT_HL_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.mmu.write(state.registers.hl--, state.registers.a); });
}

void Instructions::INC_SP(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
		Byte s = state.registers.sp >> 8;
		Byte p = state.registers.sp & 0xff;
		if (((p + 1) & 0xff) < p)
			state.tmp.push(1);
		else
			state.tmp.push(0);
		p += 1;
		state.registers.sp = toWord(p, s);
	});
	state.cpuQueue.push([](State& state) {
		Byte s = state.registers.sp >> 8;
		Byte p = state.registers.sp & 0xff;
		s += state.tmp.top();
		state.tmp.pop();
		state.registers.sp = toWord(p, s);
	});
}

void Instructions::INC_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.hl)); });
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.tmp.top() & 0xf) + 1) > 0xf)
			state.registers.setHalfCarryFlag();
		state.mmu.write(state.registers.hl, state.tmp.top() + 1);
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
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.hl)); });
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.setSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if ((((state.tmp.top() & 0xf) - 1) & 0xf) >= (state.tmp.top() & 0xf))
			state.registers.setHalfCarryFlag();
		state.mmu.write(state.registers.hl, state.tmp.top() - 1);
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
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.pc++)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.hl, state.tmp.top());
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
		SignedByte e = static_cast<SignedByte>(state.mmu.read(state.registers.pc++));
		if (state.registers.getCarryFlag())
		{
			state.registers.pc += e;
			state.cpuQueue.push([](State& state) {
				// NOP
			});
		}
	});
}

void Instructions::ADD_HL_SP(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte p = state.registers.sp & 0xff;
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		state.registers.resetCarryFlag();
		if (((state.registers.l & 0xf) + (p & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.l & 0xff) + (p & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.l += p;
	});
	state.cpuQueue.push([](State& state) {
		Byte s = state.registers.sp >> 8;
		Byte carry = state.registers.getCarryFlag();
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		state.registers.resetCarryFlag();
		if (((state.registers.h & 0xf) + (s & 0xf) + (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.h & 0xff) + (s & 0xff) + (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.h += s + carry;
	});
}

void Instructions::LDD_A_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.a = state.mmu.read(state.registers.hl--); });
}

void Instructions::DEC_SP(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
		Byte s = state.registers.sp >> 8;
		Byte p = state.registers.sp & 0xff;
		if (((p - 1) & 0xff) >= p)
			state.tmp.push(1);
		else
			state.tmp.push(0);
		p -= 1;
		state.registers.sp = toWord(p, s);
	});
	state.cpuQueue.push([](State& state) {
		Byte s = state.registers.sp >> 8;
		Byte p = state.registers.sp & 0xff;
		s -= state.tmp.top();
		state.tmp.pop();
		state.registers.sp = toWord(p, s);
	});
}

void Instructions::INC_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.resetSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.a & 0xf) + 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.a += 1;
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::DEC_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.resetZeroFlag();
		state.registers.setSubtractFlag();
		state.registers.resetHalfCarryFlag();
		if (((state.registers.a & 0xf) - 1) & 0x10)
			state.registers.setHalfCarryFlag();
		state.registers.a -= 1;
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::LD_A_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.a = state.mmu.read(state.registers.pc++); });
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
	state.cpuQueue.push([](State& state) { state.registers.b = state.registers.b; });
}

void Instructions::LD_B_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.b = state.registers.c; });
}

void Instructions::LD_B_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.b = state.registers.d; });
}

void Instructions::LD_B_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.b = state.registers.e; });
}

void Instructions::LD_B_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.b = state.registers.h; });
}

void Instructions::LD_B_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.b = state.registers.l; });
}

void Instructions::LD_B_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.b = state.mmu.read(state.registers.hl); });
}

void Instructions::LD_B_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.b = state.registers.a; });
}

void Instructions::LD_C_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.c = state.registers.b; });
}

void Instructions::LD_C_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.c = state.registers.c; });
}

void Instructions::LD_C_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.c = state.registers.d; });
}

void Instructions::LD_C_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.c = state.registers.e; });
}

void Instructions::LD_C_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.c = state.registers.h; });
}

void Instructions::LD_C_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.c = state.registers.l; });
}

void Instructions::LD_C_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.c = state.mmu.read(state.registers.hl); });
}

void Instructions::LD_C_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.c = state.registers.a; });
}

void Instructions::LD_D_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.d = state.registers.b; });
}

void Instructions::LD_D_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.d = state.registers.c; });
}

void Instructions::LD_D_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.d = state.registers.d; });
}

void Instructions::LD_D_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.d = state.registers.e; });
}

void Instructions::LD_D_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.d = state.registers.h; });
}

void Instructions::LD_D_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.d = state.registers.l; });
}

void Instructions::LD_D_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.d = state.mmu.read(state.registers.hl); });
}

void Instructions::LD_D_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.d = state.registers.a; });
}

void Instructions::LD_E_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.e = state.registers.b; });
}

void Instructions::LD_E_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.e = state.registers.c; });
}

void Instructions::LD_E_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.e = state.registers.d; });
}

void Instructions::LD_E_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.e = state.registers.e; });
}

void Instructions::LD_E_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.e = state.registers.h; });
}

void Instructions::LD_E_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.e = state.registers.l; });
}

void Instructions::LD_E_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.e = state.mmu.read(state.registers.hl); });
}

void Instructions::LD_E_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.e = state.registers.a; });
}

void Instructions::LD_H_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.h = state.registers.b; });
}

void Instructions::LD_H_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.h = state.registers.c; });
}

void Instructions::LD_H_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.h = state.registers.d; });
}

void Instructions::LD_H_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.h = state.registers.e; });
}

void Instructions::LD_H_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.h = state.registers.h; });
}

void Instructions::LD_H_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.h = state.registers.l; });
}

void Instructions::LD_H_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.h = state.mmu.read(state.registers.hl); });
}

void Instructions::LD_H_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.h = state.registers.a; });
}

void Instructions::LD_L_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.l = state.registers.b; });
}

void Instructions::LD_L_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.l = state.registers.c; });
}

void Instructions::LD_L_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.l = state.registers.d; });
}

void Instructions::LD_L_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.l = state.registers.e; });
}

void Instructions::LD_L_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.l = state.registers.h; });
}

void Instructions::LD_L_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.l = state.registers.l; });
}

void Instructions::LD_L_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.l = state.mmu.read(state.registers.hl); });
}

void Instructions::LD_L_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.l = state.registers.a; });
}

void Instructions::LD_MEM_AT_HL_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.mmu.write(state.registers.hl, state.registers.b); });
}

void Instructions::LD_MEM_AT_HL_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.mmu.write(state.registers.hl, state.registers.c); });
}

void Instructions::LD_MEM_AT_HL_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.mmu.write(state.registers.hl, state.registers.d); });
}

void Instructions::LD_MEM_AT_HL_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.mmu.write(state.registers.hl, state.registers.e); });
}

void Instructions::LD_MEM_AT_HL_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.mmu.write(state.registers.hl, state.registers.h); });
}

void Instructions::LD_MEM_AT_HL_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.mmu.write(state.registers.hl, state.registers.l); });
}

void Instructions::HALT(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& IE = state.mmu.read(LIBGREBE_REG_IE);
		const Byte& IF = state.mmu.read(LIBGREBE_REG_IF);
		if (state.ime)
		{
			state.cpuState = CPUState::LIBGREBE_CPU_STATE_HALT;
		}
		else
		{
			if (!(IE & IF & 0x1f)) // no interrupt pending
				state.cpuState = CPUState::LIBGREBE_CPU_STATE_HALT;
			else
				state.cpuState = CPUState::LIBGREBE_CPU_STATE_HALT_BUG;
		}
	});
}

void Instructions::LD_MEM_AT_HL_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.mmu.write(state.registers.hl, state.registers.a); });
}

void Instructions::LD_A_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.a = state.registers.b; });
}

void Instructions::LD_A_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.a = state.registers.c; });
}

void Instructions::LD_A_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.a = state.registers.d; });
}

void Instructions::LD_A_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.a = state.registers.e; });
}

void Instructions::LD_A_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.a = state.registers.h; });
}

void Instructions::LD_A_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.a = state.registers.l; });
}

void Instructions::LD_A_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.a = state.mmu.read(state.registers.hl); });
}

void Instructions::LD_A_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.a = state.registers.a; });
}

void Instructions::ADD_A_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		if (((state.registers.a & 0xf) + (state.registers.b & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) + (state.registers.b & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a += state.registers.b;
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADD_A_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		if (((state.registers.a & 0xf) + (state.registers.c & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) + (state.registers.c & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a += state.registers.c;
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADD_A_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		if (((state.registers.a & 0xf) + (state.registers.d & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) + (state.registers.d & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a += state.registers.d;
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADD_A_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		if (((state.registers.a & 0xf) + (state.registers.e & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) + (state.registers.e & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a += state.registers.e;
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADD_A_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		if (((state.registers.a & 0xf) + (state.registers.h & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) + (state.registers.h & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a += state.registers.h;
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADD_A_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		if (((state.registers.a & 0xf) + (state.registers.l & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) + (state.registers.l & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a += state.registers.l;
		if (state.registers.a == 0)
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
		if (((state.registers.a & 0xf) + (state.mmu.read(state.registers.hl) & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) + (state.mmu.read(state.registers.hl) & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a += state.mmu.read(state.registers.hl);
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADD_A_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		if (((state.registers.a & 0xf) + (state.registers.a & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) + (state.registers.a & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a += state.registers.a;
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADC_A_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (((state.registers.a & 0xf) + (state.registers.b & 0xf) + (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) + (state.registers.b & 0xff) + (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a += state.registers.b + carry;
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADC_A_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (((state.registers.a & 0xf) + (state.registers.c & 0xf) + (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) + (state.registers.c & 0xff) + (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a += state.registers.c + carry;
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADC_A_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (((state.registers.a & 0xf) + (state.registers.d & 0xf) + (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) + (state.registers.d & 0xff) + (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a += state.registers.d + carry;
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADC_A_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (((state.registers.a & 0xf) + (state.registers.e & 0xf) + (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) + (state.registers.e & 0xff) + (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a += state.registers.e + carry;
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADC_A_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (((state.registers.a & 0xf) + (state.registers.h & 0xf) + (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) + (state.registers.h & 0xff) + (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a += state.registers.h + carry;
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADC_A_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (((state.registers.a & 0xf) + (state.registers.l & 0xf) + (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) + (state.registers.l & 0xff) + (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a += state.registers.l + carry;
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADC_A_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		Byte carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (((state.registers.a & 0xf) + (state.mmu.read(state.registers.hl) & 0xf) + (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) + (state.mmu.read(state.registers.hl) & 0xff) + (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a += state.mmu.read(state.registers.hl) + carry;
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::ADC_A_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (((state.registers.a & 0xf) + (state.registers.a & 0xf) + (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) + (state.registers.a & 0xff) + (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a += state.registers.a + carry;
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SUB_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.a & 0xf) - (state.registers.b & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (state.registers.b & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a -= state.registers.b;
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SUB_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.a & 0xf) - (state.registers.c & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (state.registers.c & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a -= state.registers.c;
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SUB_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.a & 0xf) - (state.registers.d & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (state.registers.d & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a -= state.registers.d;
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SUB_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.a & 0xf) - (state.registers.e & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (state.registers.e & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a -= state.registers.e;
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SUB_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.a & 0xf) - (state.registers.h & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (state.registers.h & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a -= state.registers.h;
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SUB_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.a & 0xf) - (state.registers.l & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (state.registers.l & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a -= state.registers.l;
		if (state.registers.a == 0)
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
		if (((state.registers.a & 0xf) - (state.mmu.read(state.registers.hl) & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (state.mmu.read(state.registers.hl) & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a -= state.mmu.read(state.registers.hl);
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SUB_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.a & 0xf) - (state.registers.a & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (state.registers.a & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a -= state.registers.a;
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SBC_A_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.b;
		Byte carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.a & 0xf) - (operand & 0xf) - (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (operand & 0xff) - (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a -= (operand + carry);
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SBC_A_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.c;
		Byte carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.a & 0xf) - (operand & 0xf) - (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (operand & 0xff) - (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a -= (operand + carry);
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SBC_A_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.d;
		Byte carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.a & 0xf) - (operand & 0xf) - (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (operand & 0xff) - (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a -= (operand + carry);
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SBC_A_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.e;
		Byte carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.a & 0xf) - (operand & 0xf) - (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (operand & 0xff) - (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a -= (operand + carry);
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SBC_A_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.h;
		Byte carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.a & 0xf) - (operand & 0xf) - (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (operand & 0xff) - (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a -= (operand + carry);
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SBC_A_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.l;
		Byte carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.a & 0xf) - (operand & 0xf) - (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (operand & 0xff) - (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a -= (operand + carry);
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SBC_A_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.mmu.read(state.registers.hl);
		Byte carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.a & 0xf) - (operand & 0xf) - (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (operand & 0xff) - (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a -= (operand + carry);
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SBC_A_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.a;
		Byte carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.a & 0xf) - (operand & 0xf) - (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (operand & 0xff) - (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a -= (operand + carry);
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::AND_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.b;
		state.registers.a &= operand;
		state.registers.clearFlags();
		state.registers.setHalfCarryFlag();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::AND_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.c;
		state.registers.a &= operand;
		state.registers.clearFlags();
		state.registers.setHalfCarryFlag();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::AND_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.d;
		state.registers.a &= operand;
		state.registers.clearFlags();
		state.registers.setHalfCarryFlag();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::AND_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.e;
		state.registers.a &= operand;
		state.registers.clearFlags();
		state.registers.setHalfCarryFlag();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::AND_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.h;
		state.registers.a &= operand;
		state.registers.clearFlags();
		state.registers.setHalfCarryFlag();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::AND_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.l;
		state.registers.a &= operand;
		state.registers.clearFlags();
		state.registers.setHalfCarryFlag();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::AND_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.mmu.read(state.registers.hl);
		state.registers.a &= operand;
		state.registers.clearFlags();
		state.registers.setHalfCarryFlag();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::AND_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.a;
		state.registers.a &= operand;
		state.registers.clearFlags();
		state.registers.setHalfCarryFlag();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::XOR_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.b;
		state.registers.a ^= operand;
		state.registers.clearFlags();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::XOR_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.c;
		state.registers.a ^= operand;
		state.registers.clearFlags();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::XOR_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.d;
		state.registers.a ^= operand;
		state.registers.clearFlags();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::XOR_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.e;
		state.registers.a ^= operand;
		state.registers.clearFlags();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::XOR_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.h;
		state.registers.a ^= operand;
		state.registers.clearFlags();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::XOR_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.l;
		state.registers.a ^= operand;
		state.registers.clearFlags();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::XOR_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.mmu.read(state.registers.hl);
		state.registers.a ^= operand;
		state.registers.clearFlags();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::XOR_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.a;
		state.registers.a ^= operand;
		state.registers.clearFlags();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::OR_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.b;
		state.registers.a |= operand;
		state.registers.clearFlags();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::OR_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.c;
		state.registers.a |= operand;
		state.registers.clearFlags();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::OR_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.d;
		state.registers.a |= operand;
		state.registers.clearFlags();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::OR_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.e;
		state.registers.a |= operand;
		state.registers.clearFlags();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::OR_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.h;
		state.registers.a |= operand;
		state.registers.clearFlags();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::OR_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.l;
		state.registers.a |= operand;
		state.registers.clearFlags();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::OR_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.mmu.read(state.registers.hl);
		state.registers.a |= operand;
		state.registers.clearFlags();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::OR_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.a;
		state.registers.a |= operand;
		state.registers.clearFlags();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::CP_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.b;
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.a & 0xf) - (operand & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (operand & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		if (state.registers.a - operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::CP_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.c;
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.a & 0xf) - (operand & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (operand & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		if (state.registers.a - operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::CP_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.d;
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.a & 0xf) - (operand & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (operand & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		if (state.registers.a - operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::CP_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.e;
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.a & 0xf) - (operand & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (operand & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		if (state.registers.a - operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::CP_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.h;
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.a & 0xf) - (operand & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (operand & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		if (state.registers.a - operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::CP_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.l;
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.a & 0xf) - (operand & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (operand & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		if (state.registers.a - operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::CP_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.mmu.read(state.registers.hl);
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.a & 0xf) - (operand & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (operand & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		if (state.registers.a - operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::CP_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.a;
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.a & 0xf) - (operand & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (operand & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		if (state.registers.a - operand == 0)
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
			state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.sp++)); });
			state.cpuQueue.push([](State& state) {
				state.registers.pc = toWord(state.tmp.top(), state.mmu.read(state.registers.sp++));
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
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.sp++)); });
	state.cpuQueue.push([](State& state) {
		state.registers.bc = toWord(state.tmp.top(), state.mmu.read(state.registers.sp++));
		state.tmp.pop();
	});
}

void Instructions::JP_NZ_a16(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.pc++)); });
	state.cpuQueue.push([](State& state) {
		Byte d = state.mmu.read(state.registers.pc++);
		if (!state.registers.getZeroFlag())
		{
			state.registers.pc = toWord(state.tmp.top(), d);
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
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.pc++)); });
	state.cpuQueue.push([](State& state) {
		state.registers.pc = toWord(state.tmp.top(), state.mmu.read(state.registers.pc++));
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
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.pc++)); });
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.pc++));
		if (!state.registers.getZeroFlag())
		{
			state.cpuQueue.push([](State& state) {
				// NOP
			});
			state.cpuQueue.push([](State& state) { state.mmu.write(--state.registers.sp, msb(state.registers.pc)); });
			state.cpuQueue.push([](State& state) {
				state.mmu.write(--state.registers.sp, lsb(state.registers.pc));
				Byte tmp2 = state.tmp.top();
				state.tmp.pop();
				Byte tmp1 = state.tmp.top();
				state.tmp.pop();
				state.registers.pc = toWord(tmp1, tmp2);
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
	state.cpuQueue.push([](State& state) { state.mmu.write(--state.registers.sp, msb(state.registers.bc)); });
	state.cpuQueue.push([](State& state) { state.mmu.write(--state.registers.sp, lsb(state.registers.bc)); });
}

void Instructions::ADD_A_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.mmu.read(state.registers.pc);
		state.registers.clearFlags();
		if (((state.registers.a & 0xf) + (operand & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) + (operand & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a += operand;
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
		state.registers.pc += 1;
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
	state.cpuQueue.push([](State& state) { state.mmu.write(--state.registers.sp, msb(state.registers.pc)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(--state.registers.sp, lsb(state.registers.pc));
		state.registers.pc = 0;
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
			state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.sp++)); });
			state.cpuQueue.push([](State& state) {
				state.registers.pc = toWord(state.tmp.top(), state.mmu.read(state.registers.sp++));
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
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.sp++)); });
	state.cpuQueue.push([](State& state) {
		state.registers.pc = toWord(state.tmp.top(), state.mmu.read(state.registers.sp++));
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
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.pc++)); });
	state.cpuQueue.push([](State& state) {
		Byte d = state.mmu.read(state.registers.pc++);
		if (state.registers.getZeroFlag())
		{
			state.registers.pc = toWord(state.tmp.top(), d);
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
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.pc++)); });
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.pc++));
		if (state.registers.getZeroFlag())
		{
			state.cpuQueue.push([](State& state) {
				// NOP
			});
			state.cpuQueue.push([](State& state) { state.mmu.write(--state.registers.sp, msb(state.registers.pc)); });
			state.cpuQueue.push([](State& state) {
				state.mmu.write(--state.registers.sp, lsb(state.registers.pc));

				Byte tmp2 = state.tmp.top();
				state.tmp.pop();
				Byte tmp1 = state.tmp.top();
				state.tmp.pop();
				state.registers.pc = toWord(tmp1, tmp2);
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
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.pc++)); });
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.pc++)); });
	state.cpuQueue.push([](State& state) {
		// NOP
	});
	state.cpuQueue.push([](State& state) { state.mmu.write(--state.registers.sp, msb(state.registers.pc)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(--state.registers.sp, lsb(state.registers.pc));

		Byte tmp2 = state.tmp.top();
		state.tmp.pop();
		Byte tmp1 = state.tmp.top();
		state.tmp.pop();
		state.registers.pc = toWord(tmp1, tmp2);
	});
}

void Instructions::ADC_A_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		Byte carry = state.registers.getCarryFlag();
		const Byte& operand = state.mmu.read(state.registers.pc);
		state.registers.clearFlags();
		if (((state.registers.a & 0xf) + (operand & 0xf) + (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) + (operand & 0xff) + (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a += operand + carry;
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
		state.registers.pc += 1;
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
	state.cpuQueue.push([](State& state) { state.mmu.write(--state.registers.sp, msb(state.registers.pc)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(--state.registers.sp, lsb(state.registers.pc));
		state.registers.pc = 0x08;
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
			state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.sp++)); });
			state.cpuQueue.push([](State& state) {
				state.registers.pc = toWord(state.tmp.top(), state.mmu.read(state.registers.sp++));
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
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.sp++)); });
	state.cpuQueue.push([](State& state) {
		state.registers.de = toWord(state.tmp.top(), state.mmu.read(state.registers.sp++));
		state.tmp.pop();
	});
}

void Instructions::JP_NC_a16(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.pc++)); });
	state.cpuQueue.push([](State& state) {
		Byte d = state.mmu.read(state.registers.pc++);
		if (!state.registers.getCarryFlag())
		{
			state.registers.pc = toWord(state.tmp.top(), d);
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
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.pc++)); });
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.pc++));
		if (!state.registers.getCarryFlag())
		{
			state.cpuQueue.push([](State& state) {
				// NOP
			});
			state.cpuQueue.push([](State& state) { state.mmu.write(--state.registers.sp, msb(state.registers.pc)); });
			state.cpuQueue.push([](State& state) {
				state.mmu.write(--state.registers.sp, lsb(state.registers.pc));

				Byte tmp2 = state.tmp.top();
				state.tmp.pop();
				Byte tmp1 = state.tmp.top();
				state.tmp.pop();
				state.registers.pc = toWord(tmp1, tmp2);
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
	state.cpuQueue.push([](State& state) { state.mmu.write(--state.registers.sp, msb(state.registers.de)); });
	state.cpuQueue.push([](State& state) { state.mmu.write(--state.registers.sp, lsb(state.registers.de)); });
}

void Instructions::SUB_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		const Byte& operand = state.mmu.read(state.registers.pc);
		if (((state.registers.a & 0xf) - (operand & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (operand & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a -= operand;
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
		state.registers.pc += 1;
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
	state.cpuQueue.push([](State& state) { state.mmu.write(--state.registers.sp, msb(state.registers.pc)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(--state.registers.sp, lsb(state.registers.pc));
		state.registers.pc = 0x10;
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
			state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.sp++)); });
			state.cpuQueue.push([](State& state) {
				state.registers.pc = toWord(state.tmp.top(), state.mmu.read(state.registers.sp++));
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
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.sp++)); });
	state.cpuQueue.push([](State& state) {
		state.registers.pc = toWord(state.tmp.top(), state.mmu.read(state.registers.sp++));
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
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.pc++)); });
	state.cpuQueue.push([](State& state) {
		Byte d = state.mmu.read(state.registers.pc++);
		if (state.registers.getCarryFlag())
		{
			state.registers.pc = toWord(state.tmp.top(), d);
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
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.pc++)); });
	state.cpuQueue.push([](State& state) {
		state.tmp.push(state.mmu.read(state.registers.pc++));
		if (state.registers.getCarryFlag())
		{
			state.cpuQueue.push([](State& state) {
				// NOP
			});
			state.cpuQueue.push([](State& state) { state.mmu.write(--state.registers.sp, msb(state.registers.pc)); });
			state.cpuQueue.push([](State& state) {
				state.mmu.write(--state.registers.sp, lsb(state.registers.pc));

				Byte tmp2 = state.tmp.top();
				state.tmp.pop();
				Byte tmp1 = state.tmp.top();
				state.tmp.pop();
				state.registers.pc = toWord(tmp1, tmp2);
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
		const Byte& operand = state.mmu.read(state.registers.pc);
		Byte carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.a & 0xf) - (operand & 0xf) - (carry & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (operand & 0xff) - (carry & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		state.registers.a -= (operand + carry);
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
		state.registers.pc += 1;
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
	state.cpuQueue.push([](State& state) { state.mmu.write(--state.registers.sp, msb(state.registers.pc)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(--state.registers.sp, lsb(state.registers.pc));
		state.registers.pc = 0x18;
	});
}

void Instructions::LDH_MEM_AT_a8_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.pc++)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(0xff00 | state.tmp.top(), state.registers.a);
		state.tmp.pop();
	});
}

void Instructions::POP_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.sp++)); });
	state.cpuQueue.push([](State& state) {
		state.registers.hl = toWord(state.tmp.top(), state.mmu.read(state.registers.sp++));
		state.tmp.pop();
	});
}

void Instructions::LD_MEM_AT_C_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.mmu.write(0xff00 | state.registers.c, state.registers.a); });
}

void Instructions::PUSH_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		// NOP
	});
	state.cpuQueue.push([](State& state) { state.mmu.write(--state.registers.sp, msb(state.registers.hl)); });
	state.cpuQueue.push([](State& state) { state.mmu.write(--state.registers.sp, lsb(state.registers.hl)); });
}

void Instructions::AND_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.mmu.read(state.registers.pc);
		state.registers.a &= operand;
		state.registers.clearFlags();
		state.registers.setHalfCarryFlag();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
		state.registers.pc += 1;
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
	state.cpuQueue.push([](State& state) { state.mmu.write(--state.registers.sp, msb(state.registers.pc)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(--state.registers.sp, lsb(state.registers.pc));
		state.registers.pc = 0x20;
	});
}

void Instructions::ADD_SP_r8(State& state)
{
	// todo sus
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push(
		[](State& state) { state.tmp.push(static_cast<SignedByte>(state.mmu.read(state.registers.pc++))); });
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		const SignedByte& e = static_cast<SignedByte>(state.tmp.top());
		if (e >= 0)
		{
			if (((state.registers.sp & 0xf) + (e & 0xf)) > 0xf)
				state.registers.setHalfCarryFlag();
			if ((state.registers.sp & 0xff) + e > 0xff)
				state.registers.setCarryFlag();
		}
		else
		{
			if (((state.registers.sp + e) & 0xf) >= (state.registers.sp & 0xf))
				state.registers.setHalfCarryFlag();
			if (((state.registers.sp + e) & 0xff) >= (state.registers.sp & 0xff))
				state.registers.setCarryFlag();
		}
		state.registers.sp += e;
		state.tmp.pop();
	});
	state.cpuQueue.push([](State& state) {
		// NOP
	});
}

void Instructions::JP_HL(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.pc = state.registers.hl; });
}

void Instructions::LD_MEM_AT_a16_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.pc++)); });
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.pc++)); });
	state.cpuQueue.push([](State& state) {
		Byte tmp2 = state.tmp.top();
		state.tmp.pop();
		Byte tmp1 = state.tmp.top();
		state.tmp.pop();
		state.mmu.write(toWord(tmp1, tmp2), state.registers.a);
	});
}

void Instructions::XOR_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.mmu.read(state.registers.pc);
		state.registers.a ^= operand;
		state.registers.clearFlags();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
		state.registers.pc += 1;
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
	state.cpuQueue.push([](State& state) { state.mmu.write(--state.registers.sp, msb(state.registers.pc)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(--state.registers.sp, lsb(state.registers.pc));
		state.registers.pc = 0x28;
	});
}

void Instructions::LDH_A_MEM_AT_a8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.pc++)); });
	state.cpuQueue.push([](State& state) {
		state.registers.a = state.mmu.read(0xff00 | state.tmp.top());
		state.tmp.pop();
	});
}

void Instructions::POP_AF(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.sp++)); });
	state.cpuQueue.push([](State& state) {
		state.registers.af = toWord(state.tmp.top(), state.mmu.read(state.registers.sp++));
		state.tmp.pop();
	});
}

void Instructions::LD_A_MEM_AT_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.registers.a = state.mmu.read(0xff00 | state.registers.c); });
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
	state.cpuQueue.push([](State& state) { state.mmu.write(--state.registers.sp, msb(state.registers.af)); });
	state.cpuQueue.push([](State& state) { state.mmu.write(--state.registers.sp, lsb(state.registers.af)); });
}

void Instructions::OR_d8(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.mmu.read(state.registers.pc);
		state.registers.a |= operand;
		state.registers.clearFlags();
		if (state.registers.a == 0)
			state.registers.setZeroFlag();
		state.registers.pc += 1;
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
	state.cpuQueue.push([](State& state) { state.mmu.write(--state.registers.sp, msb(state.registers.pc)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(--state.registers.sp, lsb(state.registers.pc));
		state.registers.pc = 0x30;
	});
}

void Instructions::LD_HL_SP_r8(State& state)
{
	// todo this is highly sus
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push(
		[](State& state) { state.tmp.push(static_cast<SignedByte>(state.mmu.read(state.registers.pc++))); });
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		const SignedByte& e = static_cast<SignedByte>(state.tmp.top());
		if (e >= 0)
		{
			if (((state.registers.sp & 0xf) + (e & 0xf)) > 0xf)
				state.registers.setHalfCarryFlag();
			if ((state.registers.sp & 0xff) + e > 0xff)
				state.registers.setCarryFlag();
		}
		else
		{
			if (((state.registers.sp + e) & 0xf) >= (state.registers.sp & 0xf))
				state.registers.setHalfCarryFlag();
			if (((state.registers.sp + e) & 0xff) >= (state.registers.sp & 0xff))
				state.registers.setCarryFlag();
		}
		state.registers.hl = state.registers.sp + e;
		state.tmp.pop();
	});
}

void Instructions::LD_SP_HL(State& state)
{
	state.cpuQueue.push(
		[](State& state) { state.registers.sp = (state.registers.sp & 0xff00) | (state.registers.hl & 0xff); });
	state.cpuQueue.push(
		[](State& state) { state.registers.sp = (state.registers.sp & 0xff) | (state.registers.hl & 0xff00); });
}

void Instructions::LD_A_MEM_AT_a16(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.pc++)); });
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.pc++)); });
	state.cpuQueue.push([](State& state) {
		Byte tmp2 = state.tmp.top();
		state.tmp.pop();
		Byte tmp1 = state.tmp.top();
		state.tmp.pop();
		state.registers.a = state.mmu.read(toWord(tmp1, tmp2));
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
		const Byte& operand = state.mmu.read(state.registers.pc);
		state.registers.clearFlags();
		state.registers.setSubtractFlag();
		if (((state.registers.a & 0xf) - (operand & 0xf)) & 0x10)
			state.registers.setHalfCarryFlag();
		if (((state.registers.a & 0xff) - (operand & 0xff)) & 0x100)
			state.registers.setCarryFlag();
		if (state.registers.a - operand == 0)
			state.registers.setZeroFlag();
		state.registers.pc += 1;
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
	state.cpuQueue.push([](State& state) { state.mmu.write(--state.registers.sp, msb(state.registers.pc)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(--state.registers.sp, lsb(state.registers.pc));
		state.registers.pc = 0x38;
	});
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Instructions::RLC_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.b;
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand = operand << 1 | (operand >> 7);
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RLC_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.c;
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand = operand << 1 | (operand >> 7);
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RLC_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.d;
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand = operand << 1 | (operand >> 7);
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RLC_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.e;
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand = operand << 1 | (operand >> 7);
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RLC_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.h;
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand = operand << 1 | (operand >> 7);
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RLC_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.l;
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand = operand << 1 | (operand >> 7);
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RLC_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.hl)); });
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		Byte& operand = state.tmp.top();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand = operand << 1 | (operand >> 7);
		state.mmu.write(state.registers.hl, operand);
		if (operand == 0)
			state.registers.setZeroFlag();
		state.tmp.pop();
	});
}

void Instructions::RLC_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.a;
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand = operand << 1 | (operand >> 7);
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RRC_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.b;
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | (operand << 7);
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RRC_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.c;
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | (operand << 7);
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RRC_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.d;
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | (operand << 7);
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RRC_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.e;
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | (operand << 7);
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RRC_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.h;
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | (operand << 7);
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RRC_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.l;
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | (operand << 7);
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RRC_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.hl)); });
	state.cpuQueue.push([](State& state) {
		state.registers.clearFlags();
		Byte& operand = state.tmp.top();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | (operand << 7);
		state.mmu.write(state.registers.hl, operand);
		if (operand == 0)
			state.registers.setZeroFlag();
		state.tmp.pop();
	});
}

void Instructions::RRC_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.a;
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | (operand << 7);
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RL_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.b;
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand = operand << 1 | carry;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RL_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.c;
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand = operand << 1 | carry;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RL_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.d;
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand = operand << 1 | carry;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RL_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.e;
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand = operand << 1 | carry;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RL_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.h;
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand = operand << 1 | carry;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RL_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.l;
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand = operand << 1 | carry;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RL_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.hl)); });
	state.cpuQueue.push([](State& state) {
		bool carry = state.registers.getCarryFlag();
		Byte& operand = state.tmp.top();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand = operand << 1 | carry;
		state.mmu.write(state.registers.hl, operand);
		if (operand == 0)
			state.registers.setZeroFlag();
		state.tmp.pop();
	});
}

void Instructions::RL_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.a;
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand = operand << 1 | carry;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RR_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.b;
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | carry << 7;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RR_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.c;
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | carry << 7;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RR_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.d;
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | carry << 7;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RR_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.e;
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | carry << 7;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RR_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.h;
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | carry << 7;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RR_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.l;
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | carry << 7;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::RR_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.hl)); });
	state.cpuQueue.push([](State& state) {
		bool carry = state.registers.getCarryFlag();
		Byte& operand = state.tmp.top();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | carry << 7;
		state.mmu.write(state.registers.hl, operand);
		if (operand == 0)
			state.registers.setZeroFlag();
		state.tmp.pop();
	});
}

void Instructions::RR_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.a;
		bool carry = state.registers.getCarryFlag();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | carry << 7;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SLA_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.b;
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand = operand << 1;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SLA_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.c;
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand = operand << 1;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SLA_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.d;
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand = operand << 1;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SLA_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.e;
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand = operand << 1;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SLA_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.h;
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand = operand << 1;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SLA_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.l;
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand = operand << 1;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SLA_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.hl)); });
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.tmp.top();
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand <<= 1;
		state.mmu.write(state.registers.hl, operand);
		if (operand == 0)
			state.registers.setZeroFlag();
		state.tmp.pop();
	});
}

void Instructions::SLA_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.a;
		state.registers.clearFlags();
		if (operand & 0b10000000)
			state.registers.setCarryFlag();
		operand = operand << 1;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRA_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.b;
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | operand & 0b10000000;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRA_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.c;
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | operand & 0b10000000;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRA_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.d;
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | operand & 0b10000000;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRA_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.e;
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | operand & 0b10000000;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRA_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.h;
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | operand & 0b10000000;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRA_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.l;
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | operand & 0b10000000;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRA_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.hl)); });
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.tmp.top();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | operand & 0b10000000;
		state.mmu.write(state.registers.hl, operand);
		if (operand == 0)
			state.registers.setZeroFlag();
		state.tmp.pop();
	});
}

void Instructions::SRA_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.a;
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1 | operand & 0b10000000;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SWAP_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.b;
		state.registers.clearFlags();
		operand = operand >> 4 | operand << 4;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SWAP_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.c;
		state.registers.clearFlags();
		operand = operand >> 4 | operand << 4;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SWAP_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.d;
		state.registers.clearFlags();
		operand = operand >> 4 | operand << 4;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SWAP_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.e;
		state.registers.clearFlags();
		operand = operand >> 4 | operand << 4;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SWAP_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.h;
		state.registers.clearFlags();
		operand = operand >> 4 | operand << 4;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SWAP_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.l;
		state.registers.clearFlags();
		operand = operand >> 4 | operand << 4;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SWAP_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.hl)); });
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.tmp.top();
		operand = operand >> 4 | operand << 4;
		state.registers.clearFlags();
		state.mmu.write(state.registers.hl, operand);
		if (operand == 0)
			state.registers.setZeroFlag();
		state.tmp.pop();
	});
}

void Instructions::SWAP_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.a;
		state.registers.clearFlags();
		operand = operand >> 4 | operand << 4;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRL_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.b;
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRL_C(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.c;
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRL_D(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.d;
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRL_E(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.e;
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRL_H(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.h;
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRL_L(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.l;
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::SRL_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.hl)); });
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.tmp.top();
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand >>= 1;
		state.mmu.write(state.registers.hl, operand);
		if (operand == 0)
			state.registers.setZeroFlag();
		state.tmp.pop();
	});
}

void Instructions::SRL_A(State& state)
{
	state.cpuQueue.push([](State& state) {
		Byte& operand = state.registers.a;
		state.registers.clearFlags();
		if (operand & 1)
			state.registers.setCarryFlag();
		operand = operand >> 1;
		if (operand == 0)
			state.registers.setZeroFlag();
	});
}

void Instructions::BIT_0_B(State& state)
{
	state.cpuQueue.push([](State& state) {
		const Byte& operand = state.registers.b;
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
		const Byte& operand = state.registers.c;
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
		const Byte& operand = state.registers.d;
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
		const Byte& operand = state.registers.e;
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
		const Byte& operand = state.registers.h;
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
		const Byte& operand = state.registers.l;
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
		const Byte& operand = state.mmu.read(state.registers.hl);
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
		const Byte& operand = state.registers.a;
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
		const Byte& operand = state.registers.b;
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
		const Byte& operand = state.registers.c;
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
		const Byte& operand = state.registers.d;
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
		const Byte& operand = state.registers.e;
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
		const Byte& operand = state.registers.h;
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
		const Byte& operand = state.registers.l;
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
		const Byte& operand = state.mmu.read(state.registers.hl);
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
		const Byte& operand = state.registers.a;
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
		const Byte& operand = state.registers.b;
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
		const Byte& operand = state.registers.c;
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
		const Byte& operand = state.registers.d;
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
		const Byte& operand = state.registers.e;
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
		const Byte& operand = state.registers.h;
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
		const Byte& operand = state.registers.l;
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
		const Byte& operand = state.mmu.read(state.registers.hl);
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
		const Byte& operand = state.registers.a;
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
		const Byte& operand = state.registers.b;
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
		const Byte& operand = state.registers.c;
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
		const Byte& operand = state.registers.d;
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
		const Byte& operand = state.registers.e;
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
		const Byte& operand = state.registers.h;
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
		const Byte& operand = state.registers.l;
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
		const Byte& operand = state.mmu.read(state.registers.hl);
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
		const Byte& operand = state.registers.a;
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
		const Byte& operand = state.registers.b;
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
		const Byte& operand = state.registers.c;
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
		const Byte& operand = state.registers.d;
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
		const Byte& operand = state.registers.e;
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
		const Byte& operand = state.registers.h;
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
		const Byte& operand = state.registers.l;
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
		const Byte& operand = state.mmu.read(state.registers.hl);
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
		const Byte& operand = state.registers.a;
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
		const Byte& operand = state.registers.b;
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
		const Byte& operand = state.registers.c;
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
		const Byte& operand = state.registers.d;
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
		const Byte& operand = state.registers.e;
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
		const Byte& operand = state.registers.h;
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
		const Byte& operand = state.registers.l;
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
		const Byte& operand = state.mmu.read(state.registers.hl);
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
		const Byte& operand = state.registers.a;
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
		const Byte& operand = state.registers.b;
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
		const Byte& operand = state.registers.c;
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
		const Byte& operand = state.registers.d;
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
		const Byte& operand = state.registers.e;
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
		const Byte& operand = state.registers.h;
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
		const Byte& operand = state.registers.l;
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
		const Byte& operand = state.mmu.read(state.registers.hl);
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
		const Byte& operand = state.registers.a;
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
		const Byte& operand = state.registers.b;
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
		const Byte& operand = state.registers.c;
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
		const Byte& operand = state.registers.d;
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
		const Byte& operand = state.registers.e;
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
		const Byte& operand = state.registers.h;
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
		const Byte& operand = state.registers.l;
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
		const Byte& operand = state.mmu.read(state.registers.hl);
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
		const Byte& operand = state.registers.a;
		state.registers.resetSubtractFlag();
		state.registers.setHalfCarryFlag();
		state.registers.setZeroFlag();
		if (operand & (1 << 7))
			state.registers.resetZeroFlag();
	});
}

void Instructions::RES_0_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.b &= ~(1 << 0); });
}

void Instructions::RES_0_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.c &= ~(1 << 0); });
}

void Instructions::RES_0_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.d &= ~(1 << 0); });
}

void Instructions::RES_0_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.e &= ~(1 << 0); });
}

void Instructions::RES_0_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.h &= ~(1 << 0); });
}

void Instructions::RES_0_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.l &= ~(1 << 0); });
}

void Instructions::RES_0_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.hl)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.hl, state.tmp.top() & ~(1 << 0));
		state.tmp.pop();
	});
}

void Instructions::RES_0_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.a &= ~(1 << 0); });
}

void Instructions::RES_1_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.b &= ~(1 << 1); });
}

void Instructions::RES_1_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.c &= ~(1 << 1); });
}

void Instructions::RES_1_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.d &= ~(1 << 1); });
}

void Instructions::RES_1_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.e &= ~(1 << 1); });
}

void Instructions::RES_1_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.h &= ~(1 << 1); });
}

void Instructions::RES_1_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.l &= ~(1 << 1); });
}

void Instructions::RES_1_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.hl)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.hl, state.tmp.top() & ~(1 << 1));
		state.tmp.pop();
	});
}

void Instructions::RES_1_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.a &= ~(1 << 1); });
}

void Instructions::RES_2_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.b &= ~(1 << 2); });
}

void Instructions::RES_2_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.c &= ~(1 << 2); });
}

void Instructions::RES_2_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.d &= ~(1 << 2); });
}

void Instructions::RES_2_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.e &= ~(1 << 2); });
}

void Instructions::RES_2_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.h &= ~(1 << 2); });
}

void Instructions::RES_2_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.l &= ~(1 << 2); });
}

void Instructions::RES_2_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.hl)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.hl, state.tmp.top() & ~(1 << 2));
		state.tmp.pop();
	});
}

void Instructions::RES_2_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.a &= ~(1 << 2); });
}

void Instructions::RES_3_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.b &= ~(1 << 3); });
}

void Instructions::RES_3_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.c &= ~(1 << 3); });
}

void Instructions::RES_3_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.d &= ~(1 << 3); });
}

void Instructions::RES_3_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.e &= ~(1 << 3); });
}

void Instructions::RES_3_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.h &= ~(1 << 3); });
}

void Instructions::RES_3_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.l &= ~(1 << 3); });
}

void Instructions::RES_3_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.hl)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.hl, state.tmp.top() & ~(1 << 3));
		state.tmp.pop();
	});
}

void Instructions::RES_3_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.a &= ~(1 << 3); });
}

void Instructions::RES_4_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.b &= ~(1 << 4); });
}

void Instructions::RES_4_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.c &= ~(1 << 4); });
}

void Instructions::RES_4_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.d &= ~(1 << 4); });
}

void Instructions::RES_4_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.e &= ~(1 << 4); });
}

void Instructions::RES_4_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.h &= ~(1 << 4); });
}

void Instructions::RES_4_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.l &= ~(1 << 4); });
}

void Instructions::RES_4_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.hl)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.hl, state.tmp.top() & ~(1 << 4));
		state.tmp.pop();
	});
}

void Instructions::RES_4_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.a &= ~(1 << 4); });
}

void Instructions::RES_5_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.b &= ~(1 << 5); });
}

void Instructions::RES_5_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.c &= ~(1 << 5); });
}

void Instructions::RES_5_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.d &= ~(1 << 5); });
}

void Instructions::RES_5_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.e &= ~(1 << 5); });
}

void Instructions::RES_5_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.h &= ~(1 << 5); });
}

void Instructions::RES_5_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.l &= ~(1 << 5); });
}

void Instructions::RES_5_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.hl)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.hl, state.tmp.top() & ~(1 << 5));
		state.tmp.pop();
	});
}

void Instructions::RES_5_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.a &= ~(1 << 5); });
}

void Instructions::RES_6_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.b &= ~(1 << 6); });
}

void Instructions::RES_6_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.c &= ~(1 << 6); });
}

void Instructions::RES_6_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.d &= ~(1 << 6); });
}

void Instructions::RES_6_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.e &= ~(1 << 6); });
}

void Instructions::RES_6_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.h &= ~(1 << 6); });
}

void Instructions::RES_6_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.l &= ~(1 << 6); });
}

void Instructions::RES_6_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.hl)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.hl, state.tmp.top() & ~(1 << 6));
		state.tmp.pop();
	});
}

void Instructions::RES_6_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.a &= ~(1 << 6); });
}

void Instructions::RES_7_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.b &= ~(1 << 7); });
}

void Instructions::RES_7_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.c &= ~(1 << 7); });
}

void Instructions::RES_7_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.d &= ~(1 << 7); });
}

void Instructions::RES_7_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.e &= ~(1 << 7); });
}

void Instructions::RES_7_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.h &= ~(1 << 7); });
}

void Instructions::RES_7_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.l &= ~(1 << 7); });
}

void Instructions::RES_7_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.hl)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.hl, state.tmp.top() & ~(1 << 7));
		state.tmp.pop();
	});
}

void Instructions::RES_7_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.a &= ~(1 << 7); });
}

void Instructions::SET_0_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.b |= 1 << 0; });
}

void Instructions::SET_0_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.c |= 1 << 0; });
}

void Instructions::SET_0_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.d |= 1 << 0; });
}

void Instructions::SET_0_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.e |= 1 << 0; });
}

void Instructions::SET_0_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.h |= 1 << 0; });
}

void Instructions::SET_0_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.l |= 1 << 0; });
}

void Instructions::SET_0_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.hl)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.hl, state.tmp.top() | (1 << 0));
		state.tmp.pop();
	});
}

void Instructions::SET_0_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.a |= 1 << 0; });
}

void Instructions::SET_1_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.b |= 1 << 1; });
}

void Instructions::SET_1_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.c |= 1 << 1; });
}

void Instructions::SET_1_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.d |= 1 << 1; });
}

void Instructions::SET_1_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.e |= 1 << 1; });
}

void Instructions::SET_1_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.h |= 1 << 1; });
}

void Instructions::SET_1_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.l |= 1 << 1; });
}

void Instructions::SET_1_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.hl)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.hl, state.tmp.top() | (1 << 1));
		state.tmp.pop();
	});
}

void Instructions::SET_1_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.a |= 1 << 1; });
}

void Instructions::SET_2_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.b |= 1 << 2; });
}

void Instructions::SET_2_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.c |= 1 << 2; });
}

void Instructions::SET_2_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.d |= 1 << 2; });
}

void Instructions::SET_2_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.e |= 1 << 2; });
}

void Instructions::SET_2_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.h |= 1 << 2; });
}

void Instructions::SET_2_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.l |= 1 << 2; });
}

void Instructions::SET_2_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.hl)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.hl, state.tmp.top() | (1 << 2));
		state.tmp.pop();
	});
}

void Instructions::SET_2_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.a |= 1 << 2; });
}

void Instructions::SET_3_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.b |= 1 << 3; });
}

void Instructions::SET_3_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.c |= 1 << 3; });
}

void Instructions::SET_3_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.d |= 1 << 3; });
}

void Instructions::SET_3_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.e |= 1 << 3; });
}

void Instructions::SET_3_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.h |= 1 << 3; });
}

void Instructions::SET_3_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.l |= 1 << 3; });
}

void Instructions::SET_3_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.hl)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.hl, state.tmp.top() | (1 << 3));
		state.tmp.pop();
	});
}

void Instructions::SET_3_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.a |= 1 << 3; });
}

void Instructions::SET_4_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.b |= 1 << 4; });
}

void Instructions::SET_4_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.c |= 1 << 4; });
}

void Instructions::SET_4_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.d |= 1 << 4; });
}

void Instructions::SET_4_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.e |= 1 << 4; });
}

void Instructions::SET_4_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.h |= 1 << 4; });
}

void Instructions::SET_4_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.l |= 1 << 4; });
}

void Instructions::SET_4_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.hl)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.hl, state.tmp.top() | (1 << 4));
		state.tmp.pop();
	});
}

void Instructions::SET_4_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.a |= 1 << 4; });
}

void Instructions::SET_5_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.b |= 1 << 5; });
}

void Instructions::SET_5_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.c |= 1 << 5; });
}

void Instructions::SET_5_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.d |= 1 << 5; });
}

void Instructions::SET_5_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.e |= 1 << 5; });
}

void Instructions::SET_5_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.h |= 1 << 5; });
}

void Instructions::SET_5_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.l |= 1 << 5; });
}

void Instructions::SET_5_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.hl)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.hl, state.tmp.top() | (1 << 5));
		state.tmp.pop();
	});
}

void Instructions::SET_5_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.a |= 1 << 5; });
}

void Instructions::SET_6_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.b |= 1 << 6; });
}

void Instructions::SET_6_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.c |= 1 << 6; });
}

void Instructions::SET_6_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.d |= 1 << 6; });
}

void Instructions::SET_6_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.e |= 1 << 6; });
}

void Instructions::SET_6_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.h |= 1 << 6; });
}

void Instructions::SET_6_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.l |= 1 << 6; });
}

void Instructions::SET_6_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.hl)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.hl, state.tmp.top() | (1 << 6));
		state.tmp.pop();
	});
}

void Instructions::SET_6_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.a |= 1 << 6; });
}

void Instructions::SET_7_B(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.b |= 1 << 7; });
}

void Instructions::SET_7_C(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.c |= 1 << 7; });
}

void Instructions::SET_7_D(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.d |= 1 << 7; });
}

void Instructions::SET_7_E(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.e |= 1 << 7; });
}

void Instructions::SET_7_H(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.h |= 1 << 7; });
}

void Instructions::SET_7_L(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.l |= 1 << 7; });
}

void Instructions::SET_7_MEM_AT_HL(State& state)
{
	state.cpuQueue.push([](State& state) {
		// fetch
	});
	state.cpuQueue.push([](State& state) { state.tmp.push(state.mmu.read(state.registers.hl)); });
	state.cpuQueue.push([](State& state) {
		state.mmu.write(state.registers.hl, state.tmp.top() | (1 << 7));
		state.tmp.pop();
	});
}

void Instructions::SET_7_A(State& state)
{
	state.cpuQueue.push([](State& state) { state.registers.a |= 1 << 7; });
}
