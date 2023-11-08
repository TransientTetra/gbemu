#include <libgrebe/core/cpu/control_unit.test.hpp>

TEST_F(OpcodesAluTest, Test0x04)
{
	// 0x04 INC B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	// testing the opcode
	testOpcode(0x04);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setB(1);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0xff);
	// testing the opcode
	testOpcode(0x04);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setB(0);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0x0f);
	// testing the opcode
	testOpcode(0x04);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setB(0x10);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x14)
{
	// 0x14 INC D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	// testing the opcode
	testOpcode(0x14);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setD(1);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0xff);
	// testing the opcode
	testOpcode(0x14);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setD(0);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0x0f);
	// testing the opcode
	testOpcode(0x14);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setD(0x10);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	// testing the opcode
	testOpcode(0x14);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setD(1);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0xff);
	// testing the opcode
	testOpcode(0x14);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setD(0);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0x0f);
	// testing the opcode
	testOpcode(0x14);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setD(0x10);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x24)
{
	// 0x24 INC H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	// testing the opcode
	testOpcode(0x24);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setH(1);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0xff);
	// testing the opcode
	testOpcode(0x24);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setH(0);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0x0f);
	// testing the opcode
	testOpcode(0x24);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setH(0x10);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x34)
{
	// 0x34 INC (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0);
	// testing the opcode
	testOpcode(0x34);
	// expected change in registers and memory
	expectedState.clockCycles += 12;
	expectedState.registers.incPC();
	expectedState.mmu.write(0xdead, 1);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0xff);
	// testing the opcode
	testOpcode(0x34);
	// expected change in registers and memory
	expectedState.clockCycles += 12;
	expectedState.registers.incPC();
	expectedState.mmu.write(0xdead, 0);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0x0f);
	// testing the opcode
	testOpcode(0x34);
	// expected change in registers and memory
	expectedState.clockCycles += 12;
	expectedState.registers.incPC();
	expectedState.mmu.write(0xdead, 0x10);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x0C)
{
	// 0x0C INC C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	// testing the opcode
	testOpcode(0x0C);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setC(1);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0xff);
	// testing the opcode
	testOpcode(0x0C);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setC(0);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0x0f);
	// testing the opcode
	testOpcode(0x0C);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setC(0x10);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x1C)
{
	// 0x1C INC E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	// testing the opcode
	testOpcode(0x1C);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setE(1);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0xff);
	// testing the opcode
	testOpcode(0x1C);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setE(0);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0x0f);
	// testing the opcode
	testOpcode(0x1C);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setE(0x10);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x2C)
{
	// 0x2C INC L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	// testing the opcode
	testOpcode(0x2C);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setL(1);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0xff);
	// testing the opcode
	testOpcode(0x2C);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setL(0);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0x0f);
	// testing the opcode
	testOpcode(0x2C);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setL(0x10);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x3C)
{
	// 0x3C INC A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	// testing the opcode
	testOpcode(0x3C);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setA(1);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	// testing the opcode
	testOpcode(0x3C);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setA(0);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x0f);
	// testing the opcode
	testOpcode(0x3C);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setA(0x10);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}
