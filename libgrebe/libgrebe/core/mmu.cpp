#include <libgrebe/core/mmu.hpp>
#include <libgrebe/utils.hpp>

MMU::MMU()
{
    write(LIBGREBE_REG_P1, 0xCF);
    write(LIBGREBE_REG_SB, 0x00);
    write(LIBGREBE_REG_SC, 0x7E);
    write(LIBGREBE_REG_DIV, 0xAB);
    write(LIBGREBE_REG_TIMA, 0x00);
    write(LIBGREBE_REG_TMA, 0x00);
    write(LIBGREBE_REG_TAC, 0xF8);
    write(LIBGREBE_REG_IF, 0xE1);
    write(LIBGREBE_REG_NR10, 0x80);
    write(LIBGREBE_REG_NR11, 0xBF);
    write(LIBGREBE_REG_NR12, 0xF3);
    write(LIBGREBE_REG_NR13, 0xFF);
    write(LIBGREBE_REG_NR14, 0xBF);
    write(LIBGREBE_REG_NR21, 0x3F);
    write(LIBGREBE_REG_NR22, 0x00);
    write(LIBGREBE_REG_NR23, 0xFF);
    write(LIBGREBE_REG_NR24, 0xBF);
    write(LIBGREBE_REG_NR30, 0x7F);
    write(LIBGREBE_REG_NR31, 0xFF);
    write(LIBGREBE_REG_NR32, 0x9F);
    write(LIBGREBE_REG_NR33, 0xFF);
    write(LIBGREBE_REG_NR34, 0xBF);
    write(LIBGREBE_REG_NR41, 0xFF);
    write(LIBGREBE_REG_NR42, 0x00);
    write(LIBGREBE_REG_NR43, 0x00);
    write(LIBGREBE_REG_NR44, 0xBF);
    write(LIBGREBE_REG_NR50, 0x77);
    write(LIBGREBE_REG_NR51, 0xF3);
    write(LIBGREBE_REG_NR52, 0xF1);
    write(LIBGREBE_REG_LCDC, 0x91);
    write(LIBGREBE_REG_STAT, 0x85);
    write(LIBGREBE_REG_SCY, 0x00);
    write(LIBGREBE_REG_SCX, 0x00);
    write(LIBGREBE_REG_LY, 0x00);
    write(LIBGREBE_REG_LYC, 0x00);
    write(LIBGREBE_REG_DMA, 0xFF);
    write(LIBGREBE_REG_BGP, 0xFC);
    write(LIBGREBE_REG_WY, 0x00);
    write(LIBGREBE_REG_WX, 0x00);
    write(LIBGREBE_REG_KEY1, 0xFF);
    write(LIBGREBE_REG_VBK, 0xFF);
    write(LIBGREBE_REG_HDMA1, 0xFF);
    write(LIBGREBE_REG_HDMA2, 0xFF);
    write(LIBGREBE_REG_HDMA3, 0xFF);
    write(LIBGREBE_REG_HDMA4, 0xFF);
    write(LIBGREBE_REG_HDMA5, 0xFF);
    write(LIBGREBE_REG_RP, 0xFF);
    write(LIBGREBE_REG_BCPS, 0xFF);
    write(LIBGREBE_REG_BCPD, 0xFF);
    write(LIBGREBE_REG_OCPS, 0xFF);
    write(LIBGREBE_REG_OCPD, 0xFF);
    write(LIBGREBE_REG_SVBK, 0xFF);
    write(LIBGREBE_REG_IE, 0x00);
}

const Byte& MMU::read(const Word& address) const
{
    return map[address];
}

void MMU::write(const Word& address, const Byte& data)
{
    map[address] = data;
}

bool MMU::operator==(const MMU& other) const
{
    for (int i = 0; i < LIBGREBE_MEMORY_SIZE; ++i)
    {
        if (read(i) != other.read(i))
            return false;
    }
    return true;
}

MMU& MMU::operator=(const MMU& other) // NOLINT(bugprone-unhandled-self-assignment)
{
    for (int i = 0; i < LIBGREBE_MEMORY_SIZE; ++i)
    {
        write(i, other.read(i));
    }
    return *this;
}
