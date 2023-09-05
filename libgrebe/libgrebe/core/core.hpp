#ifndef LIBGREBE_CORE_HPP
#define LIBGREBE_CORE_HPP

#include <libgrebe/common/state_mutator.hpp>
#include <libgrebe/common/synchronous_component.hpp>
#include <libgrebe/core/cpu/cpu.hpp>
#include <libgrebe/core/ppu/ppu.hpp>

// Sharp LR35902 SOC
// models the whole system on a chip
class Core : public SynchronousComponent, public StateMutator
{
private:
    CPU cpu;
    PPU ppu;

public:
    Core(State& state);
    void tick() override;
    // initialize Core to the state after bootrom
    void init();
};

#endif // LIBGREBE_CORE_HPP
