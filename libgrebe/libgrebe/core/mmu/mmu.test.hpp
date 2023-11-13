#ifndef LIBGREBE_MMU_TEST_HPP
#define LIBGREBE_MMU_TEST_HPP

#include <gtest/gtest.h>

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

	inline void testContains(const Addressable& addressable, std::uint16_t rangeStart, std::uint16_t rangeEnd)
	{
		for (std::uint16_t i = rangeStart; i <= rangeEnd; ++i)
		{
			EXPECT_TRUE(addressable.contains(i));
		}
	}
	inline void testReadWrite(Addressable& addressable, std::uint16_t rangeStart, std::uint16_t rangeEnd)
	{
		for (std::uint16_t i = rangeStart; i <= rangeEnd; ++i)
		{
			testReadWrite(addressable, i);
		}
	}
	inline void testReadWrite(Addressable& addressable, std::uint16_t addr)
	{
		addressable.write(addr, 0x96);
		EXPECT_EQ(addressable.read(addr), 0x96);
		addressable.write(addr, 0x69);
		EXPECT_EQ(addressable.read(addr), 0x69);
	}
};

#endif // LIBGREBE_MMU_TEST_HPP
