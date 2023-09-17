#include <gtest/gtest.h>
#include <libgrebe/core/mmu/bootrom.hpp>
#include <libgrebe/core/mmu/hardware_registers.hpp>
#include <libgrebe/core/mmu/hram.hpp>
#include <libgrebe/core/mmu/mmu.test.hpp>
#include <libgrebe/core/mmu/vram.hpp>
#include <memory>

TEST_F(MMUTest, RegisterAddressableTest)
{
    EXPECT_EQ(mmu.addressables.size(), 0);
    for (int i = 0; i < 256; ++i)
    {
        EXPECT_EQ(mmu.addressables.size(), i);
        mmu.registerAddressable(std::make_unique<FakeAddressable>(16));
    }
}

TEST_F(MMUTest, MMUReadsWritesTest)
{
    EXPECT_EQ(mmu.read(0), 0xff);
    EXPECT_EQ(mmu.read(16), 0xff);
    mmu.registerAddressable(std::make_unique<FakeAddressable>(16));
    Word rangeStart = 0;
    Word rangeEnd = 16;
    for (Word i = rangeStart; i < rangeEnd; ++i)
    {
        mmu.write(i, 0x69);
    }
    for (Word i = 0; i < LIBGREBE_MEMORY_SIZE - 1; ++i)
    {
        if (i >= rangeStart && i < rangeEnd)
            EXPECT_EQ(mmu.read(i), 0x69);
        else
            EXPECT_EQ(mmu.read(i), 0xff);
    }
    EXPECT_EQ(mmu.read(16), 0xff);
}

TEST_F(MMUTest, BootromTest)
{
    Addressable* addressable = new Bootrom();
    testContains(*addressable, 0x00, 0xff);
    testReadWrite(*addressable, 0x00, 0xff);
}

TEST_F(MMUTest, HRAMTest)
{
    Addressable* addressable = new HRAM();
    testContains(*addressable, 0xff80, 0xffe);
    testReadWrite(*addressable, 0xff80, 0xffe);
}

TEST_F(MMUTest, VRAMTest)
{
    Addressable* addressable = new VRAM();
    testContains(*addressable, 0x8000, 0x9fff);
    testReadWrite(*addressable, 0x8000, 0x9fff);
}

TEST_F(MMUTest, HardwareRegistersTest)
{
    // todo write more hardware registers test when more functionality finalized
    Addressable* addressable = new HardwareRegisters();
    EXPECT_TRUE(addressable->contains(0xFF00));
    EXPECT_TRUE(addressable->contains(0xFF01));
    EXPECT_TRUE(addressable->contains(0xFF02));
    EXPECT_TRUE(addressable->contains(0xFF04));
    EXPECT_TRUE(addressable->contains(0xFF05));
    EXPECT_TRUE(addressable->contains(0xFF06));
    EXPECT_TRUE(addressable->contains(0xFF07));
    EXPECT_TRUE(addressable->contains(0xFF0F));
    EXPECT_TRUE(addressable->contains(0xFF10));
    EXPECT_TRUE(addressable->contains(0xFF11));
    EXPECT_TRUE(addressable->contains(0xFF12));
    EXPECT_TRUE(addressable->contains(0xFF13));
    EXPECT_TRUE(addressable->contains(0xFF14));
    EXPECT_TRUE(addressable->contains(0xFF16));
    EXPECT_TRUE(addressable->contains(0xFF17));
    EXPECT_TRUE(addressable->contains(0xFF18));
    EXPECT_TRUE(addressable->contains(0xFF19));
    EXPECT_TRUE(addressable->contains(0xFF1A));
    EXPECT_TRUE(addressable->contains(0xFF1B));
    EXPECT_TRUE(addressable->contains(0xFF1C));
    EXPECT_TRUE(addressable->contains(0xFF1D));
    EXPECT_TRUE(addressable->contains(0xFF1E));
    EXPECT_TRUE(addressable->contains(0xFF20));
    EXPECT_TRUE(addressable->contains(0xFF21));
    EXPECT_TRUE(addressable->contains(0xFF22));
    EXPECT_TRUE(addressable->contains(0xFF23));
    EXPECT_TRUE(addressable->contains(0xFF24));
    EXPECT_TRUE(addressable->contains(0xFF25));
    EXPECT_TRUE(addressable->contains(0xFF26));
    EXPECT_TRUE(addressable->contains(0xFF40));
    EXPECT_TRUE(addressable->contains(0xFF41));
    EXPECT_TRUE(addressable->contains(0xFF42));
    EXPECT_TRUE(addressable->contains(0xFF43));
    EXPECT_TRUE(addressable->contains(0xFF44));
    EXPECT_TRUE(addressable->contains(0xFF45));
    EXPECT_TRUE(addressable->contains(0xFF46));
    EXPECT_TRUE(addressable->contains(0xFF47));
    EXPECT_TRUE(addressable->contains(0xFF48));
    EXPECT_TRUE(addressable->contains(0xFF49));
    EXPECT_TRUE(addressable->contains(0xFF4A));
    EXPECT_TRUE(addressable->contains(0xFF4B));
    EXPECT_TRUE(addressable->contains(0xFFFF));
}
