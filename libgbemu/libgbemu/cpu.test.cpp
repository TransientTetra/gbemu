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
	EXPECT_EQ(cpu.registers.pc, 0x100);
	EXPECT_EQ(cpu.registers.sp, 0xfffe);
}