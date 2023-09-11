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
    expectedState = core->state;
    // execute the opcode
    machineCycle();
    expectedState.clockCycles += 4;
    expectedState.registers.pc += 1;
    EXPECT_TRUE(expectedState == core->state);

    core->state.registers.pc = 0xdead;
    core->state.ime = true;
    core->state.mmu.write(LIBGREBE_REG_IE, 0);
    core->state.mmu.write(LIBGREBE_REG_IF, 0xff);
    // injecting opcode at pc
    core->state.mmu.write(core->state.registers.pc, 0x00);
    // saving cpu and memory core->state before executing the opcode
    expectedState = core->state;
    // execute the opcode
    machineCycle();
    expectedState.clockCycles += 4;
    expectedState.registers.pc += 1;
    EXPECT_TRUE(expectedState == core->state);

    core->state.registers.pc = 0xdead;
    core->state.ime = true;
    core->state.mmu.write(LIBGREBE_REG_IE, 0xff);
    core->state.mmu.write(LIBGREBE_REG_IF, 0);
    // injecting opcode at pc
    core->state.mmu.write(core->state.registers.pc, 0x00);
    // saving cpu and memory core->state before executing the opcode
    expectedState = core->state;
    // execute the opcode
    machineCycle();
    expectedState.clockCycles += 4;
    expectedState.registers.pc += 1;
    EXPECT_TRUE(expectedState == core->state);

    core->state.registers.pc = 0xdead;
    core->state.registers.sp = 0xbeef;
    core->state.ime = true;
    core->state.mmu.write(LIBGREBE_REG_IE, 1);
    core->state.mmu.write(LIBGREBE_REG_IF, 1);
    expectedState = core->state;
    machineCycle();
    machineCycle();
    machineCycle();
    machineCycle();
    machineCycle();
    expectedState.clockCycles += 20;
    expectedState.registers.pc = LIBGREBE_INT_VBLANK;
    expectedState.registers.sp = 0xbeef - 2;
    expectedState.ime = false;
    writeWord(expectedState, 0xbeef - 2, 0xdead);
    expectedState.mmu.write(LIBGREBE_REG_IF, 0);
    EXPECT_TRUE(expectedState == core->state);

    core->state.registers.pc = 0xdead;
    core->state.registers.sp = 0xbeef;
    core->state.ime = true;
    core->state.mmu.write(LIBGREBE_REG_IE, 2);
    core->state.mmu.write(LIBGREBE_REG_IF, 2);
    expectedState = core->state;
    machineCycle();
    machineCycle();
    machineCycle();
    machineCycle();
    machineCycle();
    expectedState.clockCycles += 20;
    expectedState.registers.pc = LIBGREBE_INT_STAT;
    expectedState.registers.sp = 0xbeef - 2;
    expectedState.ime = false;
    writeWord(expectedState, 0xbeef - 2, 0xdead);
    expectedState.mmu.write(LIBGREBE_REG_IF, 0);
    EXPECT_TRUE(expectedState == core->state);

    core->state.registers.pc = 0xdead;
    core->state.registers.sp = 0xbeef;
    core->state.ime = true;
    core->state.mmu.write(LIBGREBE_REG_IE, 4);
    core->state.mmu.write(LIBGREBE_REG_IF, 4);
    expectedState = core->state;
    machineCycle();
    machineCycle();
    machineCycle();
    machineCycle();
    machineCycle();
    expectedState.clockCycles += 20;
    expectedState.registers.pc = LIBGREBE_INT_TIMER;
    expectedState.registers.sp = 0xbeef - 2;
    expectedState.ime = false;
    writeWord(expectedState, 0xbeef - 2, 0xdead);
    expectedState.mmu.write(LIBGREBE_REG_IF, 0);
    EXPECT_TRUE(expectedState == core->state);

    core->state.registers.pc = 0xdead;
    core->state.registers.sp = 0xbeef;
    core->state.ime = true;
    core->state.mmu.write(LIBGREBE_REG_IE, 8);
    core->state.mmu.write(LIBGREBE_REG_IF, 8);
    expectedState = core->state;
    machineCycle();
    machineCycle();
    machineCycle();
    machineCycle();
    machineCycle();
    expectedState.clockCycles += 20;
    expectedState.registers.pc = LIBGREBE_INT_SERIAL;
    expectedState.registers.sp = 0xbeef - 2;
    expectedState.ime = false;
    writeWord(expectedState, 0xbeef - 2, 0xdead);
    expectedState.mmu.write(LIBGREBE_REG_IF, 0);
    EXPECT_TRUE(expectedState == core->state);

    core->state.registers.pc = 0xdead;
    core->state.registers.sp = 0xbeef;
    core->state.ime = true;
    core->state.mmu.write(LIBGREBE_REG_IE, 16);
    core->state.mmu.write(LIBGREBE_REG_IF, 16);
    expectedState = core->state;
    machineCycle();
    machineCycle();
    machineCycle();
    machineCycle();
    machineCycle();
    expectedState.clockCycles += 20;
    expectedState.registers.pc = LIBGREBE_INT_JOYPAD;
    expectedState.registers.sp = 0xbeef - 2;
    expectedState.ime = false;
    writeWord(expectedState, 0xbeef - 2, 0xdead);
    expectedState.mmu.write(LIBGREBE_REG_IF, 0);
    EXPECT_TRUE(expectedState == core->state);
}

TEST_F(CoreTest, TestEI)
{
    // 0xFB EI
    // preparing cpu and memory core->state before executing the opcode
    core->state.ime = false;
    core->state.imeScheduled = false;
    // testing the opcode
    // injecting opcode at pc
    core->state.mmu.write(core->state.registers.pc, 0xFB);
    // saving cpu and memory core->state before executing the opcode
    expectedState = core->state;
    machineCycle();
    // expected change in registers and memory
    expectedState.clockCycles += 4;
    expectedState.registers.pc += 1;
    expectedState.imeScheduled = true;
    // comparing expected change to real change
    EXPECT_TRUE(expectedState == core->state);
    // testing the opcode
    core->state.mmu.write(core->state.registers.pc, 0x00);
    expectedState = core->state;
    machineCycle();
    // expected change in registers and memory
    expectedState.clockCycles += 4;
    expectedState.registers.pc += 1;
    expectedState.imeScheduled = false;
    expectedState.ime = true;
    // comparing expected change to real change
    EXPECT_TRUE(expectedState == core->state);
}
