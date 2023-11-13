#ifndef LIBGREBE_COMMON_TEST_HPP
#define LIBGREBE_COMMON_TEST_HPP

#include <iostream>
#include <libgrebe/state.hpp>

class FakeAddressable : public Addressable
{
private:
	std::vector<std::uint8_t> mem;
	size_t size;

public:
	FakeAddressable()
	{
		size = LIBGREBE_MEMORY_SIZE;
		mem.resize(LIBGREBE_MEMORY_SIZE);
	}
	FakeAddressable(std::uint16_t size)
	{
		this->size = size;
		mem.resize(size);
	}
	virtual bool contains(std::uint16_t address) const override
	{
		return address < size;
	}
	virtual std::uint8_t read(std::uint16_t address) const override
	{
		return mem[address];
	}
	virtual void write(std::uint16_t address, std::uint8_t data) override
	{
		mem[address] = data;
	}
};

void writeWord(State& state, const std::uint16_t& address, const std::uint16_t& data);

void copyMem(MMU& dst, MMU& src);

bool compareMem(const MMU& mem1, const MMU& mem2);

void copyState(State& dst, State& src);

bool compareState(const State& state1, const State& state2);

#endif // LIBGREBE_CPU_TEST_HPP
