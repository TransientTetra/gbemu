#ifndef LIBGREBE_CPU_TEST_HPP
#define LIBGREBE_CPU_TEST_HPP

#include <gtest/gtest.h>
#include <memory>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconstant-conversion"
#define private public

#include <libgrebe/core/cpu/cpu.hpp>
#include <libgrebe/core/cpu/instructions.hpp>

class CPUTest : public ::testing::Test
{
protected:
    std::unique_ptr<CPU> cpu;
    State state, expectedState;

    void SetUp() override
    {
        cpu = std::make_unique<CPU>(state);
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
        state.memory.write(state.registers.pc, opcode);
        // saving cpu and memory state before executing the opcode
        expectedState = state;
        // fetch the opcode
        machineCycle();
        // execute the opcode
        while (!state.cpuQueue.empty())
        {
            cpu->tick();
            ++state.clockCycles;
        }
    }

    static void compareMem(const Memory& mem1, const Memory& mem2)
    {
        if (mem1 == mem2)
            std::cerr << "Memories identical" << std::endl;
        else
        {
            for (int i = 0; i < LIBGREBE_MEMORY_SIZE; ++i)
            {
                if (mem1.read(i) != mem2.read(i))
                {
                    int j = std::max(0, i - 4);
                    std::cerr << "Found diff at " << std::hex << i << std::endl;
                    for (; j < std::min(LIBGREBE_MEMORY_SIZE, i + 4); ++j)
                    {
                        std::cerr << std::hex << j << "  " << std::hex << (int)mem1.read(j) << "   " << std::hex
                                  << (int)mem2.read(j) << std::endl;
                    }
                }
            }
        }
    }
};

class OpcodesLoadsTest : public CPUTest
{
};

class OpcodesMiscTest : public CPUTest
{
};

class OpcodesAluTest : public CPUTest
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

class OpcodesBitOperationsTest : public CPUTest
{
protected:
    void testOpcodeCB(Byte opcode)
    {
        // injecting opcode at pc
        state.memory.write(state.registers.pc, 0xCB);
        state.memory.write(state.registers.pc + 1, opcode);
        // saving cpu and memory state before executing the opcode
        expectedState.registers = state.registers;
        expectedState.memory = state.memory;
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

class OpcodesControlFlowTest : public CPUTest
{
};

#endif // LIBGREBE_CPU_TEST_HPP
