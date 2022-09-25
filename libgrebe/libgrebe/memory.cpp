#include <libgrebe/memory.hpp>

const Byte& Memory::read(const Word& address) const
{
	return map[address];
}

void Memory::write(const Word& address, const Byte& data)
{
	map[address] = data;
}

bool Memory::operator==(const Memory& other) const
{
	for (int i = 0; i < LIBGREBE_MEMORY_SIZE; ++i)
	{
		if (read(i) != other.read(i)) return false;
	}
	return true;
}

Memory& Memory::operator=(const Memory& other) // NOLINT(bugprone-unhandled-self-assignment)
{
	for (int i = 0; i < LIBGREBE_MEMORY_SIZE; ++i)
	{
		write(i, other.read(i));
	}
	return *this;
}

Word Memory::readWord(const Word& address) const
{
	return 0x0000 | (read(address + 1) << 8) | read(address);
}

void Memory::writeWord(const Word& address, const Word& data)
{
	write(address, static_cast<Byte>(0x00ff & data));
	write(address + 1, static_cast<Byte>(data >> 8));
}
