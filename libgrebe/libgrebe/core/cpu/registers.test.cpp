#include <gtest/gtest.h>
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

TEST_F(RegistersTest, AFBugTest)
{
	registers.setA(1);
	registers.setZeroFlag();
	registers.resetSubtractFlag();
	registers.resetHalfCarryFlag();
	registers.resetCarryFlag();
	EXPECT_EQ(registers.getA(), 1);
}

TEST_F(RegistersTest, DecBugTest)
{
	registers.setAF(0);
	registers.decF();
	EXPECT_EQ(registers.getA(), 0);
	EXPECT_EQ(registers.getF(), 0xff);

	registers.setBC(0);
	registers.decC();
	EXPECT_EQ(registers.getB(), 0);
	EXPECT_EQ(registers.getC(), 0xff);

	registers.setDE(0);
	registers.decE();
	EXPECT_EQ(registers.getD(), 0);
	EXPECT_EQ(registers.getE(), 0xff);

	registers.setHL(0);
	registers.decL();
	EXPECT_EQ(registers.getH(), 0);
	EXPECT_EQ(registers.getL(), 0xff);
}

TEST_F(RegistersTest, IncBugTest)
{
	registers.setAF(0x00ff);
	registers.incF();
	EXPECT_EQ(registers.getA(), 0);
	EXPECT_EQ(registers.getF(), 0);

	registers.setBC(0x00ff);
	registers.incC();
	EXPECT_EQ(registers.getB(), 0);
	EXPECT_EQ(registers.getC(), 0);

	registers.setDE(0x00ff);
	registers.incE();
	EXPECT_EQ(registers.getD(), 0);
	EXPECT_EQ(registers.getE(), 0);

	registers.setHL(0x00ff);
	registers.incL();
	EXPECT_EQ(registers.getH(), 0);
	EXPECT_EQ(registers.getL(), 0);
}

TEST_F(RegistersTest, GetSetTest)
{
	registers.setA(1);
	registers.setF(2);
	registers.setB(3);
	registers.setC(4);
	registers.setD(5);
	registers.setE(6);
	registers.setH(7);
	registers.setL(8);
	registers.setSP(0xdead);
	registers.setPC(0xbeef);

	EXPECT_EQ(registers.getA(), 1);
	EXPECT_EQ(registers.getF(), 2);
	EXPECT_EQ(registers.getB(), 3);
	EXPECT_EQ(registers.getC(), 4);
	EXPECT_EQ(registers.getD(), 5);
	EXPECT_EQ(registers.getE(), 6);
	EXPECT_EQ(registers.getH(), 7);
	EXPECT_EQ(registers.getL(), 8);
	EXPECT_EQ(registers.getSP(), 0xdead);
	EXPECT_EQ(registers.getPC(), 0xbeef);

	registers.setA(0);
	registers.setF(0);
	registers.setB(0);
	registers.setC(0);
	registers.setD(0);
	registers.setE(0);
	registers.setH(0);
	registers.setL(0);
	registers.setSP(0);
	registers.setPC(0);

	EXPECT_EQ(registers.getA(), 0);
	EXPECT_EQ(registers.getF(), 0);
	EXPECT_EQ(registers.getB(), 0);
	EXPECT_EQ(registers.getC(), 0);
	EXPECT_EQ(registers.getD(), 0);
	EXPECT_EQ(registers.getE(), 0);
	EXPECT_EQ(registers.getH(), 0);
	EXPECT_EQ(registers.getL(), 0);
	EXPECT_EQ(registers.getSP(), 0);
	EXPECT_EQ(registers.getPC(), 0);

	registers.setA(0xff);
	registers.setF(0xff);
	registers.setB(0xff);
	registers.setC(0xff);
	registers.setD(0xff);
	registers.setE(0xff);
	registers.setH(0xff);
	registers.setL(0xff);
	registers.setSP(0xff);
	registers.setPC(0xff);

	EXPECT_EQ(registers.getA(), 0xff);
	EXPECT_EQ(registers.getF(), 0xff);
	EXPECT_EQ(registers.getB(), 0xff);
	EXPECT_EQ(registers.getC(), 0xff);
	EXPECT_EQ(registers.getD(), 0xff);
	EXPECT_EQ(registers.getE(), 0xff);
	EXPECT_EQ(registers.getH(), 0xff);
	EXPECT_EQ(registers.getL(), 0xff);
	EXPECT_EQ(registers.getSP(), 0xff);
	EXPECT_EQ(registers.getPC(), 0xff);
}

TEST_F(RegistersTest, OperatorsTest)
{
	// operator=
	Registers other;
	other.setA(1);
	other.setF(2);
	other.setB(3);
	other.setC(4);
	other.setD(5);
	other.setE(6);
	other.setH(7);
	other.setL(8);
	other.setSP(0xdead);
	other.setPC(0xbeef);
	ASSERT_NO_THROW(registers = other);
	EXPECT_EQ(registers.getA(), 1);
	EXPECT_EQ(registers.getF(), 2);
	EXPECT_EQ(registers.getB(), 3);
	EXPECT_EQ(registers.getC(), 4);
	EXPECT_EQ(registers.getD(), 5);
	EXPECT_EQ(registers.getE(), 6);
	EXPECT_EQ(registers.getH(), 7);
	EXPECT_EQ(registers.getL(), 8);
	EXPECT_EQ(registers.getSP(), 0xdead);
	EXPECT_EQ(registers.getPC(), 0xbeef);
}

TEST_F(RegistersTest, Registers8BitTest)
{
	registers.setA(0x00);
	registers.setA(registers.getA() - 1);
	EXPECT_EQ(registers.getA(), 0xff);
	registers.setA(0xff);
	registers.setA(registers.getA() + 1);
	EXPECT_EQ(registers.getA(), 0x00);
	registers.setF(0x00);
	registers.setF(registers.getF() - 1);
	EXPECT_EQ(registers.getF(), 0xff);
	registers.setF(0xff);
	registers.setF(registers.getF() + 1);
	EXPECT_EQ(registers.getF(), 0x00);
	registers.setB(0x00);
	registers.setB(registers.getB() - 1);
	EXPECT_EQ(registers.getB(), 0xff);
	registers.setB(0xff);
	registers.setB(registers.getB() + 1);
	EXPECT_EQ(registers.getB(), 0x00);
	registers.setC(0x00);
	registers.setC(registers.getC() - 1);
	EXPECT_EQ(registers.getC(), 0xff);
	registers.setC(0xff);
	registers.setC(registers.getC() + 1);
	EXPECT_EQ(registers.getC(), 0x00);
	registers.setD(0x00);
	registers.setD(registers.getD() - 1);
	EXPECT_EQ(registers.getD(), 0xff);
	registers.setD(0xff);
	registers.setD(registers.getD() + 1);
	EXPECT_EQ(registers.getD(), 0x00);
	registers.setE(0x00);
	registers.setE(registers.getE() - 1);
	EXPECT_EQ(registers.getE(), 0xff);
	registers.setE(0xff);
	registers.setE(registers.getE() + 1);
	EXPECT_EQ(registers.getE(), 0x00);
	registers.setH(0x00);
	registers.setH(registers.getH() - 1);
	EXPECT_EQ(registers.getH(), 0xff);
	registers.setH(0xff);
	registers.setH(registers.getH() + 1);
	EXPECT_EQ(registers.getH(), 0x00);
	registers.setL(0x00);
	registers.setL(registers.getL() - 1);
	EXPECT_EQ(registers.getL(), 0xff);
	registers.setL(0xff);
	registers.setL(registers.getL() + 1);
	EXPECT_EQ(registers.getL(), 0x00);
}

TEST_F(RegistersTest, Registers16BitTest)
{
	registers.setA(0xbe);
	registers.setF(0xef);
	EXPECT_EQ(registers.getAF(), 0xbeef);
	registers.setA(0x00);
	registers.setF(0xff);
	EXPECT_EQ(registers.getAF(), 0x00ff);
	registers.incAF();
	EXPECT_EQ(registers.getAF(), 0x0100);
	registers.setAF(0);
	registers.decAF();
	EXPECT_EQ(registers.getAF(), 0xffff);
	registers.setAF(0xffff);
	registers.incAF();
	EXPECT_EQ(registers.getAF(), 0x0);
	registers.setAF(0x00ff);
	registers.incAF();
	EXPECT_EQ(registers.getAF(), 0x0100);
	registers.setAF(0x0100);
	registers.decAF();
	EXPECT_EQ(registers.getAF(), 0x00ff);
	registers.setAF(0);
	registers.decAF();
	EXPECT_EQ(registers.getAF(), 0xffff);
	registers.setAF(0xffff);
	registers.incAF();
	EXPECT_EQ(registers.getAF(), 0x0);
	registers.setAF(0x0000);

	registers.setB(0xbe);
	registers.setC(0xef);
	EXPECT_EQ(registers.getBC(), 0xbeef);
	registers.setB(0x00);
	registers.setC(0xff);
	EXPECT_EQ(registers.getBC(), 0x00ff);
	registers.incBC();
	EXPECT_EQ(registers.getBC(), 0x0100);
	registers.setBC(0);
	registers.decBC();
	EXPECT_EQ(registers.getBC(), 0xffff);
	registers.setBC(0xffff);
	registers.incBC();
	EXPECT_EQ(registers.getBC(), 0x0);
	registers.setBC(0x00ff);
	registers.incBC();
	EXPECT_EQ(registers.getBC(), 0x0100);
	registers.setBC(0x0100);
	registers.decBC();
	EXPECT_EQ(registers.getBC(), 0x00ff);
	registers.setBC(0);
	registers.decBC();
	EXPECT_EQ(registers.getBC(), 0xffff);
	registers.setBC(0xffff);
	registers.incBC();
	EXPECT_EQ(registers.getBC(), 0x0);
	registers.setBC(0x0000);

	registers.setD(0xbe);
	registers.setE(0xef);
	EXPECT_EQ(registers.getDE(), 0xbeef);
	registers.setD(0x00);
	registers.setE(0xff);
	EXPECT_EQ(registers.getDE(), 0x00ff);
	registers.incDE();
	EXPECT_EQ(registers.getDE(), 0x0100);
	registers.setDE(0);
	registers.decDE();
	EXPECT_EQ(registers.getDE(), 0xffff);
	registers.setDE(0xffff);
	registers.incDE();
	EXPECT_EQ(registers.getDE(), 0x0);
	registers.setDE(0x00ff);
	registers.incDE();
	EXPECT_EQ(registers.getDE(), 0x0100);
	registers.setDE(0x0100);
	registers.decDE();
	EXPECT_EQ(registers.getDE(), 0x00ff);
	registers.setDE(0);
	registers.decDE();
	EXPECT_EQ(registers.getDE(), 0xffff);
	registers.setDE(0xffff);
	registers.incDE();
	EXPECT_EQ(registers.getDE(), 0x0);
	registers.setDE(0x0000);

	registers.setH(0xbe);
	registers.setL(0xef);
	EXPECT_EQ(registers.getHL(), 0xbeef);
	registers.setH(0x00);
	registers.setL(0xff);
	EXPECT_EQ(registers.getHL(), 0x00ff);
	registers.incHL();
	EXPECT_EQ(registers.getHL(), 0x0100);
	registers.setHL(0);
	registers.decHL();
	EXPECT_EQ(registers.getHL(), 0xffff);
	registers.setHL(0xffff);
	registers.incHL();
	EXPECT_EQ(registers.getHL(), 0x0);
	registers.setHL(0x00ff);
	registers.incHL();
	EXPECT_EQ(registers.getHL(), 0x0100);
	registers.setHL(0x0100);
	registers.decHL();
	EXPECT_EQ(registers.getHL(), 0x00ff);
	registers.setHL(0);
	registers.decHL();
	EXPECT_EQ(registers.getHL(), 0xffff);
	registers.setHL(0xffff);
	registers.incHL();
	EXPECT_EQ(registers.getHL(), 0x0);
	registers.setHL(0x0000);

	registers.setSP(0x00ff);
	registers.incSP();
	EXPECT_EQ(registers.getSP(), 0x0100);
	registers.setSP(0x0100);
	registers.decSP();
	EXPECT_EQ(registers.getSP(), 0x00ff);
	registers.setSP(0);
	registers.decSP();
	EXPECT_EQ(registers.getSP(), 0xffff);
	registers.setSP(0xffff);
	registers.incSP();
	EXPECT_EQ(registers.getSP(), 0x0);
	registers.setSP(0x0000);

	registers.setPC(0x00ff);
	registers.incPC();
	EXPECT_EQ(registers.getPC(), 0x0100);
	registers.setPC(0x0100);
	registers.decPC();
	EXPECT_EQ(registers.getPC(), 0x00ff);
	registers.setPC(0);
	registers.decPC();
	EXPECT_EQ(registers.getPC(), 0xffff);
	registers.setPC(0xffff);
	registers.incPC();
	EXPECT_EQ(registers.getPC(), 0x0);
	registers.setPC(0x0000);
}
