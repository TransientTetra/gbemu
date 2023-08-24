#ifndef LIBGREBE_SYNCHRONOUS_COMPONENT_HPP
#define LIBGREBE_SYNCHRONOUS_COMPONENT_HPP

#include "libgrebe/state.hpp"

// interface for clock-controlled components; affecting global state
class SynchronousComponent
{
protected:
    State& state;

public:
    explicit SynchronousComponent(State& state) : state(state)
    {
    }
    // tick represents action for one t-clock
    virtual void tick() = 0;
};

#endif // LIBGREBE_SYNCHRONOUS_COMPONENT_HPP
