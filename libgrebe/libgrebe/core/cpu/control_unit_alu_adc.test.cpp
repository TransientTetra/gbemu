#include <libgrebe/core/cpu/control_unit.test.hpp>

TEST_F(OpcodesAluTest, Test0x88)
{
	// 0x88 opcodeADC B
	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0);
	state.registers.setB(0);
	// testing the opcode
	testOpcode(0x88);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0xff);
	state.registers.setB(1);
	// testing the opcode
	testOpcode(0x88);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0x0f);
	state.registers.setB(1);
	// testing the opcode
	testOpcode(0x88);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0x10);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0xf0);
	state.registers.setB(0x11);
	// testing the opcode
	testOpcode(0x88);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0);
	state.registers.setB(0);
	// testing the opcode
	testOpcode(0x88);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0xff);
	state.registers.setB(1);
	// testing the opcode
	testOpcode(0x88);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0x0f);
	state.registers.setB(1);
	// testing the opcode
	testOpcode(0x88);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0x11);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0xff);
	state.registers.setB(1);
	// testing the opcode
	testOpcode(0x88);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0xf0);
	state.registers.setB(0x10);
	// testing the opcode
	testOpcode(0x88);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x89)
{
	// 0x89 opcodeADC C
	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0);
	state.registers.setC(0);
	// testing the opcode
	testOpcode(0x89);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0xff);
	state.registers.setC(1);
	// testing the opcode
	testOpcode(0x89);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0x0f);
	state.registers.setC(1);
	// testing the opcode
	testOpcode(0x89);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0x10);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0xf0);
	state.registers.setC(0x11);
	// testing the opcode
	testOpcode(0x89);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0);
	state.registers.setC(0);
	// testing the opcode
	testOpcode(0x89);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0xff);
	state.registers.setC(1);
	// testing the opcode
	testOpcode(0x89);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0x0f);
	state.registers.setC(1);
	// testing the opcode
	testOpcode(0x89);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0x11);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0xff);
	state.registers.setC(1);
	// testing the opcode
	testOpcode(0x89);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0xf0);
	state.registers.setC(0x10);
	// testing the opcode
	testOpcode(0x89);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x8A)
{
	// 0x8A opcodeADC D
	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0);
	state.registers.setD(0);
	// testing the opcode
	testOpcode(0x8A);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0xff);
	state.registers.setD(1);
	// testing the opcode
	testOpcode(0x8A);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0x0f);
	state.registers.setD(1);
	// testing the opcode
	testOpcode(0x8A);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0x10);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0xf0);
	state.registers.setD(0x11);
	// testing the opcode
	testOpcode(0x8A);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0);
	state.registers.setD(0);
	// testing the opcode
	testOpcode(0x8A);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0xff);
	state.registers.setD(1);
	// testing the opcode
	testOpcode(0x8A);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0x0f);
	state.registers.setD(1);
	// testing the opcode
	testOpcode(0x8A);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0x11);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0xff);
	state.registers.setD(1);
	// testing the opcode
	testOpcode(0x8A);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0xf0);
	state.registers.setD(0x10);
	// testing the opcode
	testOpcode(0x8A);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x8B)
{
	// 0x8B opcodeADC E
	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0);
	state.registers.setE(0);
	// testing the opcode
	testOpcode(0x8B);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0xff);
	state.registers.setE(1);
	// testing the opcode
	testOpcode(0x8B);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0x0f);
	state.registers.setE(1);
	// testing the opcode
	testOpcode(0x8B);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0x10);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0xf0);
	state.registers.setE(0x11);
	// testing the opcode
	testOpcode(0x8B);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0);
	state.registers.setE(0);
	// testing the opcode
	testOpcode(0x8B);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0xff);
	state.registers.setE(1);
	// testing the opcode
	testOpcode(0x8B);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0x0f);
	state.registers.setE(1);
	// testing the opcode
	testOpcode(0x8B);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0x11);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0xff);
	state.registers.setE(1);
	// testing the opcode
	testOpcode(0x8B);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0xf0);
	state.registers.setE(0x10);
	// testing the opcode
	testOpcode(0x8B);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x8C)
{
	// 0x8C opcodeADC H
	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0);
	state.registers.setH(0);
	// testing the opcode
	testOpcode(0x8C);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0xff);
	state.registers.setH(1);
	// testing the opcode
	testOpcode(0x8C);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0x0f);
	state.registers.setH(1);
	// testing the opcode
	testOpcode(0x8C);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0x10);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0xf0);
	state.registers.setH(0x11);
	// testing the opcode
	testOpcode(0x8C);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0);
	state.registers.setH(0);
	// testing the opcode
	testOpcode(0x8C);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0xff);
	state.registers.setH(1);
	// testing the opcode
	testOpcode(0x8C);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0x0f);
	state.registers.setH(1);
	// testing the opcode
	testOpcode(0x8C);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0x11);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0xff);
	state.registers.setH(1);
	// testing the opcode
	testOpcode(0x8C);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0xf0);
	state.registers.setH(0x10);
	// testing the opcode
	testOpcode(0x8C);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x8D)
{
	// 0x8D opcodeADC L
	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0);
	state.registers.setL(0);
	// testing the opcode
	testOpcode(0x8D);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0xff);
	state.registers.setL(1);
	// testing the opcode
	testOpcode(0x8D);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0x0f);
	state.registers.setL(1);
	// testing the opcode
	testOpcode(0x8D);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0x10);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0xf0);
	state.registers.setL(0x11);
	// testing the opcode
	testOpcode(0x8D);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0);
	state.registers.setL(0);
	// testing the opcode
	testOpcode(0x8D);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0xff);
	state.registers.setL(1);
	// testing the opcode
	testOpcode(0x8D);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0x0f);
	state.registers.setL(1);
	// testing the opcode
	testOpcode(0x8D);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0x11);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0xff);
	state.registers.setL(1);
	// testing the opcode
	testOpcode(0x8D);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0xf0);
	state.registers.setL(0x10);
	// testing the opcode
	testOpcode(0x8D);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x8E)
{
	// 0x8E opcodeADC (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0);
	// testing the opcode
	testOpcode(0x8E);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0xff);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 1);
	// testing the opcode
	testOpcode(0x8E);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0x0f);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 1);
	// testing the opcode
	testOpcode(0x8E);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.setA(0x10);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0xf0);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0x11);
	// testing the opcode
	testOpcode(0x8E);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0);
	// testing the opcode
	testOpcode(0x8E);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0xff);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 1);
	// testing the opcode
	testOpcode(0x8E);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0x0f);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 1);
	// testing the opcode
	testOpcode(0x8E);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.setA(0x11);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0xff);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 1);
	// testing the opcode
	testOpcode(0x8E);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0xf0);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0x10);
	// testing the opcode
	testOpcode(0x8E);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x8F)
{
	// 0x8F opcodeADC A
	// preparing cpu and memory state before executing the opcode
	state.registers.resetCarryFlag();
	state.registers.setA(0);
	// testing the opcode
	testOpcode(0x8F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.resetCarryFlag();
	state.registers.setA(0x0f);
	// testing the opcode
	testOpcode(0x8F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0x1e);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.resetCarryFlag();
	state.registers.setA(0xff);
	// testing the opcode
	testOpcode(0x8F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0xfe);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.resetCarryFlag();
	state.registers.setA(0xf0);
	// testing the opcode
	testOpcode(0x8F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0xe0);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setCarryFlag();
	state.registers.setA(0);
	// testing the opcode
	testOpcode(0x8F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setCarryFlag();
	state.registers.setA(0x0f);
	// testing the opcode
	testOpcode(0x8F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0x1f);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setCarryFlag();
	state.registers.setA(0xff);
	// testing the opcode
	testOpcode(0x8F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0xff);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setCarryFlag();
	state.registers.setA(0xf0);
	// testing the opcode
	testOpcode(0x8F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0xe1);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0xCE)
{
	// 0xCE opcodeADC n
	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 0);
	// testing the opcode
	testOpcode(0xCE);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0xff);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 1);
	// testing the opcode
	testOpcode(0xCE);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0x0f);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 1);
	// testing the opcode
	testOpcode(0xCE);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0x10);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setA(0xf0);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 0x11);
	// testing the opcode
	testOpcode(0xCE);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 0);
	// testing the opcode
	testOpcode(0xCE);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0xff);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 1);
	// testing the opcode
	testOpcode(0xCE);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0x0f);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 1);
	// testing the opcode
	testOpcode(0xCE);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0x11);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0xff);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 1);
	// testing the opcode
	testOpcode(0xCE);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.setA(0xf0);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 0x10);
	// testing the opcode
	testOpcode(0xCE);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}
