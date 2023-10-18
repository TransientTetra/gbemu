#ifndef LIBGREBE_HRAM_HPP
#define LIBGREBE_HRAM_HPP
#include <array>
#include <libgrebe/common/addressable.hpp>

class HRAM : public Addressable
{
private:
	std::array<Byte, 127> mem;

public:
	// contains; returns whether address belongs to this addressable
	bool contains(Word address) const override;
	// read; attempts to read a byte at a given address
	Byte read(Word address) const override;
	// write; attempts to write a byte at a given address
	void write(Word address, Byte data) override;
};

#endif // LIBGREBE_HRAM_HPP
