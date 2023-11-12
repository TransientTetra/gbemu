#ifndef LIBGREBE_CORE_TEST_HPP
#define LIBGREBE_CORE_TEST_HPP
#include <gtest/gtest.h>
#include <memory>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconstant-conversion"

#include <libgrebe/core/core.hpp>

class CoreTest : public ::testing::Test
{
protected:
	Core core;
	Core expectedCore;

	void SetUp() override
	{
	}

	void TearDown() override
	{
	}

	void machineCycle()
	{
		core.tick();
		core.tick();
		core.tick();
		core.tick();
	}
};

#endif // LIBGREBE_CORE_TEST_HPP
