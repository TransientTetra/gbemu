#include <libgrebe/core/core.hpp>
#include <libgrebe/memory_loader.hpp>

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        State state;
        MemoryLoader ml;
        ml.LoadBootRom(state.memory, argv[1]);
        state.registers.pc = 0;
        Core core(state);
        while (true)
        {
            core.tick();
        }
    }
    return 0;
}
