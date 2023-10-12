#include <libgrebe/core/ppu/ppu.hpp>

void PPU::tick()
{
	switch (state.ppuState)
	{
		case HBLANK:
			hblank();
			break;
		case VBLANK:
			vblank();
			break;
		case OAM_SCAN:
			oamScan();
			break;
		case DRAW:
			draw();
			break;
		default:
			throw IllegalPPUStateException();
	}
}

void PPU::hblank()
{
}

void PPU::vblank()
{
}

void PPU::oamScan()
{
}

void PPU::draw()
{
}
