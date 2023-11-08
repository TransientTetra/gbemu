#include <libgrebe/core/cpu/control_unit.test.hpp>

TEST_F(OpcodesBitOperationsTest, Test0xCBC0)
{
	// 0xC0 SET 0, B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0xff);
	// testing the opcode
	testOpcodeCB(0xC0);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	// testing the opcode
	testOpcodeCB(0xC0);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(1 << 0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBC1)
{
	// 0xC1 SET 0, C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0xff);
	// testing the opcode
	testOpcodeCB(0xC1);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	// testing the opcode
	testOpcodeCB(0xC1);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(1 << 0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBC2)
{
	// 0xC2 SET 0, D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0xff);
	// testing the opcode
	testOpcodeCB(0xC2);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	// testing the opcode
	testOpcodeCB(0xC2);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(1 << 0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBC3)
{
	// 0xC3 SET 0, E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0xff);
	// testing the opcode
	testOpcodeCB(0xC3);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	// testing the opcode
	testOpcodeCB(0xC3);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(1 << 0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBC4)
{
	// 0xC4 SET 0, H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0xff);
	// testing the opcode
	testOpcodeCB(0xC4);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	// testing the opcode
	testOpcodeCB(0xC4);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(1 << 0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBC5)
{
	// 0xC5 SET 0, L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0xff);
	// testing the opcode
	testOpcodeCB(0xC5);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	// testing the opcode
	testOpcodeCB(0xC5);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(1 << 0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBC6)
{
	// 0xC6 SET 0, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0xff);
	// testing the opcode
	testOpcodeCB(0xC6);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0);
	// testing the opcode
	testOpcodeCB(0xC6);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 1 << 0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBC7)
{
	// 0xC7 SET 0, A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	// testing the opcode
	testOpcodeCB(0xC7);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	// testing the opcode
	testOpcodeCB(0xC7);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(1 << 0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBC8)
{
	// 0xC8 SET 1, B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0xff);
	// testing the opcode
	testOpcodeCB(0xC8);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	// testing the opcode
	testOpcodeCB(0xC8);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(1 << 1);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBC9)
{
	// 0xC9 SET 1, C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0xff);
	// testing the opcode
	testOpcodeCB(0xC9);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	// testing the opcode
	testOpcodeCB(0xC9);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(1 << 1);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBCA)
{
	// 0xCA SET 1, D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0xff);
	// testing the opcode
	testOpcodeCB(0xCA);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	// testing the opcode
	testOpcodeCB(0xCA);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(1 << 1);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBCB)
{
	// 0xCB SET 1, E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0xff);
	// testing the opcode
	testOpcodeCB(0xCB);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	// testing the opcode
	testOpcodeCB(0xCB);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(1 << 1);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBCC)
{
	// 0xCC SET 1, H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0xff);
	// testing the opcode
	testOpcodeCB(0xCC);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	// testing the opcode
	testOpcodeCB(0xCC);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(1 << 1);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBCD)
{
	// 0xCD SET 1, L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0xff);
	// testing the opcode
	testOpcodeCB(0xCD);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	// testing the opcode
	testOpcodeCB(0xCD);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(1 << 1);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBCE)
{
	// 0xCE SET 1, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0xff);
	// testing the opcode
	testOpcodeCB(0xCE);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0);
	// testing the opcode
	testOpcodeCB(0xCE);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 1 << 1);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBCF)
{
	// 0xCF SET 1, A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	// testing the opcode
	testOpcodeCB(0xCF);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	// testing the opcode
	testOpcodeCB(0xCF);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(1 << 1);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBD0)
{
	// 0xD0 SET 2, B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0xff);
	// testing the opcode
	testOpcodeCB(0xD0);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	// testing the opcode
	testOpcodeCB(0xD0);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(1 << 2);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBD1)
{
	// 0xD1 SET 2, C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0xff);
	// testing the opcode
	testOpcodeCB(0xD1);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	// testing the opcode
	testOpcodeCB(0xD1);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(1 << 2);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBD2)
{
	// 0xD2 SET 2, D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0xff);
	// testing the opcode
	testOpcodeCB(0xD2);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	// testing the opcode
	testOpcodeCB(0xD2);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(1 << 2);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBD3)
{
	// 0xD3 SET 2, E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0xff);
	// testing the opcode
	testOpcodeCB(0xD3);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	// testing the opcode
	testOpcodeCB(0xD3);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(1 << 2);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBD4)
{
	// 0xD4 SET 2, H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0xff);
	// testing the opcode
	testOpcodeCB(0xD4);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	// testing the opcode
	testOpcodeCB(0xD4);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(1 << 2);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBD5)
{
	// 0xD5 SET 2, L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0xff);
	// testing the opcode
	testOpcodeCB(0xD5);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	// testing the opcode
	testOpcodeCB(0xD5);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(1 << 2);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBD6)
{
	// 0xD6 SET 2, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0xff);
	// testing the opcode
	testOpcodeCB(0xD6);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0);
	// testing the opcode
	testOpcodeCB(0xD6);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 1 << 2);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBD7)
{
	// 0xD7 SET 2, A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	// testing the opcode
	testOpcodeCB(0xD7);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	// testing the opcode
	testOpcodeCB(0xD7);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(1 << 2);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBD8)
{
	// 0xD8 SET 3, B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0xff);
	// testing the opcode
	testOpcodeCB(0xD8);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	// testing the opcode
	testOpcodeCB(0xD8);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(1 << 3);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBD9)
{
	// 0xD9 SET 3, C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0xff);
	// testing the opcode
	testOpcodeCB(0xD9);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	// testing the opcode
	testOpcodeCB(0xD9);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(1 << 3);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBDA)
{
	// 0xDA SET 3, D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0xff);
	// testing the opcode
	testOpcodeCB(0xDA);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	// testing the opcode
	testOpcodeCB(0xDA);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(1 << 3);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBDB)
{
	// 0xDB SET 3, E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0xff);
	// testing the opcode
	testOpcodeCB(0xDB);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	// testing the opcode
	testOpcodeCB(0xDB);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(1 << 3);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBDC)
{
	// 0xDC SET 3, H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0xff);
	// testing the opcode
	testOpcodeCB(0xDC);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	// testing the opcode
	testOpcodeCB(0xDC);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(1 << 3);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBDD)
{
	// 0xDD SET 3, L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0xff);
	// testing the opcode
	testOpcodeCB(0xDD);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	// testing the opcode
	testOpcodeCB(0xDD);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(1 << 3);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBDE)
{
	// 0xDE SET 3, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0xff);
	// testing the opcode
	testOpcodeCB(0xDE);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0);
	// testing the opcode
	testOpcodeCB(0xDE);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 1 << 3);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBDF)
{
	// 0xDF SET 3, A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	// testing the opcode
	testOpcodeCB(0xDF);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	// testing the opcode
	testOpcodeCB(0xDF);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(1 << 3);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBE0)
{
	// 0xE0 SET 4, B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0xff);
	// testing the opcode
	testOpcodeCB(0xE0);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	// testing the opcode
	testOpcodeCB(0xE0);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(1 << 4);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBE1)
{
	// 0xE1 SET 4, C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0xff);
	// testing the opcode
	testOpcodeCB(0xE1);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	// testing the opcode
	testOpcodeCB(0xE1);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(1 << 4);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBE2)
{
	// 0xE2 SET 4, D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0xff);
	// testing the opcode
	testOpcodeCB(0xE2);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	// testing the opcode
	testOpcodeCB(0xE2);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(1 << 4);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBE3)
{
	// 0xE3 SET 4, E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0xff);
	// testing the opcode
	testOpcodeCB(0xE3);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	// testing the opcode
	testOpcodeCB(0xE3);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(1 << 4);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBE4)
{
	// 0xE4 SET 4, H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0xff);
	// testing the opcode
	testOpcodeCB(0xE4);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	// testing the opcode
	testOpcodeCB(0xE4);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(1 << 4);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBE5)
{
	// 0xE5 SET 4, L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0xff);
	// testing the opcode
	testOpcodeCB(0xE5);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	// testing the opcode
	testOpcodeCB(0xE5);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(1 << 4);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBE6)
{
	// 0xE6 SET 4, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0xff);
	// testing the opcode
	testOpcodeCB(0xE6);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0);
	// testing the opcode
	testOpcodeCB(0xE6);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 1 << 4);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBE7)
{
	// 0xE7 SET 4, A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	// testing the opcode
	testOpcodeCB(0xE7);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	// testing the opcode
	testOpcodeCB(0xE7);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(1 << 4);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBE8)
{
	// 0xE8 SET 5, B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0xff);
	// testing the opcode
	testOpcodeCB(0xE8);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	// testing the opcode
	testOpcodeCB(0xE8);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(1 << 5);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBE9)
{
	// 0xE9 SET 5, C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0xff);
	// testing the opcode
	testOpcodeCB(0xE9);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	// testing the opcode
	testOpcodeCB(0xE9);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(1 << 5);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBEA)
{
	// 0xEA SET 5, D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0xff);
	// testing the opcode
	testOpcodeCB(0xEA);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	// testing the opcode
	testOpcodeCB(0xEA);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(1 << 5);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBEB)
{
	// 0xEB SET 5, E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0xff);
	// testing the opcode
	testOpcodeCB(0xEB);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	// testing the opcode
	testOpcodeCB(0xEB);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(1 << 5);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBEC)
{
	// 0xEC SET 5, H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0xff);
	// testing the opcode
	testOpcodeCB(0xEC);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	// testing the opcode
	testOpcodeCB(0xEC);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(1 << 5);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBED)
{
	// 0xED SET 5, L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0xff);
	// testing the opcode
	testOpcodeCB(0xED);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	// testing the opcode
	testOpcodeCB(0xED);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(1 << 5);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBEE)
{
	// 0xEE SET 5, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0xff);
	// testing the opcode
	testOpcodeCB(0xEE);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0);
	// testing the opcode
	testOpcodeCB(0xEE);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 1 << 5);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBEF)
{
	// 0xEF SET 5, A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	// testing the opcode
	testOpcodeCB(0xEF);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	// testing the opcode
	testOpcodeCB(0xEF);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(1 << 5);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBF0)
{
	// 0xF0 SET 6, B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0xff);
	// testing the opcode
	testOpcodeCB(0xF0);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	// testing the opcode
	testOpcodeCB(0xF0);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(1 << 6);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBF1)
{
	// 0xF1 SET 6, C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0xff);
	// testing the opcode
	testOpcodeCB(0xF1);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	// testing the opcode
	testOpcodeCB(0xF1);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(1 << 6);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBF2)
{
	// 0xF2 SET 6, D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0xff);
	// testing the opcode
	testOpcodeCB(0xF2);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	// testing the opcode
	testOpcodeCB(0xF2);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(1 << 6);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBF3)
{
	// 0xF3 SET 6, E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0xff);
	// testing the opcode
	testOpcodeCB(0xF3);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	// testing the opcode
	testOpcodeCB(0xF3);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(1 << 6);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBF4)
{
	// 0xF4 SET 6, H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0xff);
	// testing the opcode
	testOpcodeCB(0xF4);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	// testing the opcode
	testOpcodeCB(0xF4);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(1 << 6);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBF5)
{
	// 0xF5 SET 6, L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0xff);
	// testing the opcode
	testOpcodeCB(0xF5);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	// testing the opcode
	testOpcodeCB(0xF5);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(1 << 6);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBF6)
{
	// 0xF6 SET 6, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0xff);
	// testing the opcode
	testOpcodeCB(0xF6);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0);
	// testing the opcode
	testOpcodeCB(0xF6);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 1 << 6);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBF7)
{
	// 0xF7 SET 6, A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	// testing the opcode
	testOpcodeCB(0xF7);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	// testing the opcode
	testOpcodeCB(0xF7);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(1 << 6);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBF8)
{
	// 0xF8 SET 7, B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0xff);
	// testing the opcode
	testOpcodeCB(0xF8);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	// testing the opcode
	testOpcodeCB(0xF8);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(1 << 7);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBF9)
{
	// 0xF9 SET 7, C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0xff);
	// testing the opcode
	testOpcodeCB(0xF9);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	// testing the opcode
	testOpcodeCB(0xF9);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(1 << 7);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBFA)
{
	// 0xFA SET 7, D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0xff);
	// testing the opcode
	testOpcodeCB(0xFA);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	// testing the opcode
	testOpcodeCB(0xFA);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(1 << 7);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBFB)
{
	// 0xFB SET 7, E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0xff);
	// testing the opcode
	testOpcodeCB(0xFB);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	// testing the opcode
	testOpcodeCB(0xFB);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(1 << 7);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBFC)
{
	// 0xFC SET 7, H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0xff);
	// testing the opcode
	testOpcodeCB(0xFC);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	// testing the opcode
	testOpcodeCB(0xFC);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(1 << 7);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBFD)
{
	// 0xFD SET 7, L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0xff);
	// testing the opcode
	testOpcodeCB(0xFD);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	// testing the opcode
	testOpcodeCB(0xFD);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(1 << 7);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBFE)
{
	// 0xFE SET 7, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0xff);
	// testing the opcode
	testOpcodeCB(0xFE);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0);
	// testing the opcode
	testOpcodeCB(0xFE);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 1 << 7);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBFF)
{
	// 0xFF SET 7, A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	// testing the opcode
	testOpcodeCB(0xFF);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0xff);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	// testing the opcode
	testOpcodeCB(0xFF);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(1 << 7);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}
