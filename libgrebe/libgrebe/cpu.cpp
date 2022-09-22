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
}

