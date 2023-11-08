#include <libgrebe/core/cpu/control_unit.test.hpp>

TEST_F(OpcodesBitOperationsTest, Test0x07)
{
	// 0x07 RLCA
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcode(0x07);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcode(0x07);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b00010000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcode(0x07);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b00010001);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcode(0x07);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcode(0x07);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcode(0x07);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b10001000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcode(0x07);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b00010001);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcode(0x07);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcode(0x07);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcode(0x07);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b10001000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}
TEST_F(OpcodesBitOperationsTest, Test0x17)
{
	// 0x17 RLA
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcode(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcode(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(1);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10000000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcode(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcode(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcode(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcode(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b00100001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcode(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b01000010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcode(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b10000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcode(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b00001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcode(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcode(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcode(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcode(0x17);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b10001000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}
TEST_F(OpcodesBitOperationsTest, Test0x0F)
{
	// 0x0F RRCA
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcode(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcode(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b00000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcode(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcode(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcode(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcode(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b10001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcode(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b01000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcode(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b00100010);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcode(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b00010001);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
	testOpcode(0x0F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b10001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));
}
TEST_F(OpcodesBitOperationsTest, Test0x1F)
{
	// 0x1F RRA
	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcode(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcode(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b10000000);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(1);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcode(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b00001000);
	state.registers.setCarryFlag();
	// testing the opcode
	testOpcode(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b10000100);
	expectedState.registers.clearFlags();
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedState, state));

	// preparing cpu and memory state before executing the opcode
	state.registers.setA(0b10001000);
	state.registers.resetCarryFlag();
	// testing the opcode
	testOpcode(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b01000100);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcode(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b00100010);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcode(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b00010001);
	expectedState.registers.clearFlags();
	// testing the opcode
	testOpcode(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b00001000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	testOpcode(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b10000100);
	expectedState.registers.clearFlags();
	testOpcode(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b01000010);
	expectedState.registers.clearFlags();
	testOpcode(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b00100001);
	expectedState.registers.clearFlags();
	testOpcode(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b00010000);
	expectedState.registers.clearFlags();
	expectedState.registers.setCarryFlag();
	testOpcode(0x1F);
	// expected change in registers and memory
	expectedState.clockCycles += 4;
	expectedState.registers.setPC(expectedState.registers.getPC() + 1);
	expectedState.registers.setA(0b10001000);
	expectedState.registers.clearFlags();
}
