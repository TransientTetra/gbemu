#include <gtest/gtest.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconstant-conversion"
#define private public

#include <libgbemu/cpu.hpp>

class CPUTest : public ::testing::Test
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
		expectedState.registers = state.registers;
		expectedState.memory = state.memory;
		// executing the opcode
		cpu.execute(state);
	}
};

TEST_F(CPUTest, CreationTest)
{
}

class OpcodesMiscTest : public CPUTest
{
};

TEST_F(OpcodesMiscTest, Test0x00)
{
	// 0x00 NOP
	// executing the opcode
	testOpcode(0x00);
	// expected change in registers
	expectedState.registers.pc += 1;
	EXPECT_TRUE(expectedState == state);
}

TEST_F(OpcodesMiscTest, Test0x10)
{
	// 0x10 STOP
}

TEST_F(OpcodesMiscTest, Test0xF3)
{
	// 0xF3 DI
}

TEST_F(OpcodesMiscTest, Test0x76)
{
	// 0x76 HALT
}

TEST_F(OpcodesMiscTest, Test0xFB)
{
	// 0xFB EI
}

class Opcodes16BitLoadsTest : public CPUTest
{
};

TEST_F(Opcodes16BitLoadsTest, Test0x01)
{
	// 0x01 LD BC, nn
	// preparing cpu and memory state before executing the opcode
	state.registers.bc = 0;
	state.memory.writeWord(state.registers.pc + 1, 0xbeef);
	// testing the opcode
	testOpcode(0x01);
	// expected change in registers and memory
	expectedState.registers.pc += 3;
	expectedState.registers.bc = 0xbeef;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes16BitLoadsTest, Test0x08)
{
	// 0x08 LD (nn), SP
	// preparing cpu and memory state before executing the opcode
	state.registers.sp = 0x69;
	state.memory.writeWord(state.registers.pc + 1, 0xbeef);
	state.memory.write(0xbeef, 0);
	// testing the opcode
	testOpcode(0x08);
	// expected change in registers and memory
	expectedState.registers.pc += 3;
	expectedState.memory.write(0xbeef, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes16BitLoadsTest, Test0x11)
{
	// 0x11 LD DE, nn
	// preparing cpu and memory state before executing the opcode
	state.registers.de = 0;
	state.memory.writeWord(state.registers.pc + 1, 0xbeef);
	// testing the opcode
	testOpcode(0x11);
	// expected change in registers and memory
	expectedState.registers.pc += 3;
	expectedState.registers.de = 0xbeef;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes16BitLoadsTest, Test0x21)
{
	// 0x21 LD HL, nn
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0;
	state.memory.writeWord(state.registers.pc + 1, 0xbeef);
	// testing the opcode
	testOpcode(0x21);
	// expected change in registers and memory
	expectedState.registers.pc += 3;
	expectedState.registers.hl = 0xbeef;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes16BitLoadsTest, Test0x31)
{
	// 0x31 LD SP, nn
	// preparing cpu and memory state before executing the opcode
	state.registers.sp = 0;
	state.memory.writeWord(state.registers.pc + 1, 0xbeef);
	// testing the opcode
	testOpcode(0x31);
	// expected change in registers and memory
	expectedState.registers.pc += 3;
	expectedState.registers.sp = 0xbeef;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes16BitLoadsTest, Test0xC1)
{
	// 0xC1 POP BC
	// preparing cpu and memory state before executing the opcode
	state.registers.bc = 0;
	state.registers.sp = 0xbeef;
	state.memory.writeWord(state.registers.sp, 0xdead);
	// testing the opcode
	testOpcode(0xC1);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.sp += 2;
	expectedState.registers.bc = 0xdead;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes16BitLoadsTest, Test0xD1)
{
	// 0xD1 POP DE
	// preparing cpu and memory state before executing the opcode
	state.registers.de = 0;
	state.registers.sp = 0xbeef;
	state.memory.writeWord(state.registers.sp, 0xdead);
	// testing the opcode
	testOpcode(0xD1);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.sp += 2;
	expectedState.registers.de = 0xdead;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes16BitLoadsTest, Test0xE1)
{
	// 0xE1 POP HL
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0;
	state.registers.sp = 0xbeef;
	state.memory.writeWord(state.registers.sp, 0xdead);
	// testing the opcode
	testOpcode(0xE1);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.sp += 2;
	expectedState.registers.hl = 0xdead;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes16BitLoadsTest, Test0xF1)
{
	// 0xF1 POP AF
	// preparing cpu and memory state before executing the opcode
	state.registers.af = 0;
	state.registers.sp = 0xbeef;
	state.memory.writeWord(state.registers.sp, 0xdead);
	// testing the opcode
	testOpcode(0xF1);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.sp += 2;
	expectedState.registers.af = 0xdead;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes16BitLoadsTest, Test0xC5)
{
	// 0xC5 PUSH BC
	// preparing cpu and memory state before executing the opcode
	state.registers.bc = 0xdead;
	state.registers.sp = 0xbeef;
	state.memory.writeWord(state.registers.sp, 0x0000);
	// testing the opcode
	testOpcode(0xC5);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.sp -= 2;
	expectedState.memory.writeWord(0xbeef - 2, 0xdead);
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes16BitLoadsTest, Test0xD5)
{
	// 0xD5 PUSH DE
	// preparing cpu and memory state before executing the opcode
	state.registers.de = 0xdead;
	state.registers.sp = 0xbeef;
	state.memory.writeWord(state.registers.sp, 0x0000);
	// testing the opcode
	testOpcode(0xD5);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.sp -= 2;
	expectedState.memory.writeWord(0xbeef - 2, 0xdead);
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes16BitLoadsTest, Test0xE5)
{
	// 0xE5 PUSH HL
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.registers.sp = 0xbeef;
	state.memory.writeWord(state.registers.sp, 0x0000);
	// testing the opcode
	testOpcode(0xE5);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.sp -= 2;
	expectedState.memory.writeWord(0xbeef - 2, 0xdead);
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes16BitLoadsTest, Test0xF5)
{
	// 0xF5 PUSH AF
	// preparing cpu and memory state before executing the opcode
	state.registers.af = 0xdead;
	state.registers.sp = 0xbeef;
	state.memory.writeWord(state.registers.sp, 0x0000);
	// testing the opcode
	testOpcode(0xF5);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.sp -= 2;
	expectedState.memory.writeWord(0xbeef - 2, 0xdead);
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes16BitLoadsTest, Test0xF8)
{
	// 0xF8 LD HL, SP+e
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0;
	state.registers.sp = 0xdead;
	state.memory.write(state.registers.pc + 1, 1);
	// testing the opcode
	testOpcode(0xF8);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.hl = 0xdead + 1;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	state.registers.hl = 0;
	state.registers.sp = 0x8f;
	state.memory.write(state.registers.pc + 1, 1);
	// testing the opcode
	testOpcode(0xF8);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.hl = 0x8f + 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	state.registers.hl = 0;
	state.registers.sp = 0xff;
	state.memory.write(state.registers.pc + 1, 1);
	// testing the opcode
	testOpcode(0xF8);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.hl = 0xff + 1;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	state.registers.hl = 0;
	state.registers.sp = 0xff;
	state.memory.write(state.registers.pc + 1, -5);
	// testing the opcode
	testOpcode(0xF8);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.hl = 0xff - 5;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	state.registers.hl = 0;
	state.registers.sp = 2;
	state.memory.write(state.registers.pc + 1, -5);
	// testing the opcode
	testOpcode(0xF8);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.hl = 2 - 5;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	state.registers.hl = 0;
	state.registers.sp = 0xf0;
	state.memory.write(state.registers.pc + 1, -5);
	// testing the opcode
	testOpcode(0xF8);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.hl = 0xf0 - 5;
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	state.registers.hl = 0;
	state.registers.sp = 0xf0;
	state.memory.write(state.registers.pc + 1, 0x10);
	// testing the opcode
	testOpcode(0xF8);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.hl = 0xf0 + 0x10;
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	state.registers.hl = 0;
	state.registers.sp = 0;
	state.memory.write(state.registers.pc + 1, 0);
	// testing the opcode
	testOpcode(0xF8);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.hl = 0;
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes16BitLoadsTest, Test0xF9)
{
	// 0xF9 LD SP, HL
	// preparing cpu and memory state before executing the opcode
	state.registers.sp = 0;
	state.registers.hl = 0xdead;
	// testing the opcode
	testOpcode(0xF9);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.sp = 0xdead;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}