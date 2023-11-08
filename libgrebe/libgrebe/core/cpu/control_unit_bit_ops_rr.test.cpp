#include <libgrebe/core/cpu/control_unit.test.hpp>

TEST_F(OpcodesBitOperationsTest, Test0xCB18)
{
	// 0x18 RR B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x18);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x18);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b10000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(1);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x18);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x18);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b10000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x18);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b01000100);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x18);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b00100010);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x18);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b00010001);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x18);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b00001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	testOpcodeCB(0x18);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b10000100);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x18);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b01000010);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x18);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b00100001);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x18);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	testOpcodeCB(0x18);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b10001000);
	expectedState.registers.clearFlags();
}

TEST_F(OpcodesBitOperationsTest, Test0xCB19)
{
	// 0x19 RR C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x19);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x19);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b10000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(1);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x19);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x19);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b10000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x19);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b01000100);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x19);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b00100010);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x19);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b00010001);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x19);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b00001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	testOpcodeCB(0x19);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b10000100);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x19);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b01000010);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x19);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b00100001);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x19);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	testOpcodeCB(0x19);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b10001000);
	expectedState.registers.clearFlags();
}

TEST_F(OpcodesBitOperationsTest, Test0xCB1A)
{
	// 0x1A RR D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b10000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(1);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b10000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b01000100);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x1A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b00100010);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x1A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b00010001);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x1A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b00001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	testOpcodeCB(0x1A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b10000100);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x1A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b01000010);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x1A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b00100001);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x1A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	testOpcodeCB(0x1A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b10001000);
	expectedState.registers.clearFlags();
}

TEST_F(OpcodesBitOperationsTest, Test0xCB1B)
{
	// 0x1B RR E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b10000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(1);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b10000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b01000100);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x1B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b00100010);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x1B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b00010001);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x1B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b00001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	testOpcodeCB(0x1B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b10000100);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x1B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b01000010);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x1B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b00100001);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x1B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	testOpcodeCB(0x1B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b10001000);
	expectedState.registers.clearFlags();
}

TEST_F(OpcodesBitOperationsTest, Test0xCB1C)
{
	// 0x1C RR H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b10000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(1);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b10000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b01000100);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x1C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b00100010);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x1C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b00010001);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x1C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b00001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	testOpcodeCB(0x1C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b10000100);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x1C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b01000010);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x1C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b00100001);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x1C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	testOpcodeCB(0x1C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b10001000);
	expectedState.registers.clearFlags();
}

TEST_F(OpcodesBitOperationsTest, Test0xCB1D)
{
	// 0x1D RR L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b10000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(1);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b10000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b01000100);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x1D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b00100010);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x1D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b00010001);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x1D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b00001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	testOpcodeCB(0x1D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b10000100);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x1D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b01000010);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x1D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b00100001);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x1D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	testOpcodeCB(0x1D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b10001000);
	expectedState.registers.clearFlags();
}

TEST_F(OpcodesBitOperationsTest, Test0xCB1E)
{
	// 0x1E RR (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b10000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 1);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b10000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b01000100);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x1E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b00100010);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x1E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b00010001);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x1E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b00001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	testOpcodeCB(0x1E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b10000100);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x1E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b01000010);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x1E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b00100001);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x1E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	testOpcodeCB(0x1E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b10001000);
	expectedState.registers.clearFlags();
}

TEST_F(OpcodesBitOperationsTest, Test0xCB1F)
{
	// 0x1F RR A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b10000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(1);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b10000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b01000100);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b00100010);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b00010001);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b00001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	testOpcodeCB(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b10000100);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b01000010);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b00100001);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	testOpcodeCB(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b10001000);
	expectedState.registers.clearFlags();
}
