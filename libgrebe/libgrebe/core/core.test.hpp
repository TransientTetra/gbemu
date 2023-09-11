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
    State expectedState;

    void SetUp() override
    {
        core = std::make_unique<Core>();
    }

    void TearDown() override
    {
    }

    void writeWord(State& state, const Word& address, const Word& data)
    {
        state.mmu.write(address, static_cast<Byte>(0x00ff & data));
        state.mmu.write(address + 1, static_cast<Byte>(data >> 8));
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
