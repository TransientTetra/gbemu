#include <libgrebe/display/ppu.hpp>

void PPU::tick(State& state)
{
	switch (state.ppuState)
	{
		case HBLANK:
			hblank(state);
			break;
		case VBLANK:
			vblank(state);
			break;
		case OAM_SCAN:
			oamScan(state);
			break;
		case DRAW:
			draw(state);
			break;
		default:
			throw IllegalPPUStateException();
	}
}

void PPU::hblank(State& state)
{
}

void PPU::vblank(State& state)
{
}

void PPU::oamScan(State& state)
{
}

void PPU::draw(State& state)
{
}
