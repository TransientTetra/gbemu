#include <libgrebe/core/core.hpp>
#include <libgrebe/core/mmu/bootrom.hpp>
#include <libgrebe/memory_loader.hpp>
#include <memory>

Core::Core() : cpu(state), ppu(state)
{
    // don't register bootrom here
    state.registers.a = 1;
    state.registers.setZeroFlag();
    state.registers.resetSubtractFlag();
    state.registers.resetHalfCarryFlag();
    state.registers.resetCarryFlag();
    state.registers.b = 0;
    state.registers.c = 0x13;
    state.registers.d = 0;
    state.registers.e = 0xd8;
    state.registers.h = 1;
    state.registers.l = 0x4d;
    state.registers.pc = 0x100;
    state.registers.sp = 0xfffe;

    state.mmu.write(LIBGREBE_REG_P1, 0xCF);
    state.mmu.write(LIBGREBE_REG_SB, 0x00);
    state.mmu.write(LIBGREBE_REG_SC, 0x7E);
    state.mmu.write(LIBGREBE_REG_DIV, 0xAB);
    state.mmu.write(LIBGREBE_REG_TIMA, 0x00);
    state.mmu.write(LIBGREBE_REG_TMA, 0x00);
    state.mmu.write(LIBGREBE_REG_TAC, 0xF8);
    state.mmu.write(LIBGREBE_REG_IF, 0xE1);
    state.mmu.write(LIBGREBE_REG_NR10, 0x80);
    state.mmu.write(LIBGREBE_REG_NR11, 0xBF);
    state.mmu.write(LIBGREBE_REG_NR12, 0xF3);
    state.mmu.write(LIBGREBE_REG_NR13, 0xFF);
    state.mmu.write(LIBGREBE_REG_NR14, 0xBF);
    state.mmu.write(LIBGREBE_REG_NR21, 0x3F);
    state.mmu.write(LIBGREBE_REG_NR22, 0x00);
    state.mmu.write(LIBGREBE_REG_NR23, 0xFF);
    state.mmu.write(LIBGREBE_REG_NR24, 0xBF);
    state.mmu.write(LIBGREBE_REG_NR30, 0x7F);
    state.mmu.write(LIBGREBE_REG_NR31, 0xFF);
    state.mmu.write(LIBGREBE_REG_NR32, 0x9F);
    state.mmu.write(LIBGREBE_REG_NR33, 0xFF);
    state.mmu.write(LIBGREBE_REG_NR34, 0xBF);
    state.mmu.write(LIBGREBE_REG_NR41, 0xFF);
    state.mmu.write(LIBGREBE_REG_NR42, 0x00);
    state.mmu.write(LIBGREBE_REG_NR43, 0x00);
    state.mmu.write(LIBGREBE_REG_NR44, 0xBF);
    state.mmu.write(LIBGREBE_REG_NR50, 0x77);
    state.mmu.write(LIBGREBE_REG_NR51, 0xF3);
    state.mmu.write(LIBGREBE_REG_NR52, 0xF1);
    state.mmu.write(LIBGREBE_REG_LCDC, 0x91);
    state.mmu.write(LIBGREBE_REG_STAT, 0x85);
    state.mmu.write(LIBGREBE_REG_SCY, 0x00);
    state.mmu.write(LIBGREBE_REG_SCX, 0x00);
    state.mmu.write(LIBGREBE_REG_LY, 0x00);
    state.mmu.write(LIBGREBE_REG_LYC, 0x00);
    state.mmu.write(LIBGREBE_REG_DMA, 0xFF);
    state.mmu.write(LIBGREBE_REG_BGP, 0xFC);
    state.mmu.write(LIBGREBE_REG_WY, 0x00);
    state.mmu.write(LIBGREBE_REG_WX, 0x00);
    state.mmu.write(LIBGREBE_REG_KEY1, 0xFF);
    state.mmu.write(LIBGREBE_REG_VBK, 0xFF);
    state.mmu.write(LIBGREBE_REG_HDMA1, 0xFF);
    state.mmu.write(LIBGREBE_REG_HDMA2, 0xFF);
    state.mmu.write(LIBGREBE_REG_HDMA3, 0xFF);
    state.mmu.write(LIBGREBE_REG_HDMA4, 0xFF);
    state.mmu.write(LIBGREBE_REG_HDMA5, 0xFF);
    state.mmu.write(LIBGREBE_REG_RP, 0xFF);
    state.mmu.write(LIBGREBE_REG_BCPS, 0xFF);
    state.mmu.write(LIBGREBE_REG_BCPD, 0xFF);
    state.mmu.write(LIBGREBE_REG_OCPS, 0xFF);
    state.mmu.write(LIBGREBE_REG_OCPD, 0xFF);
    state.mmu.write(LIBGREBE_REG_SVBK, 0xFF);
    state.mmu.write(LIBGREBE_REG_IE, 0x00);
}

Core::Core(const std::string& bootromPath) : cpu(state), ppu(state)
{
    // register bootrom here
    state.mmu.registerAddressable(std::make_unique<Bootrom>());
    MemoryLoader::LoadBootRom(state.mmu, bootromPath);
    state.registers.pc = 0x00;
}

void Core::tick()
{
    cpu.tick();
    ppu.tick();
    // state.tick();
}

void Core::run(bool& run)
{
    while (run)
    {
        tick();
    }
}
