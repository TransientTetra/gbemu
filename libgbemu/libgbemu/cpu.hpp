#ifndef LIBGBEMU_CPU_HPP
#define LIBGBEMU_CPU_HPP
#include <libgbemu/types.hpp>
#include <libgbemu/state.hpp>

//Sharp LR35902 SOC
//Sharp SM83 CPU
class CPU
{
private:
public:
	void execute(State& state);
};


#endif //LIBGBEMU_CPU_HPP
