#include <gtest/gtest.h>
#include <libgrebe/core/cpu/timer.test.hpp>

// FF04 — DIV: Divider register
// This register is incremented at a rate of 16384Hz (~16779Hz on SGB). Writing any value to this register resets it
// to $00. Additionally, this register is reset when executing the stop instruction, and only begins ticking again
// once stop mode ends. This also occurs during a speed switch. (TODO: how is it affected by the wait after a speed
// switch?) Note: The divider is affected by CGB double speed mode, and will increment at 32768Hz in double speed.
// FF05 — TIMA: Timer counter
// This timer is incremented at the clock frequency specified by the TAC register ($FF07).
// When the value overflows (exceeds $FF) it is reset to the value specified in TMA (FF06) and an interrupt is
// requested, as described below.
//
// FF06 — TMA: Timer modulo
// When TIMA overflows, it is reset to the value in this register and an interrupt is requested.
// Example of use: if TMA is set to $FF, an interrupt is requested at the clock frequency selected in TAC (because
// every increment is an overflow). However, if TMA is set to $FE, an interrupt is only requested every two
// increments, which effectively divides the selected clock by two. Setting TMA to $FD would divide the clock by
// three, and so on. If a TMA write is executed on the same cycle as the content of TMA is transferred to TIMA due
// to a timer overflow, the old value is transferred to TIMA.
//
// FF07 — TAC: Timer control
// Bit  2   - Timer Enable
// Bits 1-0 - Input Clock Select
// 00: timer->Clock / 1024 (DMG, SGB2, CGB Single Speed Mode:   4096 Hz, SGB1:   ~4194 Hz, CGB Double Speed Mode:
// 8192Hz)
// 01: timer->Clock / 16   (DMG, SGB2, CGB Single Speed Mode: 262144 Hz, SGB1: ~268400 Hz, CGB Double Speed
// Mode: 524288 Hz)
// 10: timer->Clock / 64   (DMG, SGB2, CGB Single Speed Mode:  65536 Hz, SGB1:  ~67110 Hz, CGB Double
// Speed Mode: 131072 Hz)
// 11: timer->Clock / 256  (DMG, SGB2, CGB Single Speed Mode:  16384 Hz, SGB1:  ~16780 Hz, CGB
// Double Speed Mode: 32768 Hz)

TEST_F(TimerTest, DIVTest)
{
	// todo add stop mode test once stop implemented in cpu
	mmu.write(LIBGREBE_REG_DIV, 0);
	EXPECT_EQ(mmu.read(LIBGREBE_REG_DIV), 0);
	for (state.clockCycles = 0; state.clockCycles < 256; ++state.clockCycles)
	{
		EXPECT_EQ(mmu.read(LIBGREBE_REG_DIV), 0);
		timer->tick();
	}
	EXPECT_EQ(mmu.read(LIBGREBE_REG_DIV), 1);
	for (state.clockCycles = 0; state.clockCycles < 256; ++state.clockCycles)
	{
		EXPECT_EQ(mmu.read(LIBGREBE_REG_DIV), 1);
		timer->tick();
	}
	EXPECT_EQ(mmu.read(LIBGREBE_REG_DIV), 2);
	for (state.clockCycles = 0; state.clockCycles < 256; ++state.clockCycles)
	{
		EXPECT_EQ(mmu.read(LIBGREBE_REG_DIV), 2);
		timer->tick();
	}
	EXPECT_EQ(mmu.read(LIBGREBE_REG_DIV), 3);

	for (state.clockCycles = 0; state.clockCycles < 256 * 253; ++state.clockCycles)
		timer->tick();
	EXPECT_EQ(mmu.read(LIBGREBE_REG_DIV), 0);
}

TEST_F(TimerTest, TIMATACTest)
{
	// tests TAC turning TIMA on and off and different TAC frequency settings
	mmu.write(LIBGREBE_REG_TMA, 0);

	mmu.write(LIBGREBE_REG_TIMA, 0);
	mmu.write(LIBGREBE_REG_TAC, 0); // disable TAC
	mmu.write(LIBGREBE_REG_DIV, 0);
	for (state.clockCycles = 0; state.clockCycles < 1024; ++state.clockCycles)
	{
		timer->tick();
		EXPECT_EQ(mmu.read(LIBGREBE_REG_TIMA), 0);
	}

	mmu.write(LIBGREBE_REG_TIMA, 0);
	mmu.write(LIBGREBE_REG_TAC, 0b00000100); // enable TAC, freq timer->Clock / 1024
	mmu.write(LIBGREBE_REG_DIV, 0);
	state.clockCycles = 0;
	for (int i = 0; i < 1024 - 1; ++i, ++state.clockCycles)
	{
		timer->tick();
		EXPECT_EQ(mmu.read(LIBGREBE_REG_TIMA), 0);
	}
	timer->tick();
	EXPECT_EQ(mmu.read(LIBGREBE_REG_TIMA), 1);
	++state.clockCycles;
	for (int i = 0; i < 1024 - 1; ++i, ++state.clockCycles)
	{
		timer->tick();
		EXPECT_EQ(mmu.read(LIBGREBE_REG_TIMA), 1);
	}
	timer->tick();
	EXPECT_EQ(mmu.read(LIBGREBE_REG_TIMA), 2);

	mmu.write(LIBGREBE_REG_TIMA, 0);
	mmu.write(LIBGREBE_REG_TAC, 0b00000101); // enable TAC, freq timer->Clock / 16
	mmu.write(LIBGREBE_REG_DIV, 0);
	state.clockCycles = 0;
	for (int i = 0; i < 16 - 1; ++i, ++state.clockCycles)
	{
		timer->tick();
		EXPECT_EQ(mmu.read(LIBGREBE_REG_TIMA), 0);
	}
	timer->tick();
	EXPECT_EQ(mmu.read(LIBGREBE_REG_TIMA), 1);
	++state.clockCycles;
	for (int i = 0; i < 16 - 1; ++i, ++state.clockCycles)
	{
		timer->tick();
		EXPECT_EQ(mmu.read(LIBGREBE_REG_TIMA), 1);
	}
	timer->tick();
	EXPECT_EQ(mmu.read(LIBGREBE_REG_TIMA), 2);

	mmu.write(LIBGREBE_REG_TIMA, 0);
	mmu.write(LIBGREBE_REG_TAC, 0b00000110); // enable TAC, freq timer->Clock / 64
	mmu.write(LIBGREBE_REG_DIV, 0);
	state.clockCycles = 0;
	for (int i = 0; i < 64 - 1; ++i, ++state.clockCycles)
	{
		timer->tick();
		EXPECT_EQ(mmu.read(LIBGREBE_REG_TIMA), 0);
	}
	timer->tick();
	EXPECT_EQ(mmu.read(LIBGREBE_REG_TIMA), 1);
	++state.clockCycles;
	for (int i = 0; i < 64 - 1; ++i, ++state.clockCycles)
	{
		timer->tick();
		EXPECT_EQ(mmu.read(LIBGREBE_REG_TIMA), 1);
	}
	timer->tick();
	EXPECT_EQ(mmu.read(LIBGREBE_REG_TIMA), 2);

	mmu.write(LIBGREBE_REG_TIMA, 0);
	mmu.write(LIBGREBE_REG_TAC, 0b00000111); // enable TAC, freq timer->Clock / 256
	mmu.write(LIBGREBE_REG_DIV, 0);
	state.clockCycles = 0;
	for (int i = 0; i < 256 - 1; ++i, ++state.clockCycles)
	{
		timer->tick();
		EXPECT_EQ(mmu.read(LIBGREBE_REG_TIMA), 0);
	}
	timer->tick();
	EXPECT_EQ(mmu.read(LIBGREBE_REG_TIMA), 1);
	++state.clockCycles;
	for (int i = 0; i < 256 - 1; ++i, ++state.clockCycles)
	{
		timer->tick();
		EXPECT_EQ(mmu.read(LIBGREBE_REG_TIMA), 1);
	}
	timer->tick();
	EXPECT_EQ(mmu.read(LIBGREBE_REG_TIMA), 2);

	// todo timer behaviour is far more complex than this, implement tests for that
}

TEST_F(TimerTest, TMATest)
{
	// tests TMA TIMA interaction
	// NOTE: interrupt is requested on TIMA overflow
	// Every time that the timer overflows (that is, when TIMA exceeds $FF), an interrupt is requested by setting bit 2
	// in the IF register ($FF0F). As soon as that interrupt is enabled, the CPU will execute it by calling the timer
	// interrupt vector at $0050.

	// todo timer behaviour is far more complex than this, implement tests for that
	mmu.write(LIBGREBE_REG_TAC, 0b00000100); // enable TAC, freq timer->Clock / 1024
	mmu.write(LIBGREBE_REG_TMA, 0x69);
	mmu.write(LIBGREBE_REG_TIMA, 0xff);
	mmu.write(LIBGREBE_REG_IF, 0);
	mmu.write(LIBGREBE_REG_DIV, 0);
	state.clockCycles = 0;
	for (int i = 0; i < 1024 - 1; ++i, ++state.clockCycles)
	{
		timer->tick();
		EXPECT_EQ(mmu.read(LIBGREBE_REG_TIMA), 0xff);
		EXPECT_EQ(mmu.read(LIBGREBE_REG_IF), 0);
	}
	timer->tick();
	EXPECT_EQ(mmu.read(LIBGREBE_REG_TIMA), 0x69);
	EXPECT_EQ(mmu.read(LIBGREBE_REG_IF), 0b00000100);
}
