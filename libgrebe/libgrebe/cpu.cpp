#include <libgrebe/cpu.hpp>
#include <libgrebe/decoder.hpp>

void CPU::execute(State& state)
{
	if (state.imeScheduled)
	{
		state.imeScheduled = false;
		state.ime = true;
	}
	// fetch
	const Byte& currentInstruction = state.memory.read(state.registers.pc++);
	// decode
	Instruction instruction;
	if (currentInstruction == 0xCB)
		instruction = Decoder::decodeCB(state.memory.read(state.registers.pc++));
	else
		instruction = Decoder::decode(currentInstruction);
	// execute
	instruction(state);
	if (state.ime)
	{
		const Byte& IE = state.memory.read(LIBGREBE_REG_IE);
		const Byte& IF = state.memory.read(LIBGREBE_REG_IF);
		if (IE & IF)
		{
			state.ime = false;
			Byte jumpVector;
			if (IE >> 0 & 1 && IF >> 0 & 1)
			{
				jumpVector = LIBGREBE_INT_VBLANK;
				state.memory.write(LIBGREBE_REG_IF, IF & ~(1 << 0));
			}
			if (IE >> 1 & 1 && IF >> 1 & 1)
			{
				jumpVector = LIBGREBE_INT_STAT;
				state.memory.write(LIBGREBE_REG_IF, IF & ~(1 << 1));
			}
			if (IE >> 2 & 1 && IF >> 2 & 1)
			{
				jumpVector = LIBGREBE_INT_TIMER;
				state.memory.write(LIBGREBE_REG_IF, IF & ~(1 << 2));
			}
			if (IE >> 3 & 1 && IF >> 3 & 1)
			{
				jumpVector = LIBGREBE_INT_SERIAL;
				state.memory.write(LIBGREBE_REG_IF, IF & ~(1 << 3));
			}
			if (IE >> 4 & 1 && IF >> 4 & 1)
			{
				jumpVector = LIBGREBE_INT_JOYPAD;
				state.memory.write(LIBGREBE_REG_IF, IF & ~(1 << 4));
			}
			state.registers.sp -= 2;
			state.memory.writeWord(state.registers.sp, state.registers.pc);
			state.registers.pc = jumpVector;
		}
	}
}

