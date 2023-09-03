#include <libgrebe/core/core.test.hpp>

TEST_F(CoreTest, InterruptsTest)
{
    state.registers.pc = 0xdead;
    state.ime = false;
    state.mmu.write(LIBGREBE_REG_IE, 0xff);
    state.mmu.write(LIBGREBE_REG_IF, 0xff);
    // injecting opcode at pc
    state.mmu.write(state.registers.pc, 0x00);
    // saving cpu and memory state before executing the opcode
    expectedState = state;
    // execute the opcode
    machineCycle();
    expectedState.clockCycles += 4;
    expectedState.registers.pc += 1;
    EXPECT_TRUE(expectedState == state);

    state.registers.pc = 0xdead;
    state.ime = true;
    state.mmu.write(LIBGREBE_REG_IE, 0);
    state.mmu.write(LIBGREBE_REG_IF, 0xff);
    // injecting opcode at pc
    state.mmu.write(state.registers.pc, 0x00);
    // saving cpu and memory state before executing the opcode
    expectedState = state;
    // execute the opcode
    machineCycle();
    expectedState.clockCycles += 4;
    expectedState.registers.pc += 1;
    EXPECT_TRUE(expectedState == state);

    state.registers.pc = 0xdead;
    state.ime = true;
    state.mmu.write(LIBGREBE_REG_IE, 0xff);
    state.mmu.write(LIBGREBE_REG_IF, 0);
    // injecting opcode at pc
    state.mmu.write(state.registers.pc, 0x00);
    // saving cpu and memory state before executing the opcode
    expectedState = state;
    // execute the opcode
    machineCycle();
    expectedState.clockCycles += 4;
    expectedState.registers.pc += 1;
    EXPECT_TRUE(expectedState == state);

    state.registers.pc = 0xdead;
    state.registers.sp = 0xbeef;
    state.ime = true;
    state.mmu.write(LIBGREBE_REG_IE, 1);
    state.mmu.write(LIBGREBE_REG_IF, 1);
    expectedState = state;
    machineCycle();
    machineCycle();
    machineCycle();
    machineCycle();
    machineCycle();
    expectedState.clockCycles += 20;
    expectedState.registers.pc = LIBGREBE_INT_VBLANK;
    expectedState.registers.sp = 0xbeef - 2;
    expectedState.ime = false;
    expectedState.mmu.writeWord(0xbeef - 2, 0xdead);
    expectedState.mmu.write(LIBGREBE_REG_IF, 0);
    EXPECT_TRUE(expectedState == state);

    state.registers.pc = 0xdead;
    state.registers.sp = 0xbeef;
    state.ime = true;
    state.mmu.write(LIBGREBE_REG_IE, 2);
    state.mmu.write(LIBGREBE_REG_IF, 2);
    expectedState = state;
    machineCycle();
    machineCycle();
    machineCycle();
    machineCycle();
    machineCycle();
    expectedState.clockCycles += 20;
    expectedState.registers.pc = LIBGREBE_INT_STAT;
    expectedState.registers.sp = 0xbeef - 2;
    expectedState.ime = false;
    expectedState.mmu.writeWord(0xbeef - 2, 0xdead);
    expectedState.mmu.write(LIBGREBE_REG_IF, 0);
    EXPECT_TRUE(expectedState == state);

    state.registers.pc = 0xdead;
    state.registers.sp = 0xbeef;
    state.ime = true;
    state.mmu.write(LIBGREBE_REG_IE, 4);
    state.mmu.write(LIBGREBE_REG_IF, 4);
    expectedState = state;
    machineCycle();
    machineCycle();
    machineCycle();
    machineCycle();
    machineCycle();
    expectedState.clockCycles += 20;
    expectedState.registers.pc = LIBGREBE_INT_TIMER;
    expectedState.registers.sp = 0xbeef - 2;
    expectedState.ime = false;
    expectedState.mmu.writeWord(0xbeef - 2, 0xdead);
    expectedState.mmu.write(LIBGREBE_REG_IF, 0);
    EXPECT_TRUE(expectedState == state);

    state.registers.pc = 0xdead;
    state.registers.sp = 0xbeef;
    state.ime = true;
    state.mmu.write(LIBGREBE_REG_IE, 8);
    state.mmu.write(LIBGREBE_REG_IF, 8);
    expectedState = state;
    machineCycle();
    machineCycle();
    machineCycle();
    machineCycle();
    machineCycle();
    expectedState.clockCycles += 20;
    expectedState.registers.pc = LIBGREBE_INT_SERIAL;
    expectedState.registers.sp = 0xbeef - 2;
    expectedState.ime = false;
    expectedState.mmu.writeWord(0xbeef - 2, 0xdead);
    expectedState.mmu.write(LIBGREBE_REG_IF, 0);
    EXPECT_TRUE(expectedState == state);

    state.registers.pc = 0xdead;
    state.registers.sp = 0xbeef;
    state.ime = true;
    state.mmu.write(LIBGREBE_REG_IE, 16);
    state.mmu.write(LIBGREBE_REG_IF, 16);
    expectedState = state;
    machineCycle();
    machineCycle();
    machineCycle();
    machineCycle();
    machineCycle();
    expectedState.clockCycles += 20;
    expectedState.registers.pc = LIBGREBE_INT_JOYPAD;
    expectedState.registers.sp = 0xbeef - 2;
    expectedState.ime = false;
    expectedState.mmu.writeWord(0xbeef - 2, 0xdead);
    expectedState.mmu.write(LIBGREBE_REG_IF, 0);
    EXPECT_TRUE(expectedState == state);
}

TEST_F(CoreTest, TestEI)
{
    // 0xFB EI
    // preparing cpu and memory state before executing the opcode
    state.ime = false;
    state.imeScheduled = false;
    // testing the opcode
    // injecting opcode at pc
    state.mmu.write(state.registers.pc, 0xFB);
    // saving cpu and memory state before executing the opcode
    expectedState = state;
    machineCycle();
    // expected change in registers and memory
    expectedState.clockCycles += 4;
    expectedState.registers.pc += 1;
    expectedState.imeScheduled = true;
    // comparing expected change to real change
    EXPECT_TRUE(expectedState == state);
    // testing the opcode
    state.mmu.write(state.registers.pc, 0x00);
    expectedState = state;
    machineCycle();
    // expected change in registers and memory
    expectedState.clockCycles += 4;
    expectedState.registers.pc += 1;
    expectedState.imeScheduled = false;
    expectedState.ime = true;
    // comparing expected change to real change
    EXPECT_TRUE(expectedState == state);
}
