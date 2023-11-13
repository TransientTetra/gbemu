#include <libgrebe/core/cpu/control_unit.hpp>
#include <libgrebe/core/cpu/decoder.hpp>
#include <libgrebe/core/cpu/interrupt_handler.hpp>

void ControlUnit::tick()
{
	if ((state.clockCycles + 1) % 4)
		return;
	switch (state.controlUnitState)
	{
		case LIBGREBE_CONTROL_UNIT_STATE_FETCH:
			fetch();
			break;
		case LIBGREBE_CONTROL_UNIT_STATE_EXECUTE:
			execute();
			break;
		case LIBGREBE_CONTROL_UNIT_STATE_HALT:
			halt();
			break;
		case LIBGREBE_CONTROL_UNIT_STATE_HALT_BUG:
			haltBug();
			break;
		case LIBGREBE_CONTROL_UNIT_STATE_STOP:
			stop();
			break;
		default:
			throw IllegalCPUStateException();
	}
}

void ControlUnit::fetch()
{
	// fetch
	const std::uint8_t& opcode = state.mmu.read(state.registers.getPC());
	state.registers.incPC();
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
	state.controlUnitState = LIBGREBE_CONTROL_UNIT_STATE_EXECUTE;
	execute(); // microops executed immediately, on the same m-cycle as fetch
}

void ControlUnit::execute()
{
	state.cpuQueue.front()(state);
	state.cpuQueue.pop();
	if (state.controlUnitState == LIBGREBE_CONTROL_UNIT_STATE_EXECUTE && state.cpuQueue.empty())
		state.controlUnitState = LIBGREBE_CONTROL_UNIT_STATE_FETCH;
}

void ControlUnit::stop()
{
	// state.clockCycles -= 4;
	// const std::uint8_t& joypad = state.memory.read(LIBGREBE_REG_P1);
	// if (~joypad & 0b00110000 && ~joypad & 0b1111)
	// {
	// 	if (state.cpuQueue.empty())
	// 		state.cpuState = FETCH_AND_DECODE;
	// 	else
	// 		state.cpuState = EXECUTE;
	// }
}

void ControlUnit::halt()
{
	// const std::uint8_t& IE = state.memory.read(LIBGREBE_REG_IE);
	// const std::uint8_t& IF = state.memory.read(LIBGREBE_REG_IF);
	// if (state.ime && (IE & IF & 0x1f))
	// {
	// 	state.cpuState = INTERRUPT_HANDLER;
	// 	InterruptHandler::tick(state);
	// 	return;
	// }
	// else if (!state.ime && (IE & IF & 0x1f))
	// {
	// 	if (state.cpuQueue.empty())
	// 		state.cpuState = FETCH_AND_DECODE;
	// 	else
	// 		state.cpuState = EXECUTE;
	// 	machineCycle(state);
	// }
}

void ControlUnit::haltBug()
{
	// todo
}
