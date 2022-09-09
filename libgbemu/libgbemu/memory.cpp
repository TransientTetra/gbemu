#include "memory.hpp"

const Byte& Memory::read(const Word& address)
{
	return map[address];
}

void Memory::write(const Word& address, const Byte& data)
{
	map[address] = data;
}

//void Memory::write(const Word& address, const Word& data)
//{
//	write(address, static_cast<Byte>(data >> 8));
//	write(address, static_cast<Byte>(data & 0x00ff));
//}
