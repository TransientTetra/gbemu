#include <libgrebe/core/cpu/control_unit.test.hpp>

TEST_F(OpcodesBitOperationsTest, Test0xCB40)
{
	// 0x40 BIT 0, B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0xff);
	state.registers.setB(state.registers.getB() & ~(1 << 0));
	// testing the opcode
	testOpcodeCB(0x40);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	state.registers.setB(state.registers.getB() | 1 << 0);
	// testing the opcode
	testOpcodeCB(0x40);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB41)
{
	// 0x41 BIT 0, C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0xff);
	state.registers.setC(state.registers.getC() & ~(1 << 0));
	// testing the opcode
	testOpcodeCB(0x41);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	state.registers.setC(state.registers.getC() | 1 << 0);
	// testing the opcode
	testOpcodeCB(0x41);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB42)
{
	// 0x42 BIT 0, D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0xff);
	state.registers.setD(state.registers.getD() & ~(1 << 0));
	// testing the opcode
	testOpcodeCB(0x42);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	state.registers.setD(state.registers.getD() | 1 << 0);
	// testing the opcode
	testOpcodeCB(0x42);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB43)
{
	// 0x43 BIT 0, E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0xff);
	state.registers.setE(state.registers.getE() & ~(1 << 0));
	// testing the opcode
	testOpcodeCB(0x43);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	state.registers.setE(state.registers.getE() | 1 << 0);
	// testing the opcode
	testOpcodeCB(0x43);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB44)
{
	// 0x44 BIT 0, H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0xff);
	state.registers.setH(state.registers.getH() & ~(1 << 0));
	// testing the opcode
	testOpcodeCB(0x44);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	state.registers.setH(state.registers.getH() | 1 << 0);
	// testing the opcode
	testOpcodeCB(0x44);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB45)
{
	// 0x45 BIT 0, L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0xff);
	state.registers.setL(state.registers.getL() & ~(1 << 0));
	// testing the opcode
	testOpcodeCB(0x45);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	state.registers.setL(state.registers.getL() | 1 << 0);
	// testing the opcode
	testOpcodeCB(0x45);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB46)
{
	// 0x46 BIT 0, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0xff & ~(1 << 0));
	// testing the opcode
	testOpcodeCB(0x46);
	// expected change in registers and memory
	expectedState.clockCycles += 12;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, (1 << 0));
	// testing the opcode
	testOpcodeCB(0x46);
	// expected change in registers and memory
	expectedState.clockCycles += 12;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB47)
{
	// 0x47 BIT 0, A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	state.registers.setA(state.registers.getA() & ~(1 << 0));
	// testing the opcode
	testOpcodeCB(0x47);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.setA(state.registers.getA() | 1 << 0);
	// testing the opcode
	testOpcodeCB(0x47);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB48)
{
	// 0x48 BIT 1, B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0xff);
	state.registers.setB(state.registers.getB() & ~(1 << 1));
	// testing the opcode
	testOpcodeCB(0x48);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	state.registers.setB(state.registers.getB() | 1 << 1);
	// testing the opcode
	testOpcodeCB(0x48);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB49)
{
	// 0x49 BIT 1, C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0xff);
	state.registers.setC(state.registers.getC() & ~(1 << 1));
	// testing the opcode
	testOpcodeCB(0x49);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	state.registers.setC(state.registers.getC() | 1 << 1);
	// testing the opcode
	testOpcodeCB(0x49);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB4A)
{
	// 0x4A BIT 1, D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0xff);
	state.registers.setD(state.registers.getD() & ~(1 << 1));
	// testing the opcode
	testOpcodeCB(0x4A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	state.registers.setD(state.registers.getD() | 1 << 1);
	// testing the opcode
	testOpcodeCB(0x4A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB4B)
{
	// 0x4B BIT 1, E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0xff);
	state.registers.setE(state.registers.getE() & ~(1 << 1));
	// testing the opcode
	testOpcodeCB(0x4B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	state.registers.setE(state.registers.getE() | 1 << 1);
	// testing the opcode
	testOpcodeCB(0x4B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB4C)
{
	// 0x4C BIT 1, H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0xff);
	state.registers.setH(state.registers.getH() & ~(1 << 1));
	// testing the opcode
	testOpcodeCB(0x4C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	state.registers.setH(state.registers.getH() | 1 << 1);
	// testing the opcode
	testOpcodeCB(0x4C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB4D)
{
	// 0x4D BIT 1, L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0xff);
	state.registers.setL(state.registers.getL() & ~(1 << 1));
	// testing the opcode
	testOpcodeCB(0x4D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	state.registers.setL(state.registers.getL() | 1 << 1);
	// testing the opcode
	testOpcodeCB(0x4D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB4E)
{
	// 0x4E BIT 1, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0xff & ~(1 << 1));
	// testing the opcode
	testOpcodeCB(0x4E);
	// expected change in registers and memory
	expectedState.clockCycles += 12;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, (1 << 1));
	// testing the opcode
	testOpcodeCB(0x4E);
	// expected change in registers and memory
	expectedState.clockCycles += 12;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB4F)
{
	// 0x4F BIT 1, A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	state.registers.setA(state.registers.getA() & ~(1 << 1));
	// testing the opcode
	testOpcodeCB(0x4F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.setA(state.registers.getA() | 1 << 1);
	// testing the opcode
	testOpcodeCB(0x4F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB50)
{
	// 0x50 BIT 2, B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0xff);
	state.registers.setB(state.registers.getB() & ~(1 << 2));
	// testing the opcode
	testOpcodeCB(0x50);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	state.registers.setB(state.registers.getB() | 1 << 2);
	// testing the opcode
	testOpcodeCB(0x50);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB51)
{
	// 0x51 BIT 2, C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0xff);
	state.registers.setC(state.registers.getC() & ~(1 << 2));
	// testing the opcode
	testOpcodeCB(0x51);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	state.registers.setC(state.registers.getC() | 1 << 2);
	// testing the opcode
	testOpcodeCB(0x51);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB52)
{
	// 0x52 BIT 2, D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0xff);
	state.registers.setD(state.registers.getD() & ~(1 << 2));
	// testing the opcode
	testOpcodeCB(0x52);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	state.registers.setD(state.registers.getD() | 1 << 2);
	// testing the opcode
	testOpcodeCB(0x52);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB53)
{
	// 0x53 BIT 2, E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0xff);
	state.registers.setE(state.registers.getE() & ~(1 << 2));
	// testing the opcode
	testOpcodeCB(0x53);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	state.registers.setE(state.registers.getE() | 1 << 2);
	// testing the opcode
	testOpcodeCB(0x53);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB54)
{
	// 0x54 BIT 2, H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0xff);
	state.registers.setH(state.registers.getH() & ~(1 << 2));
	// testing the opcode
	testOpcodeCB(0x54);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	state.registers.setH(state.registers.getH() | 1 << 2);
	// testing the opcode
	testOpcodeCB(0x54);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB55)
{
	// 0x55 BIT 2, L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0xff);
	state.registers.setL(state.registers.getL() & ~(1 << 2));
	// testing the opcode
	testOpcodeCB(0x55);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	state.registers.setL(state.registers.getL() | 1 << 2);
	// testing the opcode
	testOpcodeCB(0x55);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB56)
{
	// 0x56 BIT 2, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0xff & ~(1 << 2));
	// testing the opcode
	testOpcodeCB(0x56);
	// expected change in registers and memory
	expectedState.clockCycles += 12;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, (1 << 2));
	// testing the opcode
	testOpcodeCB(0x56);
	// expected change in registers and memory
	expectedState.clockCycles += 12;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB57)
{
	// 0x57 BIT 2, A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	state.registers.setA(state.registers.getA() & ~(1 << 2));
	// testing the opcode
	testOpcodeCB(0x57);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.setA(state.registers.getA() | 1 << 2);
	// testing the opcode
	testOpcodeCB(0x57);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB58)
{
	// 0x58 BIT 3, B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0xff);
	state.registers.setB(state.registers.getB() & ~(1 << 3));
	// testing the opcode
	testOpcodeCB(0x58);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	state.registers.setB(state.registers.getB() | 1 << 3);
	// testing the opcode
	testOpcodeCB(0x58);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB59)
{
	// 0x59 BIT 3, C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0xff);
	state.registers.setC(state.registers.getC() & ~(1 << 3));
	// testing the opcode
	testOpcodeCB(0x59);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	state.registers.setC(state.registers.getC() | 1 << 3);
	// testing the opcode
	testOpcodeCB(0x59);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB5A)
{
	// 0x5A BIT 3, D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0xff);
	state.registers.setD(state.registers.getD() & ~(1 << 3));
	// testing the opcode
	testOpcodeCB(0x5A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	state.registers.setD(state.registers.getD() | 1 << 3);
	// testing the opcode
	testOpcodeCB(0x5A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB5B)
{
	// 0x5B BIT 3, E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0xff);
	state.registers.setE(state.registers.getE() & ~(1 << 3));
	// testing the opcode
	testOpcodeCB(0x5B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	state.registers.setE(state.registers.getE() | 1 << 3);
	// testing the opcode
	testOpcodeCB(0x5B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB5C)
{
	// 0x5C BIT 3, H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0xff);
	state.registers.setH(state.registers.getH() & ~(1 << 3));
	// testing the opcode
	testOpcodeCB(0x5C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	state.registers.setH(state.registers.getH() | 1 << 3);
	// testing the opcode
	testOpcodeCB(0x5C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB5D)
{
	// 0x5D BIT 3, L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0xff);
	state.registers.setL(state.registers.getL() & ~(1 << 3));
	// testing the opcode
	testOpcodeCB(0x5D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	state.registers.setL(state.registers.getL() | 1 << 3);
	// testing the opcode
	testOpcodeCB(0x5D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB5E)
{
	// 0x5E BIT 3, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0xff & ~(1 << 3));
	// testing the opcode
	testOpcodeCB(0x5E);
	// expected change in registers and memory
	expectedState.clockCycles += 12;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, (1 << 3));
	// testing the opcode
	testOpcodeCB(0x5E);
	// expected change in registers and memory
	expectedState.clockCycles += 12;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB5F)
{
	// 0x5F BIT 3, A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	state.registers.setA(state.registers.getA() & ~(1 << 3));
	// testing the opcode
	testOpcodeCB(0x5F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.setA(state.registers.getA() | 1 << 3);
	// testing the opcode
	testOpcodeCB(0x5F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB60)
{
	// 0x60 BIT 4, B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0xff);
	state.registers.setB(state.registers.getB() & ~(1 << 4));
	// testing the opcode
	testOpcodeCB(0x60);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	state.registers.setB(state.registers.getB() | 1 << 4);
	// testing the opcode
	testOpcodeCB(0x60);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB61)
{
	// 0x61 BIT 4, C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0xff);
	state.registers.setC(state.registers.getC() & ~(1 << 4));
	// testing the opcode
	testOpcodeCB(0x61);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	state.registers.setC(state.registers.getC() | 1 << 4);
	// testing the opcode
	testOpcodeCB(0x61);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB62)
{
	// 0x62 BIT 4, D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0xff);
	state.registers.setD(state.registers.getD() & ~(1 << 4));
	// testing the opcode
	testOpcodeCB(0x62);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	state.registers.setD(state.registers.getD() | 1 << 4);
	// testing the opcode
	testOpcodeCB(0x62);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB63)
{
	// 0x63 BIT 4, E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0xff);
	state.registers.setE(state.registers.getE() & ~(1 << 4));
	// testing the opcode
	testOpcodeCB(0x63);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	state.registers.setE(state.registers.getE() | 1 << 4);
	// testing the opcode
	testOpcodeCB(0x63);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB64)
{
	// 0x64 BIT 4, H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0xff);
	state.registers.setH(state.registers.getH() & ~(1 << 4));
	// testing the opcode
	testOpcodeCB(0x64);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	state.registers.setH(state.registers.getH() | 1 << 4);
	// testing the opcode
	testOpcodeCB(0x64);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB65)
{
	// 0x65 BIT 4, L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0xff);
	state.registers.setL(state.registers.getL() & ~(1 << 4));
	// testing the opcode
	testOpcodeCB(0x65);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	state.registers.setL(state.registers.getL() | 1 << 4);
	// testing the opcode
	testOpcodeCB(0x65);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB66)
{
	// 0x66 BIT 4, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0xff & ~(1 << 4));
	// testing the opcode
	testOpcodeCB(0x66);
	// expected change in registers and memory
	expectedState.clockCycles += 12;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, (1 << 4));
	// testing the opcode
	testOpcodeCB(0x66);
	// expected change in registers and memory
	expectedState.clockCycles += 12;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB67)
{
	// 0x67 BIT 4, A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	state.registers.setA(state.registers.getA() & ~(1 << 4));
	// testing the opcode
	testOpcodeCB(0x67);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.setA(state.registers.getA() | 1 << 4);
	// testing the opcode
	testOpcodeCB(0x67);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB68)
{
	// 0x68 BIT 5, B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0xff);
	state.registers.setB(state.registers.getB() & ~(1 << 5));
	// testing the opcode
	testOpcodeCB(0x68);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	state.registers.setB(state.registers.getB() | 1 << 5);
	// testing the opcode
	testOpcodeCB(0x68);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB69)
{
	// 0x69 BIT 5, C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0xff);
	state.registers.setC(state.registers.getC() & ~(1 << 5));
	// testing the opcode
	testOpcodeCB(0x69);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	state.registers.setC(state.registers.getC() | 1 << 5);
	// testing the opcode
	testOpcodeCB(0x69);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB6A)
{
	// 0x6A BIT 5, D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0xff);
	state.registers.setD(state.registers.getD() & ~(1 << 5));
	// testing the opcode
	testOpcodeCB(0x6A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	state.registers.setD(state.registers.getD() | 1 << 5);
	// testing the opcode
	testOpcodeCB(0x6A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB6B)
{
	// 0x6B BIT 5, E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0xff);
	state.registers.setE(state.registers.getE() & ~(1 << 5));
	// testing the opcode
	testOpcodeCB(0x6B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	state.registers.setE(state.registers.getE() | 1 << 5);
	// testing the opcode
	testOpcodeCB(0x6B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB6C)
{
	// 0x6C BIT 5, H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0xff);
	state.registers.setH(state.registers.getH() & ~(1 << 5));
	// testing the opcode
	testOpcodeCB(0x6C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	state.registers.setH(state.registers.getH() | 1 << 5);
	// testing the opcode
	testOpcodeCB(0x6C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB6D)
{
	// 0x6D BIT 5, L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0xff);
	state.registers.setL(state.registers.getL() & ~(1 << 5));
	// testing the opcode
	testOpcodeCB(0x6D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	state.registers.setL(state.registers.getL() | 1 << 5);
	// testing the opcode
	testOpcodeCB(0x6D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB6E)
{
	// 0x6E BIT 5, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0xff & ~(1 << 5));
	// testing the opcode
	testOpcodeCB(0x6E);
	// expected change in registers and memory
	expectedState.clockCycles += 12;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, (1 << 5));
	// testing the opcode
	testOpcodeCB(0x6E);
	// expected change in registers and memory
	expectedState.clockCycles += 12;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB6F)
{
	// 0x6F BIT 5, A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	state.registers.setA(state.registers.getA() & ~(1 << 5));
	// testing the opcode
	testOpcodeCB(0x6F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.setA(state.registers.getA() | 1 << 5);
	// testing the opcode
	testOpcodeCB(0x6F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB70)
{
	// 0x70 BIT 6, B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0xff);
	state.registers.setB(state.registers.getB() & ~(1 << 6));
	// testing the opcode
	testOpcodeCB(0x70);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	state.registers.setB(state.registers.getB() | 1 << 6);
	// testing the opcode
	testOpcodeCB(0x70);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB71)
{
	// 0x71 BIT 6, C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0xff);
	state.registers.setC(state.registers.getC() & ~(1 << 6));
	// testing the opcode
	testOpcodeCB(0x71);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	state.registers.setC(state.registers.getC() | 1 << 6);
	// testing the opcode
	testOpcodeCB(0x71);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB72)
{
	// 0x72 BIT 6, D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0xff);
	state.registers.setD(state.registers.getD() & ~(1 << 6));
	// testing the opcode
	testOpcodeCB(0x72);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	state.registers.setD(state.registers.getD() | 1 << 6);
	// testing the opcode
	testOpcodeCB(0x72);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB73)
{
	// 0x73 BIT 6, E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0xff);
	state.registers.setE(state.registers.getE() & ~(1 << 6));
	// testing the opcode
	testOpcodeCB(0x73);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	state.registers.setE(state.registers.getE() | 1 << 6);
	// testing the opcode
	testOpcodeCB(0x73);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB74)
{
	// 0x74 BIT 6, H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0xff);
	state.registers.setH(state.registers.getH() & ~(1 << 6));
	// testing the opcode
	testOpcodeCB(0x74);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	state.registers.setH(state.registers.getH() | 1 << 6);
	// testing the opcode
	testOpcodeCB(0x74);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB75)
{
	// 0x75 BIT 6, L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0xff);
	state.registers.setL(state.registers.getL() & ~(1 << 6));
	// testing the opcode
	testOpcodeCB(0x75);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	state.registers.setL(state.registers.getL() | 1 << 6);
	// testing the opcode
	testOpcodeCB(0x75);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB76)
{
	// 0x76 BIT 6, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0xff & ~(1 << 6));
	// testing the opcode
	testOpcodeCB(0x76);
	// expected change in registers and memory
	expectedState.clockCycles += 12;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, (1 << 6));
	// testing the opcode
	testOpcodeCB(0x76);
	// expected change in registers and memory
	expectedState.clockCycles += 12;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB77)
{
	// 0x77 BIT 6, A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	state.registers.setA(state.registers.getA() & ~(1 << 6));
	// testing the opcode
	testOpcodeCB(0x77);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.setA(state.registers.getA() | 1 << 6);
	// testing the opcode
	testOpcodeCB(0x77);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB78)
{
	// 0x78 BIT 7, B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0xff);
	state.registers.setB(state.registers.getB() & ~(1 << 7));
	// testing the opcode
	testOpcodeCB(0x78);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	state.registers.setB(state.registers.getB() | 1 << 7);
	// testing the opcode
	testOpcodeCB(0x78);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB79)
{
	// 0x79 BIT 7, C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0xff);
	state.registers.setC(state.registers.getC() & ~(1 << 7));
	// testing the opcode
	testOpcodeCB(0x79);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	state.registers.setC(state.registers.getC() | 1 << 7);
	// testing the opcode
	testOpcodeCB(0x79);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB7A)
{
	// 0x7A BIT 7, D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0xff);
	state.registers.setD(state.registers.getD() & ~(1 << 7));
	// testing the opcode
	testOpcodeCB(0x7A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	state.registers.setD(state.registers.getD() | 1 << 7);
	// testing the opcode
	testOpcodeCB(0x7A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB7B)
{
	// 0x7B BIT 7, E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0xff);
	state.registers.setE(state.registers.getE() & ~(1 << 7));
	// testing the opcode
	testOpcodeCB(0x7B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	state.registers.setE(state.registers.getE() | 1 << 7);
	// testing the opcode
	testOpcodeCB(0x7B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB7C)
{
	// 0x7C BIT 7, H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0xff);
	state.registers.setH(state.registers.getH() & ~(1 << 7));
	// testing the opcode
	testOpcodeCB(0x7C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	state.registers.setH(state.registers.getH() | 1 << 7);
	// testing the opcode
	testOpcodeCB(0x7C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB7D)
{
	// 0x7D BIT 7, L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0xff);
	state.registers.setL(state.registers.getL() & ~(1 << 7));
	// testing the opcode
	testOpcodeCB(0x7D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	state.registers.setL(state.registers.getL() | 1 << 7);
	// testing the opcode
	testOpcodeCB(0x7D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB7E)
{
	// 0x7E BIT 7, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0xff & ~(1 << 7));
	// testing the opcode
	testOpcodeCB(0x7E);
	// expected change in registers and memory
	expectedState.clockCycles += 12;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, (1 << 7));
	// testing the opcode
	testOpcodeCB(0x7E);
	// expected change in registers and memory
	expectedState.clockCycles += 12;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB7F)
{
	// 0x7F BIT 7, A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	state.registers.setA(state.registers.getA() & ~(1 << 7));
	// testing the opcode
	testOpcodeCB(0x7F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.setA(state.registers.getA() | 1 << 7);
	// testing the opcode
	testOpcodeCB(0x7F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}
