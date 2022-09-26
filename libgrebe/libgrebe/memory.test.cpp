#include <gtest/gtest.h>
#include <libgrebe/memory.hpp>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconstant-conversion"
class MemoryTest : public ::testing::Test
{
protected:
	Memory mem{};
	void SetUp() override
	{
	}
	void TearDown() override
	{
	}
};

TEST_F(MemoryTest, CreationTest)
{
	// https://gbdev.io/pandocs/Power_Up_Sequence.html#hardware-registers
	EXPECT_EQ(mem.read(LIBGREBE_REG_P1), 0xCF);
	EXPECT_EQ(mem.read(LIBGREBE_REG_SB), 0x00);
	EXPECT_EQ(mem.read(LIBGREBE_REG_SC), 0x7E);
	EXPECT_EQ(mem.read(LIBGREBE_REG_DIV), 0xAB);
	EXPECT_EQ(mem.read(LIBGREBE_REG_TIMA), 0x00);
	EXPECT_EQ(mem.read(LIBGREBE_REG_TMA), 0x00);
	EXPECT_EQ(mem.read(LIBGREBE_REG_TAC), 0xF8);
	EXPECT_EQ(mem.read(LIBGREBE_REG_IF), 0xE1);
	EXPECT_EQ(mem.read(LIBGREBE_REG_NR10), 0x80);
	EXPECT_EQ(mem.read(LIBGREBE_REG_NR11), 0xBF);
	EXPECT_EQ(mem.read(LIBGREBE_REG_NR12), 0xF3);
	EXPECT_EQ(mem.read(LIBGREBE_REG_NR13), 0xFF);
	EXPECT_EQ(mem.read(LIBGREBE_REG_NR14), 0xBF);
	EXPECT_EQ(mem.read(LIBGREBE_REG_NR21), 0x3F);
	EXPECT_EQ(mem.read(LIBGREBE_REG_NR22), 0x00);
	EXPECT_EQ(mem.read(LIBGREBE_REG_NR23), 0xFF);
	EXPECT_EQ(mem.read(LIBGREBE_REG_NR24), 0xBF);
	EXPECT_EQ(mem.read(LIBGREBE_REG_NR30), 0x7F);
	EXPECT_EQ(mem.read(LIBGREBE_REG_NR31), 0xFF);
	EXPECT_EQ(mem.read(LIBGREBE_REG_NR32), 0x9F);
	EXPECT_EQ(mem.read(LIBGREBE_REG_NR33), 0xFF);
	EXPECT_EQ(mem.read(LIBGREBE_REG_NR34), 0xBF);
	EXPECT_EQ(mem.read(LIBGREBE_REG_NR41), 0xFF);
	EXPECT_EQ(mem.read(LIBGREBE_REG_NR42), 0x00);
	EXPECT_EQ(mem.read(LIBGREBE_REG_NR43), 0x00);
	EXPECT_EQ(mem.read(LIBGREBE_REG_NR44), 0xBF);
	EXPECT_EQ(mem.read(LIBGREBE_REG_NR50), 0x77);
	EXPECT_EQ(mem.read(LIBGREBE_REG_NR51), 0xF3);
	EXPECT_EQ(mem.read(LIBGREBE_REG_NR52), 0xF1);
	EXPECT_EQ(mem.read(LIBGREBE_REG_LCDC), 0x91);
	EXPECT_EQ(mem.read(LIBGREBE_REG_STAT), 0x85);
	EXPECT_EQ(mem.read(LIBGREBE_REG_SCY), 0x00);
	EXPECT_EQ(mem.read(LIBGREBE_REG_SCX), 0x00);
	EXPECT_EQ(mem.read(LIBGREBE_REG_LY), 0x00);
	EXPECT_EQ(mem.read(LIBGREBE_REG_LYC), 0x00);
	EXPECT_EQ(mem.read(LIBGREBE_REG_DMA), 0xFF);
	EXPECT_EQ(mem.read(LIBGREBE_REG_BGP), 0xFC);
	EXPECT_EQ(mem.read(LIBGREBE_REG_WY), 0x00);
	EXPECT_EQ(mem.read(LIBGREBE_REG_WX), 0x00);
	EXPECT_EQ(mem.read(LIBGREBE_REG_KEY1), 0xFF);
	EXPECT_EQ(mem.read(LIBGREBE_REG_VBK), 0xFF);
	EXPECT_EQ(mem.read(LIBGREBE_REG_HDMA1), 0xFF);
	EXPECT_EQ(mem.read(LIBGREBE_REG_HDMA2), 0xFF);
	EXPECT_EQ(mem.read(LIBGREBE_REG_HDMA3), 0xFF);
	EXPECT_EQ(mem.read(LIBGREBE_REG_HDMA4), 0xFF);
	EXPECT_EQ(mem.read(LIBGREBE_REG_HDMA5), 0xFF);
	EXPECT_EQ(mem.read(LIBGREBE_REG_RP), 0xFF);
	EXPECT_EQ(mem.read(LIBGREBE_REG_BCPS), 0xFF);
	EXPECT_EQ(mem.read(LIBGREBE_REG_BCPD), 0xFF);
	EXPECT_EQ(mem.read(LIBGREBE_REG_OCPS), 0xFF);
	EXPECT_EQ(mem.read(LIBGREBE_REG_OCPD), 0xFF);
	EXPECT_EQ(mem.read(LIBGREBE_REG_SVBK), 0xFF);
	EXPECT_EQ(mem.read(LIBGREBE_REG_IE), 0x00);
}

TEST_F(MemoryTest, ReadWriteFringeTest)
{
	ASSERT_NO_THROW(mem.write(0, 0x69));
	ASSERT_EQ(mem.read(0), 0x69);
	ASSERT_NO_THROW(mem.write(-1, 0x69));
	ASSERT_EQ(mem.read(0xffff), 0x69);
	ASSERT_NO_THROW(mem.write(0x10000 - 1, 0x42));
	ASSERT_EQ(mem.read(0xffff), 0x42);
	ASSERT_NO_THROW(mem.write(0x10000, 0x42));
	ASSERT_EQ(mem.read(0), 0x42);
}

TEST_F(MemoryTest, ReadWriteWholeTest)
{
	for (int i = 0; i < LIBGREBE_MEMORY_SIZE; ++i)
	{
		ASSERT_NO_THROW(mem.write(i, i));
	}
	for (int i = 0; i < LIBGREBE_MEMORY_SIZE; ++i)
	{
		ASSERT_NO_THROW(EXPECT_EQ(mem.read(i), static_cast<Byte>(i)));
	}
}

TEST_F(MemoryTest, ReadWordTest)
{
	mem.write(0, 0xad);
	mem.write(1, 0xde);
	EXPECT_EQ(0xdead, mem.readWord(0));
}

TEST_F(MemoryTest, WriteWordTest)
{
	mem.writeWord(0, 0xbeef);
	EXPECT_EQ(mem.read(0), 0xef);
	EXPECT_EQ(mem.read(1), 0xbe);
}

#pragma clang diagnostic pop