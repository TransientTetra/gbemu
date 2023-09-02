#ifndef LIBGREBE_CPU_HPP
#define LIBGREBE_CPU_HPP
#include <libgrebe/common/state_mutator.hpp>
#include <libgrebe/common/synchronous_component.hpp>
#include <libgrebe/core/cpu/control_unit.hpp>
#include <libgrebe/core/cpu/interrupt_handler.hpp>

// Sharp SM83 CPU, control unit + interrupt handler
class CPU : public SynchronousComponent, public StateMutator
{
private:
    ControlUnit controlUnit;
    InterruptHandler interruptHandler;

public:
    CPU(State& state);
    void tick() override;
};

#endif // LIBGREBE_CPU_HPP
