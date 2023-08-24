#include <libgrebe/state.hpp>

bool State::operator==(const State& other) const
{
	bool res = true;
	res &= registers == other.registers;
	res &= memory == other.memory;
	res &= ime == other.ime;
	res &= imeScheduled == other.imeScheduled;
	res &= clockCycles == other.clockCycles;
	res &= tmp.size() == other.tmp.size();
	res &= cpuState == other.cpuState;
	res &= interruptHandlerState == other.interruptHandlerState;
//	res &= tmp1 == other.tmp1;
//	res &= tmp2 == other.tmp2;
//	res &= cpuQueue == other.cpuQueue;
	return  res;
}

State& State::operator=(const State& other)
= default;
