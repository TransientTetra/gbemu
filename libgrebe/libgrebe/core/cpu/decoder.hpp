#ifndef LIBGREBE_DECODER_HPP
#define LIBGREBE_DECODER_HPP
#include <functional>
#include <libgrebe/core/cpu/instructions.hpp>
#include <libgrebe/state.hpp>

class Decoder
{
public:
	static std::function<void(State&)> decode(const std::uint8_t& opcode);
	static std::function<void(State&)> decodeCB(const std::uint8_t& opcode);
};

#endif // LIBGREBE_DECODER_HPP
