#include <libgrebe/core/core.hpp>
#include <string>

int main(int argc, char** argv)
{
	if (argc > 1)
	{
		Core core(argv[1]);
		bool alive = true;
		core.run(alive);
	}
	else
	{
		Core core;
		bool alive = true;
		core.run(alive);
	}
	return 0;
}
