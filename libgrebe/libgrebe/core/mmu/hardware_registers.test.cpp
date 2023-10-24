#include <gtest/gtest.h>
#include <libgrebe/core/mmu/hardware_registers.hpp>
#include <libgrebe/core/mmu/mmu.test.hpp>
#include <memory>

TEST_F(MMUTest, HardwareRegistersAddressableTest)
{
	HardwareRegisters hardwareRegisters;
	EXPECT_TRUE(hardwareRegisters.contains(0xFF00));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF01));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF02));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF04));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF05));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF06));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF07));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF0F));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF10));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF11));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF12));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF13));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF14));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF16));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF17));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF18));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF19));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF1A));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF1B));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF1C));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF1D));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF1E));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF20));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF21));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF22));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF23));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF24));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF25));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF26));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF40));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF41));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF42));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF43));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF44));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF45));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF46));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF47));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF48));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF49));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF4A));
	EXPECT_TRUE(hardwareRegisters.contains(0xFF4B));
	EXPECT_TRUE(hardwareRegisters.contains(0xFFFF));
}

TEST_F(MMUTest, HardwareRegistersTestReadWrite)
{
	// test for normal read/write registers
	HardwareRegisters hardwareRegisters;
	testReadWrite(hardwareRegisters, LIBGREBE_REG_SB);
	testReadWrite(hardwareRegisters, LIBGREBE_REG_SC);
	testReadWrite(hardwareRegisters, LIBGREBE_REG_TAC);
	testReadWrite(hardwareRegisters, LIBGREBE_REG_TMA);
	testReadWrite(hardwareRegisters, LIBGREBE_REG_TIMA);
	testReadWrite(hardwareRegisters, LIBGREBE_REG_LCDC);
	testReadWrite(hardwareRegisters, LIBGREBE_REG_SCY);
	testReadWrite(hardwareRegisters, LIBGREBE_REG_SCX);
	testReadWrite(hardwareRegisters, LIBGREBE_REG_LYC);
	testReadWrite(hardwareRegisters, LIBGREBE_REG_BGP);
	testReadWrite(hardwareRegisters, LIBGREBE_REG_OBP0);
	testReadWrite(hardwareRegisters, LIBGREBE_REG_OBP1);
	testReadWrite(hardwareRegisters, LIBGREBE_REG_WY);
	testReadWrite(hardwareRegisters, LIBGREBE_REG_WX);
}

TEST_F(MMUTest, HardwareRegistersTestReadOnly)
{
	// test for read only registers
	HardwareRegisters hardwareRegisters;
	testReadOnly(hardwareRegisters, LIBGREBE_REG_LY);
}

TEST_F(MMUTest, P1Test)
{
	// bits 0-3 are readonly
	HardwareRegisters hardwareRegisters;
	Byte p1 = hardwareRegisters.read(LIBGREBE_REG_P1);
	hardwareRegisters.write(LIBGREBE_REG_P1, ~p1);
	EXPECT_EQ(hardwareRegisters.read(LIBGREBE_REG_P1), (~p1 & 0xf0) | (p1 & 0x0f));
}

TEST_F(MMUTest, DIVTest)
{
	// read write, but writes zero the register (DIV_WIDE actually)
	HardwareRegisters hardwareRegisters;
	hardwareRegisters.write(LIBGREBE_REG_DIV, 1);
	EXPECT_EQ(hardwareRegisters.read(LIBGREBE_REG_DIV), 0);
	hardwareRegisters.write(LIBGREBE_REG_DIV, 0);
	EXPECT_EQ(hardwareRegisters.read(LIBGREBE_REG_DIV), 0);
	hardwareRegisters.write(LIBGREBE_REG_DIV, 96);
	EXPECT_EQ(hardwareRegisters.read(LIBGREBE_REG_DIV), 0);
}

TEST_F(MMUTest, STATTest)
{
	// bits 0-1 are readonly
	// bits 0-3 are readonly
	HardwareRegisters hardwareRegisters;
	Byte stat = hardwareRegisters.read(LIBGREBE_REG_STAT);
	hardwareRegisters.write(LIBGREBE_REG_STAT, ~stat);
	EXPECT_EQ(hardwareRegisters.read(LIBGREBE_REG_STAT), (~stat & 0b11111100) | (stat & 0x3));
}
