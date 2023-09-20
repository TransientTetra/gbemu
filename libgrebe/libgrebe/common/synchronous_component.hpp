#ifndef LIBGREBE_SYNCHRONOUS_COMPONENT_HPP
#define LIBGREBE_SYNCHRONOUS_COMPONENT_HPP

// interface for clock-controlled components
class SynchronousComponent
{
public:
    virtual ~SynchronousComponent(){};
    // tick represents action for one t-clock
    virtual void tick() = 0;
};

#endif // LIBGREBE_SYNCHRONOUS_COMPONENT_HPP
