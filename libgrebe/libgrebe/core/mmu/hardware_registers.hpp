#ifndef LIBGREBE_HARDWARE_REGISTERS_HPP
#define LIBGREBE_HARDWARE_REGISTERS_HPP

#include <libgrebe/common/addressable.hpp>
#include <cstdint>

class HardwareRegisters : public Addressable
{
	friend class Core;
	friend class Timer;

private:
	static const std::uint8_t defaultRead = 0xff;
	std::uint8_t P1;
	std::uint8_t SB;
	std::uint8_t SC;
	std::uint16_t DIV_WIDE;
	std::uint8_t TIMA;
	std::uint8_t TMA;
	std::uint8_t TAC;
	std::uint8_t IF;
	std::uint8_t NR10;
	std::uint8_t NR11;
	std::uint8_t NR12;
	std::uint8_t NR13;
	std::uint8_t NR14;
	std::uint8_t NR21;
	std::uint8_t NR22;
	std::uint8_t NR23;
	std::uint8_t NR24;
	std::uint8_t NR30;
	std::uint8_t NR31;
	std::uint8_t NR32;
	std::uint8_t NR33;
	std::uint8_t NR34;
	std::uint8_t NR41;
	std::uint8_t NR42;
	std::uint8_t NR43;
	std::uint8_t NR44;
	std::uint8_t NR50;
	std::uint8_t NR51;
	std::uint8_t NR52;
	std::uint8_t LCDC;
	std::uint8_t STAT;
	std::uint8_t SCY;
	std::uint8_t SCX;
	std::uint8_t LY;
	std::uint8_t LYC;
	std::uint8_t DMA;
	std::uint8_t BGP;
	std::uint8_t OBP0;
	std::uint8_t OBP1;
	std::uint8_t WY;
	std::uint8_t WX;
	std::uint8_t IE;

public:
	// contains; returns whether address belongs to this addressable
	bool contains(std::uint16_t address) const override;
	// read; attempts to read a byte at a given address
	std::uint8_t read(std::uint16_t address) const override;
	// write; attempts to write a byte at a given address
	void write(std::uint16_t address, std::uint8_t data) override;
};

#endif // LIBGREBE_HRAM_HPP
