#include <libgrebe/core/cpu.hpp>
#include <libgrebe/core/decoder.hpp>
#include <libgrebe/core/interrupt_handler.hpp>

void CPU::tick(State& state)
{
	state.cpuClockCycles += 4;
	switch (state.cpuState)
	{
		case FETCH_AND_DECODE:
			fetchAndDecode(state);
			break;
		case EXECUTE:
			execute(state);
			break;
		case HALT:
			halt(state);
			break;
		case HALT_BUG:
			haltBug(state);
			break;
		case STOP:
			stop(state);
			break;
		case INTERRUPT_HANDLER:
			InterruptHandler::tick(state);
			break;
		default:
			throw IllegalCPUStateException();
	}
}

void CPU::fetchAndDecode(State& state)
{
	const Byte& IE = state.memory.read(LIBGREBE_REG_IE);
	const Byte& IF = state.memory.read(LIBGREBE_REG_IF);
	if (state.ime && (IE & IF & 0x1f))
	{
		state.cpuState = INTERRUPT_HANDLER;
		InterruptHandler::tick(state);
		return;
	}

	if (state.imeScheduled)
	{
		state.imeScheduled = false;
		state.ime = true;
	}
	// fetch
	const Byte& opcode = state.memory.read(state.registers.pc++);
	// decode
	std::function<void(State&)> loadMicroOps;
	if (state.extendedOpcodeSet)
	{
		loadMicroOps = Decoder::decodeCB(opcode);
		state.extendedOpcodeSet = false;
	}
	else
		loadMicroOps = Decoder::decode(opcode);
	// enqueue microoperations for the decoded instruction
	loadMicroOps(state);
	state.cpuState = EXECUTE;
	execute(state); // microops executed immediately, on the same m-cycle as fetch
}

void CPU::execute(State& state)
{
	state.cpuQueue.front()(state);
	state.cpuQueue.pop();
	if (state.cpuState == EXECUTE && state.cpuQueue.empty()) state.cpuState = FETCH_AND_DECODE;
}

void CPU::stop(State& state)
{
	state.cpuClockCycles -= 4;
	const Byte& joypad = state.memory.read(LIBGREBE_REG_P1);
	if (~joypad & 0b00110000 && ~joypad & 0b1111)
	{
		if (state.cpuQueue.empty())
			state.cpuState = FETCH_AND_DECODE;
		else
			state.cpuState = EXECUTE;
	}
}

void CPU::halt(State& state)
{
	const Byte& IE = state.memory.read(LIBGREBE_REG_IE);
	const Byte& IF = state.memory.read(LIBGREBE_REG_IF);
	if (state.ime && (IE & IF & 0x1f))
	{
		state.cpuState = INTERRUPT_HANDLER;
		InterruptHandler::tick(state);
		return;
	}
	else if (!state.ime && (IE & IF & 0x1f))
	{
		if (state.cpuQueue.empty())
			state.cpuState = FETCH_AND_DECODE;
		else
			state.cpuState = EXECUTE;
		tick(state);
	}
}

void CPU::haltBug(State& state)
{
	//todo
}


