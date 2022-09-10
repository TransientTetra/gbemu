#include <gtest/gtest.h>
#define private public
#include <libgbemu/cpu.hpp>

class CPUTest : public ::testing::Test
{
protected:
	CPU cpu;
	Memory mem, testMem;
	Registers reg, testRegs;
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
		testRegs = reg;
		testMem = mem;
		// executing the opcode
		cpu.execute(reg, mem);
	}
};

TEST_F(CPUTest, CreationTest)
{
}

TEST_F(CPUTest, Registers16bitTest)
{
	reg.af = 0xbe6f;
	EXPECT_EQ(reg.a, 0xbe);
	EXPECT_EQ(reg.f, 0x6f);
	reg.bc = 0xbe6f;
	EXPECT_EQ(reg.b, 0xbe);
	EXPECT_EQ(reg.c, 0x6f);
	reg.de = 0xbe6f;
	EXPECT_EQ(reg.d, 0xbe);
	EXPECT_EQ(reg.e, 0x6f);
	reg.hl = 0xbe6f;
	EXPECT_EQ(reg.h, 0xbe);
	EXPECT_EQ(reg.l, 0x6f);

	for (Word i = 0; i < 0xffff; ++i)
	{
		ASSERT_NO_THROW(reg.af = i);
		EXPECT_EQ(reg.af, i);
	}
	for (Word i = 0; i < 0xffff; ++i)
	{
		ASSERT_NO_THROW(reg.bc = i);
		EXPECT_EQ(reg.bc, i);
	}
	for (Word i = 0; i < 0xffff; ++i)
	{
		ASSERT_NO_THROW(reg.de = i);
		EXPECT_EQ(reg.de, i);
	}
	for (Word i = 0; i < 0xffff; ++i)
	{
		ASSERT_NO_THROW(reg.hl = i);
		EXPECT_EQ(reg.hl, i);
	}
}

TEST_F(CPUTest, OpcodeMiscTest)
{
	// 0x00 NOP
	// executing the opcode
	testOpcode(0x00);
	// expected change in registers
	testRegs.pc += 1;
	EXPECT_TRUE(testRegs == reg);

	// 0x10 STOP
	// 0xF3 DI
	// 0x76 HALT
	// 0xFB EI
}

TEST_F(CPUTest, OpcodeLD8Test)
{
	// 0x02 LD (BC), A
	// preparing cpu and memory state before executing the opcode
	reg.bc = (0xbeef);
	reg.a = 0x69;
	mem.write(reg.bc, 0x0);
	// testing the opcode
	testOpcode(0x02);
	// expected change in registers and memory
	testRegs.pc += 1;
	testMem.write(reg.bc, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(testRegs == reg);
	EXPECT_TRUE(testMem == mem);

	// 0x06 LD B, n
	// preparing cpu and memory state before executing the opcode
	reg.b = 0;
	mem.write(reg.pc + 1, 0x69);
	// testing the opcode
	testOpcode(0x06);
	// expected change in registers and memory
	testRegs.pc += 2;
	testRegs.b = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(testRegs == reg);
	EXPECT_TRUE(testMem == mem);

	// 0x0A LD A, (BC)
	// preparing cpu and memory state before executing the opcode
	reg.bc = (0xbeef);
	reg.a = 0;
	mem.write(reg.bc, 0x69);
	// testing the opcode
	testOpcode(0x0A);
	// expected change in registers and memory
	testRegs.pc += 1;
	testRegs.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(testRegs == reg);
	EXPECT_TRUE(testMem == mem);

	// 0x0E LD C, n
	// preparing cpu and memory state before executing the opcode
	reg.c = 0;
	mem.write(reg.pc + 1, 0x69);
	// testing the opcode
	testOpcode(0x0E);
	// expected change in registers and memory
	testRegs.pc += 2;
	testRegs.c = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(testRegs == reg);
	EXPECT_TRUE(testMem == mem);

	// 0x12 LD (DE), A
	// preparing cpu and memory state before executing the opcode
	reg.de = (0xbeef);
	reg.a = 0x69;
	mem.write(reg.de, 0);
	// testing the opcode
	testOpcode(0x12);
	// expected change in registers and memory
	testRegs.pc += 1;
	testMem.write(reg.de, 0x69);
	// comparing expected change to real change
	EXPECT_TRUE(testRegs == reg);
	EXPECT_TRUE(testMem == mem);

	// 0x16 LD D, n
	// preparing cpu and memory state before executing the opcode
	reg.d = 0;
	mem.write(reg.pc + 1, 0x69);
	// testing the opcode
	testOpcode(0x16);
	// expected change in registers and memory
	testRegs.pc += 2;
	testRegs.d = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(testRegs == reg);
	EXPECT_TRUE(testMem == mem);

	// 0x1A LD A, (DE)
	// preparing cpu and memory state before executing the opcode
	reg.de = (0xbeef);
	reg.a = 0;
	mem.write(reg.de, 0x69);
	// testing the opcode
	testOpcode(0x1A);
	// expected change in registers and memory
	testRegs.pc += 1;
	testRegs.a = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(testRegs == reg);
	EXPECT_TRUE(testMem == mem);

	// 0x1E LD E, n
	// preparing cpu and memory state before executing the opcode
	reg.e = 0;
	mem.write(reg.pc + 1, 0x69);
	// testing the opcode
	testOpcode(0x1E);
	// expected change in registers and memory
	testRegs.pc += 2;
	testRegs.e = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(testRegs == reg);
	EXPECT_TRUE(testMem == mem);

	// 0x22 LD (HL+), A
	// 0x26 LD H, n
	// 0x2A LD A, (HL+)
	// 0x2E LD L, n
	// 0x32 LD (HL-), A
	// 0x36 LD (HL), n
	// 0x3A LD A, (HL-)
	// 0x3E LD A, n

	// 0x40 LD B, B
	// saving cpu state before executing the opcode
	testRegs = reg;
	// preparing memory
	mem.write(reg.pc, 0x40);
	// executing the opcode
	cpu.execute(reg, mem);
	// expected change in registers
	testRegs.pc += 1;
	EXPECT_TRUE(testRegs == reg);

	// 0x41 LD B, C
	// preparing cpu state before executing the opcode
	reg.b = 0x00;
	reg.c = 0x69;
	// saving cpu state before executing the opcode
	testRegs = reg;
	// preparing memory
	mem.write(reg.pc, 0x41);
	// executing the opcode
	cpu.execute(reg, mem);
	// expected change in registers
	testRegs.pc += 1;
	testRegs.c = 0x69;
	testRegs.b = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(testRegs == reg);

	// 0x42 LD B, D
	// 0x43 LD B, E
	// 0x44 LD B, H
	// 0x45 LD B, L
	// 0x46 LD B, (HL)
	// 0x47 LD B, A
	// 0x48 LD C, B
	// 0x49 LD C, C
	// 0x4A LD C, D
	// 0x4B LD C, E
	// 0x4C LD C, H
	// 0x4D LD C, L
	// 0x4E LD C, (HL)
	// 0x4F LD C, A
	// 0x50 LD D, B
	// 0x51 LD D, C
	// 0x52 LD D, D
	// 0x53 LD D, E
	// 0x54 LD D, H
	// 0x55 LD D, L
	// 0x56 LD D, (HL)
	// 0x57 LD D, A
	// 0x58 LD E, B
	// 0x59 LD E, C
	// 0x5A LD E, D
	// 0x5B LD E, E
	// 0x5C LD E, H
	// 0x5D LD E, L
	// 0x5E LD E, (HL)
	// 0x5F LD E, A
	// 0x60 LD H, B
	// 0x61 LD H, C
	// 0x62 LD H, D
	// 0x63 LD H, E
	// 0x64 LD H, H
	// 0x65 LD H, L
	// 0x66 LD H, (HL)
	// 0x67 LD H, A
	// 0x68 LD L, B
	// 0x69 LD L, C
	// 0x6A LD L, D
	// 0x6B LD L, E
	// 0x6C LD L, H
	// 0x6D LD L, L
	// 0x6E LD L, (HL)
	// 0x6F LD L, A
	// 0x70 LD (HL), B
	// 0x71 LD (HL), C
	// 0x72 LD (HL), D
	// 0x73 LD (HL), E
	// 0x74 LD (HL), H
	// 0x75 LD (HL), L
	// 0x77 LD (HL), A
	// 0x78 LD A, B
	// 0x79 LD A, C
	// 0x7A LD A, D
	// 0x7B LD A, E
	// 0x7C LD A, H
	// 0x7D LD A, L
	// 0x7E LD A, (HL)
	// 0x7F LD A, A
	// 0xE0 LDH (n), A
	// 0xE2 LDH (C), A
	// 0xEA LD (nn), A
	// 0xF0 LDH A, (n)
	// 0xF2 LDH A, (C)
	// 0xFA LD A, (nn)
}