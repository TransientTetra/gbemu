#include <libgrebe/core/cpu/control_unit.test.hpp>

TEST_F(OpcodesBitOperationsTest, Test0xCB80)
{
	// 0x80 RES 0, B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0xff);
	// testing the opcode
	testOpcodeCB(0x80);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0xff & ~(1 << 0));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	// testing the opcode
	testOpcodeCB(0x80);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB81)
{
	// 0x81 RES 0, C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0xff);
	// testing the opcode
	testOpcodeCB(0x81);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0xff & ~(1 << 0));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	// testing the opcode
	testOpcodeCB(0x81);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB82)
{
	// 0x82 RES 0, D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0xff);
	// testing the opcode
	testOpcodeCB(0x82);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0xff & ~(1 << 0));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	// testing the opcode
	testOpcodeCB(0x82);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB83)
{
	// 0x83 RES 0, E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0xff);
	// testing the opcode
	testOpcodeCB(0x83);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0xff & ~(1 << 0));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	// testing the opcode
	testOpcodeCB(0x83);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB84)
{
	// 0x84 RES 0, H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0xff);
	// testing the opcode
	testOpcodeCB(0x84);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0xff & ~(1 << 0));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	// testing the opcode
	testOpcodeCB(0x84);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB85)
{
	// 0x85 RES 0, L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0xff);
	// testing the opcode
	testOpcodeCB(0x85);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0xff & ~(1 << 0));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	// testing the opcode
	testOpcodeCB(0x85);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB86)
{
	// 0x86 RES 0, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0xff);
	// testing the opcode
	testOpcodeCB(0x86);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0xff & ~(1 << 0));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0);
	// testing the opcode
	testOpcodeCB(0x86);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB87)
{
	// 0x87 RES 0, A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	// testing the opcode
	testOpcodeCB(0x87);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0xff & ~(1 << 0));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	// testing the opcode
	testOpcodeCB(0x87);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB88)
{
	// 0x88 RES 1, B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0xff);
	// testing the opcode
	testOpcodeCB(0x88);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0xff & ~(1 << 1));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	// testing the opcode
	testOpcodeCB(0x88);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB89)
{
	// 0x89 RES 1, C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0xff);
	// testing the opcode
	testOpcodeCB(0x89);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0xff & ~(1 << 1));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	// testing the opcode
	testOpcodeCB(0x89);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB8A)
{
	// 0x8A RES 1, D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0xff);
	// testing the opcode
	testOpcodeCB(0x8A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0xff & ~(1 << 1));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	// testing the opcode
	testOpcodeCB(0x8A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB8B)
{
	// 0x8B RES 1, E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0xff);
	// testing the opcode
	testOpcodeCB(0x8B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0xff & ~(1 << 1));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	// testing the opcode
	testOpcodeCB(0x8B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB8C)
{
	// 0x8C RES 1, H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0xff);
	// testing the opcode
	testOpcodeCB(0x8C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0xff & ~(1 << 1));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	// testing the opcode
	testOpcodeCB(0x8C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB8D)
{
	// 0x8D RES 1, L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0xff);
	// testing the opcode
	testOpcodeCB(0x8D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0xff & ~(1 << 1));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	// testing the opcode
	testOpcodeCB(0x8D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB8E)
{
	// 0x8E RES 1, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0xff);
	// testing the opcode
	testOpcodeCB(0x8E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0xff & ~(1 << 1));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0);
	// testing the opcode
	testOpcodeCB(0x8E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB8F)
{
	// 0x8F RES 1, A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	// testing the opcode
	testOpcodeCB(0x8F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0xff & ~(1 << 1));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	// testing the opcode
	testOpcodeCB(0x8F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB90)
{
	// 0x90 RES 2, B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0xff);
	// testing the opcode
	testOpcodeCB(0x90);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0xff & ~(1 << 2));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	// testing the opcode
	testOpcodeCB(0x90);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB91)
{
	// 0x91 RES 2, C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0xff);
	// testing the opcode
	testOpcodeCB(0x91);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0xff & ~(1 << 2));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	// testing the opcode
	testOpcodeCB(0x91);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB92)
{
	// 0x92 RES 2, D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0xff);
	// testing the opcode
	testOpcodeCB(0x92);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0xff & ~(1 << 2));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	// testing the opcode
	testOpcodeCB(0x92);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB93)
{
	// 0x93 RES 2, E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0xff);
	// testing the opcode
	testOpcodeCB(0x93);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0xff & ~(1 << 2));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	// testing the opcode
	testOpcodeCB(0x93);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB94)
{
	// 0x94 RES 2, H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0xff);
	// testing the opcode
	testOpcodeCB(0x94);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0xff & ~(1 << 2));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	// testing the opcode
	testOpcodeCB(0x94);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB95)
{
	// 0x95 RES 2, L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0xff);
	// testing the opcode
	testOpcodeCB(0x95);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0xff & ~(1 << 2));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	// testing the opcode
	testOpcodeCB(0x95);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB96)
{
	// 0x96 RES 2, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0xff);
	// testing the opcode
	testOpcodeCB(0x96);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0xff & ~(1 << 2));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0);
	// testing the opcode
	testOpcodeCB(0x96);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB97)
{
	// 0x97 RES 2, A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	// testing the opcode
	testOpcodeCB(0x97);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0xff & ~(1 << 2));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	// testing the opcode
	testOpcodeCB(0x97);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB98)
{
	// 0x98 RES 3, B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0xff);
	// testing the opcode
	testOpcodeCB(0x98);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0xff & ~(1 << 3));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	// testing the opcode
	testOpcodeCB(0x98);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB99)
{
	// 0x99 RES 3, C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0xff);
	// testing the opcode
	testOpcodeCB(0x99);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0xff & ~(1 << 3));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	// testing the opcode
	testOpcodeCB(0x99);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB9A)
{
	// 0x9A RES 3, D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0xff);
	// testing the opcode
	testOpcodeCB(0x9A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0xff & ~(1 << 3));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	// testing the opcode
	testOpcodeCB(0x9A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB9B)
{
	// 0x9B RES 3, E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0xff);
	// testing the opcode
	testOpcodeCB(0x9B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0xff & ~(1 << 3));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	// testing the opcode
	testOpcodeCB(0x9B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB9C)
{
	// 0x9C RES 3, H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0xff);
	// testing the opcode
	testOpcodeCB(0x9C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0xff & ~(1 << 3));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	// testing the opcode
	testOpcodeCB(0x9C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB9D)
{
	// 0x9D RES 3, L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0xff);
	// testing the opcode
	testOpcodeCB(0x9D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0xff & ~(1 << 3));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	// testing the opcode
	testOpcodeCB(0x9D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB9E)
{
	// 0x9E RES 3, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0xff);
	// testing the opcode
	testOpcodeCB(0x9E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0xff & ~(1 << 3));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0);
	// testing the opcode
	testOpcodeCB(0x9E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB9F)
{
	// 0x9F RES 3, A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	// testing the opcode
	testOpcodeCB(0x9F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0xff & ~(1 << 3));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	// testing the opcode
	testOpcodeCB(0x9F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBA0)
{
	// 0xA0 RES 4, B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0xff);
	// testing the opcode
	testOpcodeCB(0xA0);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0xff & ~(1 << 4));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	// testing the opcode
	testOpcodeCB(0xA0);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBA1)
{
	// 0xA1 RES 4, C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0xff);
	// testing the opcode
	testOpcodeCB(0xA1);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0xff & ~(1 << 4));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	// testing the opcode
	testOpcodeCB(0xA1);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBA2)
{
	// 0xA2 RES 4, D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0xff);
	// testing the opcode
	testOpcodeCB(0xA2);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0xff & ~(1 << 4));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	// testing the opcode
	testOpcodeCB(0xA2);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBA3)
{
	// 0xA3 RES 4, E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0xff);
	// testing the opcode
	testOpcodeCB(0xA3);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0xff & ~(1 << 4));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	// testing the opcode
	testOpcodeCB(0xA3);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBA4)
{
	// 0xA4 RES 4, H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0xff);
	// testing the opcode
	testOpcodeCB(0xA4);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0xff & ~(1 << 4));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	// testing the opcode
	testOpcodeCB(0xA4);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBA5)
{
	// 0xA5 RES 4, L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0xff);
	// testing the opcode
	testOpcodeCB(0xA5);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0xff & ~(1 << 4));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	// testing the opcode
	testOpcodeCB(0xA5);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBA6)
{
	// 0xA6 RES 4, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0xff);
	// testing the opcode
	testOpcodeCB(0xA6);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0xff & ~(1 << 4));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0);
	// testing the opcode
	testOpcodeCB(0xA6);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBA7)
{
	// 0xA7 RES 4, A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	// testing the opcode
	testOpcodeCB(0xA7);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0xff & ~(1 << 4));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	// testing the opcode
	testOpcodeCB(0xA7);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBA8)
{
	// 0xA8 RES 5, B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0xff);
	// testing the opcode
	testOpcodeCB(0xA8);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0xff & ~(1 << 5));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	// testing the opcode
	testOpcodeCB(0xA8);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBA9)
{
	// 0xA9 RES 5, C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0xff);
	// testing the opcode
	testOpcodeCB(0xA9);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0xff & ~(1 << 5));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	// testing the opcode
	testOpcodeCB(0xA9);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBAA)
{
	// 0xAA RES 5, D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0xff);
	// testing the opcode
	testOpcodeCB(0xAA);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0xff & ~(1 << 5));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	// testing the opcode
	testOpcodeCB(0xAA);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBAB)
{
	// 0xAB RES 5, E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0xff);
	// testing the opcode
	testOpcodeCB(0xAB);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0xff & ~(1 << 5));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	// testing the opcode
	testOpcodeCB(0xAB);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBAC)
{
	// 0xAC RES 5, H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0xff);
	// testing the opcode
	testOpcodeCB(0xAC);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0xff & ~(1 << 5));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	// testing the opcode
	testOpcodeCB(0xAC);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBAD)
{
	// 0xAD RES 5, L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0xff);
	// testing the opcode
	testOpcodeCB(0xAD);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0xff & ~(1 << 5));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	// testing the opcode
	testOpcodeCB(0xAD);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBAE)
{
	// 0xAE RES 5, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0xff);
	// testing the opcode
	testOpcodeCB(0xAE);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0xff & ~(1 << 5));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0);
	// testing the opcode
	testOpcodeCB(0xAE);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBAF)
{
	// 0xAF RES 5, A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	// testing the opcode
	testOpcodeCB(0xAF);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0xff & ~(1 << 5));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	// testing the opcode
	testOpcodeCB(0xAF);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBB0)
{
	// 0xB0 RES 6, B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0xff);
	// testing the opcode
	testOpcodeCB(0xB0);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0xff & ~(1 << 6));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	// testing the opcode
	testOpcodeCB(0xB0);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBB1)
{
	// 0xB1 RES 6, C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0xff);
	// testing the opcode
	testOpcodeCB(0xB1);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0xff & ~(1 << 6));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	// testing the opcode
	testOpcodeCB(0xB1);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBB2)
{
	// 0xB2 RES 6, D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0xff);
	// testing the opcode
	testOpcodeCB(0xB2);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0xff & ~(1 << 6));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	// testing the opcode
	testOpcodeCB(0xB2);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBB3)
{
	// 0xB3 RES 6, E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0xff);
	// testing the opcode
	testOpcodeCB(0xB3);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0xff & ~(1 << 6));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	// testing the opcode
	testOpcodeCB(0xB3);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBB4)
{
	// 0xB4 RES 6, H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0xff);
	// testing the opcode
	testOpcodeCB(0xB4);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0xff & ~(1 << 6));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	// testing the opcode
	testOpcodeCB(0xB4);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBB5)
{
	// 0xB5 RES 6, L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0xff);
	// testing the opcode
	testOpcodeCB(0xB5);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0xff & ~(1 << 6));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	// testing the opcode
	testOpcodeCB(0xB5);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBB6)
{
	// 0xB6 RES 6, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0xff);
	// testing the opcode
	testOpcodeCB(0xB6);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0xff & ~(1 << 6));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0);
	// testing the opcode
	testOpcodeCB(0xB6);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBB7)
{
	// 0xB7 RES 6, A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	// testing the opcode
	testOpcodeCB(0xB7);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0xff & ~(1 << 6));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	// testing the opcode
	testOpcodeCB(0xB7);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBB8)
{
	// 0xB8 RES 7, B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0xff);
	// testing the opcode
	testOpcodeCB(0xB8);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0xff & ~(1 << 7));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	// testing the opcode
	testOpcodeCB(0xB8);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBB9)
{
	// 0xB9 RES 7, C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0xff);
	// testing the opcode
	testOpcodeCB(0xB9);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0xff & ~(1 << 7));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	// testing the opcode
	testOpcodeCB(0xB9);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBBA)
{
	// 0xBA RES 7, D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0xff);
	// testing the opcode
	testOpcodeCB(0xBA);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0xff & ~(1 << 7));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	// testing the opcode
	testOpcodeCB(0xBA);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBBB)
{
	// 0xBB RES 7, E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0xff);
	// testing the opcode
	testOpcodeCB(0xBB);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0xff & ~(1 << 7));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	// testing the opcode
	testOpcodeCB(0xBB);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBBC)
{
	// 0xBC RES 7, H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0xff);
	// testing the opcode
	testOpcodeCB(0xBC);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0xff & ~(1 << 7));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	// testing the opcode
	testOpcodeCB(0xBC);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBBD)
{
	// 0xBD RES 7, L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0xff);
	// testing the opcode
	testOpcodeCB(0xBD);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0xff & ~(1 << 7));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	// testing the opcode
	testOpcodeCB(0xBD);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBBE)
{
	// 0xBE RES 7, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0xff);
	// testing the opcode
	testOpcodeCB(0xBE);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0xff & ~(1 << 7));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0);
	// testing the opcode
	testOpcodeCB(0xBE);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCBBF)
{
	// 0xBF RES 7, A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	// testing the opcode
	testOpcodeCB(0xBF);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0xff & ~(1 << 7));
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	// testing the opcode
	testOpcodeCB(0xBF);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0);
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}
