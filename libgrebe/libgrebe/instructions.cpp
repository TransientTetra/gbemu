#include <libgrebe/instructions.hpp>

void Instructions::Undefined(State& state)
{
	throw UndefinedOpcodeException();
}

void Instructions::NOP(State& state)
{
	
	state.clockCycles += 4;
}

void Instructions::LD_BC_d16(State& state)
{
	state.registers.bc = state.memory.readWord(state.registers.pc);
	state.registers.pc += 2;
	state.clockCycles += 12;
}

void Instructions::LD_MEM_AT_BC_A(State& state)
{
	state.memory.write(state.registers.bc, state.registers.a);
	state.clockCycles += 8;
}

void Instructions::INC_BC(State& state)
{
	state.registers.bc += 1;
	state.clockCycles += 8;
}

void Instructions::INC_B(State& state)
{
	state.registers.resetZeroFlag();
	state.registers.resetSubtractFlag();
	state.registers.resetHalfCarryFlag();
	if (((state.registers.b & 0xf) + 1) & 0x10)
		state.registers.setHalfCarryFlag();
	state.registers.b += 1;
	if (state.registers.b == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::DEC_B(State& state)
{
	state.registers.resetZeroFlag();
	state.registers.setSubtractFlag();
	state.registers.resetHalfCarryFlag();
	if (((state.registers.b & 0xf) - 1) & 0x10)
		state.registers.setHalfCarryFlag();
	state.registers.b -= 1;
	if (state.registers.b == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::LD_B_d8(State& state)
{
	state.registers.b = state.memory.read(state.registers.pc);
	state.registers.pc += 1;
	state.clockCycles += 8;
}

void Instructions::RLCA(State& state)
{
	state.registers.clearFlags();
	if (state.registers.a & 0b10000000) state.registers.setCarryFlag();
	state.registers.a = state.registers.a << 1 | (state.registers.a >> 7);
	state.clockCycles += 4;
}

void Instructions::LD_MEM_AT_a16_SP(State& state)
{
	state.memory.writeWord(state.memory.readWord(state.registers.pc), state.registers.sp);
	state.registers.pc += 2;
	state.clockCycles += 20;
}

void Instructions::ADD_HL_BC(State& state)
{
	state.registers.resetSubtractFlag();
	state.registers.resetHalfCarryFlag();
	state.registers.resetCarryFlag();
	if (((state.registers.hl & 0x0fff) + (state.registers.bc & 0x0fff)) & 0x1000)
		state.registers.setHalfCarryFlag();
	if ((state.registers.hl + state.registers.bc) & 0x10000)
		state.registers.setCarryFlag();
	state.registers.hl += state.registers.bc;
	state.clockCycles += 8;
}

void Instructions::LD_A_MEM_AT_BC(State& state)
{
	state.registers.a = state.memory.read(state.registers.bc);
	state.clockCycles += 8;
}

void Instructions::DEC_BC(State& state)
{
	state.registers.bc -= 1;
	state.clockCycles += 8;
}

void Instructions::INC_C(State& state)
{
	state.registers.resetZeroFlag();
	state.registers.resetSubtractFlag();
	state.registers.resetHalfCarryFlag();
	if (((state.registers.c & 0xf) + 1) & 0x10)
		state.registers.setHalfCarryFlag();
	state.registers.c += 1;
	if (state.registers.c == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::DEC_C(State& state)
{
	state.registers.resetZeroFlag();
	state.registers.setSubtractFlag();
	state.registers.resetHalfCarryFlag();
	if (((state.registers.c & 0xf) - 1) & 0x10)
		state.registers.setHalfCarryFlag();
	state.registers.c -= 1;
	if (state.registers.c == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::LD_C_d8(State& state)
{
	state.registers.c = state.memory.read(state.registers.pc);
	state.registers.pc += 1;
	state.clockCycles += 8;
}

void Instructions::RRCA(State& state)
{
	state.registers.clearFlags();
	if (state.registers.a & 1) state.registers.setCarryFlag();
	state.registers.a = state.registers.a >> 1 | (state.registers.a << 7);
	state.clockCycles += 4;
}

void Instructions::STOP_0(State& state)
{
	state.registers.pc += 1;
	state.clockCycles += 4;
}

void Instructions::LD_DE_d16(State& state)
{
	state.registers.de = state.memory.readWord(state.registers.pc);
	state.registers.pc += 2;
	state.clockCycles += 12;
}

void Instructions::LD_MEM_AT_DE_A(State& state)
{
	state.memory.write(state.registers.de, state.registers.a);
	state.clockCycles += 8;
}

void Instructions::INC_DE(State& state)
{
	state.registers.de += 1;
	state.clockCycles += 8;
}

void Instructions::INC_D(State& state)
{
	state.registers.resetZeroFlag();
	state.registers.resetSubtractFlag();
	state.registers.resetHalfCarryFlag();
	if (((state.registers.d & 0xf) + 1) & 0x10)
		state.registers.setHalfCarryFlag();
	state.registers.d += 1;
	if (state.registers.d == 0)
		state.registers.setZeroFlag();	
	state.clockCycles += 4;
}

void Instructions::DEC_D(State& state)
{
	state.registers.resetZeroFlag();
	state.registers.setSubtractFlag();
	state.registers.resetHalfCarryFlag();
	if (((state.registers.d & 0xf) - 1) & 0x10)
		state.registers.setHalfCarryFlag();
	state.registers.d -= 1;
	if (state.registers.d == 0)
		state.registers.setZeroFlag();	
	state.clockCycles += 4;
}

void Instructions::LD_D_d8(State& state)
{
	state.registers.d = state.memory.read(state.registers.pc);
	state.registers.pc += 1;
	state.clockCycles += 8;
}

void Instructions::RLA(State& state)
{
	bool carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (state.registers.a & 0b10000000) state.registers.setCarryFlag();
	state.registers.a = state.registers.a << 1 | carry;	
	state.clockCycles += 4;
}

void Instructions::JR_r8(State& state)
{
	SignedByte e = static_cast<SignedByte>(state.memory.read(state.registers.pc++));
	state.registers.pc += e;
	state.clockCycles += 12;
}

void Instructions::ADD_HL_DE(State& state)
{
	state.registers.resetSubtractFlag();
	state.registers.resetHalfCarryFlag();
	state.registers.resetCarryFlag();
	if (((state.registers.hl & 0x0fff) + (state.registers.de & 0x0fff)) & 0x1000)
		state.registers.setHalfCarryFlag();
	if ((state.registers.hl + state.registers.de) & 0x10000)
		state.registers.setCarryFlag();
	state.registers.hl += state.registers.de;	
	state.clockCycles += 8;
}

void Instructions::LD_A_MEM_AT_DE(State& state)
{
	state.registers.a = state.memory.read(state.registers.de);	
	state.clockCycles += 8;
}

void Instructions::DEC_DE(State& state)
{
	state.registers.de -= 1;	
	state.clockCycles += 8;
}

void Instructions::INC_E(State& state)
{
	state.registers.resetZeroFlag();
	state.registers.resetSubtractFlag();
	state.registers.resetHalfCarryFlag();
	if (((state.registers.e & 0xf) + 1) & 0x10)
		state.registers.setHalfCarryFlag();
	state.registers.e += 1;
	if (state.registers.e == 0)
		state.registers.setZeroFlag();	
	state.clockCycles += 4;
}

void Instructions::DEC_E(State& state)
{
	state.registers.resetZeroFlag();
	state.registers.setSubtractFlag();
	state.registers.resetHalfCarryFlag();
	if (((state.registers.e & 0xf) - 1) & 0x10)
		state.registers.setHalfCarryFlag();
	state.registers.e -= 1;
	if (state.registers.e == 0)
		state.registers.setZeroFlag();	
	state.clockCycles += 4;
}

void Instructions::LD_E_d8(State& state)
{
	state.registers.e = state.memory.read(state.registers.pc);
	state.registers.pc += 1;
	state.clockCycles += 8;
}

void Instructions::RRA(State& state)
{
	bool carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (state.registers.a & 1) state.registers.setCarryFlag();
	state.registers.a = state.registers.a >> 1 | carry << 7;	
	state.clockCycles += 4;
}

void Instructions::JR_NZ_r8(State& state)
{
	SignedByte e = static_cast<SignedByte>(state.memory.read(state.registers.pc++));
	if (!state.registers.getZeroFlag())
	{
		state.registers.pc += e;
		state.clockCycles += 12;
	}
	else
		state.clockCycles += 8;
}

void Instructions::LD_HL_d16(State& state)
{
	state.registers.hl = state.memory.readWord(state.registers.pc);
	state.registers.pc += 2;
	state.clockCycles += 12;
}

void Instructions::LDI_MEM_AT_HL_A(State& state)
{
	state.memory.write(state.registers.hl, state.registers.a);
	state.registers.hl += 1;	
	state.clockCycles += 8;
}

void Instructions::INC_HL(State& state)
{
	state.registers.hl += 1;	
	state.clockCycles += 8;
}

void Instructions::INC_H(State& state)
{
	state.registers.resetZeroFlag();
	state.registers.resetSubtractFlag();
	state.registers.resetHalfCarryFlag();
	if (((state.registers.h & 0xf) + 1) & 0x10)
		state.registers.setHalfCarryFlag();
	state.registers.h += 1;
	if (state.registers.h == 0)
		state.registers.setZeroFlag();	
	state.clockCycles += 4;
}

void Instructions::DEC_H(State& state)
{
	state.registers.resetZeroFlag();
	state.registers.setSubtractFlag();
	state.registers.resetHalfCarryFlag();
	if (((state.registers.h & 0xf) - 1) & 0x10)
		state.registers.setHalfCarryFlag();
	state.registers.h -= 1;
	if (state.registers.h == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::LD_H_d8(State& state)
{
	state.registers.h = state.memory.read(state.registers.pc);
	state.registers.pc += 1;
	state.clockCycles += 8;
}

void Instructions::DAA(State& state)
{
	if (state.registers.getSubtractFlag())
	{
		// after subtraction
		if (state.registers.getCarryFlag()) state.registers.a -= 0x60;
		if (state.registers.getHalfCarryFlag()) state.registers.a -= 0x6;
	}
	else
	{
		// after addition
		if (state.registers.getCarryFlag() || state.registers.a > 0x99)
		{ state.registers.a += 0x60; state.registers.setCarryFlag(); }
		if (state.registers.getHalfCarryFlag() || (state.registers.a & 0x0f) > 0x09) state.registers.a += 0x6;
	}
	if (state.registers.a == 0) state.registers.setZeroFlag();
	state.registers.resetHalfCarryFlag();
	state.clockCycles += 4;
}

void Instructions::JR_Z_r8(State& state)
{
	SignedByte e = static_cast<SignedByte>(state.memory.read(state.registers.pc++));
	if (state.registers.getZeroFlag())
	{
		state.registers.pc += e;
		state.clockCycles += 12;
	}
	else
		state.clockCycles += 8;
}

void Instructions::ADD_HL_HL(State& state)
{
	state.registers.resetSubtractFlag();
	state.registers.resetHalfCarryFlag();
	state.registers.resetCarryFlag();
	if (((state.registers.hl & 0x0fff) + (state.registers.hl & 0x0fff)) & 0x1000)
		state.registers.setHalfCarryFlag();
	if ((state.registers.hl + state.registers.hl) & 0x10000)
		state.registers.setCarryFlag();
	state.registers.hl += state.registers.hl;
	state.clockCycles += 8;
}

void Instructions::LDI_A_MEM_AT_HL(State& state)
{
	state.registers.a = state.memory.read(state.registers.hl);
	state.registers.hl += 1;
	state.clockCycles += 8;
}

void Instructions::DEC_HL(State& state)
{
	state.registers.hl -= 1;
	state.clockCycles += 8;
}

void Instructions::INC_L(State& state)
{
	state.registers.resetZeroFlag();
	state.registers.resetSubtractFlag();
	state.registers.resetHalfCarryFlag();
	if (((state.registers.l & 0xf) + 1) & 0x10)
		state.registers.setHalfCarryFlag();
	state.registers.l += 1;
	if (state.registers.l == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::DEC_L(State& state)
{
	state.registers.resetZeroFlag();
	state.registers.setSubtractFlag();
	state.registers.resetHalfCarryFlag();
	if (((state.registers.l & 0xf) - 1) & 0x10)
		state.registers.setHalfCarryFlag();
	state.registers.l -= 1;
	if (state.registers.l == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::LD_L_d8(State& state)
{
	state.registers.l = state.memory.read(state.registers.pc);
	state.registers.pc += 1;
	state.clockCycles += 8;
}

void Instructions::CPL(State& state)
{
	state.registers.a = ~state.registers.a;
	state.registers.setSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.clockCycles += 4;
}

void Instructions::JR_NC_r8(State& state)
{
	SignedByte e = static_cast<SignedByte>(state.memory.read(state.registers.pc++));
	if (!state.registers.getCarryFlag())
	{
		state.registers.pc += e;
		state.clockCycles += 12;
	}
	else
		state.clockCycles += 8;
}

void Instructions::LD_SP_d16(State& state)
{
	state.registers.sp = state.memory.readWord(state.registers.pc);
	state.registers.pc += 2;
	state.clockCycles += 12;
}

void Instructions::LDD_MEM_AT_HL_A(State& state)
{
	state.memory.write(state.registers.hl, state.registers.a);
	state.registers.hl -= 1;
	state.clockCycles += 8;
}

void Instructions::INC_SP(State& state)
{
	state.registers.sp += 1;
	state.clockCycles += 8;
}

void Instructions::INC_MEM_AT_HL(State& state)
{
	state.registers.resetZeroFlag();
	state.registers.resetSubtractFlag();
	state.registers.resetHalfCarryFlag();
	const Byte& d8 = state.memory.read(state.registers.hl);
	if (((d8 & 0xf) + 1) > 0xf)
		state.registers.setHalfCarryFlag();
	state.memory.write(state.registers.hl, d8 + 1);
	if (d8 == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 12;
}

void Instructions::DEC_MEM_AT_HL(State& state)
{
	const Byte& d8 = state.memory.read(state.registers.hl);
	state.registers.resetZeroFlag();
	state.registers.setSubtractFlag();
	state.registers.resetHalfCarryFlag();
	if ((((d8 & 0xf) - 1) & 0xf) >= (d8 & 0xf))
		state.registers.setHalfCarryFlag();
	state.memory.write(state.registers.hl, d8 - 1);
	if (d8 == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 12;
}

void Instructions::LD_MEM_AT_HL_d8(State& state)
{
	state.memory.write(state.registers.hl, state.memory.read(state.registers.pc));
	state.registers.pc += 1;
	state.clockCycles += 12;
}

void Instructions::SCF(State& state)
{
	state.registers.resetSubtractFlag();
	state.registers.resetHalfCarryFlag();
	state.registers.setCarryFlag();
	state.clockCycles += 4;
}

void Instructions::JR_C_r8(State& state)
{
	SignedByte e = static_cast<SignedByte>(state.memory.read(state.registers.pc++));
	if (state.registers.getCarryFlag())
	{
		state.registers.pc += e;
		state.clockCycles += 12;
	}
	else
		state.clockCycles += 8;
}

void Instructions::ADD_HL_SP(State& state)
{
	state.registers.resetSubtractFlag();
	state.registers.resetHalfCarryFlag();
	state.registers.resetCarryFlag();
	if (((state.registers.hl & 0x0fff) + (state.registers.sp & 0x0fff)) & 0x1000)
		state.registers.setHalfCarryFlag();
	if ((state.registers.hl + state.registers.sp) & 0x10000)
		state.registers.setCarryFlag();
	state.registers.hl += state.registers.sp;
	state.clockCycles += 8;
}

void Instructions::LDD_A_MEM_AT_HL(State& state)
{
	state.registers.a = state.memory.read(state.registers.hl);
	state.registers.hl -= 1;
	state.clockCycles += 8;
}

void Instructions::DEC_SP(State& state)
{
	state.registers.sp -= 1;
	state.clockCycles += 8;
}

void Instructions::INC_A(State& state)
{
	state.registers.resetZeroFlag();
	state.registers.resetSubtractFlag();
	state.registers.resetHalfCarryFlag();
	if (((state.registers.a & 0xf) + 1) & 0x10)
		state.registers.setHalfCarryFlag();
	state.registers.a += 1;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::DEC_A(State& state)
{
	state.registers.resetZeroFlag();
	state.registers.setSubtractFlag();
	state.registers.resetHalfCarryFlag();
	if (((state.registers.a & 0xf) - 1) & 0x10)
		state.registers.setHalfCarryFlag();
	state.registers.a -= 1;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::LD_A_d8(State& state)
{
	state.registers.a = state.memory.read(state.registers.pc);
	state.registers.pc += 1;
	state.clockCycles += 8;
}

void Instructions::CCF(State& state)
{
	state.registers.resetSubtractFlag();
	state.registers.resetHalfCarryFlag();
	if (state.registers.getCarryFlag())
		state.registers.resetCarryFlag();
	else
		state.registers.setCarryFlag();
	state.clockCycles += 4;
}

void Instructions::LD_B_B(State& state)
{
	state.registers.b = state.registers.b;
	state.clockCycles += 4;
}

void Instructions::LD_B_C(State& state)
{
	state.registers.b = state.registers.c;
	state.clockCycles += 4;
}

void Instructions::LD_B_D(State& state)
{
	state.registers.b = state.registers.d;
	state.clockCycles += 4;
}

void Instructions::LD_B_E(State& state)
{
	state.registers.b = state.registers.e;
	state.clockCycles += 4;
}

void Instructions::LD_B_H(State& state)
{
	state.registers.b = state.registers.h;
	state.clockCycles += 4;
}

void Instructions::LD_B_L(State& state)
{
	state.registers.b = state.registers.l;
	state.clockCycles += 4;
}

void Instructions::LD_B_MEM_AT_HL(State& state)
{
	state.registers.b = state.memory.read(state.registers.hl);
	state.clockCycles += 8;
}

void Instructions::LD_B_A(State& state)
{
	state.registers.b = state.registers.a;
	state.clockCycles += 4;
}

void Instructions::LD_C_B(State& state)
{
	state.registers.c = state.registers.b;
	state.clockCycles += 4;
}

void Instructions::LD_C_C(State& state)
{
	state.registers.c = state.registers.c;
	state.clockCycles += 4;
}

void Instructions::LD_C_D(State& state)
{
	state.registers.c = state.registers.d;
	state.clockCycles += 4;
}

void Instructions::LD_C_E(State& state)
{
	state.registers.c = state.registers.e;
	state.clockCycles += 4;
}

void Instructions::LD_C_H(State& state)
{
	state.registers.c = state.registers.h;
	state.clockCycles += 4;
}

void Instructions::LD_C_L(State& state)
{
	state.registers.c = state.registers.l;
	state.clockCycles += 4;
}

void Instructions::LD_C_MEM_AT_HL(State& state)
{
	state.registers.c = state.memory.read(state.registers.hl);
	state.clockCycles += 8;
}

void Instructions::LD_C_A(State& state)
{
	state.registers.c = state.registers.a;
	state.clockCycles += 4;
}

void Instructions::LD_D_B(State& state)
{
	state.registers.d = state.registers.b;
	state.clockCycles += 4;
}

void Instructions::LD_D_C(State& state)
{
	state.registers.d = state.registers.c;
	state.clockCycles += 4;
}

void Instructions::LD_D_D(State& state)
{
	state.registers.d = state.registers.d;
	state.clockCycles += 4;
}

void Instructions::LD_D_E(State& state)
{
	state.registers.d = state.registers.e;
	state.clockCycles += 4;
}

void Instructions::LD_D_H(State& state)
{
	state.registers.d = state.registers.h;
	state.clockCycles += 4;
}

void Instructions::LD_D_L(State& state)
{
	state.registers.d = state.registers.l;
	state.clockCycles += 4;
}

void Instructions::LD_D_MEM_AT_HL(State& state)
{
	state.registers.d = state.memory.read(state.registers.hl);
	state.clockCycles += 8;
}

void Instructions::LD_D_A(State& state)
{
	state.registers.d = state.registers.a;
	state.clockCycles += 4;
}

void Instructions::LD_E_B(State& state)
{
	state.registers.e = state.registers.b;
	state.clockCycles += 4;
}

void Instructions::LD_E_C(State& state)
{
	state.registers.e = state.registers.c;
	state.clockCycles += 4;
}

void Instructions::LD_E_D(State& state)
{
	state.registers.e = state.registers.d;
	state.clockCycles += 4;
}

void Instructions::LD_E_E(State& state)
{
	state.registers.e = state.registers.e;
	state.clockCycles += 4;
}

void Instructions::LD_E_H(State& state)
{
	state.registers.e = state.registers.h;
	state.clockCycles += 4;
}

void Instructions::LD_E_L(State& state)
{
	state.registers.e = state.registers.l;
	state.clockCycles += 4;
}

void Instructions::LD_E_MEM_AT_HL(State& state)
{
	state.registers.e = state.memory.read(state.registers.hl);
	state.clockCycles += 8;
}

void Instructions::LD_E_A(State& state)
{
	state.registers.e = state.registers.a;
	state.clockCycles += 4;
}

void Instructions::LD_H_B(State& state)
{
	state.registers.h = state.registers.b;
	state.clockCycles += 4;
}

void Instructions::LD_H_C(State& state)
{
	state.registers.h = state.registers.c;
	state.clockCycles += 4;
}

void Instructions::LD_H_D(State& state)
{
	state.registers.h = state.registers.d;
	state.clockCycles += 4;
}

void Instructions::LD_H_E(State& state)
{
	state.registers.h = state.registers.e;
	state.clockCycles += 4;
}

void Instructions::LD_H_H(State& state)
{
	state.registers.h = state.registers.h;
	state.clockCycles += 4;
}

void Instructions::LD_H_L(State& state)
{
	state.registers.h = state.registers.l;
	state.clockCycles += 4;
}

void Instructions::LD_H_MEM_AT_HL(State& state)
{
	state.registers.h = state.memory.read(state.registers.hl);
	state.clockCycles += 8;
}

void Instructions::LD_H_A(State& state)
{
	state.registers.h = state.registers.a;
	state.clockCycles += 4;
}

void Instructions::LD_L_B(State& state)
{
	state.registers.l = state.registers.b;
	state.clockCycles += 4;
}

void Instructions::LD_L_C(State& state)
{
	state.registers.l = state.registers.c;
	state.clockCycles += 4;
}

void Instructions::LD_L_D(State& state)
{
	state.registers.l = state.registers.d;
	state.clockCycles += 4;
}

void Instructions::LD_L_E(State& state)
{
	state.registers.l = state.registers.e;
	state.clockCycles += 4;
}

void Instructions::LD_L_H(State& state)
{
	state.registers.l = state.registers.h;
	state.clockCycles += 4;
}

void Instructions::LD_L_L(State& state)
{
	state.registers.l = state.registers.l;
	state.clockCycles += 4;
}

void Instructions::LD_L_MEM_AT_HL(State& state)
{
	state.registers.l = state.memory.read(state.registers.hl);
	state.clockCycles += 8;
}

void Instructions::LD_L_A(State& state)
{
	state.registers.l = state.registers.a;
	state.clockCycles += 4;
}

void Instructions::LD_MEM_AT_HL_B(State& state)
{
	state.memory.write(state.registers.hl, state.registers.b);
	state.clockCycles += 8;
}

void Instructions::LD_MEM_AT_HL_C(State& state)
{
	state.memory.write(state.registers.hl, state.registers.c);
	state.clockCycles += 8;
}

void Instructions::LD_MEM_AT_HL_D(State& state)
{
	state.memory.write(state.registers.hl, state.registers.d);
	state.clockCycles += 8;
}

void Instructions::LD_MEM_AT_HL_E(State& state)
{
	state.memory.write(state.registers.hl, state.registers.e);
	state.clockCycles += 8;
}

void Instructions::LD_MEM_AT_HL_H(State& state)
{
	state.memory.write(state.registers.hl, state.registers.h);
	state.clockCycles += 8;
}

void Instructions::LD_MEM_AT_HL_L(State& state)
{
	state.memory.write(state.registers.hl, state.registers.l);
	state.clockCycles += 8;
}

void Instructions::HALT(State& state)
{
	state.clockCycles += 4;
}

void Instructions::LD_MEM_AT_HL_A(State& state)
{
	state.memory.write(state.registers.hl, state.registers.a);
	state.clockCycles += 8;
}

void Instructions::LD_A_B(State& state)
{
	state.registers.a = state.registers.b;
	state.clockCycles += 4;
}

void Instructions::LD_A_C(State& state)
{
	state.registers.a = state.registers.c;
	state.clockCycles += 4;
}

void Instructions::LD_A_D(State& state)
{
	state.registers.a = state.registers.d;
	state.clockCycles += 4;
}

void Instructions::LD_A_E(State& state)
{
	state.registers.a = state.registers.e;
	state.clockCycles += 4;
}

void Instructions::LD_A_H(State& state)
{
	state.registers.a = state.registers.h;
	state.clockCycles += 4;
}

void Instructions::LD_A_L(State& state)
{
	state.registers.a = state.registers.l;
	state.clockCycles += 4;
}

void Instructions::LD_A_MEM_AT_HL(State& state)
{
	state.registers.a = state.memory.read(state.registers.hl);
	state.clockCycles += 8;
}

void Instructions::LD_A_A(State& state)
{
	state.registers.a = state.registers.a;
	state.clockCycles += 4;
}

void Instructions::ADD_A_B(State& state)
{
	state.registers.clearFlags();
	if (((state.registers.a & 0xf) + (state.registers.b & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) + (state.registers.b & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a += state.registers.b;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::ADD_A_C(State& state)
{
	state.registers.clearFlags();
	if (((state.registers.a & 0xf) + (state.registers.c & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) + (state.registers.c & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a += state.registers.c;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::ADD_A_D(State& state)
{
	state.registers.clearFlags();
	if (((state.registers.a & 0xf) + (state.registers.d & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) + (state.registers.d & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a += state.registers.d;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::ADD_A_E(State& state)
{
	state.registers.clearFlags();
	if (((state.registers.a & 0xf) + (state.registers.e & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) + (state.registers.e & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a += state.registers.e;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::ADD_A_H(State& state)
{
	state.registers.clearFlags();
	if (((state.registers.a & 0xf) + (state.registers.h & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) + (state.registers.h & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a += state.registers.h;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::ADD_A_L(State& state)
{
	state.registers.clearFlags();
	if (((state.registers.a & 0xf) + (state.registers.l & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) + (state.registers.l & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a += state.registers.l;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::ADD_A_MEM_AT_HL(State& state)
{
	state.registers.clearFlags();
	if (((state.registers.a & 0xf) + (state.memory.read(state.registers.hl) & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) + (state.memory.read(state.registers.hl) & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a += state.memory.read(state.registers.hl);
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::ADD_A_A(State& state)
{
	state.registers.clearFlags();
	if (((state.registers.a & 0xf) + (state.registers.a & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) + (state.registers.a & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a += state.registers.a;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::ADC_A_B(State& state)
{
	Byte carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (((state.registers.a & 0xf) + (state.registers.b & 0xf) + (carry & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) + (state.registers.b & 0xff) + (carry & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a += state.registers.b + carry;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::ADC_A_C(State& state)
{
	Byte carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (((state.registers.a & 0xf) + (state.registers.c & 0xf) + (carry & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) + (state.registers.c & 0xff) + (carry & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a += state.registers.c + carry;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::ADC_A_D(State& state)
{
	Byte carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (((state.registers.a & 0xf) + (state.registers.d & 0xf) + (carry & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) + (state.registers.d & 0xff) + (carry & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a += state.registers.d + carry;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::ADC_A_E(State& state)
{
	Byte carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (((state.registers.a & 0xf) + (state.registers.e & 0xf) + (carry & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) + (state.registers.e & 0xff) + (carry & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a += state.registers.e + carry;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::ADC_A_H(State& state)
{
	Byte carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (((state.registers.a & 0xf) + (state.registers.h & 0xf) + (carry & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) + (state.registers.h & 0xff) + (carry & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a += state.registers.h + carry;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::ADC_A_L(State& state)
{
	Byte carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (((state.registers.a & 0xf) + (state.registers.l & 0xf) + (carry & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) + (state.registers.l & 0xff) + (carry & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a += state.registers.l + carry;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::ADC_A_MEM_AT_HL(State& state)
{
	Byte carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (((state.registers.a & 0xf) + (state.memory.read(state.registers.hl) & 0xf) + (carry & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) + (state.memory.read(state.registers.hl) & 0xff) + (carry & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a += state.memory.read(state.registers.hl) + carry;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::ADC_A_A(State& state)
{
	Byte carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (((state.registers.a & 0xf) + (state.registers.a & 0xf) + (carry & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) + (state.registers.a & 0xff) + (carry & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a += state.registers.a + carry;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::SUB_B(State& state)
{
	state.registers.clearFlags();
	state.registers.setSubtractFlag();
	if (((state.registers.a & 0xf) - (state.registers.b & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) - (state.registers.b & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a -= state.registers.b;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::SUB_C(State& state)
{
	state.registers.clearFlags();
	state.registers.setSubtractFlag();
	if (((state.registers.a & 0xf) - (state.registers.c & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) - (state.registers.c & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a -= state.registers.c;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::SUB_D(State& state)
{
	state.registers.clearFlags();
	state.registers.setSubtractFlag();
	if (((state.registers.a & 0xf) - (state.registers.d & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) - (state.registers.d & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a -= state.registers.d;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::SUB_E(State& state)
{
	state.registers.clearFlags();
	state.registers.setSubtractFlag();
	if (((state.registers.a & 0xf) - (state.registers.e & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) - (state.registers.e & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a -= state.registers.e;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::SUB_H(State& state)
{
	state.registers.clearFlags();
	state.registers.setSubtractFlag();
	if (((state.registers.a & 0xf) - (state.registers.h & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) - (state.registers.h & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a -= state.registers.h;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::SUB_L(State& state)
{
	state.registers.clearFlags();
	state.registers.setSubtractFlag();
	if (((state.registers.a & 0xf) - (state.registers.l & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) - (state.registers.l & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a -= state.registers.l;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::SUB_MEM_AT_HL(State& state)
{
	state.registers.clearFlags();
	state.registers.setSubtractFlag();
	if (((state.registers.a & 0xf) - (state.memory.read(state.registers.hl) & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) - (state.memory.read(state.registers.hl) & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a -= state.memory.read(state.registers.hl);
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SUB_A(State& state)
{
	state.registers.clearFlags();
	state.registers.setSubtractFlag();
	if (((state.registers.a & 0xf) - (state.registers.a & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) - (state.registers.a & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a -= state.registers.a;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::SBC_A_B(State& state)
{
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
	state.clockCycles += 4;
}

void Instructions::SBC_A_C(State& state)
{
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
	state.clockCycles += 4;
}

void Instructions::SBC_A_D(State& state)
{
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
	state.clockCycles += 4;
}

void Instructions::SBC_A_E(State& state)
{
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
	state.clockCycles += 4;
}

void Instructions::SBC_A_H(State& state)
{
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
	state.clockCycles += 4;
}

void Instructions::SBC_A_L(State& state)
{
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
	state.clockCycles += 4;
}

void Instructions::SBC_A_MEM_AT_HL(State& state)
{
	const Byte& operand = state.memory.read(state.registers.hl);
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
	state.clockCycles += 8;
}

void Instructions::SBC_A_A(State& state)
{
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
	state.clockCycles += 4;
}

void Instructions::AND_B(State& state)
{
	const Byte& operand = state.registers.b;
	state.registers.a &= operand;
	state.registers.clearFlags();
	state.registers.setHalfCarryFlag();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::AND_C(State& state)
{
	const Byte& operand = state.registers.c;
	state.registers.a &= operand;
	state.registers.clearFlags();
	state.registers.setHalfCarryFlag();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::AND_D(State& state)
{
	const Byte& operand = state.registers.d;
	state.registers.a &= operand;
	state.registers.clearFlags();
	state.registers.setHalfCarryFlag();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::AND_E(State& state)
{
	const Byte& operand = state.registers.e;
	state.registers.a &= operand;
	state.registers.clearFlags();
	state.registers.setHalfCarryFlag();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::AND_H(State& state)
{
	const Byte& operand = state.registers.h;
	state.registers.a &= operand;
	state.registers.clearFlags();
	state.registers.setHalfCarryFlag();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::AND_L(State& state)
{
	const Byte& operand = state.registers.l;
	state.registers.a &= operand;
	state.registers.clearFlags();
	state.registers.setHalfCarryFlag();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::AND_MEM_AT_HL(State& state)
{
	const Byte& operand = state.memory.read(state.registers.hl);
	state.registers.a &= operand;
	state.registers.clearFlags();
	state.registers.setHalfCarryFlag();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::AND_A(State& state)
{
	const Byte& operand = state.registers.a;
	state.registers.a &= operand;
	state.registers.clearFlags();
	state.registers.setHalfCarryFlag();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::XOR_B(State& state)
{
	const Byte& operand = state.registers.b;
	state.registers.a ^= operand;
	state.registers.clearFlags();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::XOR_C(State& state)
{
	const Byte& operand = state.registers.c;
	state.registers.a ^= operand;
	state.registers.clearFlags();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::XOR_D(State& state)
{
	const Byte& operand = state.registers.d;
	state.registers.a ^= operand;
	state.registers.clearFlags();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::XOR_E(State& state)
{
	const Byte& operand = state.registers.e;
	state.registers.a ^= operand;
	state.registers.clearFlags();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::XOR_H(State& state)
{
	const Byte& operand = state.registers.h;
	state.registers.a ^= operand;
	state.registers.clearFlags();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::XOR_L(State& state)
{
	const Byte& operand = state.registers.l;
	state.registers.a ^= operand;
	state.registers.clearFlags();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::XOR_MEM_AT_HL(State& state)
{
	const Byte& operand = state.memory.read(state.registers.hl);
	state.registers.a ^= operand;
	state.registers.clearFlags();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::XOR_A(State& state)
{
	const Byte& operand = state.registers.a;
	state.registers.a ^= operand;
	state.registers.clearFlags();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::OR_B(State& state)
{
	const Byte& operand = state.registers.b;
	state.registers.a |= operand;
	state.registers.clearFlags();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::OR_C(State& state)
{
	const Byte& operand = state.registers.c;
	state.registers.a |= operand;
	state.registers.clearFlags();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::OR_D(State& state)
{
	const Byte& operand = state.registers.d;
	state.registers.a |= operand;
	state.registers.clearFlags();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::OR_E(State& state)
{
	const Byte& operand = state.registers.e;
	state.registers.a |= operand;
	state.registers.clearFlags();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::OR_H(State& state)
{
	const Byte& operand = state.registers.h;
	state.registers.a |= operand;
	state.registers.clearFlags();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::OR_L(State& state)
{
	const Byte& operand = state.registers.l;
	state.registers.a |= operand;
	state.registers.clearFlags();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::OR_MEM_AT_HL(State& state)
{
	const Byte& operand = state.memory.read(state.registers.hl);
	state.registers.a |= operand;
	state.registers.clearFlags();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::OR_A(State& state)
{
	const Byte& operand = state.registers.a;
	state.registers.a |= operand;
	state.registers.clearFlags();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::CP_B(State& state)
{
	const Byte& operand = state.registers.b;
	state.registers.clearFlags();
	state.registers.setSubtractFlag();
	if (((state.registers.a & 0xf) - (operand & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) - (operand & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	if (state.registers.a - operand == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::CP_C(State& state)
{
	const Byte& operand = state.registers.c;
	state.registers.clearFlags();
	state.registers.setSubtractFlag();
	if (((state.registers.a & 0xf) - (operand & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) - (operand & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	if (state.registers.a - operand == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::CP_D(State& state)
{
	const Byte& operand = state.registers.d;
	state.registers.clearFlags();
	state.registers.setSubtractFlag();
	if (((state.registers.a & 0xf) - (operand & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) - (operand & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	if (state.registers.a - operand == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::CP_E(State& state)
{
	const Byte& operand = state.registers.e;
	state.registers.clearFlags();
	state.registers.setSubtractFlag();
	if (((state.registers.a & 0xf) - (operand & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) - (operand & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	if (state.registers.a - operand == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::CP_H(State& state)
{
	const Byte& operand = state.registers.h;
	state.registers.clearFlags();
	state.registers.setSubtractFlag();
	if (((state.registers.a & 0xf) - (operand & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) - (operand & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	if (state.registers.a - operand == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::CP_L(State& state)
{
	const Byte& operand = state.registers.l;
	state.registers.clearFlags();
	state.registers.setSubtractFlag();
	if (((state.registers.a & 0xf) - (operand & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) - (operand & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	if (state.registers.a - operand == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::CP_MEM_AT_HL(State& state)
{
	const Byte& operand = state.memory.read(state.registers.hl);
	state.registers.clearFlags();
	state.registers.setSubtractFlag();
	if (((state.registers.a & 0xf) - (operand & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) - (operand & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	if (state.registers.a - operand == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::CP_A(State& state)
{
	const Byte& operand = state.registers.a;
	state.registers.clearFlags();
	state.registers.setSubtractFlag();
	if (((state.registers.a & 0xf) - (operand & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) - (operand & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	if (state.registers.a - operand == 0)
		state.registers.setZeroFlag();
	state.clockCycles += 4;
}

void Instructions::RET_NZ(State& state)
{
	if (!state.registers.getZeroFlag())
	{
		state.registers.pc = state.memory.readWord(state.registers.sp);
		state.registers.sp += 2;
		state.clockCycles += 20;
	}
	else
		state.clockCycles += 8;
}

void Instructions::POP_BC(State& state)
{
	state.registers.bc = state.memory.readWord(state.registers.sp);
	state.registers.sp += 2;
	state.clockCycles += 12;
}

void Instructions::JP_NZ_a16(State& state)
{
	Word addr = state.memory.readWord(state.registers.pc);
	state.registers.pc += 2;
	if (!state.registers.getZeroFlag())
	{
		state.registers.pc = addr;
		state.clockCycles += 16;
	}
	else
		state.clockCycles += 12;
}

void Instructions::JP_a16(State& state)
{
	Word addr = state.memory.readWord(state.registers.pc);
	state.registers.pc = addr;
	state.clockCycles += 16;
}

void Instructions::CALL_NZ_a16(State& state)
{
	Word addr = state.memory.readWord(state.registers.pc);
	state.registers.pc += 2;
	if (!state.registers.getZeroFlag())
	{
		state.registers.sp -= 2;
		state.memory.writeWord(state.registers.sp, state.registers.pc);
		state.registers.pc = addr;
		state.clockCycles += 24;
	}
	else
		state.clockCycles += 12;
}

void Instructions::PUSH_BC(State& state)
{
	state.registers.sp -= 2;
	state.memory.writeWord(state.registers.sp, state.registers.bc);
	state.clockCycles += 16;
}

void Instructions::ADD_A_d8(State& state)
{
	const Byte& operand = state.memory.read(state.registers.pc);
	state.registers.clearFlags();
	if (((state.registers.a & 0xf) + (operand & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) + (operand & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a += operand;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.registers.pc += 1;
	state.clockCycles += 8;
}

void Instructions::RST_00H(State& state)
{
	state.registers.sp -= 2;
	state.memory.writeWord(state.registers.sp, state.registers.pc);
	state.registers.pc = 0;
	state.clockCycles += 16;
}

void Instructions::RET_Z(State& state)
{
	if (state.registers.getZeroFlag())
	{
		state.registers.pc = state.memory.readWord(state.registers.sp);
		state.registers.sp += 2;
		state.clockCycles += 20;
	}
	else
		state.clockCycles += 8;
}

void Instructions::RET(State& state)
{
	state.registers.pc = state.memory.readWord(state.registers.sp);
	state.registers.sp += 2;
	state.clockCycles += 16;
}

void Instructions::JP_Z_a16(State& state)
{
	Word addr = state.memory.readWord(state.registers.pc);
	state.registers.pc += 2;
	if (state.registers.getZeroFlag())
	{
		state.registers.pc = addr;
		state.clockCycles += 16;
	}
	else
		state.clockCycles += 12;
}

//void Instructions::PREFIX_CB(State& state)
//{
//	
//	state.clockCycles += 4;
//}

void Instructions::CALL_Z_a16(State& state)
{
	Word addr = state.memory.readWord(state.registers.pc);
	state.registers.pc += 2;
	if (state.registers.getZeroFlag())
	{
		state.registers.sp -= 2;
		state.memory.writeWord(state.registers.sp, state.registers.pc);
		state.registers.pc = addr;
		state.clockCycles += 24;
	}
	else
		state.clockCycles += 12;
}

void Instructions::CALL_a16(State& state)
{
	Word addr = state.memory.readWord(state.registers.pc);
	state.registers.pc += 2;
	state.registers.sp -= 2;
	state.memory.writeWord(state.registers.sp, state.registers.pc);
	state.registers.pc = addr;
	state.clockCycles += 24;
}

void Instructions::ADC_A_d8(State& state)
{
	Byte carry = state.registers.getCarryFlag();
	const Byte& operand = state.memory.read(state.registers.pc);
	state.registers.clearFlags();
	if (((state.registers.a & 0xf) + (operand & 0xf) + (carry & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) + (operand & 0xff) + (carry & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a += operand + carry;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.registers.pc += 1;
	state.clockCycles += 8;
}

void Instructions::RST_08H(State& state)
{
	state.registers.sp -= 2;
	state.memory.writeWord(state.registers.sp, state.registers.pc);
	state.registers.pc = 0x08;
	state.clockCycles += 16;
}

void Instructions::RET_NC(State& state)
{
	if (!state.registers.getCarryFlag())
	{
		state.registers.pc = state.memory.readWord(state.registers.sp);
		state.registers.sp += 2;
		state.clockCycles += 20;
	}
	else
		state.clockCycles += 8;
}

void Instructions::POP_DE(State& state)
{
	state.registers.de = state.memory.readWord(state.registers.sp);
	state.registers.sp += 2;
	state.clockCycles += 12;
}

void Instructions::JP_NC_a16(State& state)
{
	Word addr = state.memory.readWord(state.registers.pc);
	state.registers.pc += 2;
	if (!state.registers.getCarryFlag())
	{
		state.registers.pc = addr;
		state.clockCycles += 16;
	}
	else
		state.clockCycles += 12;
}

void Instructions::CALL_NC_a16(State& state)
{
	Word addr = state.memory.readWord(state.registers.pc);
	state.registers.pc += 2;
	if (!state.registers.getCarryFlag())
	{
		state.registers.sp -= 2;
		state.memory.writeWord(state.registers.sp, state.registers.pc);
		state.registers.pc = addr;
		state.clockCycles += 24;
	}
	else
		state.clockCycles += 12;
}

void Instructions::PUSH_DE(State& state)
{
	state.registers.sp -= 2;
	state.memory.writeWord(state.registers.sp, state.registers.de);
	state.clockCycles += 16;
}

void Instructions::SUB_d8(State& state)
{
	state.registers.clearFlags();
	state.registers.setSubtractFlag();
	const Byte& operand = state.memory.read(state.registers.pc);
	if (((state.registers.a & 0xf) - (operand & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) - (operand & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a -= operand;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.registers.pc += 1;
	state.clockCycles += 8;
}

void Instructions::RST_10H(State& state)
{
	state.registers.sp -= 2;
	state.memory.writeWord(state.registers.sp, state.registers.pc);
	state.registers.pc = 0x10;
	state.clockCycles += 16;
}

void Instructions::RET_C(State& state)
{
	if (state.registers.getCarryFlag())
	{
		state.registers.pc = state.memory.readWord(state.registers.sp);
		state.registers.sp += 2;
		state.clockCycles += 20;
	}
	else
		state.clockCycles += 8;
}

void Instructions::RETI(State& state)
{
	state.registers.pc = state.memory.readWord(state.registers.sp);
	state.registers.sp += 2;
	state.ime = true;
	state.clockCycles += 16;
}

void Instructions::JP_C_a16(State& state)
{
	Word addr = state.memory.readWord(state.registers.pc);
	state.registers.pc += 2;
	if (state.registers.getCarryFlag())
	{
		state.registers.pc = addr;
		state.clockCycles += 16;
	}
	else
		state.clockCycles += 12;
}

void Instructions::CALL_C_a16(State& state)
{
	Word addr = state.memory.readWord(state.registers.pc);
	state.registers.pc += 2;
	if (state.registers.getCarryFlag())
	{
		state.registers.sp -= 2;
		state.memory.writeWord(state.registers.sp, state.registers.pc);
		state.registers.pc = addr;
		state.clockCycles += 24;
	}
	else
		state.clockCycles += 12;
}

void Instructions::SBC_A_d8(State& state)
{
	const Byte& operand = state.memory.read(state.registers.pc);
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
	state.clockCycles += 8;
}

void Instructions::RST_18H(State& state)
{
	state.registers.sp -= 2;
	state.memory.writeWord(state.registers.sp, state.registers.pc);
	state.registers.pc = 0x18;
	state.clockCycles += 16;
}

void Instructions::LDH_MEM_AT_a8_A(State& state)
{
	state.memory.write(0xff00 | state.memory.read(state.registers.pc), state.registers.a);
	state.registers.pc += 1;
	state.clockCycles += 12;
}

void Instructions::POP_HL(State& state)
{
	state.registers.hl = state.memory.readWord(state.registers.sp);
	state.registers.sp += 2;
	state.clockCycles += 12;
}

void Instructions::LD_MEM_AT_C_A(State& state)
{
	state.memory.write(0xff00 | state.registers.c, state.registers.a);
	state.clockCycles += 8;
}

void Instructions::PUSH_HL(State& state)
{
	state.registers.sp -= 2;
	state.memory.writeWord(state.registers.sp, state.registers.hl);
	state.clockCycles += 16;
}

void Instructions::AND_d8(State& state)
{
	const Byte& operand = state.memory.read(state.registers.pc);
	state.registers.a &= operand;
	state.registers.clearFlags();
	state.registers.setHalfCarryFlag();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.registers.pc += 1;
	state.clockCycles += 8;
}

void Instructions::RST_20H(State& state)
{
	state.registers.sp -= 2;
	state.memory.writeWord(state.registers.sp, state.registers.pc);
	state.registers.pc = 0x20;
	state.clockCycles += 16;
}

void Instructions::ADD_SP_r8(State& state)
{
	const SignedByte& e = static_cast<SignedByte>(state.memory.read(state.registers.pc));
	state.registers.clearFlags();
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
	state.registers.pc += 1;
	state.clockCycles += 16;
}

void Instructions::JP_HL(State& state)
{
	state.registers.pc = state.registers.hl;
	state.clockCycles += 4;
}

void Instructions::LD_MEM_AT_a16_A(State& state)
{
	state.memory.write(state.memory.readWord(state.registers.pc), state.registers.a);
	state.registers.pc += 2;
	state.clockCycles += 16;
}

void Instructions::XOR_d8(State& state)
{
	const Byte& operand = state.memory.read(state.registers.pc);
	state.registers.a ^= operand;
	state.registers.clearFlags();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.registers.pc += 1;
	state.clockCycles += 8;
}

void Instructions::RST_28H(State& state)
{
	state.registers.sp -= 2;
	state.memory.writeWord(state.registers.sp, state.registers.pc);
	state.registers.pc = 0x28;
	state.clockCycles += 16;
}

void Instructions::LDH_A_MEM_AT_a8(State& state)
{
	state.registers.a = state.memory.read(0xff00 | state.memory.read(state.registers.pc));
	state.registers.pc += 1;
	state.clockCycles += 12;
}

void Instructions::POP_AF(State& state)
{
	state.registers.af = state.memory.readWord(state.registers.sp);
	state.registers.sp += 2;
	state.clockCycles += 12;
}

void Instructions::LD_A_MEM_AT_C(State& state)
{
	state.registers.a = state.memory.read(0xff00 | state.registers.c);
	state.clockCycles += 8;
}

void Instructions::DI(State& state)
{
	state.ime = false;
	state.imeScheduled = false;
	state.clockCycles += 4;
}

void Instructions::PUSH_AF(State& state)
{
	state.registers.sp -= 2;
	state.memory.writeWord(state.registers.sp, state.registers.af);
	state.clockCycles += 16;
}

void Instructions::OR_d8(State& state)
{
	const Byte& operand = state.memory.read(state.registers.pc);
	state.registers.a |= operand;
	state.registers.clearFlags();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
	state.registers.pc += 1;
	state.clockCycles += 8;
}

void Instructions::RST_30H(State& state)
{
	state.registers.sp -= 2;
	state.memory.writeWord(state.registers.sp, state.registers.pc);
	state.registers.pc = 0x30;
	state.clockCycles += 16;
}

void Instructions::LD_HL_SP_r8(State& state)
{
	// this is highly sus
	auto e = static_cast<SignedByte>(state.memory.read(state.registers.pc));
	state.registers.hl = state.registers.sp + e;
	state.registers.clearFlags();
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
	state.registers.pc += 1;
	state.clockCycles += 12;
}

void Instructions::LD_SP_HL(State& state)
{
	state.registers.sp = state.registers.hl;
	state.clockCycles += 8;
}

void Instructions::LD_A_MEM_AT_a16(State& state)
{
	state.registers.a = state.memory.read(state.memory.read(state.registers.pc));
	state.registers.pc += 2;
	state.clockCycles += 16;
}

void Instructions::EI(State& state)
{
	state.imeScheduled = true;
	state.clockCycles += 4;
}

void Instructions::CP_d8(State& state)
{
	const Byte& operand = state.memory.read(state.registers.pc);
	state.registers.clearFlags();
	state.registers.setSubtractFlag();
	if (((state.registers.a & 0xf) - (operand & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) - (operand & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	if (state.registers.a - operand == 0)
		state.registers.setZeroFlag();
	state.registers.pc += 1;
	state.clockCycles += 8;
}

void Instructions::RST_38H(State& state)
{
	state.registers.sp -= 2;
	state.memory.writeWord(state.registers.sp, state.registers.pc);
	state.registers.pc = 0x38;
	state.clockCycles += 16;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Instructions::RLC_B(State& state)
{
	Byte& operand = state.registers.b;
	state.registers.clearFlags();
	if (operand & 0b10000000) state.registers.setCarryFlag();
	operand = operand << 1 | (operand >> 7);
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RLC_C(State& state)
{
	Byte& operand = state.registers.c;
	state.registers.clearFlags();
	if (operand & 0b10000000) state.registers.setCarryFlag();
	operand = operand << 1 | (operand >> 7);
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RLC_D(State& state)
{
	Byte& operand = state.registers.d;
	state.registers.clearFlags();
	if (operand & 0b10000000) state.registers.setCarryFlag();
	operand = operand << 1 | (operand >> 7);
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RLC_E(State& state)
{
	Byte& operand = state.registers.e;
	state.registers.clearFlags();
	if (operand & 0b10000000) state.registers.setCarryFlag();
	operand = operand << 1 | (operand >> 7);
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RLC_H(State& state)
{
	Byte& operand = state.registers.h;
	state.registers.clearFlags();
	if (operand & 0b10000000) state.registers.setCarryFlag();
	operand = operand << 1 | (operand >> 7);
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RLC_L(State& state)
{
	Byte& operand = state.registers.l;
	state.registers.clearFlags();
	if (operand & 0b10000000) state.registers.setCarryFlag();
	operand = operand << 1 | (operand >> 7);
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RLC_MEM_AT_HL(State& state)
{
	const Byte& operand = state.memory.read(state.registers.hl);
	state.registers.clearFlags();
	if (operand & 0b10000000) state.registers.setCarryFlag();
	state.memory.write(state.registers.hl, operand << 1 | (operand >> 7));
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 16;
}

void Instructions::RLC_A(State& state)
{
	Byte& operand = state.registers.a;
	state.registers.clearFlags();
	if (operand & 0b10000000) state.registers.setCarryFlag();
	operand = operand << 1 | (operand >> 7);
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RRC_B(State& state)
{
	Byte& operand = state.registers.b;
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1 | (operand << 7);
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RRC_C(State& state)
{
	Byte& operand = state.registers.c;
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1 | (operand << 7);
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RRC_D(State& state)
{
	Byte& operand = state.registers.d;
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1 | (operand << 7);
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RRC_E(State& state)
{
	Byte& operand = state.registers.e;
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1 | (operand << 7);
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RRC_H(State& state)
{
	Byte& operand = state.registers.h;
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1 | (operand << 7);
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RRC_L(State& state)
{
	Byte& operand = state.registers.l;
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1 | (operand << 7);
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RRC_MEM_AT_HL(State& state)
{
	const Byte& operand = state.memory.read(state.registers.hl);
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	state.memory.write(state.registers.hl, operand >> 1 | (operand << 7));
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 16;
}

void Instructions::RRC_A(State& state)
{
	Byte& operand = state.registers.a;
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1 | (operand << 7);
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RL_B(State& state)
{
	Byte& operand =state.registers.b;
	bool carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (operand & 0b10000000) state.registers.setCarryFlag();
	operand = operand << 1 | carry;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RL_C(State& state)
{
	Byte& operand =state.registers.c;
	bool carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (operand & 0b10000000) state.registers.setCarryFlag();
	operand = operand << 1 | carry;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RL_D(State& state)
{
	Byte& operand =state.registers.d;
	bool carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (operand & 0b10000000) state.registers.setCarryFlag();
	operand = operand << 1 | carry;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RL_E(State& state)
{
	Byte& operand =state.registers.e;
	bool carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (operand & 0b10000000) state.registers.setCarryFlag();
	operand = operand << 1 | carry;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RL_H(State& state)
{
	Byte& operand =state.registers.h;
	bool carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (operand & 0b10000000) state.registers.setCarryFlag();
	operand = operand << 1 | carry;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RL_L(State& state)
{
	Byte& operand =state.registers.l;
	bool carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (operand & 0b10000000) state.registers.setCarryFlag();
	operand = operand << 1 | carry;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RL_MEM_AT_HL(State& state)
{
	const Byte& operand = state.memory.read(state.registers.hl);
	bool carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (operand & 0b10000000) state.registers.setCarryFlag();
	state.memory.write(state.registers.hl, operand << 1 | carry);
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 16;
}

void Instructions::RL_A(State& state)
{
	Byte& operand =state.registers.a;
	bool carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (operand & 0b10000000) state.registers.setCarryFlag();
	operand = operand << 1 | carry;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RR_B(State& state)
{
	Byte& operand = state.registers.b;
	bool carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1 | carry << 7;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RR_C(State& state)
{
	Byte& operand = state.registers.c;
	bool carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1 | carry << 7;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RR_D(State& state)
{
	Byte& operand = state.registers.d;
	bool carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1 | carry << 7;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RR_E(State& state)
{
	Byte& operand = state.registers.e;
	bool carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1 | carry << 7;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RR_H(State& state)
{
	Byte& operand = state.registers.h;
	bool carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1 | carry << 7;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RR_L(State& state)
{
	Byte& operand = state.registers.l;
	bool carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1 | carry << 7;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RR_MEM_AT_HL(State& state)
{
	const Byte& operand = state.memory.read(state.registers.hl);
	bool carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	state.memory.write(state.registers.hl, operand >> 1 | carry << 7);
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 16;
}

void Instructions::RR_A(State& state)
{
	Byte& operand = state.registers.a;
	bool carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1 | carry << 7;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SLA_B(State& state)
{
	Byte& operand = state.registers.b;
	state.registers.clearFlags();
	if (operand & 0b10000000) state.registers.setCarryFlag();
	operand = operand << 1;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SLA_C(State& state)
{
	Byte& operand = state.registers.c;
	state.registers.clearFlags();
	if (operand & 0b10000000) state.registers.setCarryFlag();
	operand = operand << 1;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SLA_D(State& state)
{
	Byte& operand = state.registers.d;
	state.registers.clearFlags();
	if (operand & 0b10000000) state.registers.setCarryFlag();
	operand = operand << 1;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SLA_E(State& state)
{
	Byte& operand = state.registers.e;
	state.registers.clearFlags();
	if (operand & 0b10000000) state.registers.setCarryFlag();
	operand = operand << 1;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SLA_H(State& state)
{
	Byte& operand = state.registers.h;
	state.registers.clearFlags();
	if (operand & 0b10000000) state.registers.setCarryFlag();
	operand = operand << 1;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SLA_L(State& state)
{
	Byte& operand = state.registers.l;
	state.registers.clearFlags();
	if (operand & 0b10000000) state.registers.setCarryFlag();
	operand = operand << 1;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SLA_MEM_AT_HL(State& state)
{
	const Byte& operand = state.memory.read(state.registers.hl);
	state.registers.clearFlags();
	if (operand & 0b10000000) state.registers.setCarryFlag();
	state.memory.write(state.registers.hl, operand << 1);
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 16;
}

void Instructions::SLA_A(State& state)
{
	Byte& operand = state.registers.a;
	state.registers.clearFlags();
	if (operand & 0b10000000) state.registers.setCarryFlag();
	operand = operand << 1;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SRA_B(State& state)
{
	Byte& operand = state.registers.b;
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1 | operand & 0b10000000;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SRA_C(State& state)
{
	Byte& operand = state.registers.c;
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1 | operand & 0b10000000;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SRA_D(State& state)
{
	Byte& operand = state.registers.d;
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1 | operand & 0b10000000;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SRA_E(State& state)
{
	Byte& operand = state.registers.e;
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1 | operand & 0b10000000;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SRA_H(State& state)
{
	Byte& operand = state.registers.h;
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1 | operand & 0b10000000;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SRA_L(State& state)
{
	Byte& operand = state.registers.l;
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1 | operand & 0b10000000;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SRA_MEM_AT_HL(State& state)
{
	const Byte& operand = state.memory.read(state.registers.hl);
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	state.memory.write(state.registers.hl, operand >> 1 | operand & 0b10000000);
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 16;
}

void Instructions::SRA_A(State& state)
{
	Byte& operand = state.registers.a;
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1 | operand & 0b10000000;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SWAP_B(State& state)
{
	Byte& operand = state.registers.b;
	state.registers.clearFlags();
	operand = operand >> 4 | operand << 4;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SWAP_C(State& state)
{
	Byte& operand = state.registers.c;
	state.registers.clearFlags();
	operand = operand >> 4 | operand << 4;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SWAP_D(State& state)
{
	Byte& operand = state.registers.d;
	state.registers.clearFlags();
	operand = operand >> 4 | operand << 4;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SWAP_E(State& state)
{
	Byte& operand = state.registers.e;
	state.registers.clearFlags();
	operand = operand >> 4 | operand << 4;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SWAP_H(State& state)
{
	Byte& operand = state.registers.h;
	state.registers.clearFlags();
	operand = operand >> 4 | operand << 4;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SWAP_L(State& state)
{
	Byte& operand = state.registers.l;
	state.registers.clearFlags();
	operand = operand >> 4 | operand << 4;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SWAP_MEM_AT_HL(State& state)
{
	const Byte& operand = state.memory.read(state.registers.hl);
	state.registers.clearFlags();
	state.memory.write(state.registers.hl, operand >> 4 | operand << 4);
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 16;
}

void Instructions::SWAP_A(State& state)
{
	Byte& operand = state.registers.a;
	state.registers.clearFlags();
	operand = operand >> 4 | operand << 4;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SRL_B(State& state)
{
	Byte& operand = state.registers.b;
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SRL_C(State& state)
{
	Byte& operand = state.registers.c;
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SRL_D(State& state)
{
	Byte& operand = state.registers.d;
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SRL_E(State& state)
{
	Byte& operand = state.registers.e;
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SRL_H(State& state)
{
	Byte& operand = state.registers.h;
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SRL_L(State& state)
{
	Byte& operand = state.registers.l;
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::SRL_MEM_AT_HL(State& state)
{
	const Byte& operand = state.memory.read(state.registers.hl);
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	state.memory.write(state.registers.hl, operand >> 1);
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 16;
}

void Instructions::SRL_A(State& state)
{
	Byte& operand = state.registers.a;
	state.registers.clearFlags();
	if (operand & 1) state.registers.setCarryFlag();
	operand = operand >> 1;
	if (operand == 0) state.registers.setZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_0_B(State& state)
{
	const Byte& operand = state.registers.b;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 0)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_0_C(State& state)
{
	const Byte& operand = state.registers.c;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 0)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_0_D(State& state)
{
	const Byte& operand = state.registers.d;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 0)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_0_E(State& state)
{
	const Byte& operand = state.registers.e;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 0)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_0_H(State& state)
{
	const Byte& operand = state.registers.h;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 0)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_0_L(State& state)
{
	const Byte& operand = state.registers.l;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 0)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_0_MEM_AT_HL(State& state)
{
	const Byte& operand = state.memory.read(state.registers.hl);
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 0)) state.registers.resetZeroFlag();
	state.clockCycles += 12;
}

void Instructions::BIT_0_A(State& state)
{
	const Byte& operand = state.registers.a;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 0)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_1_B(State& state)
{
	const Byte& operand = state.registers.b;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 1)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_1_C(State& state)
{
	const Byte& operand = state.registers.c;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 1)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_1_D(State& state)
{
	const Byte& operand = state.registers.d;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 1)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_1_E(State& state)
{
	const Byte& operand = state.registers.e;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 1)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_1_H(State& state)
{
	const Byte& operand = state.registers.h;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 1)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_1_L(State& state)
{
	const Byte& operand = state.registers.l;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 1)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_1_MEM_AT_HL(State& state)
{
	const Byte& operand = state.memory.read(state.registers.hl);
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 1)) state.registers.resetZeroFlag();
	state.clockCycles += 12;
}

void Instructions::BIT_1_A(State& state)
{
	const Byte& operand = state.registers.a;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 1)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_2_B(State& state)
{
	const Byte& operand = state.registers.b;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 2)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_2_C(State& state)
{
	const Byte& operand = state.registers.c;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 2)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_2_D(State& state)
{
	const Byte& operand = state.registers.d;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 2)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_2_E(State& state)
{
	const Byte& operand = state.registers.e;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 2)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_2_H(State& state)
{
	const Byte& operand = state.registers.h;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 2)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_2_L(State& state)
{
	const Byte& operand = state.registers.l;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 2)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_2_MEM_AT_HL(State& state)
{
	const Byte& operand = state.memory.read(state.registers.hl);
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 2)) state.registers.resetZeroFlag();
	state.clockCycles += 12;
}

void Instructions::BIT_2_A(State& state)
{
	const Byte& operand = state.registers.a;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 2)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_3_B(State& state)
{
	const Byte& operand = state.registers.b;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 3)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_3_C(State& state)
{
	const Byte& operand = state.registers.c;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 3)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_3_D(State& state)
{
	const Byte& operand = state.registers.d;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 3)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_3_E(State& state)
{
	const Byte& operand = state.registers.e;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 3)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_3_H(State& state)
{
	const Byte& operand = state.registers.h;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 3)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_3_L(State& state)
{
	const Byte& operand = state.registers.l;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 3)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_3_MEM_AT_HL(State& state)
{
	const Byte& operand = state.memory.read(state.registers.hl);
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 3)) state.registers.resetZeroFlag();
	state.clockCycles += 12;
}

void Instructions::BIT_3_A(State& state)
{
	const Byte& operand = state.registers.a;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 3)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_4_B(State& state)
{
	const Byte& operand = state.registers.b;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 4)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_4_C(State& state)
{
	const Byte& operand = state.registers.c;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 4)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_4_D(State& state)
{
	const Byte& operand = state.registers.d;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 4)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_4_E(State& state)
{
	const Byte& operand = state.registers.e;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 4)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_4_H(State& state)
{
	const Byte& operand = state.registers.h;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 4)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_4_L(State& state)
{
	const Byte& operand = state.registers.l;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 4)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_4_MEM_AT_HL(State& state)
{
	const Byte& operand = state.memory.read(state.registers.hl);
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 4)) state.registers.resetZeroFlag();
	state.clockCycles += 12;
}

void Instructions::BIT_4_A(State& state)
{
	const Byte& operand = state.registers.a;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 4)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_5_B(State& state)
{
	const Byte& operand = state.registers.b;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 5)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_5_C(State& state)
{
	const Byte& operand = state.registers.c;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 5)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_5_D(State& state)
{
	const Byte& operand = state.registers.d;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 5)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_5_E(State& state)
{
	const Byte& operand = state.registers.e;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 5)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_5_H(State& state)
{
	const Byte& operand = state.registers.h;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 5)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_5_L(State& state)
{
	const Byte& operand = state.registers.l;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 5)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_5_MEM_AT_HL(State& state)
{
	const Byte& operand = state.memory.read(state.registers.hl);
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 5)) state.registers.resetZeroFlag();
	state.clockCycles += 12;
}

void Instructions::BIT_5_A(State& state)
{
	const Byte& operand = state.registers.a;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 5)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_6_B(State& state)
{
	const Byte& operand = state.registers.b;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 6)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_6_C(State& state)
{
	const Byte& operand = state.registers.c;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 6)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_6_D(State& state)
{
	const Byte& operand = state.registers.d;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 6)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_6_E(State& state)
{
	const Byte& operand = state.registers.e;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 6)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_6_H(State& state)
{
	const Byte& operand = state.registers.h;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 6)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_6_L(State& state)
{
	const Byte& operand = state.registers.l;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 6)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_6_MEM_AT_HL(State& state)
{
	const Byte& operand = state.memory.read(state.registers.hl);
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 6)) state.registers.resetZeroFlag();
	state.clockCycles += 12;
}

void Instructions::BIT_6_A(State& state)
{
	const Byte& operand = state.registers.a;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 6)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_7_B(State& state)
{
	const Byte& operand = state.registers.b;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 7)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_7_C(State& state)
{
	const Byte& operand = state.registers.c;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 7)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_7_D(State& state)
{
	const Byte& operand = state.registers.d;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 7)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_7_E(State& state)
{
	const Byte& operand = state.registers.e;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 7)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_7_H(State& state)
{
	const Byte& operand = state.registers.h;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 7)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_7_L(State& state)
{
	const Byte& operand = state.registers.l;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 7)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::BIT_7_MEM_AT_HL(State& state)
{
	const Byte& operand = state.memory.read(state.registers.hl);
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 7)) state.registers.resetZeroFlag();
	state.clockCycles += 12;
}

void Instructions::BIT_7_A(State& state)
{
	const Byte& operand = state.registers.a;
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (operand & (1 << 7)) state.registers.resetZeroFlag();
	state.clockCycles += 8;
}

void Instructions::RES_0_B(State& state)
{
	state.registers.b &= ~(1 << 0);
	state.clockCycles += 8;
}

void Instructions::RES_0_C(State& state)
{
	state.registers.c &= ~(1 << 0);
	state.clockCycles += 8;
}

void Instructions::RES_0_D(State& state)
{
	state.registers.d &= ~(1 << 0);
	state.clockCycles += 8;
}

void Instructions::RES_0_E(State& state)
{
	state.registers.e &= ~(1 << 0);
	state.clockCycles += 8;
}

void Instructions::RES_0_H(State& state)
{
	state.registers.h &= ~(1 << 0);
	state.clockCycles += 8;
}

void Instructions::RES_0_L(State& state)
{
	state.registers.l &= ~(1 << 0);
	state.clockCycles += 8;
}

void Instructions::RES_0_MEM_AT_HL(State& state)
{
	state.memory.write(state.registers.hl, state.memory.read(state.registers.hl) & ~(1 << 0));
	state.clockCycles += 16;
}

void Instructions::RES_0_A(State& state)
{
	state.registers.a &= ~(1 << 0);
	state.clockCycles += 8;
}

void Instructions::RES_1_B(State& state)
{
	state.registers.b &= ~(1 << 1);
	state.clockCycles += 8;
}

void Instructions::RES_1_C(State& state)
{
	state.registers.c &= ~(1 << 1);
	state.clockCycles += 8;
}

void Instructions::RES_1_D(State& state)
{
	state.registers.d &= ~(1 << 1);
	state.clockCycles += 8;
}

void Instructions::RES_1_E(State& state)
{
	state.registers.e &= ~(1 << 1);
	state.clockCycles += 8;
}

void Instructions::RES_1_H(State& state)
{
	state.registers.h &= ~(1 << 1);
	state.clockCycles += 8;
}

void Instructions::RES_1_L(State& state)
{
	state.registers.l &= ~(1 << 1);
	state.clockCycles += 8;
}

void Instructions::RES_1_MEM_AT_HL(State& state)
{
	state.memory.write(state.registers.hl, state.memory.read(state.registers.hl) & ~(1 << 1));
	state.clockCycles += 16;
}

void Instructions::RES_1_A(State& state)
{
	state.registers.a &= ~(1 << 1);
	state.clockCycles += 8;
}

void Instructions::RES_2_B(State& state)
{
	state.registers.b &= ~(1 << 2);
	state.clockCycles += 8;
}

void Instructions::RES_2_C(State& state)
{
	state.registers.c &= ~(1 << 2);
	state.clockCycles += 8;
}

void Instructions::RES_2_D(State& state)
{
	state.registers.d &= ~(1 << 2);
	state.clockCycles += 8;
}

void Instructions::RES_2_E(State& state)
{
	state.registers.e &= ~(1 << 2);
	state.clockCycles += 8;
}

void Instructions::RES_2_H(State& state)
{
	state.registers.h &= ~(1 << 2);
	state.clockCycles += 8;
}

void Instructions::RES_2_L(State& state)
{
	state.registers.l &= ~(1 << 2);
	state.clockCycles += 8;
}

void Instructions::RES_2_MEM_AT_HL(State& state)
{
	state.memory.write(state.registers.hl, state.memory.read(state.registers.hl) & ~(1 << 2));
	state.clockCycles += 16;
}

void Instructions::RES_2_A(State& state)
{
	state.registers.a &= ~(1 << 2);
	state.clockCycles += 8;
}

void Instructions::RES_3_B(State& state)
{
	state.registers.b &= ~(1 << 3);
	state.clockCycles += 8;
}

void Instructions::RES_3_C(State& state)
{
	state.registers.c &= ~(1 << 3);
	state.clockCycles += 8;
}

void Instructions::RES_3_D(State& state)
{
	state.registers.d &= ~(1 << 3);
	state.clockCycles += 8;
}

void Instructions::RES_3_E(State& state)
{
	state.registers.e &= ~(1 << 3);
	state.clockCycles += 8;
}

void Instructions::RES_3_H(State& state)
{
	state.registers.h &= ~(1 << 3);
	state.clockCycles += 8;
}

void Instructions::RES_3_L(State& state)
{
	state.registers.l &= ~(1 << 3);
	state.clockCycles += 8;
}

void Instructions::RES_3_MEM_AT_HL(State& state)
{
	state.memory.write(state.registers.hl, state.memory.read(state.registers.hl) & ~(1 << 3));
	state.clockCycles += 16;
}

void Instructions::RES_3_A(State& state)
{
	state.registers.a &= ~(1 << 3);
	state.clockCycles += 8;
}

void Instructions::RES_4_B(State& state)
{
	state.registers.b &= ~(1 << 4);
	state.clockCycles += 8;
}

void Instructions::RES_4_C(State& state)
{
	state.registers.c &= ~(1 << 4);
	state.clockCycles += 8;
}

void Instructions::RES_4_D(State& state)
{
	state.registers.d &= ~(1 << 4);
	state.clockCycles += 8;
}

void Instructions::RES_4_E(State& state)
{
	state.registers.e &= ~(1 << 4);
	state.clockCycles += 8;
}

void Instructions::RES_4_H(State& state)
{
	state.registers.h &= ~(1 << 4);
	state.clockCycles += 8;
}

void Instructions::RES_4_L(State& state)
{
	state.registers.l &= ~(1 << 4);
	state.clockCycles += 8;
}

void Instructions::RES_4_MEM_AT_HL(State& state)
{
	state.memory.write(state.registers.hl, state.memory.read(state.registers.hl) & ~(1 << 4));
	state.clockCycles += 16;
}

void Instructions::RES_4_A(State& state)
{
	state.registers.a &= ~(1 << 4);
	state.clockCycles += 8;
}

void Instructions::RES_5_B(State& state)
{
	state.registers.b &= ~(1 << 5);
	state.clockCycles += 8;
}

void Instructions::RES_5_C(State& state)
{
	state.registers.c &= ~(1 << 5);
	state.clockCycles += 8;
}

void Instructions::RES_5_D(State& state)
{
	state.registers.d &= ~(1 << 5);
	state.clockCycles += 8;
}

void Instructions::RES_5_E(State& state)
{
	state.registers.e &= ~(1 << 5);
	state.clockCycles += 8;
}

void Instructions::RES_5_H(State& state)
{
	state.registers.h &= ~(1 << 5);
	state.clockCycles += 8;
}

void Instructions::RES_5_L(State& state)
{
	state.registers.l &= ~(1 << 5);
	state.clockCycles += 8;
}

void Instructions::RES_5_MEM_AT_HL(State& state)
{
	state.memory.write(state.registers.hl, state.memory.read(state.registers.hl) & ~(1 << 5));
	state.clockCycles += 16;
}

void Instructions::RES_5_A(State& state)
{
	state.registers.a &= ~(1 << 5);
	state.clockCycles += 8;
}

void Instructions::RES_6_B(State& state)
{
	state.registers.b &= ~(1 << 6);
	state.clockCycles += 8;
}

void Instructions::RES_6_C(State& state)
{
	state.registers.c &= ~(1 << 6);
	state.clockCycles += 8;
}

void Instructions::RES_6_D(State& state)
{
	state.registers.d &= ~(1 << 6);
	state.clockCycles += 8;
}

void Instructions::RES_6_E(State& state)
{
	state.registers.e &= ~(1 << 6);
	state.clockCycles += 8;
}

void Instructions::RES_6_H(State& state)
{
	state.registers.h &= ~(1 << 6);
	state.clockCycles += 8;
}

void Instructions::RES_6_L(State& state)
{
	state.registers.l &= ~(1 << 6);
	state.clockCycles += 8;
}

void Instructions::RES_6_MEM_AT_HL(State& state)
{
	state.memory.write(state.registers.hl, state.memory.read(state.registers.hl) & ~(1 << 6));
	state.clockCycles += 16;
}

void Instructions::RES_6_A(State& state)
{
	state.registers.a &= ~(1 << 6);
	state.clockCycles += 8;
}

void Instructions::RES_7_B(State& state)
{
	state.registers.b &= ~(1 << 7);
	state.clockCycles += 8;
}

void Instructions::RES_7_C(State& state)
{
	state.registers.c &= ~(1 << 7);
	state.clockCycles += 8;
}

void Instructions::RES_7_D(State& state)
{
	state.registers.d &= ~(1 << 7);
	state.clockCycles += 8;
}

void Instructions::RES_7_E(State& state)
{
	state.registers.e &= ~(1 << 7);
	state.clockCycles += 8;
}

void Instructions::RES_7_H(State& state)
{
	state.registers.h &= ~(1 << 7);
	state.clockCycles += 8;
}

void Instructions::RES_7_L(State& state)
{
	state.registers.l &= ~(1 << 7);
	state.clockCycles += 8;
}

void Instructions::RES_7_MEM_AT_HL(State& state)
{
	state.memory.write(state.registers.hl, state.memory.read(state.registers.hl) & ~(1 << 7));
	state.clockCycles += 16;
}

void Instructions::RES_7_A(State& state)
{
	state.registers.a &= ~(1 << 7);
	state.clockCycles += 8;
}

void Instructions::SET_0_B(State& state)
{
	state.registers.b |= 1 << 0;
	state.clockCycles += 8;
}

void Instructions::SET_0_C(State& state)
{
	state.registers.c |= 1 << 0;
	state.clockCycles += 8;
}

void Instructions::SET_0_D(State& state)
{
	state.registers.d |= 1 << 0;
	state.clockCycles += 8;
}

void Instructions::SET_0_E(State& state)
{
	state.registers.e |= 1 << 0;
	state.clockCycles += 8;
}

void Instructions::SET_0_H(State& state)
{
	state.registers.h |= 1 << 0;
	state.clockCycles += 8;
}

void Instructions::SET_0_L(State& state)
{
	state.registers.l |= 1 << 0;
	state.clockCycles += 8;
}

void Instructions::SET_0_MEM_AT_HL(State& state)
{
	state.memory.write(state.registers.hl, state.memory.read(state.registers.hl) | (1 << 0));
	state.clockCycles += 16;
}

void Instructions::SET_0_A(State& state)
{
	state.registers.a |= 1 << 0;
	state.clockCycles += 8;
}

void Instructions::SET_1_B(State& state)
{
	state.registers.b |= 1 << 1;
	state.clockCycles += 8;
}

void Instructions::SET_1_C(State& state)
{
	state.registers.c |= 1 << 1;
	state.clockCycles += 8;
}

void Instructions::SET_1_D(State& state)
{
	state.registers.d |= 1 << 1;
	state.clockCycles += 8;
}

void Instructions::SET_1_E(State& state)
{
	state.registers.e |= 1 << 1;
	state.clockCycles += 8;
}

void Instructions::SET_1_H(State& state)
{
	state.registers.h |= 1 << 1;
	state.clockCycles += 8;
}

void Instructions::SET_1_L(State& state)
{
	state.registers.l |= 1 << 1;
	state.clockCycles += 8;
}

void Instructions::SET_1_MEM_AT_HL(State& state)
{
	state.memory.write(state.registers.hl, state.memory.read(state.registers.hl) | (1 << 1));
	state.clockCycles += 16;
}

void Instructions::SET_1_A(State& state)
{
	state.registers.a |= 1 << 1;
	state.clockCycles += 8;
}

void Instructions::SET_2_B(State& state)
{
	state.registers.b |= 1 << 2;
	state.clockCycles += 8;
}

void Instructions::SET_2_C(State& state)
{
	state.registers.c |= 1 << 2;
	state.clockCycles += 8;
}

void Instructions::SET_2_D(State& state)
{
	state.registers.d |= 1 << 2;
	state.clockCycles += 8;
}

void Instructions::SET_2_E(State& state)
{
	state.registers.e |= 1 << 2;
	state.clockCycles += 8;
}

void Instructions::SET_2_H(State& state)
{
	state.registers.h |= 1 << 2;
	state.clockCycles += 8;
}

void Instructions::SET_2_L(State& state)
{
	state.registers.l |= 1 << 2;
	state.clockCycles += 8;
}

void Instructions::SET_2_MEM_AT_HL(State& state)
{
	state.memory.write(state.registers.hl, state.memory.read(state.registers.hl) | (1 << 2));
	state.clockCycles += 16;
}

void Instructions::SET_2_A(State& state)
{
	state.registers.a |= 1 << 2;
	state.clockCycles += 8;
}

void Instructions::SET_3_B(State& state)
{
	state.registers.b |= 1 << 3;
	state.clockCycles += 8;
}

void Instructions::SET_3_C(State& state)
{
	state.registers.c |= 1 << 3;
	state.clockCycles += 8;
}

void Instructions::SET_3_D(State& state)
{
	state.registers.d |= 1 << 3;
	state.clockCycles += 8;
}

void Instructions::SET_3_E(State& state)
{
	state.registers.e |= 1 << 3;
	state.clockCycles += 8;
}

void Instructions::SET_3_H(State& state)
{
	state.registers.h |= 1 << 3;
	state.clockCycles += 8;
}

void Instructions::SET_3_L(State& state)
{
	state.registers.l |= 1 << 3;
	state.clockCycles += 8;
}

void Instructions::SET_3_MEM_AT_HL(State& state)
{
	state.memory.write(state.registers.hl, state.memory.read(state.registers.hl) | (1 << 3));
	state.clockCycles += 16;
}

void Instructions::SET_3_A(State& state)
{
	state.registers.a |= 1 << 3;
	state.clockCycles += 8;
}

void Instructions::SET_4_B(State& state)
{
	state.registers.b |= 1 << 4;
	state.clockCycles += 8;
}

void Instructions::SET_4_C(State& state)
{
	state.registers.c |= 1 << 4;
	state.clockCycles += 8;
}

void Instructions::SET_4_D(State& state)
{
	state.registers.d |= 1 << 4;
	state.clockCycles += 8;
}

void Instructions::SET_4_E(State& state)
{
	state.registers.e |= 1 << 4;
	state.clockCycles += 8;
}

void Instructions::SET_4_H(State& state)
{
	state.registers.h |= 1 << 4;
	state.clockCycles += 8;
}

void Instructions::SET_4_L(State& state)
{
	state.registers.l |= 1 << 4;
	state.clockCycles += 8;
}

void Instructions::SET_4_MEM_AT_HL(State& state)
{
	state.memory.write(state.registers.hl, state.memory.read(state.registers.hl) | (1 << 4));
	state.clockCycles += 16;
}

void Instructions::SET_4_A(State& state)
{
	state.registers.a |= 1 << 4;
	state.clockCycles += 8;
}

void Instructions::SET_5_B(State& state)
{
	state.registers.b |= 1 << 5;
	state.clockCycles += 8;
}

void Instructions::SET_5_C(State& state)
{
	state.registers.c |= 1 << 5;
	state.clockCycles += 8;
}

void Instructions::SET_5_D(State& state)
{
	state.registers.d |= 1 << 5;
	state.clockCycles += 8;
}

void Instructions::SET_5_E(State& state)
{
	state.registers.e |= 1 << 5;
	state.clockCycles += 8;
}

void Instructions::SET_5_H(State& state)
{
	state.registers.h |= 1 << 5;
	state.clockCycles += 8;
}

void Instructions::SET_5_L(State& state)
{
	state.registers.l |= 1 << 5;
	state.clockCycles += 8;
}

void Instructions::SET_5_MEM_AT_HL(State& state)
{
	state.memory.write(state.registers.hl, state.memory.read(state.registers.hl) | (1 << 5));
	state.clockCycles += 16;
}

void Instructions::SET_5_A(State& state)
{
	state.registers.a |= 1 << 5;
	state.clockCycles += 8;
}

void Instructions::SET_6_B(State& state)
{
	state.registers.b |= 1 << 6;
	state.clockCycles += 8;
}

void Instructions::SET_6_C(State& state)
{
	state.registers.c |= 1 << 6;
	state.clockCycles += 8;
}

void Instructions::SET_6_D(State& state)
{
	state.registers.d |= 1 << 6;
	state.clockCycles += 8;
}

void Instructions::SET_6_E(State& state)
{
	state.registers.e |= 1 << 6;
	state.clockCycles += 8;
}

void Instructions::SET_6_H(State& state)
{
	state.registers.h |= 1 << 6;
	state.clockCycles += 8;
}

void Instructions::SET_6_L(State& state)
{
	state.registers.l |= 1 << 6;
	state.clockCycles += 8;
}

void Instructions::SET_6_MEM_AT_HL(State& state)
{
	state.memory.write(state.registers.hl, state.memory.read(state.registers.hl) | (1 << 6));
	state.clockCycles += 16;
}

void Instructions::SET_6_A(State& state)
{
	state.registers.a |= 1 << 6;
	state.clockCycles += 8;
}

void Instructions::SET_7_B(State& state)
{
	state.registers.b |= 1 << 7;
	state.clockCycles += 8;
}

void Instructions::SET_7_C(State& state)
{
	state.registers.c |= 1 << 7;
	state.clockCycles += 8;
}

void Instructions::SET_7_D(State& state)
{
	state.registers.d |= 1 << 7;
	state.clockCycles += 8;
}

void Instructions::SET_7_E(State& state)
{
	state.registers.e |= 1 << 7;
	state.clockCycles += 8;
}

void Instructions::SET_7_H(State& state)
{
	state.registers.h |= 1 << 7;
	state.clockCycles += 8;
}

void Instructions::SET_7_L(State& state)
{
	state.registers.l |= 1 << 7;
	state.clockCycles += 8;
}

void Instructions::SET_7_MEM_AT_HL(State& state)
{
	state.memory.write(state.registers.hl, state.memory.read(state.registers.hl) | (1 << 7));
	state.clockCycles += 16;
}

void Instructions::SET_7_A(State& state)
{
	state.registers.a |= 1 << 7;
	state.clockCycles += 8;
}
