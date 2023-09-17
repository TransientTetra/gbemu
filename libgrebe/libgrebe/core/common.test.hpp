#ifndef LIBGREBE_COMMON_TEST_HPP
#define LIBGREBE_COMMON_TEST_HPP

#include <iostream>
#include <libgrebe/state.hpp>

class FakeAddressable : public Addressable
{
private:
    std::vector<Byte> mem;
    size_t size;

public:
    FakeAddressable()
    {
        size = LIBGREBE_MEMORY_SIZE;
        mem.resize(LIBGREBE_MEMORY_SIZE);
    }
    FakeAddressable(Word size)
    {
        this->size = size;
        mem.resize(size);
    }
    virtual bool contains(const Word& address) const override
    {
        return address < size;
    }
    virtual const Byte& read(const Word& address) const override
    {
        return mem[address];
    }
    virtual void write(const Word& address, const Byte& data) override
    {
        mem[address] = data;
    }
};

void writeWord(State& state, const Word& address, const Word& data);

void copyMem(MMU& dst, MMU& src);

bool compareMem(const MMU& mem1, const MMU& mem2);

void copyState(State& dst, State& src);

bool compareState(const State& state1, const State& state2);

#endif // LIBGREBE_CPU_TEST_HPP
