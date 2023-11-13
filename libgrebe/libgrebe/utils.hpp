#ifndef LIBGREBE_UTILS_HPP
#define LIBGREBE_UTILS_HPP

#include <cstdint>

std::uint16_t toWord(const std::uint8_t& lsb, const std::uint8_t& msb);
std::uint8_t lsb(const std::uint16_t& word);
std::uint8_t msb(const std::uint16_t& word);

#endif // LIBGREBE_UTILS_HPP
