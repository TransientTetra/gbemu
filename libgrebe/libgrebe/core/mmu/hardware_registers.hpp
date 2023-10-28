#ifndef LIBGREBE_HARDWARE_REGISTERS_HPP
#define LIBGREBE_HARDWARE_REGISTERS_HPP

#include <libgrebe/common/addressable.hpp>
#include <libgrebe/types.hpp>

class HardwareRegisters : public Addressable
{
	friend class Core;
	friend class Timer;
private:
	static const Byte defaultRead = 0xff;
	Byte P1;
	Byte SB;
	Byte SC;
	Word DIV_WIDE;
	Byte TIMA;
	Byte TMA;
	Byte TAC;
	Byte IF;
	Byte NR10;
	Byte NR11;
	Byte NR12;
	Byte NR13;
	Byte NR14;
	Byte NR21;
	Byte NR22;
	Byte NR23;
	Byte NR24;
	Byte NR30;
	Byte NR31;
	Byte NR32;
	Byte NR33;
	Byte NR34;
	Byte NR41;
	Byte NR42;
	Byte NR43;
	Byte NR44;
	Byte NR50;
	Byte NR51;
	Byte NR52;
	Byte LCDC;
	Byte STAT;
	Byte SCY;
	Byte SCX;
	Byte LY;
	Byte LYC;
	Byte DMA;
	Byte BGP;
	Byte OBP0;
	Byte OBP1;
	Byte WY;
	Byte WX;
	Byte IE;

public:
	// contains; returns whether address belongs to this addressable
	bool contains(Word address) const override;
	// read; attempts to read a byte at a given address
	Byte read(Word address) const override;
	// write; attempts to write a byte at a given address
	void write(Word address, Byte data) override;
};

#endif // LIBGREBE_HRAM_HPP
