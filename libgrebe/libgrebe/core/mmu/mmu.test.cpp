#include <gtest/gtest.h>
#include <libgrebe/core/mmu/mmu.hpp>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconstant-conversion"
class MMUTest : public ::testing::Test
{
protected:
    MMU mmu{};
    void SetUp() override
    {
    }
    void TearDown() override
    {
    }
};

TEST_F(MMUTest, ReadWriteWholeTest)
{
    // for (int i = 0; i < LIBGREBE_MEMORY_SIZE; ++i)
    // {
    //     ASSERT_NO_THROW(mmu.write(i, i));
    // }
    // for (int i = 0; i < LIBGREBE_MEMORY_SIZE; ++i)
    // {
    //     ASSERT_NO_THROW(EXPECT_EQ(mmu.read(i), static_cast<Byte>(i)));
    // }
}

#pragma clang diagnostic pop
