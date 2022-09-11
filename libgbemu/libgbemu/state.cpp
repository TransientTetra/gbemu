#include <libgbemu/state.hpp>

bool State::operator==(const State& other) const
{
	return registers == other.registers && memory == other.memory;
}

State& State::operator=(const State& other)
= default;
