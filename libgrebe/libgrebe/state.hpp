#ifndef LIBGREBE_STATE_HPP
#define LIBGREBE_STATE_HPP

#include <cstdint>
#include <functional>
#include <libgrebe/core/mmu/mmu.hpp>
#include <libgrebe/core/cpu/registers.hpp>
#include <queue>
#include <stack>

enum CPUState
{
    FETCH,
    EXECUTE,
    STOP,
    HALT,
    HALT_BUG,
};

enum InterruptHandlerState
{
    CYCLE1,
    CYCLE2,
    CYCLE3,
    CYCLE4,
    CYCLE5,
};

enum PPUState
{
    HBLANK,   // MODE0
    VBLANK,   // MODE1
    OAM_SCAN, // MODE2
    DRAW,     // MODE3
};

class State
{
public:
    std::queue<std::function<void(State&)>> cpuQueue;
    uint64_t clockCycles = 0; // this will overflow in 139 years @4MiHz, think we're fine
    CPUState cpuState = FETCH;
    InterruptHandlerState interruptHandlerState = CYCLE1;
    PPUState ppuState = OAM_SCAN;

    bool extendedOpcodeSet = false;
    bool imeScheduled = false;
    bool ime = false;
    std::stack<Byte> tmp;
    Registers registers;
    MMU mmu;

    bool operator==(const State& other) const;

    State& operator=(const State& other);
};

#endif // LIBGREBE_STATE_HPP
