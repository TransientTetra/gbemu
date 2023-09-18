#include <libgrebe/core/mmu/bootrom.hpp>
#include <libgrebe/memory_locations.hpp>

bool Bootrom::contains(const Word& address) const
{
    if (enabled)
        return (address >= 0 && address <= 0xFF) || address == LIBGREBE_REG_BOOTROM_DISABLE;
    else
        return false;
}

const Byte& Bootrom::read(const Word& address) const
{
    if (address == LIBGREBE_REG_BOOTROM_DISABLE)
        return defaultRead;
    return rom.at(address);
}

void Bootrom::write(const Word& address, const Byte& data)
{
    if (address == 0xFF50)
        enabled = false;
    // bootrom in DMG is readonly, but we allow writes here to load it from a file
    else
        rom.at(address) = data;
}
