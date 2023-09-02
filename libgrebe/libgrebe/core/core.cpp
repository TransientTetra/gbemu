#include <libgrebe/core/core.hpp>

Core::Core(State& state) : StateMutator(state), cpu(state), ppu(state)
{
}

void Core::tick()
{
    cpu.tick();
    ppu.tick();
    // state.tick();
}
