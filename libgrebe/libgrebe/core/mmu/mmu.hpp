#ifndef LIBGREBE_MEMORY_HPP
#define LIBGREBE_MEMORY_HPP

#include <libgrebe/common/addressable.hpp>
#include <libgrebe/memory_locations.hpp>
#include <libgrebe/types.hpp>
#include <vector>

#define LIBGREBE_MEMORY_SIZE 0x10000

// Memory Management Unit; abstracts all memory accesses, including to memory mapped hardware
class MMU
{
private:
	static const Byte defaultRead = 0xff;
	// all mapped memory, includes ram and vram and rom
	std::vector<std::reference_wrapper<Addressable>> addressables;

public:
	void registerAddressable(Addressable& addressable);
	Byte read(Word address) const;
	void write(Word address, Byte data);

	MMU();
	MMU(const MMU&) = delete;
	MMU& operator=(const MMU&) = delete;
};

#endif // LIBGREBE_MEMORY_HPP
