#include <libgrebe/core/common.test.hpp>

void writeWord(State& state, const Word& address, const Word& data)
{
	state.mmu.write(address, static_cast<Byte>(0x00ff & data));
	state.mmu.write(address + 1, static_cast<Byte>(data >> 8));
}

void copyMem(MMU& dst, MMU& src)
{
	for (int i = 0; i < LIBGREBE_MEMORY_SIZE; ++i)
	{
		dst.write(i, src.read(i));
	}
}

bool compareMem(const MMU& mem1, const MMU& mem2)
{
	for (int i = 0; i < LIBGREBE_MEMORY_SIZE; ++i)
	{
		if (mem1.read(i) != mem2.read(i))
		{
			int j = std::max(0, i - 4);
			std::cerr << "Found diff at " << std::hex << i << std::endl;
			for (; j < std::min(LIBGREBE_MEMORY_SIZE, i + 4); ++j)
			{
				std::cerr << std::hex << j << "  " << std::hex << (int)mem1.read(j) << "   " << std::hex
						  << (int)mem2.read(j) << std::endl;
			}
			return false;
		}
	}
	return true;
}

bool operator==(const Registers& one, const Registers& two)
{
	bool res = true;
	res &= one.getA() == two.getA();
	res &= one.getF() == two.getF();
	res &= one.getB() == two.getB();
	res &= one.getC() == two.getC();
	res &= one.getD() == two.getD();
	res &= one.getE() == two.getE();
	res &= one.getH() == two.getH();
	res &= one.getL() == two.getL();
	res &= one.getAF() == two.getAF();
	res &= one.getBC() == two.getBC();
	res &= one.getDE() == two.getDE();
	res &= one.getHL() == two.getHL();
	res &= one.getSP() == two.getSP();
	res &= one.getPC() == two.getPC();
	return res;
}

void copyState(State& dst, State& src)
{
	dst.registers = src.registers;
	copyMem(dst.mmu, src.mmu);
	dst.hardwareRegisters = src.hardwareRegisters;
	dst.ime = src.ime;
	dst.imeScheduled = src.imeScheduled;
	dst.clockCycles = src.clockCycles;
	dst.controlUnitState = src.controlUnitState;
	dst.interruptHandlerState = src.interruptHandlerState;
	dst.ppuState = src.ppuState;
	dst.tmp = src.tmp;
	dst.cpuQueue = src.cpuQueue;
	dst.extendedOpcodeSet = src.extendedOpcodeSet;
}

bool compareState(const State& state1, const State& state2)
{
	bool res = true;
	res &= state1.registers == state2.registers;
	res &= compareMem(state1.mmu, state2.mmu);
	res &= state1.ime == state2.ime;
	res &= state1.imeScheduled == state2.imeScheduled;
	res &= state1.clockCycles == state2.clockCycles;
	res &= state1.tmp.size() == state2.tmp.size();
	res &= state1.controlUnitState == state2.controlUnitState;
	res &= state1.ppuState == state2.ppuState;
	res &= state1.interruptHandlerState == state2.interruptHandlerState;
	res &= state1.extendedOpcodeSet == state2.extendedOpcodeSet;
	// res &= dst.tmp == src.tmp;
	// res &= state1.cpuQueue == state2.cpuQueue;
	return res;
}
