#ifndef LIBGBEMU_STATE_HPP
#define LIBGBEMU_STATE_HPP

#include <libgbemu/registers.hpp>
#include <libgbemu/memory.hpp>

class State
{
public:
	Registers registers;
	Memory memory;

	bool operator==(const State& other) const;

	State& operator=(const State& other);

};


#endif //LIBGBEMU_STATE_HPP
