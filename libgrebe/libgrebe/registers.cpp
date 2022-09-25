#include <libgrebe/registers.hpp>

Registers::Registers()
{
	pc = 0;
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

void Registers::clearFlags()
{
	f &= 0b00001111;
}

bool Registers::getZeroFlag()
{
	return f & 0b10000000;
}

void Registers::setZeroFlag()
{
	f |= 0b10000000;
}

void Registers::resetZeroFlag()
{
	f &= 0b01111111;
}

bool Registers::getSubtractFlag()
{
	return f & 0b01000000;
}

void Registers::setSubtractFlag()
{
	f |= 0b01000000;
}

void Registers::resetSubtractFlag()
{
	f &= 0b10111111;
}

bool Registers::getHalfCarryFlag()
{
	return f & 0b00100000;
}

void Registers::setHalfCarryFlag()
{
	f |= 0b00100000;
}

void Registers::resetHalfCarryFlag()
{
	f &= 0b11011111;
}

bool Registers::getCarryFlag()
{
	return f & 0b00010000;
}

void Registers::setCarryFlag()
{
	f |= 0b00010000;
}

void Registers::resetCarryFlag()
{
	f &= 0b11101111;
}
