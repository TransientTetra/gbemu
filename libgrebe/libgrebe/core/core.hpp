#ifndef LIBGREBE_CORE_HPP
#define LIBGREBE_CORE_HPP
#include <libgrebe/common/state_mutator.hpp>
#include <libgrebe/common/synchronous_component.hpp>
#include <libgrebe/core/cpu/cpu.hpp>
#include <libgrebe/core/interrupt_handler.hpp>
#include <libgrebe/core/ppu/ppu.hpp>

// Sharp LR35902 SOC
// models the whole system on a chip
class Core : public SynchronousComponent, public StateMutator
{
private:
    CPU cpu;
    InterruptHandler interruptHandler;
    PPU ppu;

public:
    Core(State& state);
    void tick() override;
};

#endif // LIBGREBE_CORE_HPP
