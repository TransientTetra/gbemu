#include <libgrebe/core/mmu/mmu.hpp>
#include <libgrebe/utils.hpp>
#include <memory>

MMU::MMU()
{
}

void MMU::registerAddressable(Addressable& addressable)
{
	addressables.emplace_back(addressable);
}

std::uint8_t MMU::read(std::uint16_t address) const
{
	for (Addressable& item : addressables)
	{
		if (item.contains(address))
		{
			return item.read(address); // return from first applicable addressable
		}
	}
	return defaultRead;
}

void MMU::write(std::uint16_t address, std::uint8_t data)
{
	for (Addressable& item : addressables)
	{
		if (item.contains(address))
		{
			item.write(address, data);
			return; // only write on first eligible addressable
		}
	}
}
