#ifndef LIBGREBE_INSTRUCTIONS_HPP
#define LIBGREBE_INSTRUCTIONS_HPP

#include <exception>
#include <libgrebe/state.hpp>

struct UndefinedOpcodeException : public std::exception
{
	[[nodiscard]] const char* what() const noexcept override
	{
		return "Undefined opcode";
	}
};

typedef void (*Instruction)(State& state);

class Instructions
{
private:
	std::array<Instruction, 512> instructions;
	// delete copy and move constructors and assign operators
	Instructions(Instructions const&) = delete;
	Instructions(Instructions&&) = delete;
	Instructions& operator=(Instructions const&) = delete;
	Instructions& operator=(Instructions&&) = delete;

public:
	Instructions();
	static Instructions& getInstance();

	Instruction& decode(std::uint8_t opcode);
	Instruction& decodeCB(std::uint8_t opcode);
};

#endif // LIBGREBE_INSTRUCTIONS_HPP
