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
}

TEST_F(MemoryTest, AtTest)
{
	Memory mem;
	ASSERT_NO_THROW(mem.write(0, 0x69));
	ASSERT_EQ(mem.read(0), 0x69);
	ASSERT_NO_THROW(mem.write(-1, 0x69));
	ASSERT_EQ(mem.read(0xffff), 0x69);
	ASSERT_NO_THROW(mem.write(0x10000 - 1, 0x42));
	ASSERT_EQ(mem.read(0xffff), 0x42);
	ASSERT_NO_THROW(mem.write(0x10000, 0x42));
	ASSERT_EQ(mem.read(0), 0x42);
}
