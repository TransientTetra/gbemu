#ifndef LIBGREBE_INTERRUPT_HANDLER_HPP
#define LIBGREBE_INTERRUPT_HANDLER_HPP

#include <libgrebe/common/state_mutator.hpp>
#include <libgrebe/common/synchronous_component.hpp>
#include <libgrebe/state.hpp>

struct IllegalInterruptHandlerStateException : public std::exception
{
    [[nodiscard]] const char* what() const noexcept override
    {
        return "Illegal interrupt handler state";
    }
};

class InterruptHandler : public SynchronousComponent, public StateMutator
{
    using StateMutator::StateMutator;

private:
    void cycle1();
    void cycle2();
    void cycle3();
    void cycle4();
    void cycle5();

public:
    void tick() override;
};

#endif // LIBGREBE_INTERRUPT_HANDLER_HPP
