#ifndef LIBGREBE_VRAM_HPP
#define LIBGREBE_VRAM_HPP
#include <array>
#include <libgrebe/common/addressable.hpp>

class VRAM : public Addressable
{
private:
	std::array<Byte, 8192> mem;

public:
	// contains; returns whether address belongs to this addressable
	bool contains(Word address) const override;
	// read; attempts to read a byte at a given address
	Byte read(Word address) const override;
	// write; attempts to write a byte at a given address
	void write(Word address, Byte data) override;
};

#endif // LIBGREBE_VRAM_HPP
