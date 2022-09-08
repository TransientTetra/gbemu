#include "memory.hpp"

Memory::Memory()
{
	registers.pc = 0x100;
	registers.sp = 0xfffe;
}

Byte& Memory::at(const Word& address)
{
	return map[address];
}
