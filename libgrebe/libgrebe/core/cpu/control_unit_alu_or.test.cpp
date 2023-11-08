#include <libgrebe/core/cpu/control_unit.test.hpp>

TEST_F(OpcodesAluTest, Test0xB0)
{
	// 0xB0 OR B
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setB(0b00000000);
	// testing the opcode
	testOpcode(0xB0);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b11111111);
	state.registers.setB(0b00000000);
	// testing the opcode
	testOpcode(0xB0);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b11111111);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setB(0b11111111);
	// testing the opcode
	testOpcode(0xB0);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b11111111);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10101010);
	state.registers.setB(0b01010101);
	// testing the opcode
	testOpcode(0xB0);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b11111111);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b01010101);
	state.registers.setB(0b01010101);
	// testing the opcode
	testOpcode(0xB0);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b01010101);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0xB1)
{
	// 0xB1 OR C
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setC(0b00000000);
	// testing the opcode
	testOpcode(0xB1);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b11111111);
	state.registers.setC(0b00000000);
	// testing the opcode
	testOpcode(0xB1);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b11111111);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setC(0b11111111);
	// testing the opcode
	testOpcode(0xB1);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b11111111);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10101010);
	state.registers.setC(0b01010101);
	// testing the opcode
	testOpcode(0xB1);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b11111111);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b01010101);
	state.registers.setC(0b01010101);
	// testing the opcode
	testOpcode(0xB1);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b01010101);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0xB2)
{
	// 0xB2 OR D
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setD(0b00000000);
	// testing the opcode
	testOpcode(0xB2);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b11111111);
	state.registers.setD(0b00000000);
	// testing the opcode
	testOpcode(0xB2);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b11111111);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setD(0b11111111);
	// testing the opcode
	testOpcode(0xB2);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b11111111);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10101010);
	state.registers.setD(0b01010101);
	// testing the opcode
	testOpcode(0xB2);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b11111111);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b01010101);
	state.registers.setD(0b01010101);
	// testing the opcode
	testOpcode(0xB2);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b01010101);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0xB3)
{
	// 0xB3 OR E
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setE(0b00000000);
	// testing the opcode
	testOpcode(0xB3);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b11111111);
	state.registers.setE(0b00000000);
	// testing the opcode
	testOpcode(0xB3);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b11111111);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setE(0b11111111);
	// testing the opcode
	testOpcode(0xB3);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b11111111);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10101010);
	state.registers.setE(0b01010101);
	// testing the opcode
	testOpcode(0xB3);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b11111111);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b01010101);
	state.registers.setE(0b01010101);
	// testing the opcode
	testOpcode(0xB3);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b01010101);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0xB4)
{
	// 0xB4 OR H
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setH(0b00000000);
	// testing the opcode
	testOpcode(0xB4);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b11111111);
	state.registers.setH(0b00000000);
	// testing the opcode
	testOpcode(0xB4);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b11111111);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setH(0b11111111);
	// testing the opcode
	testOpcode(0xB4);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b11111111);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10101010);
	state.registers.setH(0b01010101);
	// testing the opcode
	testOpcode(0xB4);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b11111111);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b01010101);
	state.registers.setH(0b01010101);
	// testing the opcode
	testOpcode(0xB4);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b01010101);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0xB5)
{
	// 0xB5 OR L
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setL(0b00000000);
	// testing the opcode
	testOpcode(0xB5);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b11111111);
	state.registers.setL(0b00000000);
	// testing the opcode
	testOpcode(0xB5);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b11111111);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setL(0b11111111);
	// testing the opcode
	testOpcode(0xB5);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b11111111);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10101010);
	state.registers.setL(0b01010101);
	// testing the opcode
	testOpcode(0xB5);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b11111111);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b01010101);
	state.registers.setL(0b01010101);
	// testing the opcode
	testOpcode(0xB5);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b01010101);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0xB6)
{
	// 0xB6 OR (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0b00000000);
	// testing the opcode
	testOpcode(0xB6);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b11111111);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0b00000000);
	// testing the opcode
	testOpcode(0xB6);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b11111111);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0b11111111);
	// testing the opcode
	testOpcode(0xB6);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b11111111);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10101010);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0b01010101);
	// testing the opcode
	testOpcode(0xB6);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b11111111);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b01010101);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0b01010101);
	// testing the opcode
	testOpcode(0xB6);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b01010101);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0xB7)
{
	// 0xB7 OR A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	// testing the opcode
	testOpcode(0xB7);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b11111111);
	// testing the opcode
	testOpcode(0xB7);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b11111111);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10101010);
	// testing the opcode
	testOpcode(0xB7);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0b10101010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0xF6)
{
	// 0xF6 OR n
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 0b00000000);
	// testing the opcode
	testOpcode(0xF6);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b11111111);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 0b00000000);
	// testing the opcode
	testOpcode(0xF6);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b11111111);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00000000);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 0b11111111);
	// testing the opcode
	testOpcode(0xF6);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b11111111);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10101010);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 0b01010101);
	// testing the opcode
	testOpcode(0xF6);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b11111111);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b01010101);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 0b01010101);
	// testing the opcode
	testOpcode(0xF6);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b01010101);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}
