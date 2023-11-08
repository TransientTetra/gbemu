#include <libgrebe/core/cpu/control_unit.test.hpp>

TEST_F(OpcodesAluTest, Test0x05)
{
	// 0x05 DEC B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(3);
	// testing the opcode
	testOpcode(0x05);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setB(2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(1);
	// testing the opcode
	testOpcode(0x05);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setB(0);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0x10);
	// testing the opcode
	testOpcode(0x05);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setB(0x0f);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x15)
{
	// 0x15 DEC D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(3);
	// testing the opcode
	testOpcode(0x15);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setD(2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(1);
	// testing the opcode
	testOpcode(0x15);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setD(0);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0x10);
	// testing the opcode
	testOpcode(0x15);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setD(0x0f);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x25)
{
	// 0x25 DEC H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(3);
	// testing the opcode
	testOpcode(0x25);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setH(2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(1);
	// testing the opcode
	testOpcode(0x25);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setH(0);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0x10);
	// testing the opcode
	testOpcode(0x25);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setH(0x0f);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x35)
{
	// 0x35 DEC (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 3);
	// testing the opcode
	testOpcode(0x35);
	// expected change in registers and memory
	expectedState.clockCycles += 12;
	expectedState.registers.incPC();
	expectedState.mmu.write(0xdead, 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 1);
	// testing the opcode
	testOpcode(0x35);
	// expected change in registers and memory
	expectedState.clockCycles += 12;
	expectedState.registers.incPC();
	expectedState.mmu.write(0xdead, 0);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0x10);
	// testing the opcode
	testOpcode(0x35);
	// expected change in registers and memory
	expectedState.clockCycles += 12;
	expectedState.registers.incPC();
	expectedState.mmu.write(0xdead, 0x0f);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x0D)
{
	// 0x0D DEC C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(3);
	// testing the opcode
	testOpcode(0x0D);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setC(2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(1);
	// testing the opcode
	testOpcode(0x0D);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setC(0);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0x10);
	// testing the opcode
	testOpcode(0x0D);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setC(0x0f);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x1D)
{
	// 0x1D DEC E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(3);
	// testing the opcode
	testOpcode(0x1D);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setE(2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(1);
	// testing the opcode
	testOpcode(0x1D);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setE(0);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0x10);
	// testing the opcode
	testOpcode(0x1D);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setE(0x0f);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x2D)
{
	// 0x2D DEC L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(3);
	// testing the opcode
	testOpcode(0x2D);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setL(2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(1);
	// testing the opcode
	testOpcode(0x2D);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setL(0);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0x10);
	// testing the opcode
	testOpcode(0x2D);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setL(0x0f);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x3D)
{
	// 0x3D DEC A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(3);
	// testing the opcode
	testOpcode(0x3D);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setA(2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(1);
	// testing the opcode
	testOpcode(0x3D);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setA(0);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x10);
	// testing the opcode
	testOpcode(0x3D);
	// expected change in registers and memory
	expectedState.registers.incPC();
	expectedState.clockCycles += 4;
	expectedState.registers.setA(0x0f);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}
