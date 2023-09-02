#include <libgrebe/core/cpu/interrupt_handler.hpp>
#include <libgrebe/core/cpu/cpu.hpp>
#include <libgrebe/utils.hpp>

void InterruptHandler::tick()
{
    if ((state.clockCycles + 1) % 4)
        return;
    switch (state.interruptHandlerState)
    {
        case CYCLE1:
            cycle1();
            break;
        case CYCLE2:
            cycle2();
            break;
        case CYCLE3:
            cycle3();
            break;
        case CYCLE4:
            cycle4();
            break;
        case CYCLE5:
            cycle5();
            break;
        default:
            throw IllegalInterruptHandlerStateException();
    }
}

void InterruptHandler::cycle1()
{
    // NOP
    state.interruptHandlerState = CYCLE2;
}

void InterruptHandler::cycle2()
{
    // NOP
    state.interruptHandlerState = CYCLE3;
}

void InterruptHandler::cycle3()
{
    state.memory.write(--state.registers.sp, msb(state.registers.pc));
    state.interruptHandlerState = CYCLE4;
}

void InterruptHandler::cycle4()
{
    state.memory.write(--state.registers.sp, lsb(state.registers.pc));
    state.interruptHandlerState = CYCLE5;
}

void InterruptHandler::cycle5()
{
    state.ime = false;
    Byte jumpVector;
    const Byte& IE = state.memory.read(LIBGREBE_REG_IE);
    const Byte& IF = state.memory.read(LIBGREBE_REG_IF);
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
    else // if (IE >> 4 & 1 && IF >> 4 & 1)
    {
        jumpVector = LIBGREBE_INT_JOYPAD;
        state.memory.write(LIBGREBE_REG_IF, IF & ~(1 << 4));
    }
    state.registers.pc = jumpVector;
    state.interruptHandlerState = CYCLE1;
    state.cpuState = FETCH;
}
