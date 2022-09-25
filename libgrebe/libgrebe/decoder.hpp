#ifndef LIBGREBE_DECODER_HPP
#define LIBGREBE_DECODER_HPP
#include <libgrebe/state.hpp>
#include <libgrebe/instructions.hpp>

class Decoder
{
public:
	static Instruction decode(const Byte& opcode);
	static Instruction decodeCB(const Byte& opcode);
};


#endif //LIBGREBE_DECODER_HPP
