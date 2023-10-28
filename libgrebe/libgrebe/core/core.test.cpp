#include <gtest/gtest.h>
#include <libgrebe/core/common.test.hpp>
#include <libgrebe/core/core.test.hpp>

TEST_F(CoreTest, DMGInitTest)
{
	// https://gbdev.io/pandocs/Power_Up_Sequence.html#console-state-after-boot-rom-hand-off
	// test checking state after bootrom handoff
	EXPECT_EQ(core->state.registers.a, 1);
	EXPECT_EQ(core->state.registers.b, 0);
	EXPECT_EQ(core->state.registers.c, 0x13);
	EXPECT_EQ(core->state.registers.d, 0);
	EXPECT_EQ(core->state.registers.e, 0xd8);
	EXPECT_EQ(core->state.registers.h, 0x01);
	EXPECT_EQ(core->state.registers.l, 0x4d);
	EXPECT_EQ(core->state.registers.pc, 0x100);
	EXPECT_EQ(core->state.registers.sp, 0xfffe);
	EXPECT_EQ(core->state.registers.getZeroFlag(), 1);
	EXPECT_EQ(core->state.registers.getSubtractFlag(), 0);
	EXPECT_EQ(core->state.hardwareRegisters.P1, 0xCF);
	EXPECT_EQ(core->state.hardwareRegisters.SB, 0x00);
	EXPECT_EQ(core->state.hardwareRegisters.SC, 0x7E);
	EXPECT_EQ(core->state.hardwareRegisters.DIV_WIDE >> 8, 0xAB);
	EXPECT_EQ(core->state.hardwareRegisters.TIMA, 0x00);
	EXPECT_EQ(core->state.hardwareRegisters.TMA, 0x00);
	EXPECT_EQ(core->state.hardwareRegisters.TAC, 0xF8);
	EXPECT_EQ(core->state.hardwareRegisters.IF, 0xE1);
	EXPECT_EQ(core->state.hardwareRegisters.NR10, 0x80);
	EXPECT_EQ(core->state.hardwareRegisters.NR11, 0xBF);
	EXPECT_EQ(core->state.hardwareRegisters.NR12, 0xF3);
	EXPECT_EQ(core->state.hardwareRegisters.NR13, 0xFF);
	EXPECT_EQ(core->state.hardwareRegisters.NR14, 0xBF);
	EXPECT_EQ(core->state.hardwareRegisters.NR21, 0x3F);
	EXPECT_EQ(core->state.hardwareRegisters.NR22, 0x00);
	EXPECT_EQ(core->state.hardwareRegisters.NR23, 0xFF);
	EXPECT_EQ(core->state.hardwareRegisters.NR24, 0xBF);
	EXPECT_EQ(core->state.hardwareRegisters.NR30, 0x7F);
	EXPECT_EQ(core->state.hardwareRegisters.NR31, 0xFF);
	EXPECT_EQ(core->state.hardwareRegisters.NR32, 0x9F);
	EXPECT_EQ(core->state.hardwareRegisters.NR33, 0xFF);
	EXPECT_EQ(core->state.hardwareRegisters.NR34, 0xBF);
	EXPECT_EQ(core->state.hardwareRegisters.NR41, 0xFF);
	EXPECT_EQ(core->state.hardwareRegisters.NR42, 0x00);
	EXPECT_EQ(core->state.hardwareRegisters.NR43, 0x00);
	EXPECT_EQ(core->state.hardwareRegisters.NR44, 0xBF);
	EXPECT_EQ(core->state.hardwareRegisters.NR50, 0x77);
	EXPECT_EQ(core->state.hardwareRegisters.NR51, 0xF3);
	EXPECT_EQ(core->state.hardwareRegisters.NR52, 0xF1);
	EXPECT_EQ(core->state.hardwareRegisters.LCDC, 0x91);
	EXPECT_EQ(core->state.hardwareRegisters.STAT, 0x85);
	EXPECT_EQ(core->state.hardwareRegisters.SCY, 0x00);
	EXPECT_EQ(core->state.hardwareRegisters.SCX, 0x00);
	EXPECT_EQ(core->state.hardwareRegisters.LY, 0x00);
	EXPECT_EQ(core->state.hardwareRegisters.LYC, 0x00);
	EXPECT_EQ(core->state.hardwareRegisters.DMA, 0xFF);
	EXPECT_EQ(core->state.hardwareRegisters.BGP, 0xFC);
	EXPECT_EQ(core->state.hardwareRegisters.WY, 0x00);
	EXPECT_EQ(core->state.hardwareRegisters.WX, 0x00);
	EXPECT_EQ(core->state.hardwareRegisters.IE, 0x00);
}

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
