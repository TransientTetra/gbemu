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
	Memory ram;
}
