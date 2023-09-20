#include <gtest/gtest.h>
#include <libgrebe/core/mmu/hardware_registers_addressable.hpp>
#include <libgrebe/core/mmu/mmu.test.hpp>
#include <libgrebe/memory_locations.hpp>

TEST_F(MMUTest, HardwareRegistersAddressableTest)
{
    HardwareRegisters hardwareRegisters;
    HardwareRegistersAddressable addressable(hardwareRegisters);
    EXPECT_TRUE(addressable.contains(0xFF00));
    EXPECT_TRUE(addressable.contains(0xFF01));
    EXPECT_TRUE(addressable.contains(0xFF02));
    EXPECT_TRUE(addressable.contains(0xFF04));
    EXPECT_TRUE(addressable.contains(0xFF05));
    EXPECT_TRUE(addressable.contains(0xFF06));
    EXPECT_TRUE(addressable.contains(0xFF07));
    EXPECT_TRUE(addressable.contains(0xFF0F));
    EXPECT_TRUE(addressable.contains(0xFF10));
    EXPECT_TRUE(addressable.contains(0xFF11));
    EXPECT_TRUE(addressable.contains(0xFF12));
    EXPECT_TRUE(addressable.contains(0xFF13));
    EXPECT_TRUE(addressable.contains(0xFF14));
    EXPECT_TRUE(addressable.contains(0xFF16));
    EXPECT_TRUE(addressable.contains(0xFF17));
    EXPECT_TRUE(addressable.contains(0xFF18));
    EXPECT_TRUE(addressable.contains(0xFF19));
    EXPECT_TRUE(addressable.contains(0xFF1A));
    EXPECT_TRUE(addressable.contains(0xFF1B));
    EXPECT_TRUE(addressable.contains(0xFF1C));
    EXPECT_TRUE(addressable.contains(0xFF1D));
    EXPECT_TRUE(addressable.contains(0xFF1E));
    EXPECT_TRUE(addressable.contains(0xFF20));
    EXPECT_TRUE(addressable.contains(0xFF21));
    EXPECT_TRUE(addressable.contains(0xFF22));
    EXPECT_TRUE(addressable.contains(0xFF23));
    EXPECT_TRUE(addressable.contains(0xFF24));
    EXPECT_TRUE(addressable.contains(0xFF25));
    EXPECT_TRUE(addressable.contains(0xFF26));
    EXPECT_TRUE(addressable.contains(0xFF40));
    EXPECT_TRUE(addressable.contains(0xFF41));
    EXPECT_TRUE(addressable.contains(0xFF42));
    EXPECT_TRUE(addressable.contains(0xFF43));
    EXPECT_TRUE(addressable.contains(0xFF44));
    EXPECT_TRUE(addressable.contains(0xFF45));
    EXPECT_TRUE(addressable.contains(0xFF46));
    EXPECT_TRUE(addressable.contains(0xFF47));
    EXPECT_TRUE(addressable.contains(0xFF48));
    EXPECT_TRUE(addressable.contains(0xFF49));
    EXPECT_TRUE(addressable.contains(0xFF4A));
    EXPECT_TRUE(addressable.contains(0xFF4B));
    EXPECT_TRUE(addressable.contains(0xFFFF));
}

TEST_F(MMUTest, HardwareRegistersStandardTest)
{
    // test for normal read/write registers
    HardwareRegisters hardwareRegisters;
    Addressable* addressable = new HardwareRegistersAddressable(hardwareRegisters);
    testReadWrite(hardwareRegisters.SB, LIBGREBE_REG_SB, *addressable);
    testReadWrite(hardwareRegisters.SC, LIBGREBE_REG_SC, *addressable);

    delete addressable;
}

TEST_F(MMUTest, P1Test)
{
    State state;
    Addressable* addressable = new HardwareRegistersAddressable(state.hardwareRegisters);
    state.hardwareRegisters.P1 = 0x69;
    EXPECT_EQ(addressable->read(LIBGREBE_REG_P1), 0x69);
    state.hardwareRegisters.P1 = 0;
    addressable->write(LIBGREBE_REG_P1, 0xff);
    EXPECT_EQ(state.hardwareRegisters.P1, 0xf0);
    delete addressable;
}
