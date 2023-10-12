#include <libgrebe/core/mmu/wram.hpp>

bool WRAM::contains(const Word& address) const
{
	return address >= 0xC000 && address <= 0xDFFF;
}

const Byte& WRAM::read(const Word& address) const
{
	return mem.at(address - 0xC000);
}

void WRAM::write(const Word& address, const Byte& data)
{
	mem.at(address - 0xC000) = data;
}
