#include <libgrebe/core/mmu/vram.hpp>

bool VRAM::contains(Word address) const
{
	return address >= 0x8000 && address <= 0x9FFF;
}

Byte VRAM::read(Word address) const
{
	// todo prevent reads and writes when pixel transfer happens
	return mem.at(address - 0x8000);
}

void VRAM::write(Word address, Byte data)
{
	mem.at(address - 0x8000) = data;
}
