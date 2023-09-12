#ifndef LIBGREBE_COMMON_TEST_HPP
#define LIBGREBE_COMMON_TEST_HPP

#include <libgrebe/state.hpp>
#include <iostream>

void writeWord(State& state, const Word& address, const Word& data);

void copyMem(MMU& dst, MMU& src);

bool compareMem(const MMU& mem1, const MMU& mem2);

void copyState(State& dst, State& src);

bool compareState(const State& state1, const State& state2);

#endif // LIBGREBE_CPU_TEST_HPP
