#include <libgrebe/cpu.hpp>
#include <libgrebe/decoder.hpp>

void CPU::execute(State& state)
{
	// stop
	if (state.stop)
	{
		const Byte& joypad = state.memory.read(LIBGREBE_REG_P1);
		if (~joypad & 0b00110000 && ~joypad & 0b1111)
			state.stop = false;
		else
			return;
	}
	// interrupt handling
	const Byte& IE = state.memory.read(LIBGREBE_REG_IE);
	const Byte& IF = state.memory.read(LIBGREBE_REG_IF);
	if (state.ime && (IE & IF & 0x1f))
	{
		if (state.halt)
		{
			state.clockCycles += 4;
			state.halt = false;
		}
		state.clockCycles += 20;
		state.ime = false;
		Byte jumpVector;
		if (IE >> 0 & 1 && IF >> 0 & 1)
		{
			jumpVector = LIBGREBE_INT_VBLANK;
			state.memory.write(LIBGREBE_REG_IF, IF & ~(1 << 0));
		}
		else if (IE >> 1 & 1 && IF >> 1 & 1)
		{
			jumpVector = LIBGREBE_INT_STAT;
			state.memory.write(LIBGREBE_REG_IF, IF & ~(1 << 1));
		}
		else if (IE >> 2 & 1 && IF >> 2 & 1)
		{
			jumpVector = LIBGREBE_INT_TIMER;
			state.memory.write(LIBGREBE_REG_IF, IF & ~(1 << 2));
		}
		else if (IE >> 3 & 1 && IF >> 3 & 1)
		{
			jumpVector = LIBGREBE_INT_SERIAL;
			state.memory.write(LIBGREBE_REG_IF, IF & ~(1 << 3));
		}
		else// if (IE >> 4 & 1 && IF >> 4 & 1)
		{
			jumpVector = LIBGREBE_INT_JOYPAD;
			state.memory.write(LIBGREBE_REG_IF, IF & ~(1 << 4));
		}
		state.registers.sp -= 2;
		state.memory.writeWord(state.registers.sp, state.registers.pc);
		state.registers.pc = jumpVector;
		return;
	}
	// halt
	if (state.halt)
	{
		state.clockCycles += 4; // is this true? if not it should be under below if
		if (!state.ime && (IE & IF & 0x1f))
		{
			state.halt = false;
		}
		else
			return;
	}
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
}

