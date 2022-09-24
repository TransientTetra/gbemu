#include <libgrebe/cpu.hpp>

void CPU::handleUndefinedOpcode(State& state)
{
	throw UndefinedOpcodeException();
}

void CPU::execute(State& state)
{
	if (state.imeScheduled)
	{
		state.imeScheduled = false;
		state.ime = true;
	}
	Memory& memory = state.memory;
	Registers& registers = state.registers;
	const Byte& currentInstruction = memory.read(registers.pc++);
	decode(state, currentInstruction);
	if (state.ime)
	{
		const Byte& IE = memory.read(LIBGREBE_REG_IE);
		const Byte& IF = memory.read(LIBGREBE_REG_IF);
		if (IE & IF)
		{
			state.ime = false;
			Byte jumpVector;
			if (IE >> 0 & 1 && IF >> 0 & 1)
			{
				jumpVector = LIBGREBE_INT_VBLANK;
				memory.write(LIBGREBE_REG_IF, IF & ~(1 << 0));
			}
			if (IE >> 1 & 1 && IF >> 1 & 1)
			{
				jumpVector = LIBGREBE_INT_STAT;
				memory.write(LIBGREBE_REG_IF, IF & ~(1 << 1));
			}
			if (IE >> 2 & 1 && IF >> 2 & 1)
			{
				jumpVector = LIBGREBE_INT_TIMER;
				memory.write(LIBGREBE_REG_IF, IF & ~(1 << 2));
			}
			if (IE >> 3 & 1 && IF >> 3 & 1)
			{
				jumpVector = LIBGREBE_INT_SERIAL;
				memory.write(LIBGREBE_REG_IF, IF & ~(1 << 3));
			}
			if (IE >> 4 & 1 && IF >> 4 & 1)
			{
				jumpVector = LIBGREBE_INT_JOYPAD;
				memory.write(LIBGREBE_REG_IF, IF & ~(1 << 4));
			}
			state.registers.sp -= 2;
			memory.writeWord(state.registers.sp, state.registers.pc);
			state.registers.pc = jumpVector;
		}
	}
}

