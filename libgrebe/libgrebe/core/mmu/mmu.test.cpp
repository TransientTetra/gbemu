#include <gtest/gtest.h>
#include <libgrebe/core/mmu/bootrom.hpp>
#include <libgrebe/core/mmu/hardware_registers_addressable.hpp>
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
    EXPECT_EQ(addressable->contains(0xff50), true);
    EXPECT_EQ(addressable->read(0xff50), 0);
    addressable->write(0xff50, 1);
    for (Word i = 0; i < LIBGREBE_MEMORY_SIZE - 1; ++i)
    {
        EXPECT_EQ(addressable->contains(i), false);
    }
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
