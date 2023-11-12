#ifndef LIBGREBE_CPU_TEST_HPP
#define LIBGREBE_CPU_TEST_HPP

#include <gtest/gtest.h>
#include <libgrebe/common/addressable.hpp>
#include <libgrebe/core/common.test.hpp>
#include <libgrebe/core/mmu/mmu.hpp>
#include <memory>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconstant-conversion"

#include <libgrebe/core/cpu/control_unit.hpp>

class ControlUnitTest : public ::testing::Test
{
protected:
	FakeAddressable fakeAddressable;
	std::unique_ptr<ControlUnit> cpu;
	State state, expectedState;

	void SetUp() override
	{
		state.mmu.registerAddressable(fakeAddressable);
		expectedState.mmu.registerAddressable(fakeAddressable);
		cpu = std::make_unique<ControlUnit>(state);
	}

	void TearDown() override
	{
	}

	void machineCycle()
	{
		cpu->tick();
		++state.clockCycles;
		cpu->tick();
		++state.clockCycles;
		cpu->tick();
		++state.clockCycles;
		cpu->tick();
		++state.clockCycles;
	}

	void testOpcode(Byte opcode)
	{
		// injecting opcode at pc
		state.mmu.write(state.registers.getPC(), opcode);
		// saving cpu and memory state before executing the opcode
		copyState(expectedState, state);
		// fetch the opcode
		machineCycle();
		// execute the opcode
		while (!state.cpuQueue.empty())
		{
			cpu->tick();
			++state.clockCycles;
		}
	}
};

class OpcodesLoadsTest : public ControlUnitTest
{
};

class OpcodesMiscTest : public ControlUnitTest
{
};

class OpcodesAluTest : public ControlUnitTest
{
};

class OpcodesBitOperationsTest : public ControlUnitTest
{
protected:
	void testOpcodeCB(Byte opcode)
	{
		// injecting opcode at pc
		state.mmu.write(state.registers.getPC(), 0xCB);
		state.mmu.write(state.registers.getPC() + 1, opcode);
		// saving cpu and memory state before executing the opcode
		copyState(expectedState, state);
		// reading 0xCB
		machineCycle();
		// reading extended opcode
		machineCycle();
		// executing the opcode
		while (!state.cpuQueue.empty())
		{
			cpu->tick();
			++state.clockCycles;
		}
	}
};

class OpcodesControlFlowTest : public ControlUnitTest
{
};

#endif // LIBGREBE_CPU_TEST_HPP
