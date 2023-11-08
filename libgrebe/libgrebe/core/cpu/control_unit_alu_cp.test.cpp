#include <libgrebe/core/cpu/control_unit.test.hpp>

TEST_F(OpcodesAluTest, Test0xB8)
{
	// 0xB8 CP B
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.setB(0);
	// testing the opcode
	testOpcode(0xB8);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(2);
	state.registers.setB(2);
	// testing the opcode
	testOpcode(0xB8);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(5);
	state.registers.setB(2);
	// testing the opcode
	testOpcode(0xB8);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x00);
	state.registers.setB(1);
	// testing the opcode
	testOpcode(0xB8);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x10);
	state.registers.setB(2);
	// testing the opcode
	testOpcode(0xB8);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(1);
	state.registers.setB(0x11);
	// testing the opcode
	testOpcode(0xB8);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0xB9)
{
	// 0xB9 CP C
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.setC(0);
	// testing the opcode
	testOpcode(0xB9);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(2);
	state.registers.setC(2);
	// testing the opcode
	testOpcode(0xB9);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(5);
	state.registers.setC(2);
	// testing the opcode
	testOpcode(0xB9);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x00);
	state.registers.setC(1);
	// testing the opcode
	testOpcode(0xB9);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x10);
	state.registers.setC(2);
	// testing the opcode
	testOpcode(0xB9);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(1);
	state.registers.setC(0x11);
	// testing the opcode
	testOpcode(0xB9);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0xBA)
{
	// 0xBA CP D
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.setD(0);
	// testing the opcode
	testOpcode(0xBA);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(2);
	state.registers.setD(2);
	// testing the opcode
	testOpcode(0xBA);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(5);
	state.registers.setD(2);
	// testing the opcode
	testOpcode(0xBA);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x00);
	state.registers.setD(1);
	// testing the opcode
	testOpcode(0xBA);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x10);
	state.registers.setD(2);
	// testing the opcode
	testOpcode(0xBA);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(1);
	state.registers.setD(0x11);
	// testing the opcode
	testOpcode(0xBA);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0xBB)
{
	// 0xBB CP E
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.setE(0);
	// testing the opcode
	testOpcode(0xBB);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(2);
	state.registers.setE(2);
	// testing the opcode
	testOpcode(0xBB);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(5);
	state.registers.setE(2);
	// testing the opcode
	testOpcode(0xBB);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x00);
	state.registers.setE(1);
	// testing the opcode
	testOpcode(0xBB);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x10);
	state.registers.setE(2);
	// testing the opcode
	testOpcode(0xBB);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(1);
	state.registers.setE(0x11);
	// testing the opcode
	testOpcode(0xBB);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0xBC)
{
	// 0xBC CP H
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.setH(0);
	// testing the opcode
	testOpcode(0xBC);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(2);
	state.registers.setH(2);
	// testing the opcode
	testOpcode(0xBC);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(5);
	state.registers.setH(2);
	// testing the opcode
	testOpcode(0xBC);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x00);
	state.registers.setH(1);
	// testing the opcode
	testOpcode(0xBC);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x10);
	state.registers.setH(2);
	// testing the opcode
	testOpcode(0xBC);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(1);
	state.registers.setH(0x11);
	// testing the opcode
	testOpcode(0xBC);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0xBD)
{
	// 0xBD CP L
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.setL(0);
	// testing the opcode
	testOpcode(0xBD);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(2);
	state.registers.setL(2);
	// testing the opcode
	testOpcode(0xBD);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(5);
	state.registers.setL(2);
	// testing the opcode
	testOpcode(0xBD);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x00);
	state.registers.setL(1);
	// testing the opcode
	testOpcode(0xBD);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x10);
	state.registers.setL(2);
	// testing the opcode
	testOpcode(0xBD);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(1);
	state.registers.setL(0x11);
	// testing the opcode
	testOpcode(0xBD);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0xBE)
{
	// 0xBE CP (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0);
	// testing the opcode
	testOpcode(0xBE);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(2);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 2);
	// testing the opcode
	testOpcode(0xBE);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(5);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 2);
	// testing the opcode
	testOpcode(0xBE);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x00);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 1);
	// testing the opcode
	testOpcode(0xBE);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x10);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 2);
	// testing the opcode
	testOpcode(0xBE);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(1);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0x11);
	// testing the opcode
	testOpcode(0xBE);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0xBF)
{
	// 0xBF CP A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	// testing the opcode
	testOpcode(0xBF);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(2);
	// testing the opcode
	testOpcode(0xBF);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(2);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	// testing the opcode
	testOpcode(0xBF);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0xff);
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0xFE)
{
	// 0xFE CP n
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 0);
	// testing the opcode
	testOpcode(0xFE);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(2);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 2);
	// testing the opcode
	testOpcode(0xFE);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(5);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 2);
	// testing the opcode
	testOpcode(0xFE);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x00);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 1);
	// testing the opcode
	testOpcode(0xFE);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x10);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 2);
	// testing the opcode
	testOpcode(0xFE);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(1);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 0x11);
	// testing the opcode
	testOpcode(0xFE);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.clearFlags();
	expectedState.registers.setSubtractFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}
