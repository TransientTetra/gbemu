#include <libgrebe/core/common.test.hpp>
#include <libgrebe/core/core.test.hpp>

TEST_F(CoreTest, InterruptsTest)
{
	core->state.registers.pc = 0xdead;
	core->state.ime = false;
	core->state.mmu.write(LIBGREBE_REG_IE, 0xff);
	core->state.mmu.write(LIBGREBE_REG_IF, 0xff);
	// injecting opcode at pc
	core->state.mmu.write(core->state.registers.pc, 0x00);
	// saving cpu and memory core->state before executing the opcode
	copyState(expectedCore->state, core->state);
	// execute the opcode
	machineCycle();
	expectedCore->state.clockCycles += 4;
	expectedCore->state.registers.pc += 1;
	EXPECT_TRUE(compareState(expectedCore->state, core->state));

	core->state.registers.pc = 0xdead;
	core->state.ime = true;
	core->state.mmu.write(LIBGREBE_REG_IE, 0);
	core->state.mmu.write(LIBGREBE_REG_IF, 0xff);
	// injecting opcode at pc
	core->state.mmu.write(core->state.registers.pc, 0x00);
	// saving cpu and memory core->state before executing the opcode
	copyState(expectedCore->state, core->state);
	// execute the opcode
	machineCycle();
	expectedCore->state.clockCycles += 4;
	expectedCore->state.registers.pc += 1;
	EXPECT_TRUE(compareState(expectedCore->state, core->state));

	core->state.registers.pc = 0xdead;
	core->state.ime = true;
	core->state.mmu.write(LIBGREBE_REG_IE, 0xff);
	core->state.mmu.write(LIBGREBE_REG_IF, 0);
	// injecting opcode at pc
	core->state.mmu.write(core->state.registers.pc, 0x00);
	// saving cpu and memory core->state before executing the opcode
	copyState(expectedCore->state, core->state);
	// execute the opcode
	machineCycle();
	expectedCore->state.clockCycles += 4;
	expectedCore->state.registers.pc += 1;
	EXPECT_TRUE(compareState(expectedCore->state, core->state));

	core->state.registers.pc = 0xdead;
	core->state.registers.sp = 0xbeef;
	core->state.ime = true;
	core->state.mmu.write(LIBGREBE_REG_IE, 1);
	core->state.mmu.write(LIBGREBE_REG_IF, 1);
	copyState(expectedCore->state, core->state);
	machineCycle();
	machineCycle();
	machineCycle();
	machineCycle();
	machineCycle();
	expectedCore->state.clockCycles += 20;
	expectedCore->state.registers.pc = LIBGREBE_INT_VBLANK;
	expectedCore->state.registers.sp = 0xbeef - 2;
	expectedCore->state.ime = false;
	writeWord(expectedCore->state, 0xbeef - 2, 0xdead);
	expectedCore->state.mmu.write(LIBGREBE_REG_IF, 0);
	EXPECT_TRUE(compareState(expectedCore->state, core->state));

	core->state.registers.pc = 0xdead;
	core->state.registers.sp = 0xbeef;
	core->state.ime = true;
	core->state.mmu.write(LIBGREBE_REG_IE, 2);
	core->state.mmu.write(LIBGREBE_REG_IF, 2);
	copyState(expectedCore->state, core->state);
	machineCycle();
	machineCycle();
	machineCycle();
	machineCycle();
	machineCycle();
	expectedCore->state.clockCycles += 20;
	expectedCore->state.registers.pc = LIBGREBE_INT_STAT;
	expectedCore->state.registers.sp = 0xbeef - 2;
	expectedCore->state.ime = false;
	writeWord(expectedCore->state, 0xbeef - 2, 0xdead);
	expectedCore->state.mmu.write(LIBGREBE_REG_IF, 0);
	EXPECT_TRUE(compareState(expectedCore->state, core->state));

	core->state.registers.pc = 0xdead;
	core->state.registers.sp = 0xbeef;
	core->state.ime = true;
	core->state.mmu.write(LIBGREBE_REG_IE, 4);
	core->state.mmu.write(LIBGREBE_REG_IF, 4);
	copyState(expectedCore->state, core->state);
	machineCycle();
	machineCycle();
	machineCycle();
	machineCycle();
	machineCycle();
	expectedCore->state.clockCycles += 20;
	expectedCore->state.registers.pc = LIBGREBE_INT_TIMER;
	expectedCore->state.registers.sp = 0xbeef - 2;
	expectedCore->state.ime = false;
	writeWord(expectedCore->state, 0xbeef - 2, 0xdead);
	expectedCore->state.mmu.write(LIBGREBE_REG_IF, 0);
	EXPECT_TRUE(compareState(expectedCore->state, core->state));

	core->state.registers.pc = 0xdead;
	core->state.registers.sp = 0xbeef;
	core->state.ime = true;
	core->state.mmu.write(LIBGREBE_REG_IE, 8);
	core->state.mmu.write(LIBGREBE_REG_IF, 8);
	copyState(expectedCore->state, core->state);
	machineCycle();
	machineCycle();
	machineCycle();
	machineCycle();
	machineCycle();
	expectedCore->state.clockCycles += 20;
	expectedCore->state.registers.pc = LIBGREBE_INT_SERIAL;
	expectedCore->state.registers.sp = 0xbeef - 2;
	expectedCore->state.ime = false;
	writeWord(expectedCore->state, 0xbeef - 2, 0xdead);
	expectedCore->state.mmu.write(LIBGREBE_REG_IF, 0);
	EXPECT_TRUE(compareState(expectedCore->state, core->state));

	core->state.registers.pc = 0xdead;
	core->state.registers.sp = 0xbeef;
	core->state.ime = true;
	core->state.mmu.write(LIBGREBE_REG_IE, 16);
	core->state.mmu.write(LIBGREBE_REG_IF, 16);
	copyState(expectedCore->state, core->state);
	machineCycle();
	machineCycle();
	machineCycle();
	machineCycle();
	machineCycle();
	expectedCore->state.clockCycles += 20;
	expectedCore->state.registers.pc = LIBGREBE_INT_JOYPAD;
	expectedCore->state.registers.sp = 0xbeef - 2;
	expectedCore->state.ime = false;
	writeWord(expectedCore->state, 0xbeef - 2, 0xdead);
	expectedCore->state.mmu.write(LIBGREBE_REG_IF, 0);
	EXPECT_TRUE(compareState(expectedCore->state, core->state));
}

TEST_F(CoreTest, TestEI)
{
	// 0xFB EI
	// preparing cpu and memory core->state before executing the opcode
	core->state.registers.pc = 0xdead;
	core->state.ime = false;
	core->state.imeScheduled = false;
	// testing the opcode
	// injecting opcode at pc
	core->state.mmu.write(core->state.registers.pc, 0xFB);
	// saving cpu and memory core->state before executing the opcode
	copyState(expectedCore->state, core->state);
	machineCycle();
	// expected change in registers and memory
	expectedCore->state.clockCycles += 4;
	expectedCore->state.registers.pc += 1;
	expectedCore->state.imeScheduled = true;
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedCore->state, core->state));
	// testing the opcode
	core->state.mmu.write(core->state.registers.pc, 0x00);
	copyState(expectedCore->state, core->state);
	machineCycle();
	// expected change in registers and memory
	expectedCore->state.clockCycles += 4;
	expectedCore->state.registers.pc += 1;
	expectedCore->state.imeScheduled = false;
	expectedCore->state.ime = true;
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedCore->state, core->state));
}
