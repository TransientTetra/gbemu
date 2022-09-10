#include <gtest/gtest.h>
#include <libgbemu/memory.hpp>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconstant-conversion"
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

TEST_F(MemoryTest, CreationTest)
{
	Memory mem;
}

TEST_F(MemoryTest, ReadWriteFringeTest)
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

TEST_F(MemoryTest, ReadWriteWholeTest)
{
	Memory mem;
	for (int i = 0; i < LIBGEMU_MEMORY_SIZE; ++i)
	{
		ASSERT_NO_THROW(mem.write(i, i));
	}
	for (int i = 0; i < LIBGEMU_MEMORY_SIZE; ++i)
	{
		ASSERT_NO_THROW(EXPECT_EQ(mem.read(i), static_cast<Byte>(i)));
	}
}

#pragma clang diagnostic pop