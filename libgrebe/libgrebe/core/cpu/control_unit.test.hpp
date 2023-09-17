#ifndef LIBGREBE_CPU_TEST_HPP
#define LIBGREBE_CPU_TEST_HPP

#include <gtest/gtest.h>
#include <libgrebe/common/addressable.hpp>
#include <libgrebe/core/common.test.hpp>
#include <libgrebe/core/mmu/mmu.hpp>
#include <memory>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconstant-conversion"
#define private public

#include <libgrebe/core/cpu/control_unit.hpp>

class ControlUnitTest : public ::testing::Test
{
protected:
    std::unique_ptr<ControlUnit> cpu;
    State state, expectedState;

    void SetUp() override
    {
        state.mmu.registerAddressable(std::make_unique<FakeAddressable>());
        expectedState.mmu.registerAddressable(std::make_unique<FakeAddressable>());
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
        state.mmu.write(state.registers.pc, opcode);
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
protected:
    void incTest(Byte opcode, Byte& reg, Byte& expectedReg);
    void decTest(Byte opcode, Byte& reg, Byte& expectedReg);
    void addTest(Byte opcode, Byte& operand);
    void adcTest(Byte opcode, Byte& operand);
    void subTest(Byte opcode, Byte& operand);
    void sbcTest(Byte opcode, Byte& operand);
    void andTest(Byte opcode, Byte& operand);
    void xorTest(Byte opcode, Byte& operand);
    void orTest(Byte opcode, Byte& operand);
    void cpTest(Byte opcode, Byte& operand);
};

class OpcodesBitOperationsTest : public ControlUnitTest
{
protected:
    void testOpcodeCB(Byte opcode)
    {
        // injecting opcode at pc
        state.mmu.write(state.registers.pc, 0xCB);
        state.mmu.write(state.registers.pc + 1, opcode);
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

    void testOpcodeRLC(Byte opcode, Byte& reg, Byte& expectedReg);

    void testOpcodeRRC(Byte opcode, Byte& reg, Byte& expectedReg);

    void testOpcodeRL(Byte opcode, Byte& reg, Byte& expectedReg);

    void testOpcodeRR(Byte opcode, Byte& reg, Byte& expectedReg);

    void testOpcodeSLA(Byte opcode, Byte& reg, Byte& expectedReg);

    void testOpcodeSRA(Byte opcode, Byte& reg, Byte& expectedReg);

    void testOpcodeSWAP(Byte opcode, Byte& reg, Byte& expectedReg);

    void testOpcodeSRL(Byte opcode, Byte& reg, Byte& expectedReg);

    void testOpcodeBIT(Byte opcode, Byte& reg, Byte& expectedReg, Byte bit);

    void testOpcodeRES(Byte opcode, Byte& reg, Byte& expectedReg, Byte bit);

    void testOpcodeSET(Byte opcode, Byte& reg, Byte& expectedReg, Byte bit);

    void testOpcodeBIThl(Byte opcode, Byte bit);

    void testOpcodeREShl(Byte opcode, Byte bit);

    void testOpcodeSEThl(Byte opcode, Byte bit);
};

class OpcodesControlFlowTest : public ControlUnitTest
{
};

#endif // LIBGREBE_CPU_TEST_HPP
