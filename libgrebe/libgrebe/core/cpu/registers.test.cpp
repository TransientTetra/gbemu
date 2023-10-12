#include <gtest/gtest.h>
#define private public
#include <libgrebe/core/cpu/registers.hpp>

class RegistersTest : public ::testing::Test
{
protected:
	Registers registers;
	void SetUp() override
	{
	}
	void TearDown() override
	{
	}
};

TEST_F(RegistersTest, OperatorsTest)
{
	// operator=
	Registers other;
	other.a = 1;
	other.f = 2;
	other.b = 3;
	other.c = 4;
	other.d = 5;
	other.e = 6;
	other.h = 7;
	other.l = 8;
	other.sp = 0xdead;
	other.pc = 0xbeef;
	ASSERT_NO_THROW(registers = other);
	EXPECT_EQ(registers.a, 1);
	EXPECT_EQ(registers.f, 2);
	EXPECT_EQ(registers.b, 3);
	EXPECT_EQ(registers.c, 4);
	EXPECT_EQ(registers.d, 5);
	EXPECT_EQ(registers.e, 6);
	EXPECT_EQ(registers.h, 7);
	EXPECT_EQ(registers.l, 8);
	EXPECT_EQ(registers.sp, 0xdead);
	EXPECT_EQ(registers.pc, 0xbeef);

	// operator==
	EXPECT_TRUE(registers == other);
	EXPECT_TRUE(other == registers);
	registers.a += 1;
	EXPECT_FALSE(registers == other);
	EXPECT_FALSE(other == registers);
}

TEST_F(RegistersTest, Registers8BitTest)
{
	registers.a = 0x00;
	registers.a -= 1;
	EXPECT_EQ(registers.a, 0xff);
	registers.a = 0xff;
	registers.a += 1;
	EXPECT_EQ(registers.a, 0x00);
	registers.f = 0x00;
	registers.f -= 1;
	EXPECT_EQ(registers.f, 0xff);
	registers.f = 0xff;
	registers.f += 1;
	EXPECT_EQ(registers.f, 0x00);
	registers.b = 0x00;
	registers.b -= 1;
	EXPECT_EQ(registers.b, 0xff);
	registers.b = 0xff;
	registers.b += 1;
	EXPECT_EQ(registers.b, 0x00);
	registers.c = 0x00;
	registers.c -= 1;
	EXPECT_EQ(registers.c, 0xff);
	registers.c = 0xff;
	registers.c += 1;
	EXPECT_EQ(registers.c, 0x00);
	registers.d = 0x00;
	registers.d -= 1;
	EXPECT_EQ(registers.d, 0xff);
	registers.d = 0xff;
	registers.d += 1;
	EXPECT_EQ(registers.d, 0x00);
	registers.e = 0x00;
	registers.e -= 1;
	EXPECT_EQ(registers.e, 0xff);
	registers.e = 0xff;
	registers.e += 1;
	EXPECT_EQ(registers.e, 0x00);
	registers.h = 0x00;
	registers.h -= 1;
	EXPECT_EQ(registers.h, 0xff);
	registers.h = 0xff;
	registers.h += 1;
	EXPECT_EQ(registers.h, 0x00);
	registers.l = 0x00;
	registers.l -= 1;
	EXPECT_EQ(registers.l, 0xff);
	registers.l = 0xff;
	registers.l += 1;
	EXPECT_EQ(registers.l, 0x00);
}

TEST_F(RegistersTest, Registers16BitTest)
{
	registers.a = 0xbe;
	registers.f = 0xef;
	EXPECT_EQ(registers.af, 0xbeef);
	registers.a = 0x00;
	registers.f = 0xff;
	EXPECT_EQ(registers.af, 0x00ff);
	registers.af += 1;
	EXPECT_EQ(registers.af, 0x0100);
	registers.af = 0;
	registers.af -= 1;
	EXPECT_EQ(registers.af, 0xffff);
	registers.af = 0xffff;
	registers.af += 1;
	EXPECT_EQ(registers.af, 0x0);
	registers.af = 0x00ff;
	registers.af += 1;
	EXPECT_EQ(registers.af, 0x0100);
	registers.af = 0x0100;
	registers.af -= 1;
	EXPECT_EQ(registers.af, 0x00ff);
	registers.af = 0;
	registers.af -= 1;
	EXPECT_EQ(registers.af, 0xffff);
	registers.af = 0xffff;
	registers.af += 1;
	EXPECT_EQ(registers.af, 0x0);
	registers.af = 0x0000;
	for (int i = 0; i <= 0xffff; ++i)
	{
		reinterpret_cast<Word&>(registers.bytes[0]) = i;
		EXPECT_EQ(registers.af, i);
	}

	registers.b = 0xbe;
	registers.c = 0xef;
	EXPECT_EQ(registers.bc, 0xbeef);
	registers.b = 0x00;
	registers.c = 0xff;
	EXPECT_EQ(registers.bc, 0x00ff);
	registers.bc += 1;
	EXPECT_EQ(registers.bc, 0x0100);
	registers.bc = 0;
	registers.bc -= 1;
	EXPECT_EQ(registers.bc, 0xffff);
	registers.bc = 0xffff;
	registers.bc += 1;
	EXPECT_EQ(registers.bc, 0x0);
	registers.bc = 0x00ff;
	registers.bc += 1;
	EXPECT_EQ(registers.bc, 0x0100);
	registers.bc = 0x0100;
	registers.bc -= 1;
	EXPECT_EQ(registers.bc, 0x00ff);
	registers.bc = 0;
	registers.bc -= 1;
	EXPECT_EQ(registers.bc, 0xffff);
	registers.bc = 0xffff;
	registers.bc += 1;
	EXPECT_EQ(registers.bc, 0x0);
	registers.bc = 0x0000;
	for (int i = 0; i <= 0xffff; ++i)
	{
		reinterpret_cast<Word&>(registers.bytes[2]) = i;
		EXPECT_EQ(registers.bc, i);
	}

	registers.d = 0xbe;
	registers.e = 0xef;
	EXPECT_EQ(registers.de, 0xbeef);
	registers.d = 0x00;
	registers.e = 0xff;
	EXPECT_EQ(registers.de, 0x00ff);
	registers.de += 1;
	EXPECT_EQ(registers.de, 0x0100);
	registers.de = 0;
	registers.de -= 1;
	EXPECT_EQ(registers.de, 0xffff);
	registers.de = 0xffff;
	registers.de += 1;
	EXPECT_EQ(registers.de, 0x0);
	registers.de = 0x00ff;
	registers.de += 1;
	EXPECT_EQ(registers.de, 0x0100);
	registers.de = 0x0100;
	registers.de -= 1;
	EXPECT_EQ(registers.de, 0x00ff);
	registers.de = 0;
	registers.de -= 1;
	EXPECT_EQ(registers.de, 0xffff);
	registers.de = 0xffff;
	registers.de += 1;
	EXPECT_EQ(registers.de, 0x0);
	registers.de = 0x0000;
	for (int i = 0; i <= 0xffff; ++i)
	{
		reinterpret_cast<Word&>(registers.bytes[4]) = i;
		EXPECT_EQ(registers.de, i);
	}

	registers.h = 0xbe;
	registers.l = 0xef;
	EXPECT_EQ(registers.hl, 0xbeef);
	registers.h = 0x00;
	registers.l = 0xff;
	EXPECT_EQ(registers.hl, 0x00ff);
	registers.hl += 1;
	EXPECT_EQ(registers.hl, 0x0100);
	registers.hl = 0;
	registers.hl -= 1;
	EXPECT_EQ(registers.hl, 0xffff);
	registers.hl = 0xffff;
	registers.hl += 1;
	EXPECT_EQ(registers.hl, 0x0);
	registers.hl = 0x00ff;
	registers.hl += 1;
	EXPECT_EQ(registers.hl, 0x0100);
	registers.hl = 0x0100;
	registers.hl -= 1;
	EXPECT_EQ(registers.hl, 0x00ff);
	registers.hl = 0;
	registers.hl -= 1;
	EXPECT_EQ(registers.hl, 0xffff);
	registers.hl = 0xffff;
	registers.hl += 1;
	EXPECT_EQ(registers.hl, 0x0);
	registers.hl = 0x0000;
	for (int i = 0; i <= 0xffff; ++i)
	{
		reinterpret_cast<Word&>(registers.bytes[6]) = i;
		EXPECT_EQ(registers.hl, i);
	}

	registers.sp = 0x00ff;
	registers.sp += 1;
	EXPECT_EQ(registers.sp, 0x0100);
	registers.sp = 0x0100;
	registers.sp -= 1;
	EXPECT_EQ(registers.sp, 0x00ff);
	registers.sp = 0;
	registers.sp -= 1;
	EXPECT_EQ(registers.sp, 0xffff);
	registers.sp = 0xffff;
	registers.sp += 1;
	EXPECT_EQ(registers.sp, 0x0);
	registers.sp = 0x0000;
	for (int i = 0; i <= 0xffff; ++i)
	{
		reinterpret_cast<Word&>(registers.bytes[8]) = i;
		EXPECT_EQ(registers.sp, i);
	}

	registers.pc = 0x00ff;
	registers.pc += 1;
	EXPECT_EQ(registers.pc, 0x0100);
	registers.pc = 0x0100;
	registers.pc -= 1;
	EXPECT_EQ(registers.pc, 0x00ff);
	registers.pc = 0;
	registers.pc -= 1;
	EXPECT_EQ(registers.pc, 0xffff);
	registers.pc = 0xffff;
	registers.pc += 1;
	EXPECT_EQ(registers.pc, 0x0);
	registers.pc = 0x0000;
	for (int i = 0; i <= 0xffff; ++i)
	{
		reinterpret_cast<Word&>(registers.bytes[10]) = i;
		EXPECT_EQ(registers.pc, i);
	}
}
