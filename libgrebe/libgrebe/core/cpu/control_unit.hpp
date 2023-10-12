#ifndef LIBGREBE_CONTROL_UNIT_HPP
#define LIBGREBE_CONTROL_UNIT_HPP

#include <libgrebe/common/state_mutator.hpp>
#include <libgrebe/common/synchronous_component.hpp>

struct IllegalCPUStateException : public std::exception
{
	[[nodiscard]] const char* what() const noexcept override
	{
		return "Illegal CPU state";
	}
};

// Sharp SM83 CPU, control unit
class ControlUnit : public SynchronousComponent, public StateMutator
{
	using StateMutator::StateMutator;

private:
	void fetch();
	void execute();
	void stop();
	void halt();
	void haltBug();

public:
	void tick() override;
};

#endif // LIBGREBE_CONTROL_UNIT_HPP
