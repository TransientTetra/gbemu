#include <gtest/gtest.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconstant-conversion"
#define private public

#include <libgrebe/cpu.hpp>

class Opcodes8BitAluTest : public ::testing::Test
{
protected:
	CPU cpu;
	State state, expectedState;

	void SetUp() override
	{
	}

	void TearDown() override
	{
	}

	void testOpcode(Byte opcode)
	{
		// injecting opcode at pc
		state.memory.write(state.registers.pc, opcode);
		// saving cpu and memory state before executing the opcode
		expectedState = state;
		// executing the opcode
		cpu.execute(state);
	}

	void incTest(Byte opcode, Byte& reg, Byte& expectedReg);
	void decTest(Byte opcode, Byte& reg, Byte& expectedReg);
	void addTest(Byte opcode, Byte& operand);
	void adcTest(Byte opcode, Byte& operand);
	void subTest(Byte opcode, Byte& operand);
	void sbcTest(Byte opcode, Byte& operand);
	void andTest(Byte opcode, Byte& operand);
	void xorTest(Byte opcode, Byte& operand);
	void orTest(Byte opcode, Byte& operand);
	void cpTest(Byte opcode, Byte& operand);
};

void Opcodes8BitAluTest::incTest(Byte opcode, Byte& reg, Byte& expectedReg)
{
	// preparing cpu and memory state before executing the opcode
	reg = 0;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedReg = 1;
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	reg = 0xff;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedReg = 0;
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	reg = 0x0f;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedReg = 0x10;
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

void Opcodes8BitAluTest::decTest(Byte opcode, Byte& reg, Byte& expectedReg)
{
	// preparing cpu and memory state before executing the opcode
	reg = 3;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedReg = 2;
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	reg = 1;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedReg = 0;
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	reg = 0x10;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedReg = 0x0f;
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

void Opcodes8BitAluTest::addTest(Byte opcode, Byte& operand)
{
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	operand = 0;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0xff;
	operand = 1;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0xff;
	operand = 0xff;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0xfe;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x0f;
	operand = 1;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x10;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0xf0;
	operand = 0x11;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

void Opcodes8BitAluTest::adcTest(Byte opcode, Byte& operand)
{
	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 0;
	operand = 0;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 0xff;
	operand = 1;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 0x0f;
	operand = 1;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x10;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 0xf0;
	operand = 0x11;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 0;
	operand = 0;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 1;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 0xff;
	operand = 1;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();	
	state.registers.a = 0x0f;
	operand = 1;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x11;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 0xff;
	operand = 1;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 0xf0;
	operand = 0x10;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

void Opcodes8BitAluTest::subTest(Byte opcode, Byte& operand)
{
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	operand = 0;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 2;
	operand = 2;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 5;
	operand = 2;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 3;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x00;
	operand = 1;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0xff;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x10;
	operand = 2;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x0e;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 1;
	operand = 0x11;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0xf0;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

void Opcodes8BitAluTest::sbcTest(Byte opcode, Byte& operand)
{
	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 0;
	operand = 0;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 2;
	operand = 2;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 5;
	operand = 2;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 3;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 0x00;
	operand = 1;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0xff;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 0x10;
	operand = 2;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x0e;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 1;
	operand = 0x11;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0xf0;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 1;
	operand = 0;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 2;
	operand = 1;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 5;
	operand = 2;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 2;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 0x00;
	operand = 1;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0xfe;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 0x10;
	operand = 1;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x0e;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 1;
	operand = 0x10;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0xf0;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

void Opcodes8BitAluTest::andTest(Byte opcode, Byte& operand)
{
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b00000000;
	operand = 0b00000000;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b11111111;
	operand = 0b00000000;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b00000000;
	operand = 0b11111111;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b10101010;
	operand = 0b01010101;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b01010101;
	operand = 0b01010101;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b01010101;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

void Opcodes8BitAluTest::xorTest(Byte opcode, Byte& operand)
{
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b00000000;
	operand = 0b00000000;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b11111111;
	operand = 0b00000000;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b11111111;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b00000000;
	operand = 0b11111111;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b11111111;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b10101010;
	operand = 0b01010101;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b11111111;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b01010101;
	operand = 0b01010101;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

void Opcodes8BitAluTest::orTest(Byte opcode, Byte& operand)
{
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b00000000;
	operand = 0b00000000;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b11111111;
	operand = 0b00000000;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b11111111;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b00000000;
	operand = 0b11111111;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b11111111;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b10101010;
	operand = 0b01010101;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b11111111;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b01010101;
	operand = 0b01010101;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b01010101;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

void Opcodes8BitAluTest::cpTest(Byte opcode, Byte& operand)
{
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	operand = 0;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 2;
	operand = 2;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 5;
	operand = 2;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x00;
	operand = 1;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x10;
	operand = 2;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 1;
	operand = 0x11;
	// testing the opcode
	testOpcode(opcode);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0x04)
{
	// 0x04 INC B
	incTest(0x04, state.registers.b, expectedState.registers.b);
}

TEST_F(Opcodes8BitAluTest, Test0x14)
{
	// 0x14 INC D
	incTest(0x14, state.registers.d, expectedState.registers.d);
}

TEST_F(Opcodes8BitAluTest, Test0x24)
{
	// 0x24 INC H
	incTest(0x24, state.registers.h, expectedState.registers.h);
}

TEST_F(Opcodes8BitAluTest, Test0x34)
{
	// 0x34 INC (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0);
	// testing the opcode
	testOpcode(0x34);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.memory.write(0xdead, 1);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0xff);
	// testing the opcode
	testOpcode(0x34);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.memory.write(0xdead, 0);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0x0f);
	// testing the opcode
	testOpcode(0x34);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.memory.write(0xdead, 0x10);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0x0C)
{
	// 0x0C INC C
	incTest(0x0C, state.registers.c, expectedState.registers.c);
}

TEST_F(Opcodes8BitAluTest, Test0x1C)
{
	// 0x1C INC E
	incTest(0x1C, state.registers.e, expectedState.registers.e);
}

TEST_F(Opcodes8BitAluTest, Test0x2C)
{
	// 0x2C INC L
	incTest(0x2C, state.registers.l, expectedState.registers.l);
}

TEST_F(Opcodes8BitAluTest, Test0x3C)
{
	// 0x3C INC A
	incTest(0x3C, state.registers.a, expectedState.registers.a);
}

TEST_F(Opcodes8BitAluTest, Test0x05)
{
	// 0x05 DEC B
	decTest(0x05, state.registers.b, expectedState.registers.b);
}

TEST_F(Opcodes8BitAluTest, Test0x15)
{
	// 0x15 DEC D
	decTest(0x15, state.registers.d, expectedState.registers.d);
}

TEST_F(Opcodes8BitAluTest, Test0x25)
{
	// 0x25 DEC H
	decTest(0x25, state.registers.h, expectedState.registers.h);
}

TEST_F(Opcodes8BitAluTest, Test0x35)
{
	// 0x35 DEC (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 3);
	// testing the opcode
	testOpcode(0x35);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.memory.write(0xdead, 2);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 1);
	// testing the opcode
	testOpcode(0x35);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.memory.write(0xdead, 0);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0x10);
	// testing the opcode
	testOpcode(0x35);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.memory.write(0xdead, 0x0f);
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0x0D)
{
	// 0x0D DEC C
	decTest(0x0D, state.registers.c, expectedState.registers.c);
}

TEST_F(Opcodes8BitAluTest, Test0x1D)
{
	// 0x1D DEC E
	decTest(0x1D, state.registers.e, expectedState.registers.e);
}

TEST_F(Opcodes8BitAluTest, Test0x2D)
{
	// 0x2D DEC L
	decTest(0x2D, state.registers.l, expectedState.registers.l);
}

TEST_F(Opcodes8BitAluTest, Test0x3D)
{
	// 0x3D DEC A
	decTest(0x3D, state.registers.a, expectedState.registers.a);
}

TEST_F(Opcodes8BitAluTest, Test0x80)
{
	// 0x80 ADD B
	addTest(0x80, state.registers.b);
}

TEST_F(Opcodes8BitAluTest, Test0x81)
{
	// 0x81 ADD C
	addTest(0x81, state.registers.c);
}

TEST_F(Opcodes8BitAluTest, Test0x82)
{
	// 0x82 ADD D
	addTest(0x82, state.registers.d);
}

TEST_F(Opcodes8BitAluTest, Test0x83)
{
	// 0x83 ADD E
	addTest(0x83, state.registers.e);
}

TEST_F(Opcodes8BitAluTest, Test0x84)
{
	// 0x84 ADD H
	addTest(0x84, state.registers.h);
}

TEST_F(Opcodes8BitAluTest, Test0x85)
{
	// 0x85 ADD L
	addTest(0x85, state.registers.l);
}

TEST_F(Opcodes8BitAluTest, Test0x86)
{
	// 0x86 ADD (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0);
	// testing the opcode
	testOpcode(0x86);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0xff;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 1);
	// testing the opcode
	testOpcode(0x86);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x0f;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 1);
	// testing the opcode
	testOpcode(0x86);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x10;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0xf0;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0x11);
	// testing the opcode
	testOpcode(0x86);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0xf0;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0x11);
	// testing the opcode
	testOpcode(0x86);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0x87)
{
	// 0x87 ADD A
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	// testing the opcode
	testOpcode(0x87);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x0f;
	// testing the opcode
	testOpcode(0x87);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x1e;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0xff;
	// testing the opcode
	testOpcode(0x87);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0xfe;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0xf0;
	// testing the opcode
	testOpcode(0x87);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0xe0;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0xC6)
{
	// 0xC6 ADD n
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0);
	// testing the opcode
	testOpcode(0xC6);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0xff;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 1);
	// testing the opcode
	testOpcode(0xC6);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x0f;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 1);
	// testing the opcode
	testOpcode(0xC6);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0x10;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0xf0;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0x11);
	// testing the opcode
	testOpcode(0xC6);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0x88)
{
	// 0x88 opcodeADC B
	adcTest(0x88, state.registers.b);
}

TEST_F(Opcodes8BitAluTest, Test0x89)
{
	// 0x89 opcodeADC C
	adcTest(0x89, state.registers.c);
}

TEST_F(Opcodes8BitAluTest, Test0x8A)
{
	// 0x8A opcodeADC D
	adcTest(0x8A, state.registers.d);
}

TEST_F(Opcodes8BitAluTest, Test0x8B)
{
	// 0x8B opcodeADC E
	adcTest(0x8B, state.registers.e);
}

TEST_F(Opcodes8BitAluTest, Test0x8C)
{
	// 0x8C opcodeADC H
	adcTest(0x8C, state.registers.h);
}

TEST_F(Opcodes8BitAluTest, Test0x8D)
{
	// 0x8D opcodeADC L
	adcTest(0x8D, state.registers.l);
}

TEST_F(Opcodes8BitAluTest, Test0x8E)
{
	// 0x8E opcodeADC (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 0;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0);
	// testing the opcode
	testOpcode(0x8E);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 0xff;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 1);
	// testing the opcode
	testOpcode(0x8E);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 0x0f;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 1);
	// testing the opcode
	testOpcode(0x8E);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x10;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 0xf0;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0x11);
	// testing the opcode
	testOpcode(0x8E);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 0;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0);
	// testing the opcode
	testOpcode(0x8E);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 1;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 0xff;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 1);
	// testing the opcode
	testOpcode(0x8E);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 0x0f;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 1);
	// testing the opcode
	testOpcode(0x8E);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x11;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 0xff;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 1);
	// testing the opcode
	testOpcode(0x8E);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 0xf0;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0x10);
	// testing the opcode
	testOpcode(0x8E);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0x8F)
{
	// 0x8F opcodeADC A
	// preparing cpu and memory state before executing the opcode
	state.registers.resetCarryFlag();
	state.registers.a = 0;
	// testing the opcode
	testOpcode(0x8F);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.resetCarryFlag();
	state.registers.a = 0x0f;
	// testing the opcode
	testOpcode(0x8F);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x1e;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.resetCarryFlag();
	state.registers.a = 0xff;
	// testing the opcode
	testOpcode(0x8F);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0xfe;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.resetCarryFlag();
	state.registers.a = 0xf0;
	// testing the opcode
	testOpcode(0x8F);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0xe0;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.setCarryFlag();
	state.registers.a = 0;
	// testing the opcode
	testOpcode(0x8F);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 1;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.setCarryFlag();
	state.registers.a = 0x0f;
	// testing the opcode
	testOpcode(0x8F);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x1f;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.setCarryFlag();
	state.registers.a = 0xff;
	// testing the opcode
	testOpcode(0x8F);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0xff;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.setCarryFlag();
	state.registers.a = 0xf0;
	// testing the opcode
	testOpcode(0x8F);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0xe1;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0xCE)
{
	// 0xCE opcodeADC n
	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 0;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0);
	// testing the opcode
	testOpcode(0xCE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 0xff;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 1);
	// testing the opcode
	testOpcode(0xCE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 0x0f;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 1);
	// testing the opcode
	testOpcode(0xCE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0x10;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 0xf0;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0x11);
	// testing the opcode
	testOpcode(0xCE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 0;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0);
	// testing the opcode
	testOpcode(0xCE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 1;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 0xff;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 1);
	// testing the opcode
	testOpcode(0xCE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 0x0f;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 1);
	// testing the opcode
	testOpcode(0xCE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0x11;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 0xff;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 1);
	// testing the opcode
	testOpcode(0xCE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 0xf0;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0x10);
	// testing the opcode
	testOpcode(0xCE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0x90)
{
	// 0x90 SUB B
	subTest(0x90, state.registers.b);
}

TEST_F(Opcodes8BitAluTest, Test0x91)
{
	// 0x91 SUB C
	subTest(0x91, state.registers.c);
}

TEST_F(Opcodes8BitAluTest, Test0x92)
{
	// 0x92 SUB D
	subTest(0x92, state.registers.d);
}

TEST_F(Opcodes8BitAluTest, Test0x93)
{
	// 0x93 SUB E
	subTest(0x93, state.registers.e);
}

TEST_F(Opcodes8BitAluTest, Test0x94)
{
	// 0x94 SUB H
	subTest(0x94, state.registers.h);
}

TEST_F(Opcodes8BitAluTest, Test0x95)
{
	// 0x95 SUB L
	subTest(0x95, state.registers.l);
}

TEST_F(Opcodes8BitAluTest, Test0x96)
{
	// 0x96 SUB (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0);
	// testing the opcode
	testOpcode(0x96);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 2;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 2);
	// testing the opcode
	testOpcode(0x96);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 5;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 2);
	// testing the opcode
	testOpcode(0x96);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 3;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x00;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 1);
	// testing the opcode
	testOpcode(0x96);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0xff;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x10;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 2);
	// testing the opcode
	testOpcode(0x96);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x0e;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 1;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0x11);
	// testing the opcode
	testOpcode(0x96);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0xf0;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0x97)
{
	// 0x97 SUB A
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	// testing the opcode
	testOpcode(0x97);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 2;
	// testing the opcode
	testOpcode(0x97);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0xff;
	// testing the opcode
	testOpcode(0x97);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0xD6)
{
	// 0xD6 SUB n
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0);
	// testing the opcode
	testOpcode(0xD6);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 2;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 2);
	// testing the opcode
	testOpcode(0xD6);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 5;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 2);
	// testing the opcode
	testOpcode(0xD6);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 3;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x00;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 1);
	// testing the opcode
	testOpcode(0xD6);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0xff;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x10;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 2);
	// testing the opcode
	testOpcode(0xD6);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0x0e;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 1;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0x11);
	// testing the opcode
	testOpcode(0xD6);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0xf0;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0x98)
{
	// 0x98 SBC B
	sbcTest(0x98, state.registers.b);
}

TEST_F(Opcodes8BitAluTest, Test0x99)
{
	// 0x99 SBC C
	sbcTest(0x99, state.registers.c);
}

TEST_F(Opcodes8BitAluTest, Test0x9A)
{
	// 0x9A SBC D
	sbcTest(0x9A, state.registers.d);
}

TEST_F(Opcodes8BitAluTest, Test0x9B)
{
	// 0x9B SBC E
	sbcTest(0x9B, state.registers.e);
}

TEST_F(Opcodes8BitAluTest, Test0x9C)
{
	// 0x9C SBC H
	sbcTest(0x9C, state.registers.h);
}

TEST_F(Opcodes8BitAluTest, Test0x9D)
{
	// 0x9D SBC L
	sbcTest(0x9D, state.registers.l);
}

TEST_F(Opcodes8BitAluTest, Test0x9E)
{
	// 0x9E SBC (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 0;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0);
	// testing the opcode
	testOpcode(0x9E);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 2;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 2);
	// testing the opcode
	testOpcode(0x9E);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 5;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 2);
	// testing the opcode
	testOpcode(0x9E);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 3;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 0x00;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 1);
	// testing the opcode
	testOpcode(0x9E);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0xff;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 0x10;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 2);
	// testing the opcode
	testOpcode(0x9E);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x0e;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 1;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0x11);
	// testing the opcode
	testOpcode(0x9E);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0xf0;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 1;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0);
	// testing the opcode
	testOpcode(0x9E);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 2;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 1);
	// testing the opcode
	testOpcode(0x9E);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 5;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 2);
	// testing the opcode
	testOpcode(0x9E);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 2;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 0x00;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 1);
	// testing the opcode
	testOpcode(0x9E);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0xfe;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 0x10;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 1);
	// testing the opcode
	testOpcode(0x9E);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x0e;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 1;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0x10);
	// testing the opcode
	testOpcode(0x9E);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0xf0;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0x9F)
{
	// 0x9F SBC A
	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 0;
	// testing the opcode
	testOpcode(0x9F);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 2;
	// testing the opcode
	testOpcode(0x9F);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 0xff;
	// testing the opcode
	testOpcode(0x9F);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// 0x9F SBC A
	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 0;
	// testing the opcode
	testOpcode(0x9F);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0xff;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setCarryFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// 0x9F SBC A
	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 3;
	// testing the opcode
	testOpcode(0x9F);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0xff;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setCarryFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// 0x9F SBC A
	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 0xff;
	// testing the opcode
	testOpcode(0x9F);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0xff;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setCarryFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0xDE)
{
	// 0xDE SBC n
	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 0;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0);
	// testing the opcode
	testOpcode(0xDE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 2;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 2);
	// testing the opcode
	testOpcode(0xDE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 5;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 2);
	// testing the opcode
	testOpcode(0xDE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 3;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 0x00;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 1);
	// testing the opcode
	testOpcode(0xDE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0xff;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 0x10;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 2);
	// testing the opcode
	testOpcode(0xDE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0x0e;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.a = 1;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0x11);
	// testing the opcode
	testOpcode(0xDE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0xf0;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 1;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0);
	// testing the opcode
	testOpcode(0xDE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 2;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 1);
	// testing the opcode
	testOpcode(0xDE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 5;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 2);
	// testing the opcode
	testOpcode(0xDE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 2;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 0x00;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 1);
	// testing the opcode
	testOpcode(0xDE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0xfe;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 0x10;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 1);
	// testing the opcode
	testOpcode(0xDE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0x0e;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.clearFlags();
	state.registers.setCarryFlag();
	state.registers.a = 1;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0x10);
	// testing the opcode
	testOpcode(0xDE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0xf0;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0xA0)
{
	// 0xA0 AND B
	andTest(0xA0, state.registers.b);
}

TEST_F(Opcodes8BitAluTest, Test0xA1)
{
	// 0xA1 AND C
	andTest(0xA1, state.registers.c);
}

TEST_F(Opcodes8BitAluTest, Test0xA2)
{
	// 0xA2 AND D
	andTest(0xA2, state.registers.d);
}

TEST_F(Opcodes8BitAluTest, Test0xA3)
{
	// 0xA3 AND E
	andTest(0xA3, state.registers.e);
}

TEST_F(Opcodes8BitAluTest, Test0xA4)
{
	// 0xA4 AND H
	andTest(0xA4, state.registers.h);
}

TEST_F(Opcodes8BitAluTest, Test0xA5)
{
	// 0xA5 AND L
	andTest(0xA5, state.registers.l);
}

TEST_F(Opcodes8BitAluTest, Test0xA6)
{
	// 0xA6 AND (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b00000000;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b00000000);
	// testing the opcode
	testOpcode(0xA6);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b11111111;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b00000000);
	// testing the opcode
	testOpcode(0xA6);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b00000000;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b11111111);
	// testing the opcode
	testOpcode(0xA6);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b10101010;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b01010101);
	// testing the opcode
	testOpcode(0xA6);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b01010101;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b01010101);
	// testing the opcode
	testOpcode(0xA6);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b01010101;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0xA7)
{
	// 0xA7 AND A
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b00000000;
	// testing the opcode
	testOpcode(0xA7);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b11111111;
	// testing the opcode
	testOpcode(0xA7);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b11111111;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b10101010;
	// testing the opcode
	testOpcode(0xA7);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b10101010;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0xE6)
{
	// 0xE6 AND n
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b00000000;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0b00000000);
	// testing the opcode
	testOpcode(0xE6);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b11111111;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0b00000000);
	// testing the opcode
	testOpcode(0xE6);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b00000000;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0b11111111);
	// testing the opcode
	testOpcode(0xE6);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b10101010;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0b01010101);
	// testing the opcode
	testOpcode(0xE6);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b01010101;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0b01010101);
	// testing the opcode
	testOpcode(0xE6);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0b01010101;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0xA8)
{
	// 0xA8 XOR B
	xorTest(0xA8, state.registers.b);
}

TEST_F(Opcodes8BitAluTest, Test0xA9)
{
	// 0xA9 XOR C
	xorTest(0xA9, state.registers.c);

}

TEST_F(Opcodes8BitAluTest, Test0xAA)
{
	// 0xAA XOR D
	xorTest(0xAA, state.registers.d);
}

TEST_F(Opcodes8BitAluTest, Test0xAB)
{
	// 0xAB XOR E
	xorTest(0xAB, state.registers.e);
}

TEST_F(Opcodes8BitAluTest, Test0xAC)
{
	// 0xAC XOR H
	xorTest(0xAC, state.registers.h);
}

TEST_F(Opcodes8BitAluTest, Test0xAD)
{
	// 0xAD XOR L
	xorTest(0xAD, state.registers.l);
}

TEST_F(Opcodes8BitAluTest, Test0xAE)
{
	// 0xAE XOR (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b00000000;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b00000000);
	// testing the opcode
	testOpcode(0xAE);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b11111111;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b00000000);
	// testing the opcode
	testOpcode(0xAE);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b11111111;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b00000000;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b11111111);
	// testing the opcode
	testOpcode(0xAE);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b11111111;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b10101010;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b01010101);
	// testing the opcode
	testOpcode(0xAE);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b11111111;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b01010101;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b01010101);
	// testing the opcode
	testOpcode(0xAE);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0xAF)
{
	// 0xAF XOR A
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b00000000;
	// testing the opcode
	testOpcode(0xAF);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b11111111;
	// testing the opcode
	testOpcode(0xAF);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b10101010;
	// testing the opcode
	testOpcode(0xAF);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0xEE)
{
	// 0xEE XOR n
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b00000000;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0b00000000);
	// testing the opcode
	testOpcode(0xEE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b11111111;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0b00000000);
	// testing the opcode
	testOpcode(0xEE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0b11111111;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b00000000;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0b11111111);
	// testing the opcode
	testOpcode(0xEE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0b11111111;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b10101010;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0b01010101);
	// testing the opcode
	testOpcode(0xEE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0b11111111;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b01010101;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0b01010101);
	// testing the opcode
	testOpcode(0xEE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0xB0)
{
	// 0xB0 OR B
	orTest(0xB0, state.registers.b);
}

TEST_F(Opcodes8BitAluTest, Test0xB1)
{
	// 0xB1 OR C
	orTest(0xB1, state.registers.c);
}

TEST_F(Opcodes8BitAluTest, Test0xB2)
{
	// 0xB2 OR D
	orTest(0xB2, state.registers.d);
}

TEST_F(Opcodes8BitAluTest, Test0xB3)
{
	// 0xB3 OR E
	orTest(0xB3, state.registers.e);
}

TEST_F(Opcodes8BitAluTest, Test0xB4)
{
	// 0xB4 OR H
	orTest(0xB4, state.registers.h);
}

TEST_F(Opcodes8BitAluTest, Test0xB5)
{
	// 0xB5 OR L
	orTest(0xB5, state.registers.l);
}

TEST_F(Opcodes8BitAluTest, Test0xB6)
{
	// 0xB6 OR (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b00000000;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b00000000);
	// testing the opcode
	testOpcode(0xB6);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b11111111;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b00000000);
	// testing the opcode
	testOpcode(0xB6);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b11111111;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b00000000;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b11111111);
	// testing the opcode
	testOpcode(0xB6);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b11111111;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b10101010;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b01010101);
	// testing the opcode
	testOpcode(0xB6);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b11111111;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b01010101;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0b01010101);
	// testing the opcode
	testOpcode(0xB6);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b01010101;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0xB7)
{
	// 0xB7 OR A
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b00000000;
	// testing the opcode
	testOpcode(0xB7);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b11111111;
	// testing the opcode
	testOpcode(0xB7);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b11111111;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b10101010;
	// testing the opcode
	testOpcode(0xB7);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b10101010;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0xF6)
{
	// 0xF6 OR n
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b00000000;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0b00000000);
	// testing the opcode
	testOpcode(0xF6);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0b00000000;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b11111111;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0b00000000);
	// testing the opcode
	testOpcode(0xF6);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0b11111111;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b00000000;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0b11111111);
	// testing the opcode
	testOpcode(0xF6);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0b11111111;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b10101010;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0b01010101);
	// testing the opcode
	testOpcode(0xF6);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0b11111111;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b01010101;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0b01010101);
	// testing the opcode
	testOpcode(0xF6);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0b01010101;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0xB8)
{
	// 0xB8 CP B
	cpTest(0xB8, state.registers.b);
}

TEST_F(Opcodes8BitAluTest, Test0xB9)
{
	// 0xB9 CP C
	cpTest(0xB9, state.registers.c);
}

TEST_F(Opcodes8BitAluTest, Test0xBA)
{
	// 0xBA CP D
	cpTest(0xBA, state.registers.d);
}

TEST_F(Opcodes8BitAluTest, Test0xBB)
{
	// 0xBB CP E
	cpTest(0xBB, state.registers.e);
}

TEST_F(Opcodes8BitAluTest, Test0xBC)
{
	// 0xBC CP H
	cpTest(0xBC, state.registers.h);
}

TEST_F(Opcodes8BitAluTest, Test0xBD)
{
	// 0xBD CP L
	cpTest(0xBD, state.registers.l);
}

TEST_F(Opcodes8BitAluTest, Test0xBE)
{
	// 0xBE CP (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0);
	// testing the opcode
	testOpcode(0xBE);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 2;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 2);
	// testing the opcode
	testOpcode(0xBE);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 5;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 2);
	// testing the opcode
	testOpcode(0xBE);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x00;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 1);
	// testing the opcode
	testOpcode(0xBE);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x10;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 2);
	// testing the opcode
	testOpcode(0xBE);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 1;
	state.registers.hl = 0xdead;
	state.memory.write(0xdead, 0x11);
	// testing the opcode
	testOpcode(0xBE);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0xBF)
{
	// 0xBF CP A
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	// testing the opcode
	testOpcode(0xBF);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 2;
	// testing the opcode
	testOpcode(0xBF);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 2;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0xff;
	// testing the opcode
	testOpcode(0xBF);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0xff;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0xFE)
{
	// 0xFE CP n
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0);
	// testing the opcode
	testOpcode(0xFE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 2;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 2);
	// testing the opcode
	testOpcode(0xFE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 5;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 2);
	// testing the opcode
	testOpcode(0xFE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x00;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 1);
	// testing the opcode
	testOpcode(0xFE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x10;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 2);
	// testing the opcode
	testOpcode(0xFE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 1;
	state.registers.pc = 0xdead;
	state.memory.write(0xdeae, 0x11);
	// testing the opcode
	testOpcode(0xFE);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0x27)
{
	// 0x27 DAA
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	state.registers.b = 0;
	testOpcode(0x80);
	// testing the opcode
	testOpcode(0x27);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.resetCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	state.registers.b = 0x32;
	testOpcode(0x80);
	// testing the opcode
	testOpcode(0x27);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x32;
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.resetCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x11;
	state.registers.b = 0x12;
	testOpcode(0x80);
	// testing the opcode
	testOpcode(0x27);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x23;
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.resetCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x51;
	state.registers.b = 0x63;
	testOpcode(0x80);
	// testing the opcode
	testOpcode(0x27);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x14;
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x36;
	state.registers.b = 0x12;
	testOpcode(0x90);
	// testing the opcode
	testOpcode(0x27);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x24;
	expectedState.registers.resetZeroFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.resetCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x36;
	state.registers.b = 0x36;
	testOpcode(0x90);
	// testing the opcode
	testOpcode(0x27);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0;
	expectedState.registers.setZeroFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.resetCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// todo below
//	// preparing cpu and memory state before executing the opcode
//	state.registers.a = 0x19;
//	state.registers.b = 0x36;
//	testOpcode(0x90);
//	// testing the opcode
//	testOpcode(0x27);
//	// expected change in registers and memory
//	expectedState.registers.pc += 1;
//	expectedState.registers.a = 0x17;
//	expectedState.registers.resetZeroFlag();
//	expectedState.registers.resetHalfCarryFlag();
//	expectedState.registers.setCarryFlag();
//	// comparing expected change to real change
//	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0x37)
{
	// 0x37 SCF
	// preparing cpu and memory state before executing the opcode
	state.registers.f = 0xff;
	// testing the opcode
	testOpcode(0x37);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.f = 0;
	// testing the opcode
	testOpcode(0x37);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0x2F)
{
	// 0x2F CPL
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0xff;
	// testing the opcode
	testOpcode(0x2F);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x00;
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0b10101010;
	// testing the opcode
	testOpcode(0x2F);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0b01010101;
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitAluTest, Test0x3F)
{
	// 0x3F CCF
	// preparing cpu and memory state before executing the opcode
	state.registers.f = 0xff;
	// testing the opcode
	testOpcode(0x3F);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.resetCarryFlag();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.registers.f = 0;
	// testing the opcode
	testOpcode(0x3F);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.resetSubtractFlag();
	expectedState.registers.resetHalfCarryFlag();
	expectedState.registers.resetCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}
