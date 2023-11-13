#ifndef LIBGREBE_REGISTERS_HPP
#define LIBGREBE_REGISTERS_HPP

#include <cstdint>

class Registers
{
private:
	std::uint16_t af;
	std::uint16_t bc;
	std::uint16_t de;
	std::uint16_t hl;
	std::uint16_t sp;
	std::uint16_t pc;

public:
	// clang-format off
	inline std::uint8_t getA() const { return af >> 8; }
	inline std::uint8_t getF() const { return af & 0x00ff; }
	inline std::uint8_t getB() const { return bc >> 8; }
	inline std::uint8_t getC() const { return bc & 0x00ff; }
	inline std::uint8_t getD() const { return de >> 8; }
	inline std::uint8_t getE() const { return de & 0x00ff; }
	inline std::uint8_t getH() const { return hl >> 8; }
	inline std::uint8_t getL() const { return hl & 0x00ff; }
	inline std::uint16_t getAF() const { return af; }
	inline std::uint16_t getBC() const { return bc; }
	inline std::uint16_t getDE() const { return de; }
	inline std::uint16_t getHL() const { return hl; }
	inline std::uint16_t getSP() const { return sp; }
	inline std::uint16_t getPC() const { return pc; }
	inline void setA(std::uint8_t val) { af = af & 0x00ff | (val << 8); }
	inline void setF(std::uint8_t val) { af = af & 0xff00 | val; }
	inline void setB(std::uint8_t val) { bc = bc & 0x00ff | (val << 8); }
	inline void setC(std::uint8_t val) { bc = bc & 0xff00 | val; }
	inline void setD(std::uint8_t val) { de = de & 0x00ff | (val << 8); }
	inline void setE(std::uint8_t val) { de = de & 0xff00 | val; }
	inline void setH(std::uint8_t val) { hl = hl & 0x00ff | (val << 8); }
	inline void setL(std::uint8_t val) { hl = hl & 0xff00 | val; }
	inline void setAF(std::uint16_t val) { af = val; }
	inline void setBC(std::uint16_t val) { bc = val; }
	inline void setDE(std::uint16_t val) { de = val; }
	inline void setHL(std::uint16_t val) { hl = val; }
	inline void setSP(std::uint16_t val) { sp = val; }
	inline void setPC(std::uint16_t val) { pc = val; }
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
