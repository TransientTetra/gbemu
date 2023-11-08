#ifndef LIBGREBE_REGISTERS_HPP
#define LIBGREBE_REGISTERS_HPP

#include <libgrebe/types.hpp>

class Registers
{
private:
	Word af;
	Word bc;
	Word de;
	Word hl;
	Word sp;
	Word pc;

public:
	// clang-format off
	inline Byte getA() const { return af >> 8; }
	inline Byte getF() const { return af & 0x00ff; }
	inline Byte getB() const { return bc >> 8; }
	inline Byte getC() const { return bc & 0x00ff; }
	inline Byte getD() const { return de >> 8; }
	inline Byte getE() const { return de & 0x00ff; }
	inline Byte getH() const { return hl >> 8; }
	inline Byte getL() const { return hl & 0x00ff; }
	inline Word getAF() const { return af; }
	inline Word getBC() const { return bc; }
	inline Word getDE() const { return de; }
	inline Word getHL() const { return hl; }
	inline Word getSP() const { return sp; }
	inline Word getPC() const { return pc; }
	inline void setA(Byte val) { af = af & 0x00ff | (val << 8); }
	inline void setF(Byte val) { af = af & 0xff00 | val; }
	inline void setB(Byte val) { bc = bc & 0x00ff | (val << 8); }
	inline void setC(Byte val) { bc = bc & 0xff00 | val; }
	inline void setD(Byte val) { de = de & 0x00ff | (val << 8); }
	inline void setE(Byte val) { de = de & 0xff00 | val; }
	inline void setH(Byte val) { hl = hl & 0x00ff | (val << 8); }
	inline void setL(Byte val) { hl = hl & 0xff00 | val; }
	inline void setAF(Word val) { af = val; }
	inline void setBC(Word val) { bc = val; }
	inline void setDE(Word val) { de = val; }
	inline void setHL(Word val) { hl = val; }
	inline void setSP(Word val) { sp = val; }
	inline void setPC(Word val) { pc = val; }
	inline void incA() { af = (af & 0x00ff) | ((getA() + 1) << 8); }
	inline void incF() { af = (af & 0xff00) | (getF() + 1) & 0xff; }
	inline void incB() { bc = (bc & 0x00ff) | ((getB() + 1) << 8); }
	inline void incC() { bc = (bc & 0xff00) | (getC() + 1) & 0xff; }
	inline void incD() { de = (de & 0x00ff) | ((getD() + 1) << 8); }
	inline void incE() { de = (de & 0xff00) | (getE() + 1) & 0xff; }
	inline void incH() { hl = (hl & 0x00ff) | ((getH() + 1) << 8); }
	inline void incL() { hl = (hl & 0xff00) | (getL() + 1) & 0xff; }
	inline void incAF() { af += 1; }
	inline void incBC() { bc += 1; }
	inline void incDE() { de += 1; }
	inline void incHL() { hl += 1; }
	inline void incSP() { sp += 1; }
	inline void incPC() { pc += 1; }
	inline void decA() { af = (af & 0x00ff) | ((getA() - 1) << 8); }
	inline void decF() { af = (af & 0xff00) | (getF() - 1) & 0xff; }
	inline void decB() { bc = (bc & 0x00ff) | ((getB() - 1) << 8); }
	inline void decC() { bc = (bc & 0xff00) | (getC() - 1) & 0xff; }
	inline void decD() { de = (de & 0x00ff) | ((getD() - 1) << 8); }
	inline void decE() { de = (de & 0xff00) | (getE() - 1) & 0xff; }
	inline void decH() { hl = (hl & 0x00ff) | ((getH() - 1) << 8); }
	inline void decL() { hl = (hl & 0xff00) | (getL() - 1) & 0xff; }
	inline void decAF() { af -= 1; }
	inline void decBC() { bc -= 1; }
	inline void decDE() { de -= 1; }
	inline void decHL() { hl -= 1; }
	inline void decSP() { sp -= 1; }
	inline void decPC() { pc -= 1; }

	inline void clearFlags() { af &= 0b1111111100001111; }
	inline bool getZeroFlag() const { return af & 0b10000000; }
	inline bool getSubtractFlag() const { return af & 0b01000000; }
	inline bool getHalfCarryFlag() const { return af & 0b00100000; }
	inline bool getCarryFlag() const { return af & 0b00010000; }
	inline void setZeroFlag() { af |= 0b10000000; }
	inline void setSubtractFlag() { af |= 0b01000000; }
	inline void setHalfCarryFlag() { af |= 0b00100000; }
	inline void setCarryFlag() { af |= 0b00010000; }
	inline void resetZeroFlag() { af &= 0b1111111101111111; }
	inline void resetSubtractFlag() { af &= 0b1111111110111111; }
	inline void resetHalfCarryFlag() { af &= 0b1111111111011111; }
	inline void resetCarryFlag() { af &= 0b1111111111101111; }
	// clang-format on
};

#endif // LIBGREBE_REGISTERS_HPP
