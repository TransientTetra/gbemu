#include <libgrebe/core/mmu/hram.hpp>

bool HRAM::contains(std::uint16_t address) const
{
	return address >= 0xFF80 && address <= 0xFFFE;
}

std::uint8_t HRAM::read(std::uint16_t address) const
{
	return mem.at(address - 0xFF80);
}

void HRAM::write(std::uint16_t address, std::uint8_t data)
{
	mem.at(address - 0xFF80) = data;
}
