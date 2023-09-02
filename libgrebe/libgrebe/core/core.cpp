#include <libgrebe/common/state_mutator.hpp>
#include <libgrebe/core/core.hpp>
#include <libgrebe/core/cpu/interrupt_handler.hpp>

Core::Core(State& state) : StateMutator(state), cpu(state), interruptHandler(state), ppu(state)
{
}

void Core::tick()
{
    const Byte& IE = state.memory.read(LIBGREBE_REG_IE);
    const Byte& IF = state.memory.read(LIBGREBE_REG_IF);
    if (state.imeScheduled)
    {
        state.imeScheduled = false;
        state.ime = true;
    }

    // possible that interrupts shouldn't be handled on the same tick as imeScheduled resolves to ime, in that case
    // add return in above if block (?)
    if (state.ime && (IE & IF & 0x1f))
    {
        // in interrupt handler
        interruptHandler.tick();
    }
    else
    {
        // normal cpu execution
        cpu.tick();
    }

    ppu.tick();
}
