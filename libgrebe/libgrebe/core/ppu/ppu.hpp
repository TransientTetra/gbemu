#ifndef LIBGREBE_PPU_HPP
#define LIBGREBE_PPU_HPP

#include <libgrebe/common/synchronous_component.hpp>
#include <libgrebe/state.hpp>

struct IllegalPPUStateException : public std::exception
{
    [[nodiscard]] const char* what() const noexcept override
    {
        return "Illegal PPU state";
    }
};

class PPU : public SynchronousComponent
{
    using SynchronousComponent::SynchronousComponent;
private:
    void hblank();
    void vblank();
    void oamScan();
    void draw();

public:
    void tick();
};

#endif // LIBGREBE_PPU_HPP
