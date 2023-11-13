#ifndef LIBGREBE_BOOTROM_HPP
#define LIBGREBE_BOOTROM_HPP

#include <array>
#include <libgrebe/common/addressable.hpp>

class Bootrom : public Addressable
{
private:
	static const std::uint8_t defaultRead = 0;
	bool enabled = true;
	std::array<std::uint8_t, 256> rom;

public:
	// contains; returns whether address belongs to this addressable
	bool contains(std::uint16_t address) const override;
	// read; attempts to read a byte at a given address
	std::uint8_t read(std::uint16_t address) const override;
	// write; attempts to write a byte at a given address
	void write(std::uint16_t address, std::uint8_t data) override;
};

#endif // LIBGREBE_BOOTROM_HPP
