#include <libgrebe/core/cpu/interrupt_handler.hpp>
#include <libgrebe/utils.hpp>

void InterruptHandler::tick()
{
	if ((state.clockCycles + 1) % 4)
		return;
	switch (state.interruptHandlerState)
	{
		case LIBGREBE_INTERRUPT_HANDLER_STATE_CYCLE1:
			cycle1();
			break;
		case LIBGREBE_INTERRUPT_HANDLER_STATE_CYCLE2:
			cycle2();
			break;
		case LIBGREBE_INTERRUPT_HANDLER_STATE_CYCLE3:
			cycle3();
			break;
		case LIBGREBE_INTERRUPT_HANDLER_STATE_CYCLE4:
			cycle4();
			break;
		case LIBGREBE_INTERRUPT_HANDLER_STATE_CYCLE5:
			cycle5();
			break;
		default:
			throw IllegalInterruptHandlerStateException();
	}
}

void InterruptHandler::cycle1()
{
	// NOP
	state.interruptHandlerState = LIBGREBE_INTERRUPT_HANDLER_STATE_CYCLE2;
}

void InterruptHandler::cycle2()
{
	// NOP
	state.interruptHandlerState = LIBGREBE_INTERRUPT_HANDLER_STATE_CYCLE3;
}

void InterruptHandler::cycle3()
{
	state.registers.decSP();
	state.mmu.write(state.registers.getSP(), msb(state.registers.getPC()));
	state.interruptHandlerState = LIBGREBE_INTERRUPT_HANDLER_STATE_CYCLE4;
}

void InterruptHandler::cycle4()
{
	state.registers.decSP();
	state.mmu.write(state.registers.getSP(), lsb(state.registers.getPC()));
	state.interruptHandlerState = LIBGREBE_INTERRUPT_HANDLER_STATE_CYCLE5;
}

void InterruptHandler::cycle5()
{
	state.ime = false;
	Byte jumpVector;
	const Byte& IE = state.mmu.read(LIBGREBE_REG_IE);
	const Byte& IF = state.mmu.read(LIBGREBE_REG_IF);
	if (IE >> 0 & 1 && IF >> 0 & 1)
	{
		jumpVector = LIBGREBE_INT_VBLANK;
		state.mmu.write(LIBGREBE_REG_IF, IF & ~(1 << 0));
	}
	else if (IE >> 1 & 1 && IF >> 1 & 1)
	{
		jumpVector = LIBGREBE_INT_STAT;
		state.mmu.write(LIBGREBE_REG_IF, IF & ~(1 << 1));
	}
	else if (IE >> 2 & 1 && IF >> 2 & 1)
	{
		jumpVector = LIBGREBE_INT_TIMER;
		state.mmu.write(LIBGREBE_REG_IF, IF & ~(1 << 2));
	}
	else if (IE >> 3 & 1 && IF >> 3 & 1)
	{
		jumpVector = LIBGREBE_INT_SERIAL;
		state.mmu.write(LIBGREBE_REG_IF, IF & ~(1 << 3));
	}
	else // if (IE >> 4 & 1 && IF >> 4 & 1)
	{
		jumpVector = LIBGREBE_INT_JOYPAD;
		state.mmu.write(LIBGREBE_REG_IF, IF & ~(1 << 4));
	}
	state.registers.setPC(jumpVector);
	state.interruptHandlerState = LIBGREBE_INTERRUPT_HANDLER_STATE_CYCLE1;
	state.controlUnitState = LIBGREBE_CONTROL_UNIT_STATE_FETCH;
}
