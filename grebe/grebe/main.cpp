#include <libgrebe/core/cpu/cpu.hpp>
#include <libgrebe/memory_loader.hpp>

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        State state;
        MemoryLoader ml;
        ml.LoadBootRom(state.memory, argv[1]);
    }
    return 0;
}
