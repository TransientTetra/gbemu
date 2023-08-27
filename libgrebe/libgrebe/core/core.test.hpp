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
    State state, expectedState;

    void SetUp() override
    {
      core = std::make_unique<Core>(state);
    }

    void TearDown() override
    {
    }

    void machineCycle()
    {
        state.clockCycles += 4;
        core->tick();
        core->tick();
        core->tick();
        core->tick();
    }
};

#endif // LIBGREBE_CORE_TEST_HPP
