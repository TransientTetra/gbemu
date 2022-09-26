#include <libgrebe/cpu.test.hpp>

TEST_F(CPUTest, InterruptsTest)
{
	state.registers.pc = 0xdead;
	state.ime = false;
	state.memory.write(LIBGREBE_REG_IE, 0xff);
	state.memory.write(LIBGREBE_REG_IF, 0xff);
	testOpcode(0x00);
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	EXPECT_TRUE(expectedState == state);

	state.registers.pc = 0xdead;
	state.ime = true;
	state.memory.write(LIBGREBE_REG_IE, 0);
	state.memory.write(LIBGREBE_REG_IF, 0xff);
	testOpcode(0x00);
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	EXPECT_TRUE(expectedState == state);

	state.registers.pc = 0xdead;
	state.ime = true;
	state.memory.write(LIBGREBE_REG_IE, 0xff);
	state.memory.write(LIBGREBE_REG_IF, 0);
	testOpcode(0x00);
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	EXPECT_TRUE(expectedState == state);

	state.registers.pc = 0xdead;
	state.registers.sp = 0xbeef;
	state.ime = true;
	state.memory.write(LIBGREBE_REG_IE, 1);
	state.memory.write(LIBGREBE_REG_IF, 1);
	testOpcode(0x00);
	expectedState.clockCycles += 20;
	expectedState.registers.pc = LIBGREBE_INT_VBLANK;
	expectedState.registers.sp = 0xbeef - 2;
	expectedState.ime = false;
	expectedState.memory.writeWord(0xbeef - 2, 0xdead);
	expectedState.memory.write(LIBGREBE_REG_IF, 0);
	EXPECT_TRUE(expectedState == state);

	state.registers.pc = 0xdead;
	state.registers.sp = 0xbeef;
	state.ime = true;
	state.memory.write(LIBGREBE_REG_IE, 2);
	state.memory.write(LIBGREBE_REG_IF, 2);
	testOpcode(0x00);
	expectedState.clockCycles += 20;
	expectedState.registers.pc = LIBGREBE_INT_STAT;
	expectedState.registers.sp = 0xbeef - 2;
	expectedState.ime = false;
	expectedState.memory.writeWord(0xbeef - 2, 0xdead);
	expectedState.memory.write(LIBGREBE_REG_IF, 0);
	EXPECT_TRUE(expectedState == state);

	state.registers.pc = 0xdead;
	state.registers.sp = 0xbeef;
	state.ime = true;
	state.memory.write(LIBGREBE_REG_IE, 4);
	state.memory.write(LIBGREBE_REG_IF, 4);
	testOpcode(0x00);
	expectedState.clockCycles += 20;
	expectedState.registers.pc = LIBGREBE_INT_TIMER;
	expectedState.registers.sp = 0xbeef - 2;
	expectedState.ime = false;
	expectedState.memory.writeWord(0xbeef - 2, 0xdead);
	expectedState.memory.write(LIBGREBE_REG_IF, 0);
	EXPECT_TRUE(expectedState == state);

	state.registers.pc = 0xdead;
	state.registers.sp = 0xbeef;
	state.ime = true;
	state.memory.write(LIBGREBE_REG_IE, 8);
	state.memory.write(LIBGREBE_REG_IF, 8);
	testOpcode(0x00);
	expectedState.clockCycles += 20;
	expectedState.registers.pc = LIBGREBE_INT_SERIAL;
	expectedState.registers.sp = 0xbeef - 2;
	expectedState.ime = false;
	expectedState.memory.writeWord(0xbeef - 2, 0xdead);
	expectedState.memory.write(LIBGREBE_REG_IF, 0);
	EXPECT_TRUE(expectedState == state);

	state.registers.pc = 0xdead;
	state.registers.sp = 0xbeef;
	state.ime = true;
	state.memory.write(LIBGREBE_REG_IE, 16);
	state.memory.write(LIBGREBE_REG_IF, 16);
	testOpcode(0x00);
	expectedState.clockCycles += 20;
	expectedState.registers.pc = LIBGREBE_INT_JOYPAD;
	expectedState.registers.sp = 0xbeef - 2;
	expectedState.ime = false;
	expectedState.memory.writeWord(0xbeef - 2, 0xdead);
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
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	EXPECT_TRUE(expectedState == state);
}

TEST_F(OpcodesMiscTest, Test0x10)
{
	// 0x10 STOP
	// preparing cpu and memory state before executing the opcode
	// testing the opcode
	testOpcode(0x10);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 2;
	expectedState.stop = true;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	cpu.execute(state);
	cpu.execute(state);
	cpu.execute(state);
	EXPECT_TRUE(expectedState == state);
	state.memory.write(LIBGREBE_REG_P1, 0b11110111);
	expectedState = state;
	cpu.execute(state);
	cpu.execute(state);
	cpu.execute(state);
	EXPECT_TRUE(expectedState == state);
	state.memory.write(LIBGREBE_REG_P1, 0b11011111);
	expectedState = state;
	cpu.execute(state);
	cpu.execute(state);
	cpu.execute(state);
	EXPECT_TRUE(expectedState == state);
	state.memory.write(LIBGREBE_REG_P1, 0b11011110);
	testOpcode(0);
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.stop = false;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(OpcodesMiscTest, Test0xF3)
{
	// 0xF3 DI
	// preparing cpu and memory state before executing the opcode
	state.ime = true;
	// testing the opcode
	testOpcode(0xF3);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
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
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.ime = false;
	expectedState.imeScheduled = false;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(OpcodesMiscTest, Test0x76)
{
	// 0x76 HALT
	// preparing cpu and memory state before executing the opcode
	state.ime = true;
	// testing the opcode
	testOpcode(0x76);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.halt = true;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	// testing the opcode
	testOpcode(0x00);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	// testing the opcode
	testOpcode(0xCF);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	// testing the opcode
	testOpcode(0xCF);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// injecting interrupt
	state.registers.pc = 0xdead;
	state.registers.sp = 0xbeef;
	state.memory.write(LIBGREBE_REG_IE, 1);
	state.memory.write(LIBGREBE_REG_IF, 1);
	testOpcode(0x00);
	expectedState.clockCycles += 24;
	expectedState.registers.pc = LIBGREBE_INT_VBLANK;
	expectedState.registers.sp = 0xbeef - 2;
	expectedState.ime = false;
	expectedState.halt = false;
	expectedState.memory.writeWord(0xbeef - 2, 0xdead);
	expectedState.memory.write(LIBGREBE_REG_IF, 0);
	EXPECT_TRUE(expectedState == state);

	// halt bug
	// preparing cpu and memory state before executing the opcode
	state.ime = false;
	state.memory.write(LIBGREBE_REG_IE, 0);
	state.memory.write(LIBGREBE_REG_IF, 0);
	// testing the opcode
	testOpcode(0x76);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.halt = true;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	// testing the opcode
	testOpcode(0xCF);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	// testing the opcode
	testOpcode(0xCF);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);

	// injecting interrupt
	state.memory.write(LIBGREBE_REG_IE, 1);
	state.memory.write(LIBGREBE_REG_IF, 1);
	testOpcode(0x00);
	expectedState.clockCycles += 8;
	expectedState.registers.pc += 1;
	expectedState.halt = false;
	EXPECT_TRUE(expectedState == state);

	// todo halt bug 2
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
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.imeScheduled = true;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
	// testing the opcode
	testOpcode(0x00);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.pc += 1;
	expectedState.imeScheduled = false;
	expectedState.ime = true;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}
