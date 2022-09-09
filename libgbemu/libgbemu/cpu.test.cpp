#include <gtest/gtest.h>
#define private public
#include <libgbemu/cpu.hpp>

void copyRegisters(Registers& dst, const Registers& src)
{
	dst.a = src.a;
	dst.f = src.f;
	dst.b = src.b;
	dst.c = src.c;
	dst.d = src.d;
	dst.e = src.e;
	dst.h = src.h;
	dst.l = src.l;
	dst.sp = src.sp;
	dst.pc = src.pc;
}

bool compare(const Registers& a, const Registers& b)
{
	if (a.a != b.a) return false;
	if (a.f != b.f) return false;
	if (a.b != b.b) return false;
	if (a.c != b.c) return false;
	if (a.d != b.d) return false;
	if (a.e != b.e) return false;
	if (a.h != b.h) return false;
	if (a.l != b.l) return false;
	if (a.sp != b.sp) return false;
	if (a.pc != b.pc) return false;
	return true;
}

class CPUTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
	}
	void TearDown() override
	{
	}
};

TEST_F(CPUTest, CPUCreationTest)
{
	CPU cpu;
	EXPECT_EQ(cpu.registers.pc, 0x100);
	EXPECT_EQ(cpu.registers.sp, 0xfffe);
}

TEST_F(CPUTest, MiscTest)
{
	CPU cpu;
	Memory mem;
	Registers r;

	// 0x00 NOP
	// saving cpu state before executing the opcode
	copyRegisters(r, cpu.registers);
	// preparing memory
	mem.write(cpu.registers.pc, 0x00);
	// executing the opcode
	cpu.execute(mem);
	// expected change in registers
	r.pc += 1;
	EXPECT_TRUE(compare(r, cpu.registers));

	// 0x10 STOP
	// 0xF3 DI
	// 0x76 HALT
	// 0xFB EI
}

TEST_F(CPUTest, LD8Test)
{
	CPU cpu;
	Memory mem;
	Registers r;

	// 0x02 LD (BC), A
	// 0x06 LD B, n
	// 0x0A LD A, (BC)
	// 0x0E LD C, n
	// 0x12 LD (DE), A
	// 0x16 LD D, n
	// 0x1A LD A, (DE)
	// 0x1E LD E, n
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
	copyRegisters(r, cpu.registers);
	// preparing memory
	mem.write(cpu.registers.pc, 0x40);
	// executing the opcode
	cpu.execute(mem);
	// expected change in registers
	r.pc += 1;
	EXPECT_TRUE(compare(r, cpu.registers));

	// 0x41 LD B, C
	// preparing cpu state before executing the opcode
	cpu.registers.b = 0x00;
	cpu.registers.c = 0x69;
	// saving cpu state before executing the opcode
	copyRegisters(r, cpu.registers);
	// preparing memory
	mem.write(cpu.registers.pc, 0x41);
	// executing the opcode
	cpu.execute(mem);
	// expected change in registers
	r.pc += 1;
	r.c = 0x69;
	r.b = 0x69;
	// comparing expected change to real change
	EXPECT_TRUE(compare(r, cpu.registers));

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