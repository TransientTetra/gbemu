#ifndef LIBGREBE_STATE_HPP
#define LIBGREBE_STATE_HPP

#include <cstdint>
#include <functional>
#include <libgrebe/core/cpu/registers.hpp>
#include <libgrebe/core/mmu/bootrom.hpp>
#include <libgrebe/core/mmu/hardware_registers.hpp>
#include <libgrebe/core/mmu/hram.hpp>
#include <libgrebe/core/mmu/mmu.hpp>
#include <libgrebe/core/mmu/vram.hpp>
#include <libgrebe/core/mmu/wram.hpp>
#include <queue>
#include <stack>

enum CPUState
{
	FETCH,
	EXECUTE,
	STOP,
	HALT,
	HALT_BUG,
};

enum InterruptHandlerState
{
	CYCLE1,
	CYCLE2,
	CYCLE3,
	CYCLE4,
	CYCLE5,
};

enum PPUState
{
	HBLANK,	  // MODE0
	VBLANK,	  // MODE1
	OAM_SCAN, // MODE2
	DRAW,	  // MODE3
};

struct State
{
	std::queue<std::function<void(State&)>> cpuQueue;
	uint64_t clockCycles = 0; // this will overflow in 139 years @ 4MiHz, think we're fine
	CPUState cpuState = FETCH;
	InterruptHandlerState interruptHandlerState = CYCLE1;
	PPUState ppuState = OAM_SCAN;

	bool extendedOpcodeSet = false;
	bool imeScheduled = false;
	bool ime = false;
	std::stack<Byte> tmp;
	Registers registers;

	HardwareRegisters hardwareRegisters;
	Bootrom bootrom;
	HRAM hram;
	WRAM wram;
	VRAM vram;
	MMU mmu;

	State(){};
	State(const State&) = delete;
	State& operator=(const State&) = delete;
};

#endif // LIBGREBE_STATE_HPP
