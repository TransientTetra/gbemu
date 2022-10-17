#ifndef LIBGREBE_MEMORY_HPP
#define LIBGREBE_MEMORY_HPP

#include <libgrebe/memory_locations.hpp>
#include <libgrebe/types.hpp>

#define LIBGREBE_MEMORY_SIZE 0x10000
class Memory
{
private:
	// all mapped memory, includes ram and vram and rom
	Byte map[LIBGREBE_MEMORY_SIZE];
public:
	Memory();
	[[nodiscard]] const Byte& read(const Word& address) const;
	[[nodiscard]] Word readWord(const Word& address) const;
	void write(const Word& address, const Byte& data);
	void writeWord(const Word& address, const Word& data);
	bool operator==(const Memory& other) const;
	Memory& operator=(const Memory& other);
};


#endif //LIBGREBE_MEMORY_HPP
