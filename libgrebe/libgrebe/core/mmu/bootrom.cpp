#include <libgrebe/core/mmu/bootrom.hpp>

bool Bootrom::contains(const Word& address) const
{
    return address >= 0 && address <= 0xFF;
}

const Byte& Bootrom::read(const Word& address) const
{
    return rom.at(address);
}

void Bootrom::write(const Word& address, const Byte& data)
{
    // bootrom in DMG is readonly, but we allow writes here to load it from a file
    rom.at(address) = data;
}
