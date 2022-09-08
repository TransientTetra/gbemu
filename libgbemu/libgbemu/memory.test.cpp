#include <gtest/gtest.h>
#include <libgbemu/memory.hpp>

class MemoryTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
	}
	void TearDown() override
	{
	}
};

TEST_F(MemoryTest, MemoryCreationTest)
{
	Memory mem;
	EXPECT_EQ(mem.registers.pc, 0x100);
	EXPECT_EQ(mem.registers.sp, 0xfffe);
}

TEST_F(MemoryTest, AtTest)
{
	Memory mem;
	ASSERT_NO_THROW(mem.at(0) = 0x69);
	ASSERT_EQ(mem.at(0), 0x69);
	ASSERT_NO_THROW(mem.at(-1) = 0x69);
	ASSERT_EQ(mem.at(0xFFFF), 0x69);
	ASSERT_NO_THROW(mem.at(0x10000 - 1) = 0x42);
	ASSERT_EQ(mem.at(0xFFFF), 0x42);
	ASSERT_NO_THROW(mem.at(0x10000) = 0x42);
	ASSERT_EQ(mem.at(0), 0x42);
}
