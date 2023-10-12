#include <filesystem>
#include <fstream>
#include <libgrebe/memory_loader.hpp>
#include <vector>

void MemoryLoader::LoadBootRom(MMU& memory, const std::string& path)
{
	if (std::filesystem::exists(path))
	{
		std::ifstream input(path, std::ios::binary);
		std::vector<Byte> buf(std::istreambuf_iterator<char>(input), {});
		if (buf.size() != 256)
			throw InvalidBootRomException();
		for (int i = 0; i < 256; ++i)
		{
			memory.write(i, buf.at(i));
		}
	}
	else
		throw InvalidBootRomException();
}
