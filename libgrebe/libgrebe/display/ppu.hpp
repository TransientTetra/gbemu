#ifndef LIBGREBE_PPU_HPP
#define LIBGREBE_PPU_HPP

#include <libgrebe/state.hpp>

struct IllegalPPUStateException : public std::exception
{
    [[nodiscard]] const char* what() const noexcept override
    {
        return "Illegal PPU state";
    }
};

class PPU
{
private:
    static void hblank(State& state);
    static void vblank(State& state);
    static void oamScan(State& state);
    static void draw(State& state);

public:
    static void tick(State& state);
};

#endif // LIBGREBE_PPU_HPP
