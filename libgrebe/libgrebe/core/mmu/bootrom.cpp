#include <libgrebe/core/mmu/bootrom.hpp>
#include <libgrebe/memory_locations.hpp>

bool Bootrom::contains(std::uint16_t address) const
{
	if (enabled)
		return (address >= 0 && address <= 0xFF) || address == LIBGREBE_REG_BOOTROM_DISABLE;
	else
		return false;
}

std::uint8_t Bootrom::read(std::uint16_t address) const
{
	if (address == LIBGREBE_REG_BOOTROM_DISABLE)
		return defaultRead;
	return rom.at(address);
}

void Bootrom::write(std::uint16_t address, std::uint8_t data)
{
	if (address == 0xFF50)
		enabled = false;
	// bootrom in DMG is readonly, but we allow writes here to load it from a file
	else
		rom.at(address) = data;
}
