#include <libgrebe/core/cpu/control_unit.test.hpp>
TEST_F(OpcodesAluTest, Test0x80)
{
	// 0x80 ADD B
	state.registers.setA(0);
	state.registers.setB(0);
	// testing the opcode
	testOpcode(0x80);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	state.registers.setB(1);
	// testing the opcode
	testOpcode(0x80);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	state.registers.setB(0xff);
	// testing the opcode
	testOpcode(0x80);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0xfe);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x0f);
	state.registers.setB(1);
	// testing the opcode
	testOpcode(0x80);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0x10);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xf0);
	state.registers.setB(0x11);
	// testing the opcode
	testOpcode(0x80);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x81)
{
	// 0x81 ADD C
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.setC(0);
	// testing the opcode
	testOpcode(0x81);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	state.registers.setC(1);
	// testing the opcode
	testOpcode(0x81);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	state.registers.setC(0xff);
	// testing the opcode
	testOpcode(0x81);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0xfe);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x0f);
	state.registers.setC(1);
	// testing the opcode
	testOpcode(0x81);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0x10);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xf0);
	state.registers.setC(0x11);
	// testing the opcode
	testOpcode(0x81);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x82)
{
	// 0x82 ADD D
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.setD(0);
	// testing the opcode
	testOpcode(0x82);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	state.registers.setD(1);
	// testing the opcode
	testOpcode(0x82);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	state.registers.setD(0xff);
	// testing the opcode
	testOpcode(0x82);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0xfe);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x0f);
	state.registers.setD(1);
	// testing the opcode
	testOpcode(0x82);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0x10);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xf0);
	state.registers.setD(0x11);
	// testing the opcode
	testOpcode(0x82);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x83)
{
	// 0x83 ADD E
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.setE(0);
	// testing the opcode
	testOpcode(0x83);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	state.registers.setE(1);
	// testing the opcode
	testOpcode(0x83);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	state.registers.setE(0xff);
	// testing the opcode
	testOpcode(0x83);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0xfe);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x0f);
	state.registers.setE(1);
	// testing the opcode
	testOpcode(0x83);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0x10);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xf0);
	state.registers.setE(0x11);
	// testing the opcode
	testOpcode(0x83);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x84)
{
	// 0x84 ADD H
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.setH(0);
	// testing the opcode
	testOpcode(0x84);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	state.registers.setH(1);
	// testing the opcode
	testOpcode(0x84);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	state.registers.setH(0xff);
	// testing the opcode
	testOpcode(0x84);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0xfe);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x0f);
	state.registers.setH(1);
	// testing the opcode
	testOpcode(0x84);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0x10);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xf0);
	state.registers.setH(0x11);
	// testing the opcode
	testOpcode(0x84);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x85)
{
	// 0x85 ADD L
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.setL(0);
	// testing the opcode
	testOpcode(0x85);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	state.registers.setL(1);
	// testing the opcode
	testOpcode(0x85);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	state.registers.setL(0xff);
	// testing the opcode
	testOpcode(0x85);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0xfe);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x0f);
	state.registers.setL(1);
	// testing the opcode
	testOpcode(0x85);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0x10);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xf0);
	state.registers.setL(0x11);
	// testing the opcode
	testOpcode(0x85);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x86)
{
	// 0x86 ADD (HL)
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0);
	// testing the opcode
	testOpcode(0x86);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 1);
	// testing the opcode
	testOpcode(0x86);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x0f);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 1);
	// testing the opcode
	testOpcode(0x86);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.setA(0x10);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xf0);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0x11);
	// testing the opcode
	testOpcode(0x86);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xf0);
	state.registers.setHL(0xdead);
	state.mmu.write(0xdead, 0x11);
	// testing the opcode
	testOpcode(0x86);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.incPC();
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0x87)
{
	// 0x87 ADD A
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	// testing the opcode
	testOpcode(0x87);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x0f);
	// testing the opcode
	testOpcode(0x87);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0x1e);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	// testing the opcode
	testOpcode(0x87);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0xfe);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xf0);
	// testing the opcode
	testOpcode(0x87);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.incPC();
	expectedState.registers.setA(0xe0);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}

TEST_F(OpcodesAluTest, Test0xC6)
{
	// 0xC6 ADD n
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 0);
	// testing the opcode
	testOpcode(0xC6);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xff);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 1);
	// testing the opcode
	testOpcode(0xC6);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setZeroFlag();
	expectedState.registers.setHalfCarryFlag();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0x0f);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 1);
	// testing the opcode
	testOpcode(0xC6);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(0x10);
	expectedState.registers.clearFlags();
	expectedState.registers.setHalfCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0xf0);
	state.registers.setPC(0xdead);
	state.mmu.write(0xdeae, 0x11);
	// testing the opcode
	testOpcode(0xC6);
	// expected change in registers and memory
	expectedState.clockCycles += 8;
	expectedState.registers.setPC(expectedState.registers.getPC() + 2);
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}
