#ifndef LIBGBEMU_CPU_HPP
#define LIBGBEMU_CPU_HPP
#include <libgbemu/types.hpp>

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

class CPU
{
private:

public:
	Registers registers;

	CPU();
	void execute();
};


#endif //LIBGBEMU_CPU_HPP
