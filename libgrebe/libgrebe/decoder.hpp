#ifndef LIBGREBE_DECODER_HPP
#define LIBGREBE_DECODER_HPP
#include <functional>
#include <libgrebe/state.hpp>
#include <libgrebe/instructions.hpp>

class Decoder
{
public:
	static std::function<void(State&)> decode(const Byte& opcode);
	static std::function<void(State&)> decodeCB(const Byte& opcode);
};


#endif //LIBGREBE_DECODER_HPP
