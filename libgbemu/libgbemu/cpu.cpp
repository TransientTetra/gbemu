#include <libgbemu/cpu.hpp>

CPU::CPU()
{
	registers.pc = 0x100;
	registers.sp = 0xfffe;
}

void CPU::execute()
{

}
