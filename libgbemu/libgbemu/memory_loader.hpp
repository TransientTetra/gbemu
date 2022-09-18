#ifndef LIBGBEMU_MEMORY_LOADER_HPP
#define LIBGBEMU_MEMORY_LOADER_HPP
#include <libgbemu/memory.hpp>
#include <string>

struct InvalidBootRomException : public std::exception
{
	[[nodiscard]] const char* what() const noexcept override
	{
		return "Invalid boot rom file or file not found";
	}
};

class MemoryLoader
{
public:
	static void LoadBootRom(Memory& memory, const std::string& path);
};


#endif //LIBGBEMU_MEMORY_LOADER_HPP
