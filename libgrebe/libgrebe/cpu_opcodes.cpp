#include <libgrebe/cpu.hpp>

void CPU::opcodeLD(Byte& op1, const Byte& op2)
{
	op1 = op2;
}

void CPU::opcodeLDmem(Memory& memory, const Word& address, const Byte& op2)
{
	memory.write(address, op2);
}

void CPU::opcodeLD16(State& state, Word& op1, const Word& op2)
{
	op1 = op2;
	state.registers.pc += 2;
}

void CPU::opcodeLD16mem(State& state, const Word& address, const Word& op2)
{
	state.memory.writeWord(address, op2);
	state.registers.pc += 2;
}

void CPU::opcodeLD16spe(State& state)
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
}

void CPU::opcodeLD16sphl(State& state)
{
	state.registers.sp = state.registers.hl;
}

void CPU::opcodePUSH(State& state, const Word& operand)
{
	state.registers.sp -= 2;
	state.memory.writeWord(state.registers.sp, operand);
}

void CPU::opcodePOP(State& state, Word& operand)
{
	operand = state.memory.readWord(state.registers.sp);
	state.registers.sp += 2;
}

void CPU::opcodeINC(State& state, Byte& operand)
{
	state.registers.resetZeroFlag();
	state.registers.resetSubtractFlag();
	state.registers.resetHalfCarryFlag();
	if (((operand & 0xf) + 1) & 0x10)
		state.registers.setHalfCarryFlag();
	operand += 1;
	if (operand == 0)
		state.registers.setZeroFlag();
}

void CPU::opcodeDEC(State& state, Byte& operand)
{
	state.registers.resetZeroFlag();
	state.registers.setSubtractFlag();
	state.registers.resetHalfCarryFlag();
	if (((operand & 0xf) - 1) & 0x10)
		state.registers.setHalfCarryFlag();
	operand -= 1;
	if (operand == 0)
		state.registers.setZeroFlag();
}

void CPU::opcodeADD(State& state, const Byte& operand)
{
	state.registers.clearFlags();
	if (((state.registers.a & 0xf) + (operand & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) + (operand & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a += operand;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
}

void CPU::opcodeADC(State& state, const Byte& operand)
{
	Byte carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (((state.registers.a & 0xf) + (operand & 0xf) + (carry & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) + (operand & 0xff) + (carry & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a += operand + carry;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
}

void CPU::opcodeSUB(State& state, const Byte& operand)
{
	state.registers.clearFlags();
	state.registers.setSubtractFlag();
	if (((state.registers.a & 0xf) - (operand & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) - (operand & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a -= operand;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
}

void CPU::opcodeSBC(State& state, const Byte& operand)
{
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
}

void CPU::opcodeAND(State& state, const Byte& operand)
{
	state.registers.a &= operand;
	state.registers.clearFlags();
	state.registers.setHalfCarryFlag();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
}

void CPU::opcodeXOR(State& state, const Byte& operand)
{
	state.registers.a ^= operand;
	state.registers.clearFlags();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
}

void CPU::opcodeOR(State& state, const Byte& operand)
{
	state.registers.a |= operand;
	state.registers.clearFlags();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
}

void CPU::opcodeCP(State& state, const Byte& operand)
{
	state.registers.clearFlags();
	state.registers.setSubtractFlag();
	if (((state.registers.a & 0xf) - (operand & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) - (operand & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	if (state.registers.a - operand == 0)
		state.registers.setZeroFlag();
}

void CPU::opcodeDAA(State& state)
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
}

void CPU::opcodeSCF(State& state)
{
	state.registers.resetSubtractFlag();
	state.registers.resetHalfCarryFlag();
	state.registers.setCarryFlag();
}

void CPU::opcodeCPL(State& state)
{
	state.registers.a = ~state.registers.a;
	state.registers.setSubtractFlag();
	state.registers.setHalfCarryFlag();
}

void CPU::opcodeCCF(State& state)
{
	state.registers.resetSubtractFlag();
	state.registers.resetHalfCarryFlag();
	if (state.registers.getCarryFlag())
		state.registers.resetCarryFlag();
	else
		state.registers.setCarryFlag();
}

void CPU::opcodeRLCA(State& state)
{
	state.registers.clearFlags();
	if (state.registers.a & 0b10000000) state.registers.setCarryFlag();
	state.registers.a = state.registers.a << 1 | (state.registers.a >> 7);
}

void CPU::opcodeRLA(State& state)
{
	bool carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (state.registers.a & 0b10000000) state.registers.setCarryFlag();
	state.registers.a = state.registers.a << 1 | carry;
}

void CPU::opcodeRRCA(State& state)
{
	state.registers.clearFlags();
	if (state.registers.a & 1) state.registers.setCarryFlag();
	state.registers.a = state.registers.a >> 1 | (state.registers.a << 7);
}

void CPU::opcodeRRA(State& state)
{
	bool carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (state.registers.a & 1) state.registers.setCarryFlag();
	state.registers.a = state.registers.a >> 1 | carry << 7;
}

void CPU::opcodeINChl(State& state)
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
}

void CPU::opcodeDEChl(State& state)
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
}

void CPU::opcodeRLC(Registers& registers, Byte& operand)
{
	registers.clearFlags();
	if (operand & 0b10000000) registers.setCarryFlag();
	operand = operand << 1 | (operand >> 7);
	if (operand == 0) registers.setZeroFlag();
}

void CPU::opcodeRRC(Registers& registers, Byte& operand)
{
	registers.clearFlags();
	if (operand & 1) registers.setCarryFlag();
	operand = operand >> 1 | (operand << 7);
	if (operand == 0) registers.setZeroFlag();
}

void CPU::opcodeRL(Registers& registers, Byte& operand)
{
	bool carry = registers.getCarryFlag();
	registers.clearFlags();
	if (operand & 0b10000000) registers.setCarryFlag();
	operand = operand << 1 | carry;
	if (operand == 0) registers.setZeroFlag();
}

void CPU::opcodeRR(Registers& registers, Byte& operand)
{
	bool carry = registers.getCarryFlag();
	registers.clearFlags();
	if (operand & 1) registers.setCarryFlag();
	operand = operand >> 1 | carry << 7;
	if (operand == 0) registers.setZeroFlag();
}

void CPU::opcodeSLA(Registers& registers, Byte& operand)
{
	registers.clearFlags();
	if (operand & 0b10000000) registers.setCarryFlag();
	operand = operand << 1;
	if (operand == 0) registers.setZeroFlag();
}

void CPU::opcodeSRA(Registers& registers, Byte& operand)
{
	registers.clearFlags();
	if (operand & 1) registers.setCarryFlag();
	operand = operand >> 1 | operand & 0b10000000;
	if (operand == 0) registers.setZeroFlag();
}

void CPU::opcodeSWAP(Registers& registers, Byte& operand)
{
	registers.clearFlags();
	operand = operand >> 4 | operand << 4;
	if (operand == 0) registers.setZeroFlag();
}

void CPU::opcodeSRL(Registers& registers, Byte& operand)
{
	registers.clearFlags();
	if (operand & 1) registers.setCarryFlag();
	operand = operand >> 1;
	if (operand == 0) registers.setZeroFlag();
}

void CPU::opcodeBIT(Registers& registers, const Byte& operand, Byte bit)
{
	registers.resetSubtractFlag();
	registers.setHalfCarryFlag();
	registers.setZeroFlag();
	if (operand & (1 << bit)) registers.resetZeroFlag();
}

void CPU::opcodeRES(Byte& operand, Byte bit)
{
	operand &= ~(1 << bit);
}

void CPU::opcodeSET(Byte& operand, Byte bit)
{
	operand |= 1 << bit;
}

void CPU::opcodeRLChl(State& state)
{
	const Byte& d = state.memory.read(state.registers.hl);
	state.registers.clearFlags();
	if (d & 0b10000000) state.registers.setCarryFlag();
	state.memory.write(state.registers.hl, d << 1 | (d >> 7));
	if (d == 0) state.registers.setZeroFlag();
}

void CPU::opcodeRRChl(State& state)
{
	const Byte& d = state.memory.read(state.registers.hl);
	state.registers.clearFlags();
	if (d & 1) state.registers.setCarryFlag();
	state.memory.write(state.registers.hl, d >> 1 | (d << 7));
	if (d == 0) state.registers.setZeroFlag();
}

void CPU::opcodeRLhl(State& state)
{
	const Byte& d = state.memory.read(state.registers.hl);
	bool carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (d & 0b10000000) state.registers.setCarryFlag();
	state.memory.write(state.registers.hl, d << 1 | carry);
	if (d == 0) state.registers.setZeroFlag();
}

void CPU::opcodeRRhl(State& state)
{
	const Byte& d = state.memory.read(state.registers.hl);
	bool carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (d & 1) state.registers.setCarryFlag();
	state.memory.write(state.registers.hl, d >> 1 | carry << 7);
	if (d == 0) state.registers.setZeroFlag();
}

void CPU::opcodeSLAhl(State& state)
{
	const Byte& d = state.memory.read(state.registers.hl);
	state.registers.clearFlags();
	if (d & 0b10000000) state.registers.setCarryFlag();
	state.memory.write(state.registers.hl, d << 1);
	if (d == 0) state.registers.setZeroFlag();
}

void CPU::opcodeSRAhl(State& state)
{
	const Byte& d = state.memory.read(state.registers.hl);
	state.registers.clearFlags();
	if (d & 1) state.registers.setCarryFlag();
	state.memory.write(state.registers.hl, d >> 1 | d & 0b10000000);
	if (d == 0) state.registers.setZeroFlag();
}

void CPU::opcodeSWAPhl(State& state)
{
	const Byte& d = state.memory.read(state.registers.hl);
	state.registers.clearFlags();
	state.memory.write(state.registers.hl, d >> 4 | d << 4);
	if (d == 0) state.registers.setZeroFlag();
}

void CPU::opcodeSRLhl(State& state)
{
	const Byte& d = state.memory.read(state.registers.hl);
	state.registers.clearFlags();
	if (d & 1) state.registers.setCarryFlag();
	state.memory.write(state.registers.hl, d >> 1);
	if (d == 0) state.registers.setZeroFlag();
}

void CPU::opcodeBIThl(State& state, Byte bit)
{
	const Byte& d = state.memory.read(state.registers.hl);
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (d & (1 << bit)) state.registers.resetZeroFlag();
}

void CPU::opcodeREShl(State& state, Byte bit)
{
	state.memory.write(state.registers.hl, state.memory.read(state.registers.hl) & ~(1 << bit));
}

void CPU::opcodeSEThl(State& state, Byte bit)
{
	state.memory.write(state.registers.hl, state.memory.read(state.registers.hl) | 1 << bit);
}

