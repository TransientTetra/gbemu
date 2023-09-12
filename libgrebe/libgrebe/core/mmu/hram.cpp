#include <libgrebe/core/mmu/hram.hpp>

bool HRAM::contains(const Word& address) const
{
    return address >= 0xC000 && address <= 0xDFFF;
}

const Byte& HRAM::read(const Word& address) const
{
    return mem.at(address - 0xC000);
}

void HRAM::write(const Word& address, const Byte& data)
{
    mem.at(address - 0xC000) = data;
}
