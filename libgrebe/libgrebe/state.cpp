#include <libgrebe/state.hpp>

bool State::operator==(const State& other) const
{
	return registers == other.registers && memory == other.memory && ime == other.ime &&
	       imeScheduled == other.imeScheduled && clockCycles == other.clockCycles;
}

State& State::operator=(const State& other)
= default;
