#ifndef LIBGREBE_CPU_HPP
#define LIBGREBE_CPU_HPP

#include <libgrebe/types.hpp>
#include <libgrebe/state.hpp>
#include <exception>

//Sharp LR35902 SOC
//Sharp SM83 CPU
class CPU
{
private:

public:
	static void execute(State& state);
};


#endif //LIBGREBE_CPU_HPP
