#include <libgrebe/utils.hpp>

std::uint16_t toWord(const std::uint8_t& lsb, const std::uint8_t& msb)
{
	return (static_cast<const std::uint16_t&>(msb) << 8) | lsb;
}

std::uint8_t lsb(const std::uint16_t& word)
{
	return word & 0xff;
}

std::uint8_t msb(const std::uint16_t& word)
{
	return word >> 8;
}
