#include <gtest/gtest.h>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconstant-conversion"
#define private public
#include <libgbemu/cpu.hpp>

class CPUTest : public ::testing::Test
{
protected:
	CPU cpu;
	Memory mem, expectedMem;
	Registers reg, expectedRegs;
	void SetUp() override
	{
	}
	void TearDown() override
	{
	}
	void testOpcode(Byte opcode)
	{
		// injecting opcode at pc
		mem.write(reg.pc, opcode);
		// saving cpu and memory state before executing the opcode
		expectedRegs = reg;
		expectedMem = mem;
		// executing the opcode
		cpu.execute(reg, mem);
	}
};

TEST_F(CPUTest, CreationTest)
{
}

TEST_F(CPUTest, OpcodeMiscTest)
{
	// 0x00 NOP
	// executing the opcode
	testOpcode(0x00);
	// expected change in registers
	expectedRegs.pc += 1;
	EXPECT_TRUE(expectedRegs == reg);

	// 0x10 STOP
	// 0xF3 DI
	// 0x76 HALT
	// 0xFB EI
}

TEST_F(CPUTest, Opcode8BitLoadsTest)
{
	// 0x02 LD (BC), A
	// preparing cpu and memory state before executing the opcode
	reg.bc = 0xbeef;
	reg.a = 0x69;
	mem.write(reg.bc, 0x0);
	// testing the opcode
	testOpcode(0x02);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedMem.write(reg.bc, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x06 LD B, n
	// preparing cpu and memory state before executing the opcode
	reg.b = 0;
	mem.write(reg.pc + 1, 0x69);
	// testing the opcode
	testOpcode(0x06);
	// expected change in registers and memory
	expectedRegs.pc += 2;
	expectedRegs.b = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x0A LD A, (BC)
	// preparing cpu and memory state before executing the opcode
	reg.bc = 0xbeef;
	reg.a = 0;
	mem.write(reg.bc, 0x69);
	// testing the opcode
	testOpcode(0x0A);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x0E LD C, n
	// preparing cpu and memory state before executing the opcode
	reg.c = 0;
	mem.write(reg.pc + 1, 0x69);
	// testing the opcode
	testOpcode(0x0E);
	// expected change in registers and memory
	expectedRegs.pc += 2;
	expectedRegs.c = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x12 LD (DE), A
	// preparing cpu and memory state before executing the opcode
	reg.de = 0xbeef;
	reg.a = 0x69;
	mem.write(reg.de, 0);
	// testing the opcode
	testOpcode(0x12);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedMem.write(reg.de, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x16 LD D, n
	// preparing cpu and memory state before executing the opcode
	reg.d = 0;
	mem.write(reg.pc + 1, 0x69);
	// testing the opcode
	testOpcode(0x16);
	// expected change in registers and memory
	expectedRegs.pc += 2;
	expectedRegs.d = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x1A LD A, (DE)
	// preparing cpu and memory state before executing the opcode
	reg.de = 0xbeef;
	reg.a = 0;
	mem.write(reg.de, 0x69);
	// testing the opcode
	testOpcode(0x1A);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x1E LD E, n
	// preparing cpu and memory state before executing the opcode
	reg.e = 0;
	mem.write(reg.pc + 1, 0x69);
	// testing the opcode
	testOpcode(0x1E);
	// expected change in registers and memory
	expectedRegs.pc += 2;
	expectedRegs.e = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x22 LD (HL+), A
	// preparing cpu and memory state before executing the opcode
	reg.a = 0x69;
	reg.hl = 0xdead;
	mem.write(reg.hl, 0);
	// testing the opcode
	testOpcode(0x22);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.hl = 0xdead + 1;
	expectedMem.write(0xdead, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x26 LD H, n
	// preparing cpu and memory state before executing the opcode
	reg.h = 0;
	mem.write(reg.pc + 1, 0x69);
	// testing the opcode
	testOpcode(0x26);
	// expected change in registers and memory
	expectedRegs.pc += 2;
	expectedRegs.h = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x2A LD A, (HL+)
	// preparing cpu and memory state before executing the opcode
	reg.a = 0x0;
	reg.hl = 0xdead;
	mem.write(reg.hl, 0x69);
	// testing the opcode
	testOpcode(0x2A);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.hl = 0xdead + 1;
	expectedRegs.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x2E LD L, n
	// preparing cpu and memory state before executing the opcode
	reg.l = 0;
	mem.write(reg.pc + 1, 0x69);
	// testing the opcode
	testOpcode(0x2E);
	// expected change in registers and memory
	expectedRegs.pc += 2;
	expectedRegs.l = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x32 LD (HL-), A
	// preparing cpu and memory state before executing the opcode
	reg.a = 0x69;
	reg.hl = 0xdead;
	mem.write(reg.hl, 0);
	// testing the opcode
	testOpcode(0x32);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.hl = 0xdead - 1;
	expectedMem.write(0xdead, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x36 LD (HL), n
	// preparing cpu and memory state before executing the opcode
	reg.hl = 0xdead;
	mem.write(reg.hl, 0);
	mem.write(reg.pc + 1, 0x69);
	// testing the opcode
	testOpcode(0x36);
	// expected change in registers and memory
	expectedRegs.pc += 2;
	expectedMem.write(0xdead, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x3A LD A, (HL-)
	// preparing cpu and memory state before executing the opcode
	reg.a = 0x0;
	reg.hl = 0xdead;
	mem.write(reg.hl, 0x69);
	// testing the opcode
	testOpcode(0x3A);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.hl = 0xdead - 1;
	expectedRegs.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x3E LD A, n
	// preparing cpu and memory state before executing the opcode
	reg.a = 0;
	mem.write(reg.pc + 1, 0x69);
	// testing the opcode
	testOpcode(0x3E);
	// expected change in registers and memory
	expectedRegs.pc += 2;
	expectedRegs.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x40 LD B, B
	// preparing cpu and memory state before executing the opcode
	reg.b = 0x69;
	// testing the opcode
	testOpcode(0x40);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.b = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x41 LD B, C
	// preparing cpu and memory state before executing the opcode
	reg.b = 0;
	reg.c = 0x69;
	// testing the opcode
	testOpcode(0x41);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.b = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x42 LD B, D
	// preparing cpu and memory state before executing the opcode
	reg.b = 0;
	reg.d = 0x69;
	// testing the opcode
	testOpcode(0x42);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.b = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x43 LD B, E
	// preparing cpu and memory state before executing the opcode
	reg.b = 0;
	reg.e = 0x69;
	// testing the opcode
	testOpcode(0x43);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.b = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x44 LD B, H
	// preparing cpu and memory state before executing the opcode
	reg.b = 0;
	reg.h = 0x69;
	// testing the opcode
	testOpcode(0x44);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.b = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x45 LD B, L
	// preparing cpu and memory state before executing the opcode
	reg.b = 0;
	reg.l = 0x69;
	// testing the opcode
	testOpcode(0x45);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.b = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x46 LD B, (HL)
	// preparing cpu and memory state before executing the opcode
	reg.hl = 0xbeef;
	reg.b = 0;
	mem.write(reg.hl, 0x69);
	// testing the opcode
	testOpcode(0x46);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.b = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x47 LD B, A
	// preparing cpu and memory state before executing the opcode
	reg.b = 0;
	reg.a = 0x69;
	// testing the opcode
	testOpcode(0x47);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.b = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x48 LD C, B
	// preparing cpu and memory state before executing the opcode
	reg.c = 0;
	reg.b = 0x69;
	// testing the opcode
	testOpcode(0x48);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.c = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x49 LD C, C
	// preparing cpu and memory state before executing the opcode
	reg.c = 0;
	reg.c = 0x69;
	// testing the opcode
	testOpcode(0x49);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.c = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x4A LD C, D
	// preparing cpu and memory state before executing the opcode
	reg.c = 0;
	reg.d = 0x69;
	// testing the opcode
	testOpcode(0x4A);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.c = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x4B LD C, E
	// preparing cpu and memory state before executing the opcode
	reg.c = 0;
	reg.e = 0x69;
	// testing the opcode
	testOpcode(0x4B);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.c = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x4C LD C, H
	// preparing cpu and memory state before executing the opcode
	reg.c = 0;
	reg.h = 0x69;
	// testing the opcode
	testOpcode(0x4C);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.c = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x4D LD C, L
	// preparing cpu and memory state before executing the opcode
	reg.c = 0;
	reg.l = 0x69;
	// testing the opcode
	testOpcode(0x4D);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.c = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x4E LD C, (HL)
	// preparing cpu and memory state before executing the opcode
	reg.hl = 0xbeef;
	reg.c = 0;
	mem.write(reg.hl, 0x69);
	// testing the opcode
	testOpcode(0x4E);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.c = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x4F LD C, A
	// preparing cpu and memory state before executing the opcode
	reg.c = 0;
	reg.a = 0x69;
	// testing the opcode
	testOpcode(0x4F);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.c = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x50 LD D, B
	// preparing cpu and memory state before executing the opcode
	reg.d = 0;
	reg.b = 0x69;
	// testing the opcode
	testOpcode(0x50);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.d = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x51 LD D, C
	// preparing cpu and memory state before executing the opcode
	reg.d = 0;
	reg.c = 0x69;
	// testing the opcode
	testOpcode(0x51);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.d = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x52 LD D, D
	// preparing cpu and memory state before executing the opcode
	reg.d = 0;
	reg.d = 0x69;
	// testing the opcode
	testOpcode(0x52);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.d = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x53 LD D, E
	// preparing cpu and memory state before executing the opcode
	reg.d = 0;
	reg.e = 0x69;
	// testing the opcode
	testOpcode(0x53);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.d = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x54 LD D, H
	// preparing cpu and memory state before executing the opcode
	reg.d = 0;
	reg.h = 0x69;
	// testing the opcode
	testOpcode(0x54);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.d = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x55 LD D, L
	// preparing cpu and memory state before executing the opcode
	reg.d = 0;
	reg.l = 0x69;
	// testing the opcode
	testOpcode(0x55);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.d = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x56 LD D, (HL)
	// preparing cpu and memory state before executing the opcode
	reg.hl = 0xbeef;
	reg.d = 0;
	mem.write(reg.hl, 0x69);
	// testing the opcode
	testOpcode(0x56);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.d = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x57 LD D, A
	// preparing cpu and memory state before executing the opcode
	reg.d = 0;
	reg.a = 0x69;
	// testing the opcode
	testOpcode(0x57);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.d = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x58 LD E, B
	// preparing cpu and memory state before executing the opcode
	reg.e = 0;
	reg.b = 0x69;
	// testing the opcode
	testOpcode(0x58);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.e = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x59 LD E, C
	// preparing cpu and memory state before executing the opcode
	reg.e = 0;
	reg.c = 0x69;
	// testing the opcode
	testOpcode(0x59);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.e = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x5A LD E, D
	// preparing cpu and memory state before executing the opcode
	reg.e = 0;
	reg.d = 0x69;
	// testing the opcode
	testOpcode(0x5A);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.e = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x5B LD E, E
	// preparing cpu and memory state before executing the opcode
	reg.e = 0;
	reg.e = 0x69;
	// testing the opcode
	testOpcode(0x5B);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.e = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x5C LD E, H
	// preparing cpu and memory state before executing the opcode
	reg.e = 0;
	reg.h = 0x69;
	// testing the opcode
	testOpcode(0x5C);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.e = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x5D LD E, L
	// preparing cpu and memory state before executing the opcode
	reg.e = 0;
	reg.l = 0x69;
	// testing the opcode
	testOpcode(0x5D);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.e = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x5E LD E, (HL)
	// preparing cpu and memory state before executing the opcode
	reg.hl = 0xbeef;
	reg.e = 0;
	mem.write(reg.hl, 0x69);
	// testing the opcode
	testOpcode(0x5E);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.e = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x5F LD E, A
	// preparing cpu and memory state before executing the opcode
	reg.e = 0;
	reg.a = 0x69;
	// testing the opcode
	testOpcode(0x5F);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.e = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x60 LD H, B
	// preparing cpu and memory state before executing the opcode
	reg.h = 0;
	reg.b = 0x69;
	// testing the opcode
	testOpcode(0x60);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.h = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x61 LD H, C
	// preparing cpu and memory state before executing the opcode
	reg.h = 0;
	reg.c = 0x69;
	// testing the opcode
	testOpcode(0x61);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.h = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x62 LD H, D
	// preparing cpu and memory state before executing the opcode
	reg.h = 0;
	reg.d = 0x69;
	// testing the opcode
	testOpcode(0x62);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.h = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x63 LD H, E
	// preparing cpu and memory state before executing the opcode
	reg.h = 0;
	reg.e = 0x69;
	// testing the opcode
	testOpcode(0x63);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.h = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x64 LD H, H
	// preparing cpu and memory state before executing the opcode
	reg.h = 0;
	reg.h = 0x69;
	// testing the opcode
	testOpcode(0x64);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.h = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x65 LD H, L
	// preparing cpu and memory state before executing the opcode
	reg.h = 0;
	reg.l = 0x69;
	// testing the opcode
	testOpcode(0x65);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.h = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x66 LD H, (HL)
	// preparing cpu and memory state before executing the opcode
	reg.hl = 0xbeef;
	reg.h = 0;
	mem.write(reg.hl, 0x69);
	// testing the opcode
	testOpcode(0x66);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.h = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x67 LD H, A
	// preparing cpu and memory state before executing the opcode
	reg.h = 0;
	reg.a = 0x69;
	// testing the opcode
	testOpcode(0x67);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.h = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x68 LD L, B
	// preparing cpu and memory state before executing the opcode
	reg.l = 0;
	reg.b = 0x69;
	// testing the opcode
	testOpcode(0x68);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.l = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x69 LD L, C
	// preparing cpu and memory state before executing the opcode
	reg.l = 0;
	reg.c = 0x69;
	// testing the opcode
	testOpcode(0x69);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.l = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x6A LD L, D
	// preparing cpu and memory state before executing the opcode
	reg.l = 0;
	reg.d = 0x69;
	// testing the opcode
	testOpcode(0x6A);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.l = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x6B LD L, E
	// preparing cpu and memory state before executing the opcode
	reg.l = 0;
	reg.e = 0x69;
	// testing the opcode
	testOpcode(0x6B);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.l = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x6C LD L, H
	// preparing cpu and memory state before executing the opcode
	reg.l = 0;
	reg.h = 0x69;
	// testing the opcode
	testOpcode(0x6C);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.l = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x6D LD L, L
	// preparing cpu and memory state before executing the opcode
	reg.l = 0;
	reg.l = 0x69;
	// testing the opcode
	testOpcode(0x6D);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.l = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x6E LD L, (HL)
	// preparing cpu and memory state before executing the opcode
	reg.hl = 0xbeef;
	reg.l = 0;
	mem.write(reg.hl, 0x69);
	// testing the opcode
	testOpcode(0x6E);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.l = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x6F LD L, A
	// preparing cpu and memory state before executing the opcode
	reg.l = 0;
	reg.a = 0x69;
	// testing the opcode
	testOpcode(0x6F);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.l = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x70 LD (HL), B
	// preparing cpu and memory state before executing the opcode
	reg.hl = 0xdead;
	reg.b = 0x69;
	mem.write(reg.hl, 0);
	// testing the opcode
	testOpcode(0x70);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedMem.write(0xdead, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x71 LD (HL), C
	// preparing cpu and memory state before executing the opcode
	reg.hl = 0xdead;
	reg.c = 0x69;
	mem.write(reg.hl, 0);
	// testing the opcode
	testOpcode(0x71);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedMem.write(0xdead, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x72 LD (HL), D
	// preparing cpu and memory state before executing the opcode
	reg.hl = 0xdead;
	reg.d = 0x69;
	mem.write(reg.hl, 0);
	// testing the opcode
	testOpcode(0x72);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedMem.write(0xdead, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x73 LD (HL), E
	// preparing cpu and memory state before executing the opcode
	reg.hl = 0xdead;
	reg.e = 0x69;
	mem.write(reg.hl, 0);
	// testing the opcode
	testOpcode(0x73);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedMem.write(0xdead, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x74 LD (HL), H
	// preparing cpu and memory state before executing the opcode
	reg.hl = 0xdead;
	mem.write(reg.hl, 0);
	// testing the opcode
	testOpcode(0x74);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedMem.write(0xdead, 0xde);
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x75 LD (HL), L
	// preparing cpu and memory state before executing the opcode
	reg.hl = 0xdead;
	mem.write(reg.hl, 0);
	// testing the opcode
	testOpcode(0x75);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedMem.write(0xdead, 0xad);
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x77 LD (HL), A
	// preparing cpu and memory state before executing the opcode
	reg.hl = 0xdead;
	reg.a = 0x69;
	mem.write(reg.hl, 0);
	// testing the opcode
	testOpcode(0x73);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedMem.write(0xdead, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x78 LD A, B
	// preparing cpu and memory state before executing the opcode
	reg.a = 0;
	reg.b = 0x69;
	// testing the opcode
	testOpcode(0x78);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x79 LD A, C
	// preparing cpu and memory state before executing the opcode
	reg.a = 0;
	reg.c = 0x69;
	// testing the opcode
	testOpcode(0x79);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x7A LD A, D
	// preparing cpu and memory state before executing the opcode
	reg.a = 0;
	reg.d = 0x69;
	// testing the opcode
	testOpcode(0x7A);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x7B LD A, E
	// preparing cpu and memory state before executing the opcode
	reg.a = 0;
	reg.e = 0x69;
	// testing the opcode
	testOpcode(0x7B);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x7C LD A, H
	// preparing cpu and memory state before executing the opcode
	reg.a = 0;
	reg.h = 0x69;
	// testing the opcode
	testOpcode(0x7C);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x7D LD A, L
	// preparing cpu and memory state before executing the opcode
	reg.a = 0;
	reg.l = 0x69;
	// testing the opcode
	testOpcode(0x7D);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x7E LD A, (HL)
	// preparing cpu and memory state before executing the opcode
	reg.hl = 0xbeef;
	reg.a = 0;
	mem.write(reg.hl, 0x69);
	// testing the opcode
	testOpcode(0x7E);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x7F LD A, A
	// preparing cpu and memory state before executing the opcode
	reg.a = 0;
	reg.a = 0x69;
	// testing the opcode
	testOpcode(0x7F);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0xE0 LDH (n), A
	// preparing cpu and memory state before executing the opcode
	reg.a = 0x69;
	mem.write(reg.pc + 1, 0x42);
	mem.write(0xFF42, 0);
	// testing the opcode
	testOpcode(0xE0);
	// expected change in registers and memory
	expectedRegs.pc += 2;
	expectedMem.write(0xFF42, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0xE2 LDH (C), A
	// preparing cpu and memory state before executing the opcode
	reg.a = 0x69;
	reg.c = 0x42;
	mem.write(0xFF42, 0);
	// testing the opcode
	testOpcode(0xE2);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedMem.write(0xFF42, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0xEA LD (nn), A
	// preparing cpu and memory state before executing the opcode
	reg.a = 0x69;
	mem.write(reg.pc + 1, 0xef);
	mem.write(reg.pc + 2, 0xbe);
	mem.write(0xbeef, 0);
	// testing the opcode
	testOpcode(0xEA);
	// expected change in registers and memory
	expectedRegs.pc += 3;
	expectedMem.write(0xbeef, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0xF0 LDH A, (n)
	// preparing cpu and memory state before executing the opcode
	reg.a = 0;
	mem.write(reg.pc + 1, 0x42);
	mem.write(0xFF42, 0x69);
	// testing the opcode
	testOpcode(0xF0);
	// expected change in registers and memory
	expectedRegs.pc += 2;
	expectedRegs.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0xF2 LDH A, (C)
	// preparing cpu and memory state before executing the opcode
	reg.a = 0;
	reg.c = 0x42;
	mem.write(0xFF42, 0x69);
	// testing the opcode
	testOpcode(0xF2);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0xFA LD A, (nn)
	// preparing cpu and memory state before executing the opcode
	reg.a = 0;
	mem.write(reg.pc + 1, 0xef);
	mem.write(reg.pc + 2, 0xbe);
	mem.write(0xbeef, 0x69);
	// testing the opcode
	testOpcode(0xFA);
	// expected change in registers and memory
	expectedRegs.pc += 3;
	expectedRegs.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

}

TEST_F(CPUTest, Opcode16bitLoadsTest)
{
	// 16-bit loads

	// 0x01 LD BC, nn
	// preparing cpu and memory state before executing the opcode
	reg.bc = 0;
	mem.writeWord(reg.pc + 1, 0xbeef);
	// testing the opcode
	testOpcode(0x01);
	// expected change in registers and memory
	expectedRegs.pc += 3;
	expectedRegs.bc = 0xbeef;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x08 LD (nn), SP
	// preparing cpu and memory state before executing the opcode
	reg.sp = 0x69;
	mem.writeWord(reg.pc + 1, 0xbeef);
	mem.write(0xbeef, 0);
	// testing the opcode
	testOpcode(0x08);
	// expected change in registers and memory
	expectedRegs.pc += 3;
	expectedMem.write(0xbeef, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x11 LD DE, nn
	// preparing cpu and memory state before executing the opcode
	reg.de = 0;
	mem.writeWord(reg.pc + 1, 0xbeef);
	// testing the opcode
	testOpcode(0x11);
	// expected change in registers and memory
	expectedRegs.pc += 3;
	expectedRegs.de = 0xbeef;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x21 LD HL, nn
	// preparing cpu and memory state before executing the opcode
	reg.hl = 0;
	mem.writeWord(reg.pc + 1, 0xbeef);
	// testing the opcode
	testOpcode(0x21);
	// expected change in registers and memory
	expectedRegs.pc += 3;
	expectedRegs.hl = 0xbeef;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0x31 LD SP, nn
	// preparing cpu and memory state before executing the opcode
	reg.sp = 0;
	mem.writeWord(reg.pc + 1, 0xbeef);
	// testing the opcode
	testOpcode(0x31);
	// expected change in registers and memory
	expectedRegs.pc += 3;
	expectedRegs.sp = 0xbeef;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0xC1 POP BC
	// preparing cpu and memory state before executing the opcode
	reg.bc = 0;
	reg.sp = 0xbeef;
	mem.writeWord(reg.sp, 0xdead);
	// testing the opcode
	testOpcode(0xC1);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.sp += 2;
	expectedRegs.bc = 0xdead;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0xD1 POP DE
	// preparing cpu and memory state before executing the opcode
	reg.de = 0;
	reg.sp = 0xbeef;
	mem.writeWord(reg.sp, 0xdead);
	// testing the opcode
	testOpcode(0xD1);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.sp += 2;
	expectedRegs.de = 0xdead;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0xE1 POP HL
	// preparing cpu and memory state before executing the opcode
	reg.hl = 0;
	reg.sp = 0xbeef;
	mem.writeWord(reg.sp, 0xdead);
	// testing the opcode
	testOpcode(0xE1);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.sp += 2;
	expectedRegs.hl = 0xdead;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0xF1 POP AF
	// preparing cpu and memory state before executing the opcode
	reg.af = 0;
	reg.sp = 0xbeef;
	mem.writeWord(reg.sp, 0xdead);
	// testing the opcode
	testOpcode(0xF1);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.sp += 2;
	expectedRegs.af = 0xdead;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0xC5 PUSH BC
	// preparing cpu and memory state before executing the opcode
	reg.bc = 0xdead;
	reg.sp = 0xbeef;
	mem.writeWord(reg.sp, 0x0000);
	// testing the opcode
	testOpcode(0xC5);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.sp -= 2;
	expectedMem.writeWord(0xbeef - 2, 0xdead);
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0xD5 PUSH DE
	// preparing cpu and memory state before executing the opcode
	reg.de = 0xdead;
	reg.sp = 0xbeef;
	mem.writeWord(reg.sp, 0x0000);
	// testing the opcode
	testOpcode(0xD5);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.sp -= 2;
	expectedMem.writeWord(0xbeef - 2, 0xdead);
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0xE5 PUSH HL
	// preparing cpu and memory state before executing the opcode
	reg.hl = 0xdead;
	reg.sp = 0xbeef;
	mem.writeWord(reg.sp, 0x0000);
	// testing the opcode
	testOpcode(0xE5);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.sp -= 2;
	expectedMem.writeWord(0xbeef - 2, 0xdead);
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0xF5 PUSH AF
	// preparing cpu and memory state before executing the opcode
	reg.af = 0xdead;
	reg.sp = 0xbeef;
	mem.writeWord(reg.sp, 0x0000);
	// testing the opcode
	testOpcode(0xF5);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.sp -= 2;
	expectedMem.writeWord(0xbeef - 2, 0xdead);
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0xF8 LD HL, SP+e
	// preparing cpu and memory state before executing the opcode
	reg.hl = 0;
	reg.sp = 0xdead;
	mem.write(reg.pc + 1, 1);
	// testing the opcode
	testOpcode(0xF8);
	// expected change in registers and memory
	expectedRegs.pc += 2;
	expectedRegs.hl = 0xdead + 1;
	expectedRegs.f &= 0b00001111;
	expectedRegs.f |= 0b00000000;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	reg.hl = 0;
	reg.sp = 0x8f;
	mem.write(reg.pc + 1, 1);
	// testing the opcode
	testOpcode(0xF8);
	// expected change in registers and memory
	expectedRegs.pc += 2;
	expectedRegs.hl = 0x8f + 1;
	expectedRegs.f &= 0b00001111;
	expectedRegs.f |= 0b00100000;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	reg.hl = 0;
	reg.sp = 0xff;
	mem.write(reg.pc + 1, 1);
	// testing the opcode
	testOpcode(0xF8);
	// expected change in registers and memory
	expectedRegs.pc += 2;
	expectedRegs.hl = 0xff + 1;
	expectedRegs.f &= 0b00001111;
	expectedRegs.f |= 0b00110000;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	reg.hl = 0;
	reg.sp = 0xff;
	mem.write(reg.pc + 1, -5);
	// testing the opcode
	testOpcode(0xF8);
	// expected change in registers and memory
	expectedRegs.pc += 2;
	expectedRegs.hl = 0xff - 5;
	expectedRegs.f &= 0b00001111;
	expectedRegs.f |= 0b00000000;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	reg.hl = 0;
	reg.sp = 2;
	mem.write(reg.pc + 1, -5);
	// testing the opcode
	testOpcode(0xF8);
	// expected change in registers and memory
	expectedRegs.pc += 2;
	expectedRegs.hl = 2 - 5;
	expectedRegs.f &= 0b00001111;
	expectedRegs.f |= 0b00110000;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	reg.hl = 0;
	reg.sp = 0xf0;
	mem.write(reg.pc + 1, -5);
	// testing the opcode
	testOpcode(0xF8);
	// expected change in registers and memory
	expectedRegs.pc += 2;
	expectedRegs.hl = 0xf0 - 5;
	expectedRegs.f &= 0b00001111;
	expectedRegs.f |= 0b00100000;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);

	// 0xF9 LD SP, HL
	// preparing cpu and memory state before executing the opcode
	reg.sp = 0;
	reg.hl = 0xdead;
	// testing the opcode
	testOpcode(0xF9);
	// expected change in registers and memory
	expectedRegs.pc += 1;
	expectedRegs.sp = 0xdead;
	// comparing expected change to real change
	EXPECT_TRUE(expectedRegs == reg);
	EXPECT_TRUE(expectedMem == mem);
}
#pragma clang diagnostic pop