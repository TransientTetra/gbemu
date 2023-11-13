#include <libgrebe/core/cpu/cpu.hpp>

CPU::CPU(State& state) : StateMutator(state), controlUnit(state), interruptHandler(state), timer(state)
{
}

void CPU::tick()
{
	timer.tick(); // here?
	const std::uint8_t& IE = state.mmu.read(LIBGREBE_REG_IE);
	const std::uint8_t& IF = state.mmu.read(LIBGREBE_REG_IF);
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
		controlUnit.tick();
	}
}
