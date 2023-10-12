#ifndef LIBGREBE_STATE_MUTATOR_HPP
#define LIBGREBE_STATE_MUTATOR_HPP
#include <libgrebe/state.hpp>

// interface for components affecting global state
class StateMutator
{
protected:
	State& state;

public:
	virtual ~StateMutator(){};
	explicit StateMutator(State& state) : state(state)
	{
	}
};

#endif // LIBGREBE_STATE_MUTATOR_HPP
