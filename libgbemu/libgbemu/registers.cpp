#include "registers.hpp"

Registers::Registers()
{
	pc = 0x100;
	sp = 0xfffe;
}

bool Registers::operator==(const Registers& other) const
{
	if (a != other.a) return false;
	if (f != other.f) return false;
	if (b != other.b) return false;
	if (c != other.c) return false;
	if (d != other.d) return false;
	if (e != other.e) return false;
	if (h != other.h) return false;
	if (l != other.l) return false;
	if (sp != other.sp) return false;
	if (pc != other.pc) return false;
	return true;
}

Registers& Registers::operator=(const Registers& other)
{
	a = other.a;
	f = other.f;
	b = other.b;
	c = other.c;
	d = other.d;
	e = other.e;
	h = other.h;
	l = other.l;
	sp = other.sp;
	pc = other.pc;
	return *this;
}
