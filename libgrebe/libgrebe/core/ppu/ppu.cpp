#include <libgrebe/core/ppu/ppu.hpp>

void PPU::tick()
{
	switch (state.ppuState)
	{
		case LIBGREBE_PPU_STATE_HBLANK:
			hblank();
			break;
		case LIBGREBE_PPU_STATE_VBLANK:
			vblank();
			break;
		case LIBGREBE_PPU_STATE_OAM_SCAN:
			oamScan();
			break;
		case LIBGREBE_PPU_STATE_DRAW:
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
