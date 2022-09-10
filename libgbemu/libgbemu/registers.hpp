#ifndef LIBGBEMU_REGISTERS_HPP
#define LIBGBEMU_REGISTERS_HPP
#include <libgbemu/types.hpp>

class Registers
{
private:
	Byte bytes[12];

public:
	Registers();

#ifdef LIBGBEMU_LITTLE_ENDIAN
	Byte& a = bytes[1];
	Byte& f = bytes[0];
	Byte& b = bytes[3];
	Byte& c = bytes[2];
	Byte& d = bytes[5];
	Byte& e = bytes[4];
	Byte& h = bytes[7];
	Byte& l = bytes[6];
#else // LIBGBEMU_LITTLE_ENDIAN
	Byte& a = bytes[0];
	Byte& f = bytes[1];
	Byte& b = bytes[2];
	Byte& c = bytes[3];
	Byte& d = bytes[4];
	Byte& e = bytes[5];
	Byte& h = bytes[6];
	Byte& l = bytes[7];
#endif // LIBGBEMU_LITTLE_ENDIAN
	Word& sp = reinterpret_cast<Word&>(bytes[8]);
	Word& pc = reinterpret_cast<Word&>(bytes[10]);

	Word& af = reinterpret_cast<Word&>(bytes[0]);
	Word& bc = reinterpret_cast<Word&>(bytes[2]);
	Word& de = reinterpret_cast<Word&>(bytes[4]);
	Word& hl = reinterpret_cast<Word&>(bytes[6]);

	bool operator==(const Registers& other) const;
	Registers& operator=(const Registers& other);
};


#endif //LIBGBEMU_REGISTERS_HPP
