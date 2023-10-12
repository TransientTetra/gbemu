#ifndef LIBGREBE_WRAM_HPP
#define LIBGREBE_WRAM_HPP
#include <array>
#include <libgrebe/common/addressable.hpp>

class WRAM : public Addressable
{
private:
	std::array<Byte, 8192> mem;

public:
	// contains; returns whether address belongs to this addressable
	bool contains(const Word& address) const override;
	// read; attempts to read a byte at a given address
	const Byte& read(const Word& address) const override;
	// write; attempts to write a byte at a given address
	void write(const Word& address, const Byte& data) override;
};

#endif // LIBGREBE_WRAM_HPP
