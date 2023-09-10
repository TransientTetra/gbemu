#include <libgrebe/core/mmu/mmu.hpp>
#include <libgrebe/utils.hpp>
#include <memory>

void MMU::registerAddressable(std::unique_ptr<Addressable> addressable)
{
    addressables.emplace_back(std::move(addressable));
}

Byte MMU::read(const Word& address) const
{
    for (auto&& item : addressables)
    {
        if (item->contains(address))
        {
            return item->read(address); // return from first applicable addressable
        }
    }
    return 0xff;
}

void MMU::write(const Word& address, const Byte& data)
{
    for (auto&& item : addressables)
    {
        if (item->contains(address))
        {
            item->write(address, data);
            return; // only write on first eligible addressable
        }
    }
}

bool MMU::operator==(const MMU& other) const
{
    for (int i = 0; i < LIBGREBE_MEMORY_SIZE; ++i)
    {
        if (read(i) != other.read(i))
            return false;
    }
    return true;
}

MMU& MMU::operator=(const MMU& other) // NOLINT(bugprone-unhandled-self-assignment)
{
    for (int i = 0; i < LIBGREBE_MEMORY_SIZE; ++i)
    {
        write(i, other.read(i)); // this can have unexpected results since writes can affect state
    }
    return *this;
}
