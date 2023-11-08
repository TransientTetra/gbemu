#include <libgrebe/core/cpu/control_unit.test.hpp>

TEST_F(OpcodesAluTest, Test0xA0)
{
	// 0xA0 AND B
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setB(0b00000000);
	// testing the opcode
	testOpcode(0xA0);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b11111111);
	state.registers.setB(0b00000000);
	// testing the opcode
	testOpcode(0xA0);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setB(0b11111111);
	// testing the opcode
	testOpcode(0xA0);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10101010);
	state.registers.setB(0b01010101);
	// testing the opcode
	testOpcode(0xA0);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b01010101);
	state.registers.setB(0b01010101);
	// testing the opcode
	testOpcode(0xA0);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b01010101);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0xA1)
{
	// 0xA1 AND C
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setC(0b00000000);
	// testing the opcode
	testOpcode(0xA1);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b11111111);
	state.registers.setC(0b00000000);
	// testing the opcode
	testOpcode(0xA1);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setC(0b11111111);
	// testing the opcode
	testOpcode(0xA1);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10101010);
	state.registers.setC(0b01010101);
	// testing the opcode
	testOpcode(0xA1);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b01010101);
	state.registers.setC(0b01010101);
	// testing the opcode
	testOpcode(0xA1);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b01010101);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0xA2)
{
	// 0xA2 AND D
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setD(0b00000000);
	// testing the opcode
	testOpcode(0xA2);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b11111111);
	state.registers.setD(0b00000000);
	// testing the opcode
	testOpcode(0xA2);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setD(0b11111111);
	// testing the opcode
	testOpcode(0xA2);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10101010);
	state.registers.setD(0b01010101);
	// testing the opcode
	testOpcode(0xA2);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b01010101);
	state.registers.setD(0b01010101);
	// testing the opcode
	testOpcode(0xA2);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b01010101);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0xA3)
{
	// 0xA3 AND E
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setE(0b00000000);
	// testing the opcode
	testOpcode(0xA3);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b11111111);
	state.registers.setE(0b00000000);
	// testing the opcode
	testOpcode(0xA3);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setE(0b11111111);
	// testing the opcode
	testOpcode(0xA3);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10101010);
	state.registers.setE(0b01010101);
	// testing the opcode
	testOpcode(0xA3);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b01010101);
	state.registers.setE(0b01010101);
	// testing the opcode
	testOpcode(0xA3);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b01010101);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0xA4)
{
	// 0xA4 AND H
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setH(0b00000000);
	// testing the opcode
	testOpcode(0xA4);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b11111111);
	state.registers.setH(0b00000000);
	// testing the opcode
	testOpcode(0xA4);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setH(0b11111111);
	// testing the opcode
	testOpcode(0xA4);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10101010);
	state.registers.setH(0b01010101);
	// testing the opcode
	testOpcode(0xA4);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b01010101);
	state.registers.setH(0b01010101);
	// testing the opcode
	testOpcode(0xA4);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b01010101);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0xA5)
{
	// 0xA5 AND L
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setL(0b00000000);
	// testing the opcode
	testOpcode(0xA5);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b11111111);
	state.registers.setL(0b00000000);
	// testing the opcode
	testOpcode(0xA5);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setL(0b11111111);
	// testing the opcode
	testOpcode(0xA5);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10101010);
	state.registers.setL(0b01010101);
	// testing the opcode
	testOpcode(0xA5);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b01010101);
	state.registers.setL(0b01010101);
	// testing the opcode
	testOpcode(0xA5);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b01010101);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0xA6)
{
	// 0xA6 AND (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0b00000000);
	// testing the opcode
	testOpcode(0xA6);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b11111111);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0b00000000);
	// testing the opcode
	testOpcode(0xA6);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0b11111111);
	// testing the opcode
	testOpcode(0xA6);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10101010);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0b01010101);
	// testing the opcode
	testOpcode(0xA6);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b01010101);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0b01010101);
	// testing the opcode
	testOpcode(0xA6);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b01010101);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0xA7)
{
	// 0xA7 AND A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	// testing the opcode
	testOpcode(0xA7);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b11111111);
	// testing the opcode
	testOpcode(0xA7);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b11111111);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10101010);
	// testing the opcode
	testOpcode(0xA7);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b10101010);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0xE6)
{
	// 0xE6 AND n
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 0b00000000);
	// testing the opcode
	testOpcode(0xE6);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b11111111);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 0b00000000);
	// testing the opcode
	testOpcode(0xE6);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 0b11111111);
	// testing the opcode
	testOpcode(0xE6);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10101010);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 0b01010101);
	// testing the opcode
	testOpcode(0xE6);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b01010101);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 0b01010101);
	// testing the opcode
	testOpcode(0xE6);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b01010101);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}
