#ifndef LIBGREBE_REGISTERS_HPP
#define LIBGREBE_REGISTERS_HPP

#include <libgrebe/types.hpp>

class Registers
{
private:
    Byte bytes[12];

public:
#ifdef LIBGREBE_LITTLE_ENDIAN
    Byte& a = bytes[1];
    Byte& f = bytes[0];
    Byte& b = bytes[3];
    Byte& c = bytes[2];
    Byte& d = bytes[5];
    Byte& e = bytes[4];
    Byte& h = bytes[7];
    Byte& l = bytes[6];
#else  // LIBGREBE_LITTLE_ENDIAN
    Byte& a = bytes[0];
    Byte& f = bytes[1];
    Byte& b = bytes[2];
    Byte& c = bytes[3];
    Byte& d = bytes[4];
    Byte& e = bytes[5];
    Byte& h = bytes[6];
    Byte& l = bytes[7];
#endif // LIBGREBE_LITTLE_ENDIAN
    Word& sp = reinterpret_cast<Word&>(bytes[8]);
    Word& pc = reinterpret_cast<Word&>(bytes[10]);

    Word& af = reinterpret_cast<Word&>(bytes[0]);
    Word& bc = reinterpret_cast<Word&>(bytes[2]);
    Word& de = reinterpret_cast<Word&>(bytes[4]);
    Word& hl = reinterpret_cast<Word&>(bytes[6]);

    Registers();

    void clearFlags();

    bool getZeroFlag();

    void setZeroFlag();

    void resetZeroFlag();

    bool getSubtractFlag();

    void setSubtractFlag();

    void resetSubtractFlag();

    bool getHalfCarryFlag();

    void setHalfCarryFlag();

    void resetHalfCarryFlag();

    bool getCarryFlag();

    void setCarryFlag();

    void resetCarryFlag();

    bool operator==(const Registers& other) const;

    Registers& operator=(const Registers& other);
};

#endif // LIBGREBE_REGISTERS_HPP
