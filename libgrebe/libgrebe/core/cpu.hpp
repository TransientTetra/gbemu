#ifndef LIBGREBE_CPU_HPP
#define LIBGREBE_CPU_HPP

#include <libgrebe/types.hpp>
#include <libgrebe/state.hpp>
#include <libgrebe/memory_locations.hpp>

struct IllegalCPUStateException : public std::exception
{
	[[nodiscard]] const char* what() const noexcept override
	{
		return "Illegal CPU state";
	}
};

//Sharp LR35902 SOC
//Sharp SM83 CPU
class CPU
{
private:
	static void fetchAndDecode(State& state);
	static void execute(State& state);
	static void stop(State& state);
	static void halt(State& state);
	static void haltBug(State& state);
public:
	static void tick(State& state);
};


#endif //LIBGREBE_CPU_HPP
