#include <libgrebe/core/mmu/vram.hpp>

bool VRAM::contains(std::uint16_t address) const
{
	return address >= 0x8000 && address <= 0x9FFF;
}

std::uint8_t VRAM::read(std::uint16_t address) const
{
	// todo prevent reads and writes when pixel transfer happens
	return mem.at(address - 0x8000);
}

void VRAM::write(std::uint16_t address, std::uint8_t data)
{
	mem.at(address - 0x8000) = data;
}
