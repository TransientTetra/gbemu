#include <libgrebe/core/mmu/mmu.hpp>
#include <libgrebe/utils.hpp>
#include <memory>

MMU::MMU()
{
}

void MMU::registerAddressable(std::unique_ptr<Addressable> addressable)
{
	addressables.emplace_back(std::move(addressable));
}

Byte MMU::read(Word address) const
{
	for (auto&& item : addressables)
	{
		if (item->contains(address))
		{
			return item->read(address); // return from first applicable addressable
		}
	}
	return defaultRead;
}

void MMU::write(Word address, Byte data)
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
