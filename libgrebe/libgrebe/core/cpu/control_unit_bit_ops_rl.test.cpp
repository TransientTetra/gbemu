#include <libgrebe/core/cpu/control_unit.test.hpp>

TEST_F(OpcodesBitOperationsTest, Test0xCB10)
{
	// 0x10 RL B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x10);
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
	testOpcodeCB(0x10);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(1);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0b10000000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x10);
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
	testOpcodeCB(0x10);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x10);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x10);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b00100001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x10);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b01000010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x10);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b10000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x10);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b00001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x10);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x10);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x10);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x10);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b10001000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB11)
{
	// 0x11 RL C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x11);
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
	testOpcodeCB(0x11);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(1);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0b10000000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x11);
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
	testOpcodeCB(0x11);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x11);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x11);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b00100001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x11);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b01000010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x11);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b10000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x11);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b00001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x11);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x11);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x11);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x11);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b10001000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB12)
{
	// 0x12 RL D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x12);
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
	testOpcodeCB(0x12);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(1);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0b10000000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x12);
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
	testOpcodeCB(0x12);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x12);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x12);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b00100001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x12);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b01000010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x12);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b10000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x12);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b00001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x12);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x12);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x12);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x12);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b10001000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB13)
{
	// 0x13 RL E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x13);
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
	testOpcodeCB(0x13);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(1);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0b10000000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x13);
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
	testOpcodeCB(0x13);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x13);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x13);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b00100001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x13);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b01000010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x13);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b10000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x13);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b00001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x13);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x13);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x13);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x13);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b10001000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB14)
{
	// 0x14 RL H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x14);
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
	testOpcodeCB(0x14);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(1);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0b10000000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x14);
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
	testOpcodeCB(0x14);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x14);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x14);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b00100001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x14);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b01000010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x14);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b10000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x14);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b00001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x14);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x14);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x14);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x14);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b10001000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB15)
{
	// 0x15 RL L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x15);
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
	testOpcodeCB(0x15);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(1);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0b10000000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x15);
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
	testOpcodeCB(0x15);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x15);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x15);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b00100001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x15);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b01000010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x15);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b10000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x15);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b00001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x15);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x15);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x15);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x15);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b10001000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB16)
{
	// 0x16 RL (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x16);
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
	testOpcodeCB(0x16);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 1);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0b10000000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x16);
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
	testOpcodeCB(0x16);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x16);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x16);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b00100001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x16);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b01000010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x16);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b10000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x16);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b00001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x16);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x16);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x16);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x16);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b10001000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB17)
{
	// 0x17 RL A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x17);
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
	testOpcodeCB(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10000000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x17);
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
	testOpcodeCB(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b00100001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b01000010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b10000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b00001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b10001000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}
