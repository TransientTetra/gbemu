#include <libgrebe/core/mmu/hram.hpp>

bool HRAM::contains(const Word& address) const
{
    return address >= 0xFF80 && address <= 0xFFFE;
}

const Byte& HRAM::read(const Word& address) const
{
    return mem.at(address - 0xFF80);
}

void HRAM::write(const Word& address, const Byte& data)
{
    mem.at(address - 0xFF80) = data;
}
