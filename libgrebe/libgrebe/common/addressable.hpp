#ifndef LIBGREBE_ADDRESSABLE_HPP
#define LIBGREBE_ADDRESSABLE_HPP

#include <exception>
#include <cstdint>

struct IllegalAddressableReadException : public std::exception
{
	[[nodiscard]] const char* what() const noexcept override
	{
		return "Illegal read on addressable";
	}
};

struct IllegalAddressableWriteException : public std::exception
{
	[[nodiscard]] const char* what() const noexcept override
	{
		return "Illegal write on addressable";
	}
};

class Addressable
{
private:
public:
	virtual ~Addressable(){};
	// contains; returns whether address belongs to this addressable
	virtual bool contains(std::uint16_t address) const = 0;
	// read; attempts to read a byte at a given address
	virtual std::uint8_t read(std::uint16_t address) const = 0;
	// write; attempts to write a byte at a given address
	virtual void write(std::uint16_t address, std::uint8_t data) = 0;
};

#endif // LIBGREBE_ADDRESSABLE_HPP
