#ifndef LIBGREBE_CPU_HPP
#define LIBGREBE_CPU_HPP

#include <libgrebe/common/synchronous_component.hpp>
#include <libgrebe/memory_locations.hpp>
#include <libgrebe/state.hpp>
#include <libgrebe/types.hpp>

struct IllegalCPUStateException : public std::exception
{
    [[nodiscard]] const char* what() const noexcept override
    {
        return "Illegal CPU state";
    }
};

// Sharp LR35902 SOC
// Sharp SM83 CPU
class CPU : public SynchronousComponent
{
    using SynchronousComponent::SynchronousComponent;

private:
    void fetchAndDecode();
    void execute();
    void stop();
    void halt();
    void haltBug();

public:
    void tick() override;
};

#endif // LIBGREBE_CPU_HPP
