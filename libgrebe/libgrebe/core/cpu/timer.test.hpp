#ifndef LIBGREBE_TIMER_TEST_HPP
#define LIBGREBE_TIMER_TEST_HPP

#include <gtest/gtest.h>
#include <libgrebe/core/common.test.hpp>
#include <libgrebe/core/cpu/timer.hpp>
#include <memory>

class TimerTest : public ::testing::Test
{
protected:
    State state;
    std::unique_ptr<Timer> timer;
    void SetUp() override
    {
        timer = std::make_unique<Timer>(state);
    }
    void TearDown() override
    {
    }
};

#endif // LIBGREBE_TIMER_TEST_HPP
