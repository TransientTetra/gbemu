#ifndef LIBGREBE_HARDWARE_REGISTERS_ADDRESSABLE_HPP
#define LIBGREBE_HARDWARE_REGISTERS_ADDRESSABLE_HPP
#include <libgrebe/common/addressable.hpp>
#include <libgrebe/core/mmu/hardware_registers.hpp>

class HardwareRegistersAddressable : public Addressable
{
private:
	HardwareRegisters& hardwareRegisters;
	static const Byte defaultRead = 0xff;

public:
	HardwareRegistersAddressable(HardwareRegisters& hardwareRegisters);
	// contains; returns whether address belongs to this addressable
	bool contains(Word address) const override;
	// read; attempts to read a byte at a given address
	Byte read(Word address) const override;
	// write; attempts to write a byte at a given address
	void write(Word address, Byte data) override;
};

#endif // LIBGREBE_HARDWARE_REGISTERS_ADDRESSABLE_HPP
