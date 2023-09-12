#ifndef LIBGREBE_CORE_HPP
#define LIBGREBE_CORE_HPP

#include <libgrebe/common/synchronous_component.hpp>
#include <libgrebe/core/cpu/cpu.hpp>
#include <libgrebe/core/ppu/ppu.hpp>

// todo add hardware registers addressable along with the logic to turn off the bootrom
// (remove it from the vector? do it like in tigris?); ime in state as a bool?? should be an addressable in mmu, no?
// Sharp LR35902 SOC models the whole system on a chip
class Core : public SynchronousComponent
{
private:
    CPU cpu;
    PPU ppu;
    State state;
    void tick() override;
    void initCommon();

public:
    // initialize Core without bootrom file
    Core();
    // initialize Core with bootrom file
    Core(const std::string& bootromPath);
    void run(bool& run);
};

#endif // LIBGREBE_CORE_HPP
