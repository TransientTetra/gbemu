#include <libgrebe/core/cpu/cpu.hpp>
#include <libgrebe/core/cpu/decoder.hpp>
#include <libgrebe/core/interrupt_handler.hpp>

void CPU::tick()
{
    if ((state.clockCycles + 1) % 4)
        return;
    switch (state.cpuState)
    {
        case FETCH:
            fetch();
            break;
        case EXECUTE:
            execute();
            break;
        case HALT:
            halt();
            break;
        case HALT_BUG:
            haltBug();
            break;
        case STOP:
            stop();
            break;
        default:
            throw IllegalCPUStateException();
    }
}

void CPU::fetch()
{
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
    execute(); // microops executed immediately, on the same m-cycle as fetch
}

void CPU::execute()
{
    state.cpuQueue.front()(state);
    state.cpuQueue.pop();
    if (state.cpuState == EXECUTE && state.cpuQueue.empty())
        state.cpuState = FETCH;
}

void CPU::stop()
{
    // state.clockCycles -= 4;
    // const Byte& joypad = state.memory.read(LIBGREBE_REG_P1);
    // if (~joypad & 0b00110000 && ~joypad & 0b1111)
    // {
    // 	if (state.cpuQueue.empty())
    // 		state.cpuState = FETCH_AND_DECODE;
    // 	else
    // 		state.cpuState = EXECUTE;
    // }
}

void CPU::halt()
{
    // const Byte& IE = state.memory.read(LIBGREBE_REG_IE);
    // const Byte& IF = state.memory.read(LIBGREBE_REG_IF);
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

void CPU::haltBug()
{
    // todo
}
