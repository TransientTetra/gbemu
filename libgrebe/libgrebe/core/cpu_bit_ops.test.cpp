#include <libgrebe/core/cpu.test.hpp>

void OpcodesBitOperationsTest::testOpcodeRLC(Byte opcode, Byte& reg, Byte& expectedReg)
{
	// preparing cpu and memory state before executing the opcode
	reg = 0;
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	reg = 0b00001000;
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00010000;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	reg = 0b10001000;
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00010001;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00100010;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b01000100;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b10001000;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00010001;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00100010;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b01000100;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b10001000;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

void OpcodesBitOperationsTest::testOpcodeRRC(Byte opcode, Byte& reg, Byte& expectedReg)
{
	// preparing cpu and memory state before executing the opcode
	reg = 0;
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	reg = 0b00001000;
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00000100;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	reg = 0b10001000;
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b01000100;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00100010;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00010001;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b10001000;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b01000100;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00100010;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00010001;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b10001000;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

void OpcodesBitOperationsTest::testOpcodeRL(Byte opcode, Byte& reg, Byte& expectedReg)
{
	// preparing cpu and memory state before executing the opcode
	reg = 0;
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	reg = 0;
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 1;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	reg = 0b10000000;
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	reg = 0b00001000;
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00010001;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	reg = 0b10001000;
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00010000;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00100001;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b01000010;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b10000100;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00001000;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00010001;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00100010;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b01000100;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b10001000;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

void OpcodesBitOperationsTest::testOpcodeRR(Byte opcode, Byte& reg, Byte& expectedReg)
{
	// preparing cpu and memory state before executing the opcode
	reg = 0;
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	reg = 0;
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b10000000;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	reg = 1;
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	reg = 0b00001000;
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b10000100;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	reg = 0b10001000;
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b01000100;
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00100010;
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00010001;
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00001000;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b10000100;
	expectedState.registers.clearFlags();
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b01000010;
	expectedState.registers.clearFlags();
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00100001;
	expectedState.registers.clearFlags();
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00010000;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b10001000;
	expectedState.registers.clearFlags();
}

void OpcodesBitOperationsTest::testOpcodeSLA(Byte opcode, Byte& reg, Byte& expectedReg)
{
	// preparing cpu and memory state before executing the opcode
	reg = 0;
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	reg = 0b00001000;
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00010000;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	reg = 0b10001000;
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00010000;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00100000;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b01000000;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b10000000;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
}

void OpcodesBitOperationsTest::testOpcodeSRA(Byte opcode, Byte& reg, Byte& expectedReg)
{
	// preparing cpu and memory state before executing the opcode
	reg = 0;
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	reg = 0b00001000;
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00000100;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	reg = 0b10001000;
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b11000100;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b11100010;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b11110001;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b11111000;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b11111100;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b11111110;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b11111111;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b11111111;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

void OpcodesBitOperationsTest::testOpcodeSWAP(Byte opcode, Byte& reg, Byte& expectedReg)
{
	// preparing cpu and memory state before executing the opcode
	reg = 0;
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	reg = 0x69;
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0x96;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

void OpcodesBitOperationsTest::testOpcodeSRL(Byte opcode, Byte& reg, Byte& expectedReg)
{
	// preparing cpu and memory state before executing the opcode
	reg = 0;
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	reg = 0b00001000;
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00000100;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	reg = 0b10001000;
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b01000100;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00100010;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00010001;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00001000;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00000100;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00000010;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00000001;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

void OpcodesBitOperationsTest::testOpcodeBIT(Byte opcode, Byte& reg, Byte& expectedReg, Byte bit)
{
	// preparing cpu and memory state before executing the opcode
	reg = 0xff;
	reg &= ~(1 << bit);
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	reg = 0;
	reg |= 1 << bit;
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

void OpcodesBitOperationsTest::testOpcodeRES(Byte opcode, Byte& reg, Byte& expectedReg, Byte bit)
{
	// preparing cpu and memory state before executing the opcode
	reg = 0xff;
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0xff & ~(1 << bit);
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	reg = 0;
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

void OpcodesBitOperationsTest::testOpcodeSET(Byte opcode, Byte& reg, Byte& expectedReg, Byte bit)
{
	// preparing cpu and memory state before executing the opcode
	reg = 0xff;
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 0xff;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	reg = 0;
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 2;
	expectedReg = 1 << bit;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

void OpcodesBitOperationsTest::testOpcodeBIThl(Byte opcode, Byte bit)
{
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0xff & ~(1 << bit));
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 12;
	expectedState.registers.pc += 2;
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, (1 << bit));
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 12;
	expectedState.registers.pc += 2;
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

void OpcodesBitOperationsTest::testOpcodeREShl(Byte opcode, Byte bit)
{
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0xff);
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0xff & ~(1 << bit));
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0);
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

void OpcodesBitOperationsTest::testOpcodeSEThl(Byte opcode, Byte bit)
{
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0xff);
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0);
	// testing the opcode
	testOpcodeCB(opcode);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 1 << bit);
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(OpcodesBitOperationsTest, Test0x07)
{
	// 0x07 RLCA
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcode(0x07);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b00001000;
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcode(0x07);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00010000;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b10001000;
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcode(0x07);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00010001;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcode(0x07);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00100010;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcode(0x07);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b01000100;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcode(0x07);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b10001000;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcode(0x07);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00010001;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcode(0x07);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00100010;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcode(0x07);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b01000100;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcode(0x07);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b10001000;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}
TEST_F(OpcodesBitOperationsTest, Test0x17)
{
	// 0x17 RLA
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcode(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcode(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 1;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b10000000;
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcode(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b00001000;
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcode(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00010001;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b10001000;
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcode(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00010000;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcode(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00100001;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcode(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b01000010;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcode(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b10000100;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcode(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00001000;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcode(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00010001;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcode(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00100010;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcode(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b01000100;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcode(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b10001000;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}
TEST_F(OpcodesBitOperationsTest, Test0x0F)
{
	// 0x0F RRCA
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcode(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b00001000;
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcode(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00000100;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b10001000;
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcode(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b01000100;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcode(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00100010;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcode(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00010001;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcode(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b10001000;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcode(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b01000100;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcode(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00100010;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcode(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00010001;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcode(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b10001000;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}
TEST_F(OpcodesBitOperationsTest, Test0x1F)
{
	// 0x1F RRA
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcode(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcode(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b10000000;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 1;
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcode(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b00001000;
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcode(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b10000100;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b10001000;
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcode(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b01000100;
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcode(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00100010;
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcode(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00010001;
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcode(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00001000;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	testOpcode(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b10000100;
	expectedState.registers.clearFlags();
	testOpcode(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b01000010;
	expectedState.registers.clearFlags();
	testOpcode(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00100001;
	expectedState.registers.clearFlags();
	testOpcode(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00010000;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	testOpcode(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b10001000;
	expectedState.registers.clearFlags();
}

TEST_F(OpcodesBitOperationsTest, Test0xCB00)
{
	// 0x00 RLC B
	testOpcodeRLC(0x00, state.registers.b, expectedState.registers.b);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB01)
{
	// 0x01 RLC C
	testOpcodeRLC(0x01, state.registers.c, expectedState.registers.c);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB02)
{
	// 0x02 RLC D
	testOpcodeRLC(0x02, state.registers.d, expectedState.registers.d);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB03)
{
	// 0x03 RLC E
	testOpcodeRLC(0x03, state.registers.e, expectedState.registers.e);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB04)
{
	// 0x04 RLC H
	testOpcodeRLC(0x04, state.registers.h, expectedState.registers.h);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB05)
{
	// 0x05 RLC L
	testOpcodeRLC(0x05, state.registers.l, expectedState.registers.l);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB06)
{
	// 0x06 RLC (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x06);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x06);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00010000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x06);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00010001);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x06);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x06);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x06);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b10001000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x06);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00010001);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x06);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x06);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x06);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b10001000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB07)
{
	// 0x07 RLC A
	testOpcodeRLC(0x07, state.registers.a, expectedState.registers.a);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB08)
{
	// 0x08 RRC B
	testOpcodeRRC(0x08, state.registers.b, expectedState.registers.b);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB09)
{
	// 0x09 RRC C
	testOpcodeRRC(0x09, state.registers.c, expectedState.registers.c);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB0A)
{
	// 0x0A RRC D
	testOpcodeRRC(0x0A, state.registers.d, expectedState.registers.d);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB0B)
{
	// 0x0B RRC E
	testOpcodeRRC(0x0B, state.registers.e, expectedState.registers.e);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB0C)
{
	// 0x0C RRC H
	testOpcodeRRC(0x0C, state.registers.h, expectedState.registers.h);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB0D)
{
	// 0x0D RRC L
	testOpcodeRRC(0x0D, state.registers.l, expectedState.registers.l);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB0E)
{
	// 0x0E RRC (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x0E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x0E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x0E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x0E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x0E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x0E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b10001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x0E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x0E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x0E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x0E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b10001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB0F)
{
	// 0x0F RRC A
	testOpcodeRRC(0x0F, state.registers.a, expectedState.registers.a);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB10)
{
	// 0x10 RL B
	testOpcodeRL(0x10, state.registers.b, expectedState.registers.b);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB11)
{
	// 0x11 RL C
	testOpcodeRL(0x11, state.registers.c, expectedState.registers.c);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB12)
{
	// 0x12 RL D
	testOpcodeRL(0x12, state.registers.d, expectedState.registers.d);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB13)
{
	// 0x13 RL E
	testOpcodeRL(0x13, state.registers.e, expectedState.registers.e);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB14)
{
	// 0x14 RL H
	testOpcodeRL(0x14, state.registers.h, expectedState.registers.h);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB15)
{
	// 0x15 RL L
	testOpcodeRL(0x15, state.registers.l, expectedState.registers.l);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB16)
{
	// 0x16 RL (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x16);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x16);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 1);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b10000000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x16);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x16);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x16);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x16);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00100001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x16);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b01000010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x16);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b10000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x16);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x16);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x16);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x16);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x16);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b10001000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB17)
{
	// 0x17 RL A
	testOpcodeRL(0x17, state.registers.a, expectedState.registers.a);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB18)
{
	// 0x18 RR B
	testOpcodeRR(0x18, state.registers.b, expectedState.registers.b);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB19)
{
	// 0x19 RR C
	testOpcodeRR(0x19, state.registers.c, expectedState.registers.c);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB1A)
{
	// 0x1A RR D
	testOpcodeRR(0x1A, state.registers.d, expectedState.registers.d);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB1B)
{
	// 0x1B RR E
	testOpcodeRR(0x1B, state.registers.e, expectedState.registers.e);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB1C)
{
	// 0x1C RR H
	testOpcodeRR(0x1C, state.registers.h, expectedState.registers.h);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB1D)
{
	// 0x1D RR L
	testOpcodeRR(0x1D, state.registers.l, expectedState.registers.l);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB1E)
{
	// 0x1E RR (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b10000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 1);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b10000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x1E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b01000100);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x1E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00100010);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x1E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00010001);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcodeCB(0x1E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	testOpcodeCB(0x1E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b10000100);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x1E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b01000010);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x1E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00100001);
	expectedState.registers.clearFlags();
	testOpcodeCB(0x1E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	testOpcodeCB(0x1E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b10001000);
	expectedState.registers.clearFlags();
}

TEST_F(OpcodesBitOperationsTest, Test0xCB1F)
{
	// 0x1F RR A
	testOpcodeRR(0x1F, state.registers.a, expectedState.registers.a);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB20)
{
	// 0x20 SLA B
	testOpcodeSLA(0x20, state.registers.b, expectedState.registers.b);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB21)
{
	// 0x21 SLA C
	testOpcodeSLA(0x21, state.registers.c, expectedState.registers.c);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB22)
{
	// 0x22 SLA D
	testOpcodeSLA(0x22, state.registers.d, expectedState.registers.d);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB23)
{
	// 0x23 SLA E
	testOpcodeSLA(0x23, state.registers.e, expectedState.registers.e);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB24)
{
	// 0x24 SLA H
	testOpcodeSLA(0x24, state.registers.h, expectedState.registers.h);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB25)
{
	// 0x25 SLA L
	testOpcodeSLA(0x25, state.registers.l, expectedState.registers.l);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB26)
{
	// 0x26 SLA (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x26);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x26);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00010000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x26);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x26);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00100000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x26);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b01000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x26);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b10000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x26);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x26);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB27)
{
	// 0x27 SLA A
	testOpcodeSLA(0x27, state.registers.a, expectedState.registers.a);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB28)
{
	// 0x28 SRA B
	testOpcodeSRA(0x28, state.registers.b, expectedState.registers.b);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB29)
{
	// 0x29 SRA C
	testOpcodeSRA(0x29, state.registers.c, expectedState.registers.c);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB2A)
{
	// 0x2A SRA D
	testOpcodeSRA(0x2A, state.registers.d, expectedState.registers.d);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB2B)
{
	// 0x2B SRA E
	testOpcodeSRA(0x2B, state.registers.e, expectedState.registers.e);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB2C)
{
	// 0x2C SRA H
	testOpcodeSRA(0x2C, state.registers.h, expectedState.registers.h);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB2D)
{
	// 0x2D SRA L
	testOpcodeSRA(0x2D, state.registers.l, expectedState.registers.l);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB2E)
{
	// 0x2E SRA (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x2E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x2E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x2E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b11000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x2E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b11100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x2E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b11110001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x2E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b11111000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x2E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b11111100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x2E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b11111110);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x2E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b11111111);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x2E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b11111111);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB2F)
{
	// 0x2F SRA A
	testOpcodeSRA(0x2F, state.registers.a, expectedState.registers.a);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB30)
{
	// 0x30 SWAP B
	testOpcodeSWAP(0x30, state.registers.b, expectedState.registers.b);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB31)
{
	// 0x31 SWAP C
	testOpcodeSWAP(0x31, state.registers.c, expectedState.registers.c);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB32)
{
	// 0x32 SWAP D
	testOpcodeSWAP(0x32, state.registers.d, expectedState.registers.d);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB33)
{
	// 0x33 SWAP E
	testOpcodeSWAP(0x33, state.registers.e, expectedState.registers.e);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB34)
{
	// 0x34 SWAP H
	testOpcodeSWAP(0x34, state.registers.h, expectedState.registers.h);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB35)
{
	// 0x35 SWAP L
	testOpcodeSWAP(0x35, state.registers.l, expectedState.registers.l);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB36)
{
	// 0x36 SWAP (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0);
	// testing the opcode
	testOpcodeCB(0x36);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0x69);
	// testing the opcode
	testOpcodeCB(0x36);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0x96);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB37)
{
	// 0x37 SWAP A
	testOpcodeSWAP(0x37, state.registers.a, expectedState.registers.a);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB38)
{
	// 0x38 SRL B
	testOpcodeSRL(0x38, state.registers.b, expectedState.registers.b);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB39)
{
	// 0x39 SRL C
	testOpcodeSRL(0x39, state.registers.c, expectedState.registers.c);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB3A)
{
	// 0x3A SRL D
	testOpcodeSRL(0x3A, state.registers.d, expectedState.registers.d);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB3B)
{
	// 0x3B SRL E
	testOpcodeSRL(0x3B, state.registers.e, expectedState.registers.e);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB3C)
{
	// 0x3C SRL H
	testOpcodeSRL(0x3C, state.registers.h, expectedState.registers.h);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB3D)
{
	// 0x3D SRL L
	testOpcodeSRL(0x3D, state.registers.l, expectedState.registers.l);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB3E)
{
	// 0x3E SRL (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x3E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x3E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x3E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x3E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x3E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x3E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x3E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x3E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00000010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x3E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00000001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x3E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	testOpcodeCB(0x3E);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB3F)
{
	// 0x3F SRL A
	testOpcodeSRL(0x3F, state.registers.a, expectedState.registers.a);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB40)
{
	// 0x40 BIT 0, B
	testOpcodeBIT(0x40, state.registers.b, expectedState.registers.b, 0);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB41)
{
	// 0x41 BIT 0, C
	testOpcodeBIT(0x41, state.registers.c, expectedState.registers.c, 0);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB42)
{
	// 0x42 BIT 0, D
	testOpcodeBIT(0x42, state.registers.d, expectedState.registers.d, 0);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB43)
{
	// 0x43 BIT 0, E
	testOpcodeBIT(0x43, state.registers.e, expectedState.registers.e, 0);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB44)
{
	// 0x44 BIT 0, H
	testOpcodeBIT(0x44, state.registers.h, expectedState.registers.h, 0);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB45)
{
	// 0x45 BIT 0, L
	testOpcodeBIT(0x45, state.registers.l, expectedState.registers.l, 0);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB46)
{
	// 0x46 BIT 0, (HL)
	testOpcodeBIThl(0x46, 0);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB47)
{
	// 0x47 BIT 0, A
	testOpcodeBIT(0x47, state.registers.a, expectedState.registers.a, 0);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB48)
{
	// 0x48 BIT 1, B
	testOpcodeBIT(0x48, state.registers.b, expectedState.registers.b, 1);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB49)
{
	// 0x49 BIT 1, C
	testOpcodeBIT(0x49, state.registers.c, expectedState.registers.c, 1);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB4A)
{
	// 0x4A BIT 1, D
	testOpcodeBIT(0x4A, state.registers.d, expectedState.registers.d, 1);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB4B)
{
	// 0x4B BIT 1, E
	testOpcodeBIT(0x4B, state.registers.e, expectedState.registers.e, 1);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB4C)
{
	// 0x4C BIT 1, H
	testOpcodeBIT(0x4C, state.registers.h, expectedState.registers.h, 1);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB4D)
{
	// 0x4D BIT 1, L
	testOpcodeBIT(0x4D, state.registers.l, expectedState.registers.l, 1);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB4E)
{
	// 0x4E BIT 1, (HL)
	testOpcodeBIThl(0x4E, 1);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB4F)
{
	// 0x4F BIT 1, A
	testOpcodeBIT(0x4F, state.registers.a, expectedState.registers.a, 1);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB50)
{
	// 0x50 BIT 2, B
	testOpcodeBIT(0x50, state.registers.b, expectedState.registers.b, 2);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB51)
{
	// 0x51 BIT 2, C
	testOpcodeBIT(0x51, state.registers.c, expectedState.registers.c, 2);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB52)
{
	// 0x52 BIT 2, D
	testOpcodeBIT(0x52, state.registers.d, expectedState.registers.d, 2);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB53)
{
	// 0x53 BIT 2, E
	testOpcodeBIT(0x53, state.registers.e, expectedState.registers.e, 2);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB54)
{
	// 0x54 BIT 2, H
	testOpcodeBIT(0x54, state.registers.h, expectedState.registers.h, 2);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB55)
{
	// 0x55 BIT 2, L
	testOpcodeBIT(0x55, state.registers.l, expectedState.registers.l, 2);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB56)
{
	// 0x56 BIT 2, (HL)
	testOpcodeBIThl(0x56, 2);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB57)
{
	// 0x57 BIT 2, A
	testOpcodeBIT(0x57, state.registers.a, expectedState.registers.a, 2);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB58)
{
	// 0x58 BIT 3, B
	testOpcodeBIT(0x58, state.registers.b, expectedState.registers.b, 3);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB59)
{
	// 0x59 BIT 3, C
	testOpcodeBIT(0x59, state.registers.c, expectedState.registers.c, 3);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB5A)
{
	// 0x5A BIT 3, D
	testOpcodeBIT(0x5A, state.registers.d, expectedState.registers.d, 3);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB5B)
{
	// 0x5B BIT 3, E
	testOpcodeBIT(0x5B, state.registers.e, expectedState.registers.e, 3);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB5C)
{
	// 0x5C BIT 3, H
	testOpcodeBIT(0x5C, state.registers.h, expectedState.registers.h, 3);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB5D)
{
	// 0x5D BIT 3, L
	testOpcodeBIT(0x5D, state.registers.l, expectedState.registers.l, 3);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB5E)
{
	// 0x5E BIT 3, (HL)
	testOpcodeBIThl(0x5E, 3);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB5F)
{
	// 0x5F BIT 3, A
	testOpcodeBIT(0x5F, state.registers.a, expectedState.registers.a, 3);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB60)
{
	// 0x60 BIT 4, B
	testOpcodeBIT(0x60, state.registers.b, expectedState.registers.b, 4);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB61)
{
	// 0x61 BIT 4, C
	testOpcodeBIT(0x61, state.registers.c, expectedState.registers.c, 4);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB62)
{
	// 0x62 BIT 4, D
	testOpcodeBIT(0x62, state.registers.d, expectedState.registers.d, 4);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB63)
{
	// 0x63 BIT 4, E
	testOpcodeBIT(0x63, state.registers.e, expectedState.registers.e, 4);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB64)
{
	// 0x64 BIT 4, H
	testOpcodeBIT(0x64, state.registers.h, expectedState.registers.h, 4);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB65)
{
	// 0x65 BIT 4, L
	testOpcodeBIT(0x65, state.registers.l, expectedState.registers.l, 4);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB66)
{
	// 0x66 BIT 4, (HL)
	testOpcodeBIThl(0x66, 4);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB67)
{
	// 0x67 BIT 4, A
	testOpcodeBIT(0x67, state.registers.a, expectedState.registers.a, 4);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB68)
{
	// 0x68 BIT 5, B
	testOpcodeBIT(0x68, state.registers.b, expectedState.registers.b, 5);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB69)
{
	// 0x69 BIT 5, C
	testOpcodeBIT(0x69, state.registers.c, expectedState.registers.c, 5);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB6A)
{
	// 0x6A BIT 5, D
	testOpcodeBIT(0x6A, state.registers.d, expectedState.registers.d, 5);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB6B)
{
	// 0x6B BIT 5, E
	testOpcodeBIT(0x6B, state.registers.e, expectedState.registers.e, 5);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB6C)
{
	// 0x6C BIT 5, H
	testOpcodeBIT(0x6C, state.registers.h, expectedState.registers.h, 5);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB6D)
{
	// 0x6D BIT 5, L
	testOpcodeBIT(0x6D, state.registers.l, expectedState.registers.l, 5);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB6E)
{
	// 0x6E BIT 5, (HL)
	testOpcodeBIThl(0x6E, 5);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB6F)
{
	// 0x6F BIT 5, A
	testOpcodeBIT(0x6F, state.registers.a, expectedState.registers.a, 5);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB70)
{
	// 0x70 BIT 6, B
	testOpcodeBIT(0x70, state.registers.b, expectedState.registers.b, 6);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB71)
{
	// 0x71 BIT 6, C
	testOpcodeBIT(0x71, state.registers.c, expectedState.registers.c, 6);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB72)
{
	// 0x72 BIT 6, D
	testOpcodeBIT(0x72, state.registers.d, expectedState.registers.d, 6);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB73)
{
	// 0x73 BIT 6, E
	testOpcodeBIT(0x73, state.registers.e, expectedState.registers.e, 6);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB74)
{
	// 0x74 BIT 6, H
	testOpcodeBIT(0x74, state.registers.h, expectedState.registers.h, 6);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB75)
{
	// 0x75 BIT 6, L
	testOpcodeBIT(0x75, state.registers.l, expectedState.registers.l, 6);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB76)
{
	// 0x76 BIT 6, (HL)
	testOpcodeBIThl(0x76, 6);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB77)
{
	// 0x77 BIT 6, A
	testOpcodeBIT(0x77, state.registers.a, expectedState.registers.a, 6);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB78)
{
	// 0x78 BIT 7, B
	testOpcodeBIT(0x78, state.registers.b, expectedState.registers.b, 7);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB79)
{
	// 0x79 BIT 7, C
	testOpcodeBIT(0x79, state.registers.c, expectedState.registers.c, 7);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB7A)
{
	// 0x7A BIT 7, D
	testOpcodeBIT(0x7A, state.registers.d, expectedState.registers.d, 7);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB7B)
{
	// 0x7B BIT 7, E
	testOpcodeBIT(0x7B, state.registers.e, expectedState.registers.e, 7);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB7C)
{
	// 0x7C BIT 7, H
	testOpcodeBIT(0x7C, state.registers.h, expectedState.registers.h, 7);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB7D)
{
	// 0x7D BIT 7, L
	testOpcodeBIT(0x7D, state.registers.l, expectedState.registers.l, 7);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB7E)
{
	// 0x7E BIT 7, (HL)
	testOpcodeBIThl(0x7E, 7);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB7F)
{
	// 0x7F BIT 7, A
	testOpcodeBIT(0x7F, state.registers.a, expectedState.registers.a, 7);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB80)
{
	// 0x80 RES 0, B
	testOpcodeRES(0x80, state.registers.b, expectedState.registers.b, 0);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB81)
{
	// 0x81 RES 0, C
	testOpcodeRES(0x81, state.registers.c, expectedState.registers.c, 0);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB82)
{
	// 0x82 RES 0, D
	testOpcodeRES(0x82, state.registers.d, expectedState.registers.d, 0);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB83)
{
	// 0x83 RES 0, E
	testOpcodeRES(0x83, state.registers.e, expectedState.registers.e, 0);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB84)
{
	// 0x84 RES 0, H
	testOpcodeRES(0x84, state.registers.h, expectedState.registers.h, 0);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB85)
{
	// 0x85 RES 0, L
	testOpcodeRES(0x85, state.registers.l, expectedState.registers.l, 0);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB86)
{
	// 0x86 RES 0, (HL)
	testOpcodeREShl(0x86, 0);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB87)
{
	// 0x87 RES 0, A
	testOpcodeRES(0x87, state.registers.a, expectedState.registers.a, 0);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB88)
{
	// 0x88 RES 1, B
	testOpcodeRES(0x88, state.registers.b, expectedState.registers.b, 1);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB89)
{
	// 0x89 RES 1, C
	testOpcodeRES(0x89, state.registers.c, expectedState.registers.c, 1);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB8A)
{
	// 0x8A RES 1, D
	testOpcodeRES(0x8A, state.registers.d, expectedState.registers.d, 1);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB8B)
{
	// 0x8B RES 1, E
	testOpcodeRES(0x8B, state.registers.e, expectedState.registers.e, 1);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB8C)
{
	// 0x8C RES 1, H
	testOpcodeRES(0x8C, state.registers.h, expectedState.registers.h, 1);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB8D)
{
	// 0x8D RES 1, L
	testOpcodeRES(0x8D, state.registers.l, expectedState.registers.l, 1);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB8E)
{
	// 0x8E RES 1, (HL)
	testOpcodeREShl(0x8E, 1);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB8F)
{
	// 0x8F RES 1, A
	testOpcodeRES(0x8F, state.registers.a, expectedState.registers.a, 1);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB90)
{
	// 0x90 RES 2, B
	testOpcodeRES(0x90, state.registers.b, expectedState.registers.b, 2);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB91)
{
	// 0x91 RES 2, C
	testOpcodeRES(0x91, state.registers.c, expectedState.registers.c, 2);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB92)
{
	// 0x92 RES 2, D
	testOpcodeRES(0x92, state.registers.d, expectedState.registers.d, 2);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB93)
{
	// 0x93 RES 2, E
	testOpcodeRES(0x93, state.registers.e, expectedState.registers.e, 2);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB94)
{
	// 0x94 RES 2, H
	testOpcodeRES(0x94, state.registers.h, expectedState.registers.h, 2);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB95)
{
	// 0x95 RES 2, L
	testOpcodeRES(0x95, state.registers.l, expectedState.registers.l, 2);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB96)
{
	// 0x96 RES 2, (HL)
	testOpcodeREShl(0x96, 2);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB97)
{
	// 0x97 RES 2, A
	testOpcodeRES(0x97, state.registers.a, expectedState.registers.a, 2);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB98)
{
	// 0x98 RES 3, B
	testOpcodeRES(0x98, state.registers.b, expectedState.registers.b, 3);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB99)
{
	// 0x99 RES 3, C
	testOpcodeRES(0x99, state.registers.c, expectedState.registers.c, 3);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB9A)
{
	// 0x9A RES 3, D
	testOpcodeRES(0x9A, state.registers.d, expectedState.registers.d, 3);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB9B)
{
	// 0x9B RES 3, E
	testOpcodeRES(0x9B, state.registers.e, expectedState.registers.e, 3);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB9C)
{
	// 0x9C RES 3, H
	testOpcodeRES(0x9C, state.registers.h, expectedState.registers.h, 3);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB9D)
{
	// 0x9D RES 3, L
	testOpcodeRES(0x9D, state.registers.l, expectedState.registers.l, 3);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB9E)
{
	// 0x9E RES 3, (HL)
	testOpcodeREShl(0x9E, 3);
}

TEST_F(OpcodesBitOperationsTest, Test0xCB9F)
{
	// 0x9F RES 3, A
	testOpcodeRES(0x9F, state.registers.a, expectedState.registers.a, 3);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBA0)
{
	// 0xA0 RES 4, B
	testOpcodeRES(0xA0, state.registers.b, expectedState.registers.b, 4);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBA1)
{
	// 0xA1 RES 4, C
	testOpcodeRES(0xA1, state.registers.c, expectedState.registers.c, 4);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBA2)
{
	// 0xA2 RES 4, D
	testOpcodeRES(0xA2, state.registers.d, expectedState.registers.d, 4);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBA3)
{
	// 0xA3 RES 4, E
	testOpcodeRES(0xA3, state.registers.e, expectedState.registers.e, 4);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBA4)
{
	// 0xA4 RES 4, H
	testOpcodeRES(0xA4, state.registers.h, expectedState.registers.h, 4);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBA5)
{
	// 0xA5 RES 4, L
	testOpcodeRES(0xA5, state.registers.l, expectedState.registers.l, 4);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBA6)
{
	// 0xA6 RES 4, (HL)
	testOpcodeREShl(0xA6, 4);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBA7)
{
	// 0xA7 RES 4, A
	testOpcodeRES(0xA7, state.registers.a, expectedState.registers.a, 4);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBA8)
{
	// 0xA8 RES 5, B
	testOpcodeRES(0xA8, state.registers.b, expectedState.registers.b, 5);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBA9)
{
	// 0xA9 RES 5, C
	testOpcodeRES(0xA9, state.registers.c, expectedState.registers.c, 5);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBAA)
{
	// 0xAA RES 5, D
	testOpcodeRES(0xAA, state.registers.d, expectedState.registers.d, 5);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBAB)
{
	// 0xAB RES 5, E
	testOpcodeRES(0xAB, state.registers.e, expectedState.registers.e, 5);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBAC)
{
	// 0xAC RES 5, H
	testOpcodeRES(0xAC, state.registers.h, expectedState.registers.h, 5);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBAD)
{
	// 0xAD RES 5, L
	testOpcodeRES(0xAD, state.registers.l, expectedState.registers.l, 5);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBAE)
{
	// 0xAE RES 5, (HL)
	testOpcodeREShl(0xAE, 5);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBAF)
{
	// 0xAF RES 5, A
	testOpcodeRES(0xAF, state.registers.a, expectedState.registers.a, 5);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBB0)
{
	// 0xB0 RES 6, B
	testOpcodeRES(0xB0, state.registers.b, expectedState.registers.b, 6);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBB1)
{
	// 0xB1 RES 6, C
	testOpcodeRES(0xB1, state.registers.c, expectedState.registers.c, 6);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBB2)
{
	// 0xB2 RES 6, D
	testOpcodeRES(0xB2, state.registers.d, expectedState.registers.d, 6);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBB3)
{
	// 0xB3 RES 6, E
	testOpcodeRES(0xB3, state.registers.e, expectedState.registers.e, 6);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBB4)
{
	// 0xB4 RES 6, H
	testOpcodeRES(0xB4, state.registers.h, expectedState.registers.h, 6);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBB5)
{
	// 0xB5 RES 6, L
	testOpcodeRES(0xB5, state.registers.l, expectedState.registers.l, 6);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBB6)
{
	// 0xB6 RES 6, (HL)
	testOpcodeREShl(0xB6, 6);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBB7)
{
	// 0xB7 RES 6, A
	testOpcodeRES(0xB7, state.registers.a, expectedState.registers.a, 6);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBB8)
{
	// 0xB8 RES 7, B
	testOpcodeRES(0xB8, state.registers.b, expectedState.registers.b, 7);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBB9)
{
	// 0xB9 RES 7, C
	testOpcodeRES(0xB9, state.registers.c, expectedState.registers.c, 7);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBBA)
{
	// 0xBA RES 7, D
	testOpcodeRES(0xBA, state.registers.d, expectedState.registers.d, 7);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBBB)
{
	// 0xBB RES 7, E
	testOpcodeRES(0xBB, state.registers.e, expectedState.registers.e, 7);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBBC)
{
	// 0xBC RES 7, H
	testOpcodeRES(0xBC, state.registers.h, expectedState.registers.h, 7);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBBD)
{
	// 0xBD RES 7, L
	testOpcodeRES(0xBD, state.registers.l, expectedState.registers.l, 7);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBBE)
{
	// 0xBE RES 7, (HL)
	testOpcodeREShl(0xBE, 7);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBBF)
{
	// 0xBF RES 7, A
	testOpcodeRES(0xBF, state.registers.a, expectedState.registers.a, 7);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBC0)
{
	// 0xC0 SET 0, B
	testOpcodeSET(0xC0, state.registers.b, expectedState.registers.b, 0);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBC1)
{
	// 0xC1 SET 0, C
	testOpcodeSET(0xC1, state.registers.c, expectedState.registers.c, 0);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBC2)
{
	// 0xC2 SET 0, D
	testOpcodeSET(0xC2, state.registers.d, expectedState.registers.d, 0);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBC3)
{
	// 0xC3 SET 0, E
	testOpcodeSET(0xC3, state.registers.e, expectedState.registers.e, 0);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBC4)
{
	// 0xC4 SET 0, H
	testOpcodeSET(0xC4, state.registers.h, expectedState.registers.h, 0);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBC5)
{
	// 0xC5 SET 0, L
	testOpcodeSET(0xC5, state.registers.l, expectedState.registers.l, 0);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBC6)
{
	// 0xC6 SET 0, (HL)
	testOpcodeSEThl(0xC6, 0);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBC7)
{
	// 0xC7 SET 0, A
	testOpcodeSET(0xC7, state.registers.a, expectedState.registers.a, 0);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBC8)
{
	// 0xC8 SET 1, B
	testOpcodeSET(0xC8, state.registers.b, expectedState.registers.b, 1);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBC9)
{
	// 0xC9 SET 1, C
	testOpcodeSET(0xC9, state.registers.c, expectedState.registers.c, 1);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBCA)
{
	// 0xCA SET 1, D
	testOpcodeSET(0xCA, state.registers.d, expectedState.registers.d, 1);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBCB)
{
	// 0xCB SET 1, E
	testOpcodeSET(0xCB, state.registers.e, expectedState.registers.e, 1);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBCC)
{
	// 0xCC SET 1, H
	testOpcodeSET(0xCC, state.registers.h, expectedState.registers.h, 1);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBCD)
{
	// 0xCD SET 1, L
	testOpcodeSET(0xCD, state.registers.l, expectedState.registers.l, 1);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBCE)
{
	// 0xCE SET 1, (HL)
	testOpcodeSEThl(0xCE, 1);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBCF)
{
	// 0xCF SET 1, A
	testOpcodeSET(0xCF, state.registers.a, expectedState.registers.a, 1);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBD0)
{
	// 0xD0 SET 2, B
	testOpcodeSET(0xD0, state.registers.b, expectedState.registers.b, 2);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBD1)
{
	// 0xD1 SET 2, C
	testOpcodeSET(0xD1, state.registers.c, expectedState.registers.c, 2);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBD2)
{
	// 0xD2 SET 2, D
	testOpcodeSET(0xD2, state.registers.d, expectedState.registers.d, 2);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBD3)
{
	// 0xD3 SET 2, E
	testOpcodeSET(0xD3, state.registers.e, expectedState.registers.e, 2);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBD4)
{
	// 0xD4 SET 2, H
	testOpcodeSET(0xD4, state.registers.h, expectedState.registers.h, 2);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBD5)
{
	// 0xD5 SET 2, L
	testOpcodeSET(0xD5, state.registers.l, expectedState.registers.l, 2);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBD6)
{
	// 0xD6 SET 2, (HL)
	testOpcodeSEThl(0xD6, 2);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBD7)
{
	// 0xD7 SET 2, A
	testOpcodeSET(0xD7, state.registers.a, expectedState.registers.a, 2);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBD8)
{
	// 0xD8 SET 3, B
	testOpcodeSET(0xD8, state.registers.b, expectedState.registers.b, 3);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBD9)
{
	// 0xD9 SET 3, C
	testOpcodeSET(0xD9, state.registers.c, expectedState.registers.c, 3);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBDA)
{
	// 0xDA SET 3, D
	testOpcodeSET(0xDA, state.registers.d, expectedState.registers.d, 3);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBDB)
{
	// 0xDB SET 3, E
	testOpcodeSET(0xDB, state.registers.e, expectedState.registers.e, 3);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBDC)
{
	// 0xDC SET 3, H
	testOpcodeSET(0xDC, state.registers.h, expectedState.registers.h, 3);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBDD)
{
	// 0xDD SET 3, L
	testOpcodeSET(0xDD, state.registers.l, expectedState.registers.l, 3);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBDE)
{
	// 0xDE SET 3, (HL)
	testOpcodeSEThl(0xDE, 3);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBDF)
{
	// 0xDF SET 3, A
	testOpcodeSET(0xDF, state.registers.a, expectedState.registers.a, 3);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBE0)
{
	// 0xE0 SET 4, B
	testOpcodeSET(0xE0, state.registers.b, expectedState.registers.b, 4);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBE1)
{
	// 0xE1 SET 4, C
	testOpcodeSET(0xE1, state.registers.c, expectedState.registers.c, 4);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBE2)
{
	// 0xE2 SET 4, D
	testOpcodeSET(0xE2, state.registers.d, expectedState.registers.d, 4);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBE3)
{
	// 0xE3 SET 4, E
	testOpcodeSET(0xE3, state.registers.e, expectedState.registers.e, 4);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBE4)
{
	// 0xE4 SET 4, H
	testOpcodeSET(0xE4, state.registers.h, expectedState.registers.h, 4);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBE5)
{
	// 0xE5 SET 4, L
	testOpcodeSET(0xE5, state.registers.l, expectedState.registers.l, 4);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBE6)
{
	// 0xE6 SET 4, (HL)
	testOpcodeSEThl(0xE6, 4);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBE7)
{
	// 0xE7 SET 4, A
	testOpcodeSET(0xE7, state.registers.a, expectedState.registers.a, 4);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBE8)
{
	// 0xE8 SET 5, B
	testOpcodeSET(0xE8, state.registers.b, expectedState.registers.b, 5);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBE9)
{
	// 0xE9 SET 5, C
	testOpcodeSET(0xE9, state.registers.c, expectedState.registers.c, 5);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBEA)
{
	// 0xEA SET 5, D
	testOpcodeSET(0xEA, state.registers.d, expectedState.registers.d, 5);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBEB)
{
	// 0xEB SET 5, E
	testOpcodeSET(0xEB, state.registers.e, expectedState.registers.e, 5);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBEC)
{
	// 0xEC SET 5, H
	testOpcodeSET(0xEC, state.registers.h, expectedState.registers.h, 5);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBED)
{
	// 0xED SET 5, L
	testOpcodeSET(0xED, state.registers.l, expectedState.registers.l, 5);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBEE)
{
	// 0xEE SET 5, (HL)
	testOpcodeSEThl(0xEE, 5);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBEF)
{
	// 0xEF SET 5, A
	testOpcodeSET(0xEF, state.registers.a, expectedState.registers.a, 5);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBF0)
{
	// 0xF0 SET 6, B
	testOpcodeSET(0xF0, state.registers.b, expectedState.registers.b, 6);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBF1)
{
	// 0xF1 SET 6, C
	testOpcodeSET(0xF1, state.registers.c, expectedState.registers.c, 6);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBF2)
{
	// 0xF2 SET 6, D
	testOpcodeSET(0xF2, state.registers.d, expectedState.registers.d, 6);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBF3)
{
	// 0xF3 SET 6, E
	testOpcodeSET(0xF3, state.registers.e, expectedState.registers.e, 6);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBF4)
{
	// 0xF4 SET 6, H
	testOpcodeSET(0xF4, state.registers.h, expectedState.registers.h, 6);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBF5)
{
	// 0xF5 SET 6, L
	testOpcodeSET(0xF5, state.registers.l, expectedState.registers.l, 6);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBF6)
{
	// 0xF6 SET 6, (HL)
	testOpcodeSEThl(0xF6, 6);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBF7)
{
	// 0xF7 SET 6, A
	testOpcodeSET(0xF7, state.registers.a, expectedState.registers.a, 6);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBF8)
{
	// 0xF8 SET 7, B
	testOpcodeSET(0xF8, state.registers.b, expectedState.registers.b, 7);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBF9)
{
	// 0xF9 SET 7, C
	testOpcodeSET(0xF9, state.registers.c, expectedState.registers.c, 7);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBFA)
{
	// 0xFA SET 7, D
	testOpcodeSET(0xFA, state.registers.d, expectedState.registers.d, 7);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBFB)
{
	// 0xFB SET 7, E
	testOpcodeSET(0xFB, state.registers.e, expectedState.registers.e, 7);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBFC)
{
	// 0xFC SET 7, H
	testOpcodeSET(0xFC, state.registers.h, expectedState.registers.h, 7);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBFD)
{
	// 0xFD SET 7, L
	testOpcodeSET(0xFD, state.registers.l, expectedState.registers.l, 7);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBFE)
{
	// 0xFE SET 7, (HL)
	testOpcodeSEThl(0xFE, 7);
}

TEST_F(OpcodesBitOperationsTest, Test0xCBFF)
{
	// 0xFF SET 7, A
	testOpcodeSET(0xFF, state.registers.a, expectedState.registers.a, 7);
}
