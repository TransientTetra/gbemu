#include <gtest/gtest.h>
#include <libgrebe/core/common.test.hpp>
#include <libgrebe/core/core.test.hpp>

TEST_F(CoreTest, DMGInitTest)
{
	// https://gbdev.io/pandocs/Power_Up_Sequence.html#console-state-after-boot-rom-hand-off
	// test checking state after bootrom handoff
	EXPECT_EQ(core.state.registers.getA(), 0x01);
	EXPECT_EQ(core.state.registers.getB(), 0x00);
	EXPECT_EQ(core.state.registers.getC(), 0x13);
	EXPECT_EQ(core.state.registers.getD(), 0x00);
	EXPECT_EQ(core.state.registers.getE(), 0xd8);
	EXPECT_EQ(core.state.registers.getH(), 0x01);
	EXPECT_EQ(core.state.registers.getL(), 0x4d);
	EXPECT_EQ(core.state.registers.getPC(), 0x100);
	EXPECT_EQ(core.state.registers.getSP(), 0xfffe);
	EXPECT_EQ(core.state.registers.getZeroFlag(), 1);
	EXPECT_EQ(core.state.registers.getSubtractFlag(), 0);
	EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_P1), 0xCF);
	EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_SB), 0x00);
	EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_SC), 0x7E);
	EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_DIV), 0xAB);
	EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_TIMA), 0x00);
	EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_TMA), 0x00);
	EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_TAC), 0xF8);
	EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_IF), 0xE1);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_NR10), 0x80);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_NR11), 0xBF);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_NR12), 0xF3);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_NR13), 0xFF);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_NR14), 0xBF);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_NR21), 0x3F);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_NR22), 0x00);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_NR23), 0xFF);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_NR24), 0xBF);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_NR30), 0x7F);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_NR31), 0xFF);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_NR32), 0x9F);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_NR33), 0xFF);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_NR34), 0xBF);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_NR41), 0xFF);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_NR42), 0x00);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_NR43), 0x00);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_NR44), 0xBF);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_NR50), 0x77);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_NR51), 0xF3);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_NR52), 0xF1);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_LCDC), 0x91);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_STAT), 0x85);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_SCY), 0x00);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_SCX), 0x00);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_LY), 0x00);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_LYC), 0x00);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_DMA), 0xFF);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_BGP), 0xFC);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_WY), 0x00);
	// EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_WX), 0x00);
	EXPECT_EQ(core.state.mmu.read(LIBGREBE_REG_IE), 0x00);
}

TEST_F(CoreTest, InterruptsTest)
{
	core.state.registers.setPC(0xdead);
	core.state.ime = false;
	core.state.mmu.write(LIBGREBE_REG_IE, 0xff);
	core.state.mmu.write(LIBGREBE_REG_IF, 0xff);
	// injecting opcode at pc
	core.state.mmu.write(core.state.registers.getPC(), 0x00);
	// saving cpu and memory core.state before executing the opcode
	copyState(expectedCore.state, core.state);
	// execute the opcode
	machineCycle();
	expectedCore.state.clockCycles += 4;
	expectedCore.state.registers.incPC();
	EXPECT_TRUE(compareState(expectedCore.state, core.state));

	core.state.registers.setPC(0xdead);
	core.state.ime = true;
	core.state.mmu.write(LIBGREBE_REG_IE, 0);
	core.state.mmu.write(LIBGREBE_REG_IF, 0xff);
	// injecting opcode at pc
	core.state.mmu.write(core.state.registers.getPC(), 0x00);
	// saving cpu and memory core.state before executing the opcode
	copyState(expectedCore.state, core.state);
	// execute the opcode
	machineCycle();
	expectedCore.state.clockCycles += 4;
	expectedCore.state.registers.incPC();
	EXPECT_TRUE(compareState(expectedCore.state, core.state));

	core.state.registers.setPC(0xdead);
	core.state.ime = true;
	core.state.mmu.write(LIBGREBE_REG_IE, 0xff);
	core.state.mmu.write(LIBGREBE_REG_IF, 0);
	// injecting opcode at pc
	core.state.mmu.write(core.state.registers.getPC(), 0x00);
	// saving cpu and memory core.state before executing the opcode
	copyState(expectedCore.state, core.state);
	// execute the opcode
	machineCycle();
	expectedCore.state.clockCycles += 4;
	expectedCore.state.registers.incPC();
	EXPECT_TRUE(compareState(expectedCore.state, core.state));

	core.state.registers.setPC(0xdead);
	core.state.registers.setSP(0xbeef);
	core.state.ime = true;
	core.state.mmu.write(LIBGREBE_REG_IE, 1);
	core.state.mmu.write(LIBGREBE_REG_IF, 1);
	copyState(expectedCore.state, core.state);
	machineCycle();
	machineCycle();
	machineCycle();
	machineCycle();
	machineCycle();
	expectedCore.state.clockCycles += 20;
	expectedCore.state.registers.setPC(LIBGREBE_INT_VBLANK);
	expectedCore.state.registers.setSP(0xbeef - 2);
	expectedCore.state.ime = false;
	writeWord(expectedCore.state, 0xbeef - 2, 0xdead);
	expectedCore.state.mmu.write(LIBGREBE_REG_IF, 0);
	EXPECT_TRUE(compareState(expectedCore.state, core.state));

	core.state.registers.setPC(0xdead);
	core.state.registers.setSP(0xbeef);
	core.state.ime = true;
	core.state.mmu.write(LIBGREBE_REG_IE, 2);
	core.state.mmu.write(LIBGREBE_REG_IF, 2);
	copyState(expectedCore.state, core.state);
	machineCycle();
	machineCycle();
	machineCycle();
	machineCycle();
	machineCycle();
	expectedCore.state.clockCycles += 20;
	expectedCore.state.registers.setPC(LIBGREBE_INT_STAT);
	expectedCore.state.registers.setSP(0xbeef - 2);
	expectedCore.state.ime = false;
	writeWord(expectedCore.state, 0xbeef - 2, 0xdead);
	expectedCore.state.mmu.write(LIBGREBE_REG_IF, 0);
	EXPECT_TRUE(compareState(expectedCore.state, core.state));

	core.state.registers.setPC(0xdead);
	core.state.registers.setSP(0xbeef);
	core.state.ime = true;
	core.state.mmu.write(LIBGREBE_REG_IE, 4);
	core.state.mmu.write(LIBGREBE_REG_IF, 4);
	copyState(expectedCore.state, core.state);
	machineCycle();
	machineCycle();
	machineCycle();
	machineCycle();
	machineCycle();
	expectedCore.state.clockCycles += 20;
	expectedCore.state.registers.setPC(LIBGREBE_INT_TIMER);
	expectedCore.state.registers.setSP(0xbeef - 2);
	expectedCore.state.ime = false;
	writeWord(expectedCore.state, 0xbeef - 2, 0xdead);
	expectedCore.state.mmu.write(LIBGREBE_REG_IF, 0);
	EXPECT_TRUE(compareState(expectedCore.state, core.state));

	core.state.registers.setPC(0xdead);
	core.state.registers.setSP(0xbeef);
	core.state.ime = true;
	core.state.mmu.write(LIBGREBE_REG_IE, 8);
	core.state.mmu.write(LIBGREBE_REG_IF, 8);
	copyState(expectedCore.state, core.state);
	machineCycle();
	machineCycle();
	machineCycle();
	machineCycle();
	machineCycle();
	expectedCore.state.clockCycles += 20;
	expectedCore.state.registers.setPC(LIBGREBE_INT_SERIAL);
	expectedCore.state.registers.setSP(0xbeef - 2);
	expectedCore.state.ime = false;
	writeWord(expectedCore.state, 0xbeef - 2, 0xdead);
	expectedCore.state.mmu.write(LIBGREBE_REG_IF, 0);
	EXPECT_TRUE(compareState(expectedCore.state, core.state));

	core.state.registers.setPC(0xdead);
	core.state.registers.setSP(0xbeef);
	core.state.ime = true;
	core.state.mmu.write(LIBGREBE_REG_IE, 16);
	core.state.mmu.write(LIBGREBE_REG_IF, 16);
	copyState(expectedCore.state, core.state);
	machineCycle();
	machineCycle();
	machineCycle();
	machineCycle();
	machineCycle();
	expectedCore.state.clockCycles += 20;
	expectedCore.state.registers.setPC(LIBGREBE_INT_JOYPAD);
	expectedCore.state.registers.setSP(0xbeef - 2);
	expectedCore.state.ime = false;
	writeWord(expectedCore.state, 0xbeef - 2, 0xdead);
	expectedCore.state.mmu.write(LIBGREBE_REG_IF, 0);
	EXPECT_TRUE(compareState(expectedCore.state, core.state));
}

TEST_F(CoreTest, TestEI)
{
	// 0xFB EI
	// preparing cpu and memory core.state before executing the opcode
	core.state.registers.setPC(0xdead);
	core.state.ime = false;
	core.state.imeScheduled = false;
	// testing the opcode
	// injecting opcode at pc
	core.state.mmu.write(core.state.registers.getPC(), 0xFB);
	// saving cpu and memory core.state before executing the opcode
	copyState(expectedCore.state, core.state);
	machineCycle();
	// expected change in registers and memory
	expectedCore.state.clockCycles += 4;
	expectedCore.state.registers.incPC();
	expectedCore.state.imeScheduled = true;
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedCore.state, core.state));
	// testing the opcode
	core.state.mmu.write(core.state.registers.getPC(), 0x00);
	copyState(expectedCore.state, core.state);
	machineCycle();
	// expected change in registers and memory
	expectedCore.state.clockCycles += 4;
	expectedCore.state.registers.incPC();
	expectedCore.state.imeScheduled = false;
	expectedCore.state.ime = true;
	// comparing expected change to real change
	EXPECT_TRUE(compareState(expectedCore.state, core.state));
}
