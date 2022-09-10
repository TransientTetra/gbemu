#ifndef LIBGBEMU_CPU_HPP
#define LIBGBEMU_CPU_HPP
#include <libgbemu/types.hpp>
#include <libgbemu/memory.hpp>
#include <libgbemu/registers.hpp>

//Sharp LR35902 SOC
//Sharp SM83 CPU
class CPU
{
private:
public:
	void execute(Registers& registers, Memory& memory);
};


#endif //LIBGBEMU_CPU_HPP
