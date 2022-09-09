#ifndef LIBGBEMU_CPU_HPP
#define LIBGBEMU_CPU_HPP
#include <libgbemu/types.hpp>
#include <libgbemu/memory.hpp>

struct Registers
{
	Byte a;
	Byte f;
	Byte b;
	Byte c;
	Byte d;
	Byte e;
	Byte h;
	Byte l;
	Word sp;
	Word pc;

	bool operator==(const Registers& other) const;
	Registers& operator=(const Registers& other);
};

//Sharp LR35902 SOC
//Sharp SM83 CPU
class CPU
{
private:
	Registers registers;

	Word readAF();
	void writeAF(const Word& data);
	Word readBC();
	void writeBC(const Word& data);
	Word readDE();
	void writeDE(const Word& data);
	Word readHL();
	void writeHL(const Word& data);

public:
	CPU();
	void execute(Memory& memory);
};


#endif //LIBGBEMU_CPU_HPP
