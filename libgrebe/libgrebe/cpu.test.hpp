#ifndef LIBGREBE_CPU_TEST_HPP
#define LIBGREBE_CPU_TEST_HPP

#include <gtest/gtest.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconstant-conversion"
#define private public

#include <libgrebe/cpu.hpp>
#include <libgrebe/instructions.hpp>

class CPUTest : public ::testing::Test
{
protected:
	CPU cpu;
	State state, expectedState;

	void SetUp() override
	{
	}

	void TearDown() override
	{
	}

	void testOpcode(Byte opcode)
	{
		// injecting opcode at pc
		state.memory.write(state.registers.pc, opcode);
		// saving cpu and memory state before executing the opcode
		expectedState = state;
		// executing the opcode
		cpu.execute(state);
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
		// executing the opcode
		cpu.execute(state);
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

#endif //LIBGREBE_CPU_TEST_HPP
