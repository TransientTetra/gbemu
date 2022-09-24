#include <libgrebe/cpu.test.hpp>

TEST_F(CPUTest, InterruptsTest)
{
	state.registers.pc = 0xdead;
	state.ime = false;
	state.memory.write(LIBGREBE_REG_IE, 0xff);
	state.memory.write(LIBGREBE_REG_IF, 0xff);
	testOpcode(0x00);
	expectedState.registers.pc += 1;
	EXPECT_TRUE(expectedState == state);

	state.registers.pc = 0xdead;
	state.ime = true;
	state.memory.write(LIBGREBE_REG_IE, 0);
	state.memory.write(LIBGREBE_REG_IF, 0xff);
	testOpcode(0x00);
	expectedState.registers.pc += 1;
	EXPECT_TRUE(expectedState == state);

	state.registers.pc = 0xdead;
	state.ime = true;
	state.memory.write(LIBGREBE_REG_IE, 0xff);
	state.memory.write(LIBGREBE_REG_IF, 0);
	testOpcode(0x00);
	expectedState.registers.pc += 1;
	EXPECT_TRUE(expectedState == state);

	state.registers.pc = 0xdead;
	state.registers.sp = 0xbeef;
	state.ime = true;
	state.memory.write(LIBGREBE_REG_IE, 1);
	state.memory.write(LIBGREBE_REG_IF, 1);
	testOpcode(0x00);
	expectedState.registers.pc = LIBGREBE_INT_VBLANK;
	expectedState.registers.sp = 0xbeef - 2;
	expectedState.ime = false;
	expectedState.memory.writeWord(0xbeef - 2, 0xdead + 1);
	expectedState.memory.write(LIBGREBE_REG_IF, 0);
	EXPECT_TRUE(expectedState == state);

	state.registers.pc = 0xdead;
	state.registers.sp = 0xbeef;
	state.ime = true;
	state.memory.write(LIBGREBE_REG_IE, 2);
	state.memory.write(LIBGREBE_REG_IF, 2);
	testOpcode(0x00);
	expectedState.registers.pc = LIBGREBE_INT_STAT;
	expectedState.registers.sp = 0xbeef - 2;
	expectedState.ime = false;
	expectedState.memory.writeWord(0xbeef - 2, 0xdead + 1);
	expectedState.memory.write(LIBGREBE_REG_IF, 0);
	EXPECT_TRUE(expectedState == state);

	state.registers.pc = 0xdead;
	state.registers.sp = 0xbeef;
	state.ime = true;
	state.memory.write(LIBGREBE_REG_IE, 4);
	state.memory.write(LIBGREBE_REG_IF, 4);
	testOpcode(0x00);
	expectedState.registers.pc = LIBGREBE_INT_TIMER;
	expectedState.registers.sp = 0xbeef - 2;
	expectedState.ime = false;
	expectedState.memory.writeWord(0xbeef - 2, 0xdead + 1);
	expectedState.memory.write(LIBGREBE_REG_IF, 0);
	EXPECT_TRUE(expectedState == state);

	state.registers.pc = 0xdead;
	state.registers.sp = 0xbeef;
	state.ime = true;
	state.memory.write(LIBGREBE_REG_IE, 8);
	state.memory.write(LIBGREBE_REG_IF, 8);
	testOpcode(0x00);
	expectedState.registers.pc = LIBGREBE_INT_SERIAL;
	expectedState.registers.sp = 0xbeef - 2;
	expectedState.ime = false;
	expectedState.memory.writeWord(0xbeef - 2, 0xdead + 1);
	expectedState.memory.write(LIBGREBE_REG_IF, 0);
	EXPECT_TRUE(expectedState == state);

	state.registers.pc = 0xdead;
	state.registers.sp = 0xbeef;
	state.ime = true;
	state.memory.write(LIBGREBE_REG_IE, 16);
	state.memory.write(LIBGREBE_REG_IF, 16);
	testOpcode(0x00);
	expectedState.registers.pc = LIBGREBE_INT_JOYPAD;
	expectedState.registers.sp = 0xbeef - 2;
	expectedState.ime = false;
	expectedState.memory.writeWord(0xbeef - 2, 0xdead + 1);
	expectedState.memory.write(LIBGREBE_REG_IF, 0);
	EXPECT_TRUE(expectedState == state);
}

TEST_F(CPUTest, UndefinedOpcodesTest)
{
	EXPECT_THROW(testOpcode(0xD3), UndefinedOpcodeException);
	EXPECT_THROW(testOpcode(0xE3), UndefinedOpcodeException);
	EXPECT_THROW(testOpcode(0xE4), UndefinedOpcodeException);
	EXPECT_THROW(testOpcode(0xF4), UndefinedOpcodeException);
	EXPECT_THROW(testOpcode(0xDB), UndefinedOpcodeException);
	EXPECT_THROW(testOpcode(0xDD), UndefinedOpcodeException);
	EXPECT_THROW(testOpcode(0xEB), UndefinedOpcodeException);
	EXPECT_THROW(testOpcode(0xEC), UndefinedOpcodeException);
	EXPECT_THROW(testOpcode(0xED), UndefinedOpcodeException);
	EXPECT_THROW(testOpcode(0xFC), UndefinedOpcodeException);
	EXPECT_THROW(testOpcode(0xFD), UndefinedOpcodeException);
}

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
	// preparing cpu and memory state before executing the opcode
	state.ime = true;
	// testing the opcode
	testOpcode(0xF3);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.ime = false;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// preparing cpu and memory state before executing the opcode
	state.ime = true;
	state.imeScheduled = true;
	// testing the opcode
	testOpcode(0xF3);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.ime = false;
	expectedState.imeScheduled = false;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(OpcodesMiscTest, Test0x76)
{
	// 0x76 HALT
}

TEST_F(OpcodesMiscTest, Test0xFB)
{
	// 0xFB EI
	// preparing cpu and memory state before executing the opcode
	state.ime = false;
	state.imeScheduled = false;
	// testing the opcode
	testOpcode(0xFB);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.imeScheduled = true;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	// testing the opcode
	testOpcode(0x00);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.imeScheduled = false;
	expectedState.ime = true;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

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