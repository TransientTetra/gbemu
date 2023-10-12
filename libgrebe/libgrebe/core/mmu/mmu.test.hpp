#ifndef LIBGREBE_MMU_TEST_HPP
#define LIBGREBE_MMU_TEST_HPP

#include <gtest/gtest.h>

#define private public
#include <libgrebe/core/common.test.hpp>

class MMUTest : public ::testing::Test
{
protected:
	MMU mmu;
	void SetUp() override
	{
	}
	void TearDown() override
	{
	}

	void testContains(const Addressable& addressable, const Word& rangeStart, const Word& rangeEnd)
	{
		for (Word i = rangeStart; i <= rangeEnd; ++i)
		{
			EXPECT_TRUE(addressable.contains(i));
		}
	}
	void testReadWrite(Addressable& addressable, const Word& rangeStart, const Word& rangeEnd)
	{
		for (Word i = rangeStart; i <= rangeEnd; ++i)
		{
			addressable.write(i, 0x69);
		}
		for (Word i = rangeStart; i <= rangeEnd; ++i)
		{
			EXPECT_EQ(addressable.read(i), 0x69);
		}
	}
	void testReadWrite(Byte& hwReg, Word addr, Addressable& addressable)
	{
		hwReg = 0x69;
		EXPECT_EQ(addressable.read(addr), 0x69);
		addressable.write(addr, 0x96);
		EXPECT_EQ(hwReg, 0x96);
	}
};

#endif // LIBGREBE_MMU_TEST_HPP
