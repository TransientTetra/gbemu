#include <libgrebe/core/cpu/control_unit.test.hpp>

TEST_F(OpcodesBitOperationsTest, Test0xCB08)
{
	// 0x08 RRC B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x08);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x08);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b00000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x08);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x08);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x08);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x08);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b10001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x08);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x08);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x08);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x08);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b10001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB09)
{
	// 0x09 RRC C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x09);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x09);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b00000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x09);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x09);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x09);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x09);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b10001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x09);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x09);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x09);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x09);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b10001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB0A)
{
	// 0x0A RRC D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x0A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x0A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b00000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x0A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b10001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0A);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b10001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB0B)
{
	// 0x0B RRC E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x0B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x0B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b00000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x0B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b10001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0B);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b10001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB0C)
{
	// 0x0C RRC H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x0C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x0C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b00000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x0C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b10001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0C);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b10001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB0D)
{
	// 0x0D RRC L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x0D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x0D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b00000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x0D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b10001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0D);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b10001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB0E)
{
	// 0x0E RRC (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x0E);
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
	state.mmu.write(0xdead, 0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x0E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b00000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x0E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b10001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b10001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB0F)
{
	// 0x0F RRC A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b00000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b10001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b10001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}
