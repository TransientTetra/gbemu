#include <libgrebe/cpu.test.hpp>

TEST_F(Opcodes8BitLoadsTest, Test0x02)
{
	// 0x02 LD (BC), A
	// preparing cpu and memory state before executing the opcode
	state.registers.bc = 0xbeef;
	state.registers.a = 0x69;
	state.memory.write(state.registers.bc, 0x0);
	// testing the opcode
	testOpcode(0x02);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.memory.write(state.registers.bc, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x06)
{
	// 0x06 LD B, n
	// preparing cpu and memory state before executing the opcode
	state.registers.b = 0;
	state.memory.write(state.registers.pc + 1, 0x69);
	// testing the opcode
	testOpcode(0x06);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.b = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x0A)
{
	// 0x0A LD A, (BC)
	// preparing cpu and memory state before executing the opcode
	state.registers.bc = 0xbeef;
	state.registers.a = 0;
	state.memory.write(state.registers.bc, 0x69);
	// testing the opcode
	testOpcode(0x0A);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x0E)
{
	// 0x0E LD C, n
	// preparing cpu and memory state before executing the opcode
	state.registers.c = 0;
	state.memory.write(state.registers.pc + 1, 0x69);
	// testing the opcode
	testOpcode(0x0E);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.c = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x12)
{
	// 0x12 LD (DE), A
	// preparing cpu and memory state before executing the opcode
	state.registers.de = 0xbeef;
	state.registers.a = 0x69;
	state.memory.write(state.registers.de, 0);
	// testing the opcode
	testOpcode(0x12);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.memory.write(state.registers.de, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x16)
{
	// 0x16 LD D, n
	// preparing cpu and memory state before executing the opcode
	state.registers.d = 0;
	state.memory.write(state.registers.pc + 1, 0x69);
	// testing the opcode
	testOpcode(0x16);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.d = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x1A)
{
	// 0x1A LD A, (DE)
	// preparing cpu and memory state before executing the opcode
	state.registers.de = 0xbeef;
	state.registers.a = 0;
	state.memory.write(state.registers.de, 0x69);
	// testing the opcode
	testOpcode(0x1A);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x1E)
{
	// 0x1E LD E, n
	// preparing cpu and memory state before executing the opcode
	state.registers.e = 0;
	state.memory.write(state.registers.pc + 1, 0x69);
	// testing the opcode
	testOpcode(0x1E);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.e = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x22)
{
	// 0x22 LD (HL+), A
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x69;
	state.registers.hl = 0xdead;
	state.memory.write(state.registers.hl, 0);
	// testing the opcode
	testOpcode(0x22);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.hl = 0xdead + 1;
	expectedState.memory.write(0xdead, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x26)
{
	// 0x26 LD H, n
	// preparing cpu and memory state before executing the opcode
	state.registers.h = 0;
	state.memory.write(state.registers.pc + 1, 0x69);
	// testing the opcode
	testOpcode(0x26);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.h = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x2A)
{
	// 0x2A LD A, (HL+)
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x0;
	state.registers.hl = 0xdead;
	state.memory.write(state.registers.hl, 0x69);
	// testing the opcode
	testOpcode(0x2A);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.hl = 0xdead + 1;
	expectedState.registers.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x2E)
{
	// 0x2E LD L, n
	// preparing cpu and memory state before executing the opcode
	state.registers.l = 0;
	state.memory.write(state.registers.pc + 1, 0x69);
	// testing the opcode
	testOpcode(0x2E);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.l = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x32)
{
	// 0x32 LD (HL-), A
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x69;
	state.registers.hl = 0xdead;
	state.memory.write(state.registers.hl, 0);
	// testing the opcode
	testOpcode(0x32);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.hl = 0xdead - 1;
	expectedState.memory.write(0xdead, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x36)
{
	// 0x36 LD (HL), n
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(state.registers.hl, 0);
	state.memory.write(state.registers.pc + 1, 0x69);
	// testing the opcode
	testOpcode(0x36);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xdead, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x3A)
{
	// 0x3A LD A, (HL-)
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x0;
	state.registers.hl = 0xdead;
	state.memory.write(state.registers.hl, 0x69);
	// testing the opcode
	testOpcode(0x3A);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.hl = 0xdead - 1;
	expectedState.registers.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x3E)
{
	// 0x3E LD A, n
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	state.memory.write(state.registers.pc + 1, 0x69);
	// testing the opcode
	testOpcode(0x3E);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x40)
{
	// 0x40 LD B, B
	// preparing cpu and memory state before executing the opcode
	state.registers.b = 0x69;
	// testing the opcode
	testOpcode(0x40);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.b = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x41)
{
	// 0x41 LD B, C
	// preparing cpu and memory state before executing the opcode
	state.registers.b = 0;
	state.registers.c = 0x69;
	// testing the opcode
	testOpcode(0x41);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.b = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x42)
{
	// 0x42 LD B, D
	// preparing cpu and memory state before executing the opcode
	state.registers.b = 0;
	state.registers.d = 0x69;
	// testing the opcode
	testOpcode(0x42);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.b = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x43)
{
	// 0x43 LD B, E
	// preparing cpu and memory state before executing the opcode
	state.registers.b = 0;
	state.registers.e = 0x69;
	// testing the opcode
	testOpcode(0x43);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.b = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x44)
{
	// 0x44 LD B, H
	// preparing cpu and memory state before executing the opcode
	state.registers.b = 0;
	state.registers.h = 0x69;
	// testing the opcode
	testOpcode(0x44);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.b = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x45)
{
	// 0x45 LD B, L
	// preparing cpu and memory state before executing the opcode
	state.registers.b = 0;
	state.registers.l = 0x69;
	// testing the opcode
	testOpcode(0x45);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.b = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x46)
{
	// 0x46 LD B, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xbeef;
	state.registers.b = 0;
	state.memory.write(state.registers.hl, 0x69);
	// testing the opcode
	testOpcode(0x46);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.b = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x47)
{
	// 0x47 LD B, A
	// preparing cpu and memory state before executing the opcode
	state.registers.b = 0;
	state.registers.a = 0x69;
	// testing the opcode
	testOpcode(0x47);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.b = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x48)
{
	// 0x48 LD C, B
	// preparing cpu and memory state before executing the opcode
	state.registers.c = 0;
	state.registers.b = 0x69;
	// testing the opcode
	testOpcode(0x48);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.c = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x49)
{
	// 0x49 LD C, C
	// preparing cpu and memory state before executing the opcode
	state.registers.c = 0;
	state.registers.c = 0x69;
	// testing the opcode
	testOpcode(0x49);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.c = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x4A)
{
	// 0x4A LD C, D
	// preparing cpu and memory state before executing the opcode
	state.registers.c = 0;
	state.registers.d = 0x69;
	// testing the opcode
	testOpcode(0x4A);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.c = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x4B)
{
	// 0x4B LD C, E
	// preparing cpu and memory state before executing the opcode
	state.registers.c = 0;
	state.registers.e = 0x69;
	// testing the opcode
	testOpcode(0x4B);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.c = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x4C)
{
	// 0x4C LD C, H
	// preparing cpu and memory state before executing the opcode
	state.registers.c = 0;
	state.registers.h = 0x69;
	// testing the opcode
	testOpcode(0x4C);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.c = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x4D)
{
	// 0x4D LD C, L
	// preparing cpu and memory state before executing the opcode
	state.registers.c = 0;
	state.registers.l = 0x69;
	// testing the opcode
	testOpcode(0x4D);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.c = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x4E)
{
	// 0x4E LD C, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xbeef;
	state.registers.c = 0;
	state.memory.write(state.registers.hl, 0x69);
	// testing the opcode
	testOpcode(0x4E);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.c = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x4F)
{
	// 0x4F LD C, A
	// preparing cpu and memory state before executing the opcode
	state.registers.c = 0;
	state.registers.a = 0x69;
	// testing the opcode
	testOpcode(0x4F);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.c = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x50)
{
	// 0x50 LD D, B
	// preparing cpu and memory state before executing the opcode
	state.registers.d = 0;
	state.registers.b = 0x69;
	// testing the opcode
	testOpcode(0x50);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.d = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x51)
{
	// 0x51 LD D, C
	// preparing cpu and memory state before executing the opcode
	state.registers.d = 0;
	state.registers.c = 0x69;
	// testing the opcode
	testOpcode(0x51);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.d = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x52)
{
	// 0x52 LD D, D
	// preparing cpu and memory state before executing the opcode
	state.registers.d = 0;
	state.registers.d = 0x69;
	// testing the opcode
	testOpcode(0x52);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.d = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x53)
{
	// 0x53 LD D, E
	// preparing cpu and memory state before executing the opcode
	state.registers.d = 0;
	state.registers.e = 0x69;
	// testing the opcode
	testOpcode(0x53);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.d = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x54)
{
	// 0x54 LD D, H
	// preparing cpu and memory state before executing the opcode
	state.registers.d = 0;
	state.registers.h = 0x69;
	// testing the opcode
	testOpcode(0x54);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.d = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x55)
{
	// 0x55 LD D, L
	// preparing cpu and memory state before executing the opcode
	state.registers.d = 0;
	state.registers.l = 0x69;
	// testing the opcode
	testOpcode(0x55);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.d = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x56)
{
	// 0x56 LD D, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xbeef;
	state.registers.d = 0;
	state.memory.write(state.registers.hl, 0x69);
	// testing the opcode
	testOpcode(0x56);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.d = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x57)
{
	// 0x57 LD D, A
	// preparing cpu and memory state before executing the opcode
	state.registers.d = 0;
	state.registers.a = 0x69;
	// testing the opcode
	testOpcode(0x57);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.d = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x58)
{
	// 0x58 LD E, B
	// preparing cpu and memory state before executing the opcode
	state.registers.e = 0;
	state.registers.b = 0x69;
	// testing the opcode
	testOpcode(0x58);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.e = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x59)
{
	// 0x59 LD E, C
	// preparing cpu and memory state before executing the opcode
	state.registers.e = 0;
	state.registers.c = 0x69;
	// testing the opcode
	testOpcode(0x59);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.e = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x5A)
{
	// 0x5A LD E, D
	// preparing cpu and memory state before executing the opcode
	state.registers.e = 0;
	state.registers.d = 0x69;
	// testing the opcode
	testOpcode(0x5A);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.e = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x5B)
{
	// 0x5B LD E, E
	// preparing cpu and memory state before executing the opcode
	state.registers.e = 0;
	state.registers.e = 0x69;
	// testing the opcode
	testOpcode(0x5B);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.e = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x5C)
{
	// 0x5C LD E, H
	// preparing cpu and memory state before executing the opcode
	state.registers.e = 0;
	state.registers.h = 0x69;
	// testing the opcode
	testOpcode(0x5C);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.e = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x5D)
{
	// 0x5D LD E, L
	// preparing cpu and memory state before executing the opcode
	state.registers.e = 0;
	state.registers.l = 0x69;
	// testing the opcode
	testOpcode(0x5D);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.e = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x5E)
{
	// 0x5E LD E, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xbeef;
	state.registers.e = 0;
	state.memory.write(state.registers.hl, 0x69);
	// testing the opcode
	testOpcode(0x5E);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.e = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x5F)
{
	// 0x5F LD E, A
	// preparing cpu and memory state before executing the opcode
	state.registers.e = 0;
	state.registers.a = 0x69;
	// testing the opcode
	testOpcode(0x5F);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.e = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x60)
{
	// 0x60 LD H, B
	// preparing cpu and memory state before executing the opcode
	state.registers.h = 0;
	state.registers.b = 0x69;
	// testing the opcode
	testOpcode(0x60);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.h = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x61)
{
	// 0x61 LD H, C
	// preparing cpu and memory state before executing the opcode
	state.registers.h = 0;
	state.registers.c = 0x69;
	// testing the opcode
	testOpcode(0x61);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.h = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x62)
{
	// 0x62 LD H, D
	// preparing cpu and memory state before executing the opcode
	state.registers.h = 0;
	state.registers.d = 0x69;
	// testing the opcode
	testOpcode(0x62);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.h = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x63)
{
	// 0x63 LD H, E
	// preparing cpu and memory state before executing the opcode
	state.registers.h = 0;
	state.registers.e = 0x69;
	// testing the opcode
	testOpcode(0x63);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.h = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x64)
{
	// 0x64 LD H, H
	// preparing cpu and memory state before executing the opcode
	state.registers.h = 0;
	state.registers.h = 0x69;
	// testing the opcode
	testOpcode(0x64);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.h = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x65)
{
	// 0x65 LD H, L
	// preparing cpu and memory state before executing the opcode
	state.registers.h = 0;
	state.registers.l = 0x69;
	// testing the opcode
	testOpcode(0x65);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.h = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x66)
{
	// 0x66 LD H, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xbeef;
	state.registers.h = 0;
	state.memory.write(state.registers.hl, 0x69);
	// testing the opcode
	testOpcode(0x66);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.h = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x67)
{
	// 0x67 LD H, A
	// preparing cpu and memory state before executing the opcode
	state.registers.h = 0;
	state.registers.a = 0x69;
	// testing the opcode
	testOpcode(0x67);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.h = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x68)
{
	// 0x68 LD L, B
	// preparing cpu and memory state before executing the opcode
	state.registers.l = 0;
	state.registers.b = 0x69;
	// testing the opcode
	testOpcode(0x68);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.l = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x69)
{
	// 0x69 LD L, C
	// preparing cpu and memory state before executing the opcode
	state.registers.l = 0;
	state.registers.c = 0x69;
	// testing the opcode
	testOpcode(0x69);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.l = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x6A)
{
	// 0x6A LD L, D
	// preparing cpu and memory state before executing the opcode
	state.registers.l = 0;
	state.registers.d = 0x69;
	// testing the opcode
	testOpcode(0x6A);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.l = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x6B)
{
	// 0x6B LD L, E
	// preparing cpu and memory state before executing the opcode
	state.registers.l = 0;
	state.registers.e = 0x69;
	// testing the opcode
	testOpcode(0x6B);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.l = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x6C)
{
	// 0x6C LD L, H
	// preparing cpu and memory state before executing the opcode
	state.registers.l = 0;
	state.registers.h = 0x69;
	// testing the opcode
	testOpcode(0x6C);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.l = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x6D)
{
	// 0x6D LD L, L
	// preparing cpu and memory state before executing the opcode
	state.registers.l = 0;
	state.registers.l = 0x69;
	// testing the opcode
	testOpcode(0x6D);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.l = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x6E)
{
	// 0x6E LD L, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xbeef;
	state.registers.l = 0;
	state.memory.write(state.registers.hl, 0x69);
	// testing the opcode
	testOpcode(0x6E);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.l = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x6F)
{
	// 0x6F LD L, A
	// preparing cpu and memory state before executing the opcode
	state.registers.l = 0;
	state.registers.a = 0x69;
	// testing the opcode
	testOpcode(0x6F);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.l = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x70)
{
	// 0x70 LD (HL), B
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.registers.b = 0x69;
	state.memory.write(state.registers.hl, 0);
	// testing the opcode
	testOpcode(0x70);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.memory.write(0xdead, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x71)
{
	// 0x71 LD (HL), C
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.registers.c = 0x69;
	state.memory.write(state.registers.hl, 0);
	// testing the opcode
	testOpcode(0x71);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.memory.write(0xdead, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x72)
{
	// 0x72 LD (HL), D
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.registers.d = 0x69;
	state.memory.write(state.registers.hl, 0);
	// testing the opcode
	testOpcode(0x72);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.memory.write(0xdead, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x73)
{
	// 0x73 LD (HL), E
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.registers.e = 0x69;
	state.memory.write(state.registers.hl, 0);
	// testing the opcode
	testOpcode(0x73);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.memory.write(0xdead, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x74)
{
	// 0x74 LD (HL), H
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(state.registers.hl, 0);
	// testing the opcode
	testOpcode(0x74);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.memory.write(0xdead, 0xde);
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x75)
{
	// 0x75 LD (HL), L
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.memory.write(state.registers.hl, 0);
	// testing the opcode
	testOpcode(0x75);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.memory.write(0xdead, 0xad);
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x77)
{
	// 0x77 LD (HL), A
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xdead;
	state.registers.a = 0x69;
	state.memory.write(state.registers.hl, 0);
	// testing the opcode
	testOpcode(0x73);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.memory.write(0xdead, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x78)
{
	// 0x78 LD A, B
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	state.registers.b = 0x69;
	// testing the opcode
	testOpcode(0x78);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x79)
{
	// 0x79 LD A, C
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	state.registers.c = 0x69;
	// testing the opcode
	testOpcode(0x79);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x7A)
{
	// 0x7A LD A, D
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	state.registers.d = 0x69;
	// testing the opcode
	testOpcode(0x7A);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x7B)
{
	// 0x7B LD A, E
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	state.registers.e = 0x69;
	// testing the opcode
	testOpcode(0x7B);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x7C)
{
	// 0x7C LD A, H
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	state.registers.h = 0x69;
	// testing the opcode
	testOpcode(0x7C);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x7D)
{
	// 0x7D LD A, L
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	state.registers.l = 0x69;
	// testing the opcode
	testOpcode(0x7D);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x7E)
{
	// 0x7E LD A, (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.hl = 0xbeef;
	state.registers.a = 0;
	state.memory.write(state.registers.hl, 0x69);
	// testing the opcode
	testOpcode(0x7E);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0x7F)
{
	// 0x7F LD A, A
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	state.registers.a = 0x69;
	// testing the opcode
	testOpcode(0x7F);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0xE0)
{
	// 0xE0 LDH (n), A
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x69;
	state.memory.write(state.registers.pc + 1, 0x42);
	state.memory.write(0xFF42, 0);
	// testing the opcode
	testOpcode(0xE0);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.memory.write(0xFF42, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0xE2)
{
	// 0xE2 LDH (C), A
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x69;
	state.registers.c = 0x42;
	state.memory.write(0xFF42, 0);
	// testing the opcode
	testOpcode(0xE2);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.memory.write(0xFF42, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0xEA)
{
	// 0xEA LD (nn), A
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0x69;
	state.memory.write(state.registers.pc + 1, 0xef);
	state.memory.write(state.registers.pc + 2, 0xbe);
	state.memory.write(0xbeef, 0);
	// testing the opcode
	testOpcode(0xEA);
	// expected change in registers and memory
	expectedState.registers.pc += 3;
	expectedState.memory.write(0xbeef, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0xF0)
{
	// 0xF0 LDH A, (n)
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	state.memory.write(state.registers.pc + 1, 0x42);
	state.memory.write(0xFF42, 0x69);
	// testing the opcode
	testOpcode(0xF0);
	// expected change in registers and memory
	expectedState.registers.pc += 2;
	expectedState.registers.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0xF2)
{        // 0xF2 LDH A, (C)
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	state.registers.c = 0x42;
	state.memory.write(0xFF42, 0x69);
	// testing the opcode
	testOpcode(0xF2);
	// expected change in registers and memory
	expectedState.registers.pc += 1;
	expectedState.registers.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}

TEST_F(Opcodes8BitLoadsTest, Test0xFA)
{
	// 0xFA LD A, (nn)
	// preparing cpu and memory state before executing the opcode
	state.registers.a = 0;
	state.memory.write(state.registers.pc + 1, 0xef);
	state.memory.write(state.registers.pc + 2, 0xbe);
	state.memory.write(0xbeef, 0x69);
	// testing the opcode
	testOpcode(0xFA);
	// expected change in registers and memory
	expectedState.registers.pc += 3;
	expectedState.registers.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedState == state);
}
