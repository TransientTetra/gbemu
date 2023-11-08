#include <libgrebe/core/cpu/control_unit.test.hpp>

TEST_F(OpcodesBitOperationsTest, Test0xCB20)
{
	// 0x20 SLA B
	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x20);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x20);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b00010000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setB(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x20);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x20);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b00100000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x20);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b01000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x20);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b10000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x20);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x20);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setB(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
}

TEST_F(OpcodesBitOperationsTest, Test0xCB21)
{
	// 0x21 SLA C
	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x21);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x21);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b00010000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setC(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x21);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x21);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b00100000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x21);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b01000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x21);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b10000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x21);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x21);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setC(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
}

TEST_F(OpcodesBitOperationsTest, Test0xCB22)
{
	// 0x22 SLA D
	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x22);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x22);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b00010000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setD(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x22);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x22);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b00100000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x22);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b01000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x22);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b10000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x22);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x22);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setD(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
}

TEST_F(OpcodesBitOperationsTest, Test0xCB23)
{
	// 0x23 SLA E
	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x23);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x23);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b00010000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setE(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x23);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x23);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b00100000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x23);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b01000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x23);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b10000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x23);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x23);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setE(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
}

TEST_F(OpcodesBitOperationsTest, Test0xCB24)
{
	// 0x24 SLA H
	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x24);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x24);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b00010000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setH(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x24);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x24);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b00100000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x24);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b01000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x24);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b10000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x24);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x24);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setH(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
}

TEST_F(OpcodesBitOperationsTest, Test0xCB25)
{
	// 0x25 SLA L
	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x25);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x25);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b00010000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setL(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x25);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x25);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b00100000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x25);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b01000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x25);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b10000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x25);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x25);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setL(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
}

TEST_F(OpcodesBitOperationsTest, Test0xCB26)
{
	// 0x26 SLA (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x26);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x26);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b00010000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x26);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x26);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b00100000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x26);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b01000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x26);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b10000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x26);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x26);
	// expected change in registers and memory
	expectedState.clockCycles += 16;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.mmu.write(0xdead, 0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesBitOperationsTest, Test0xCB27)
{
	// 0x27 SLA A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x27);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcodeCB(0x27);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b00010000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcodeCB(0x27);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x27);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b00100000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x27);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b01000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x27);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b10000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x27);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcodeCB(0x27);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0b00000000);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
}
