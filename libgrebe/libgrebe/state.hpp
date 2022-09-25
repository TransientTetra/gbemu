#ifndef LIBGREBE_STATE_HPP
#define LIBGREBE_STATE_HPP

#include <libgrebe/registers.hpp>
#include <libgrebe/memory.hpp>

class State
{
public:
	bool imeScheduled = false;
	bool ime = true;
	unsigned long long clockCycles = 0;
	Registers registers;
	Memory memory;

	bool operator==(const State& other) const;

	State& operator=(const State& other);

};


#endif //LIBGREBE_STATE_HPP
