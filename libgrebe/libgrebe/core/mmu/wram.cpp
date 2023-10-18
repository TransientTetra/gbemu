#include <libgrebe/core/mmu/wram.hpp>

bool WRAM::contains(Word address) const
{
	return address >= 0xC000 && address <= 0xDFFF;
}

Byte WRAM::read(Word address) const
{
	return mem.at(address - 0xC000);
}

void WRAM::write(Word address, Byte data)
{
	mem.at(address - 0xC000) = data;
}
