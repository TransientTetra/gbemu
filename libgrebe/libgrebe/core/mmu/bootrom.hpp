#ifndef LIBGREBE_BOOTROM_HPP
#define LIBGREBE_BOOTROM_HPP

#include <array>
#include <libgrebe/common/addressable.hpp>

class Bootrom : public Addressable
{
private:
	static const Byte defaultRead = 0;
	bool enabled = true;
	std::array<Byte, 256> rom;

public:
	// contains; returns whether address belongs to this addressable
	bool contains(Word address) const override;
	// read; attempts to read a byte at a given address
	Byte read(Word address) const override;
	// write; attempts to write a byte at a given address
	void write(Word address, Byte data) override;
};

#endif // LIBGREBE_BOOTROM_HPP
