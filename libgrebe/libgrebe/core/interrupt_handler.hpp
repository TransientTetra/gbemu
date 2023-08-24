#ifndef LIBGREBE_INTERRUPT_HANDLER_HPP
#define LIBGREBE_INTERRUPT_HANDLER_HPP

#include <libgrebe/state.hpp>

struct IllegalInterruptHandlerStateException : public std::exception
{
    [[nodiscard]] const char* what() const noexcept override
    {
        return "Illegal interrupt handler state";
    }
};

class InterruptHandler
{
private:
    static void cycle1(State& state);
    static void cycle2(State& state);
    static void cycle3(State& state);
    static void cycle4(State& state);
    static void cycle5(State& state);

public:
    static void tick(State& state);
};

#endif // LIBGREBE_INTERRUPT_HANDLER_HPP
