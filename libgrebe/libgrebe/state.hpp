#ifndef LIBGREBE_STATE_HPP
#define LIBGREBE_STATE_HPP

#include <queue>
#include <functional>
#include <stack>
#include "libgrebe/core/registers.hpp"
#include "libgrebe/core/memory.hpp"

enum CPUState
{
	FETCH_AND_DECODE,
	EXECUTE,
	STOP,
	HALT,
	HALT_BUG,
	INTERRUPT_HANDLER,
};

enum InterruptHandlerState
{
	CYCLE1,
	CYCLE2,
	CYCLE3,
	CYCLE4,
	CYCLE5,
};

class State
{
public:
	std::queue<std::function<void(State&)>> cpuQueue;
	unsigned long long cpuClockCycles = 0;
	CPUState cpuState = FETCH_AND_DECODE;
	InterruptHandlerState interruptHandlerState = CYCLE1;

	bool extendedOpcodeSet = false;
	bool imeScheduled = false;
	bool ime = false;
	std::stack<Byte> tmp;
	Registers registers;
	Memory memory;

	bool operator==(const State& other) const;

	State& operator=(const State& other);

};


#endif //LIBGREBE_STATE_HPP
