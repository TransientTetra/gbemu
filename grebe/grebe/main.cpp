#include <libgrebe/memory_loader.hpp>
#include <libgrebe/core/cpu.hpp>

int main(int argc, char** argv)
{
	if (argc > 1)
	{
		State state;
		MemoryLoader ml;
		ml.LoadBootRom(state.memory, argv[1]);
		CPU cpu;
		cpu.execute2(state);
	}
	return 0;
}