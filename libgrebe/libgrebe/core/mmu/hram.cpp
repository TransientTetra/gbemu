#include <libgrebe/core/mmu/hram.hpp>

bool HRAM::contains(Word address) const
{
	return address >= 0xFF80 && address <= 0xFFFE;
}

Byte HRAM::read(Word address) const
{
	return mem.at(address - 0xFF80);
}

void HRAM::write(Word address, Byte data)
{
	mem.at(address - 0xFF80) = data;
}
