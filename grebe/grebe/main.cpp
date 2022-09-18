#include <libgrebe/memory_loader.hpp>
#include <libgrebe/cpu.hpp>

int main(int argc, char** argv)
{
	if (argc > 1)
	{
		State state;
		MemoryLoader ml;
		ml.LoadBootRom(state.memory, argv[1]);
		CPU cpu;
		cpu.execute(state);
	}
	return 0;
}