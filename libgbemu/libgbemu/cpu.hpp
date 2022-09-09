#ifndef LIBGBEMU_CPU_HPP
#define LIBGBEMU_CPU_HPP
#include <libgbemu/types.hpp>
#include <libgbemu/memory.hpp>

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

//Sharp LR35902 SOC
//Sharp SM83 CPU
class CPU
{
private:
	Registers registers;

public:
	CPU();
	void execute(Memory& memory);
};


#endif //LIBGBEMU_CPU_HPP
