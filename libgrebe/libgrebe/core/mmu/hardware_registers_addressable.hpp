#ifndef LIBGREBE_HARDWARE_REGISTERS_ADDRESSABLE_HPP
#define LIBGREBE_HARDWARE_REGISTERS_ADDRESSABLE_HPP
#include <libgrebe/common/addressable.hpp>
#include <libgrebe/core/mmu/hardware_registers.hpp>

class HardwareRegistersAddressable : public Addressable
{
private:
	HardwareRegisters& hardwareRegisters;
	Byte defaultRead = 0xff;

public:
	HardwareRegistersAddressable(HardwareRegisters& hardwareRegisters);
	// contains; returns whether address belongs to this addressable
	bool contains(const Word& address) const override;
	// read; attempts to read a byte at a given address
	const Byte& read(const Word& address) const override;
	// write; attempts to write a byte at a given address
	void write(const Word& address, const Byte& data) override;
};

#endif // LIBGREBE_HARDWARE_REGISTERS_ADDRESSABLE_HPP
