#ifndef LIBGREBE_CORE_TEST_HPP
#define LIBGREBE_CORE_TEST_HPP
#include <gtest/gtest.h>
#include <memory>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconstant-conversion"
#define private public

#include <libgrebe/core/core.hpp>

class CoreTest : public ::testing::Test
{
protected:
	std::unique_ptr<Core> core;
	std::unique_ptr<Core> expectedCore;

	void SetUp() override
	{
		core = std::make_unique<Core>();
		expectedCore = std::make_unique<Core>();
	}

	void TearDown() override
	{
	}

	void machineCycle()
	{
		core->tick();
		++core->state.clockCycles;
		core->tick();
		++core->state.clockCycles;
		core->tick();
		++core->state.clockCycles;
		core->tick();
		++core->state.clockCycles;
	}
};

#endif // LIBGREBE_CORE_TEST_HPP
