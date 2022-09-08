#ifndef LIBGBEMU_MEMORY_HPP
#define LIBGBEMU_MEMORY_HPP

#include <libgbemu/types.hpp>
#include <exception>

#define LIBGEMU_MEMORY_SIZE 0x10000

struct Registers
{
	Byte a;
	Byte f;
	Byte b;
	Byte c;
	Byte d;
	Byte e;
	Byte h;
	Byte l;
	Word sp;
	Word pc;
};

class Memory
{
private:
	// all mapped memory, includes ram and vram and rom
	Byte map[LIBGEMU_MEMORY_SIZE];
public:
	Registers registers;

	Memory();
	Byte& at(const Word& address);
};


#endif //LIBGBEMU_MEMORY_HPP
