#include <libgrebe/core/mmu/wram.hpp>

bool WRAM::contains(std::uint16_t address) const
{
	return address >= 0xC000 && address <= 0xDFFF;
}

std::uint8_t WRAM::read(std::uint16_t address) const
{
	return mem.at(address - 0xC000);
}

void WRAM::write(std::uint16_t address, std::uint8_t data)
{
	mem.at(address - 0xC000) = data;
}
