#include <gtest/gtest.h>
#include <libgbemu/memory.hpp>

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
	for (int i = 0; i < LIBGEMU_MEMORY_SIZE; ++i)
	{
		ASSERT_NO_THROW(mem.write(i, i));
	}
	for (int i = 0; i < LIBGEMU_MEMORY_SIZE; ++i)
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

#pragma clang diagnostic pop