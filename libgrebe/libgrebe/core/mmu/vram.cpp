#include <libgrebe/core/mmu/vram.hpp>

bool VRAM::contains(const Word& address) const
{
    return address >= 0x8000 && address <= 0x9FFF;
}

const Byte& VRAM::read(const Word& address) const
{
    // todo prevent reads and writes when pixel transfer happens
    return mem.at(address - 0x8000);
}

void VRAM::write(const Word& address, const Byte& data)
{
    mem.at(address - 0x8000) = data;
}
