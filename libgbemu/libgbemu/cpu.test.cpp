#include <gtest/gtest.h>
#include <libgbemu/cpu.hpp>

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
}