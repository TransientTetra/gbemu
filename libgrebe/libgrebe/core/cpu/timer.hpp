#ifndef LIBGREBE_TIMER_HPP
#define LIBGREBE_TIMER_HPP
#include <libgrebe/common/state_mutator.hpp>
#include <libgrebe/common/synchronous_component.hpp>

class Timer : public SynchronousComponent, public StateMutator
{
    using StateMutator::StateMutator;

private:
public:
    void tick() override;
};

#endif // LIBGREBE_TIMER_HPP
