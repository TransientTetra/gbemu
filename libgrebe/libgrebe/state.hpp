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

enum ControlUnitState
{
	LIBGREBE_CONTROL_UNIT_STATE_FETCH,
	LIBGREBE_CONTROL_UNIT_STATE_EXECUTE,
	LIBGREBE_CONTROL_UNIT_STATE_STOP,
	LIBGREBE_CONTROL_UNIT_STATE_HALT,
	LIBGREBE_CONTROL_UNIT_STATE_HALT_BUG,
};

enum InterruptHandlerState
{
	LIBGREBE_INTERRUPT_HANDLER_STATE_CYCLE1,
	LIBGREBE_INTERRUPT_HANDLER_STATE_CYCLE2,
	LIBGREBE_INTERRUPT_HANDLER_STATE_CYCLE3,
	LIBGREBE_INTERRUPT_HANDLER_STATE_CYCLE4,
	LIBGREBE_INTERRUPT_HANDLER_STATE_CYCLE5,
};

enum PPUState
{
	LIBGREBE_PPU_STATE_HBLANK,	  // MODE0
	LIBGREBE_PPU_STATE_VBLANK,	  // MODE1
	LIBGREBE_PPU_STATE_OAM_SCAN, // MODE2
	LIBGREBE_PPU_STATE_DRAW,	  // MODE3
};

struct State
{
	std::queue<std::function<void(State&)>> cpuQueue;
	uint64_t clockCycles = 0; // this will overflow in 139 years @ 4MiHz, think we're fine
	ControlUnitState controlUnitState = LIBGREBE_CONTROL_UNIT_STATE_FETCH;
	InterruptHandlerState interruptHandlerState = LIBGREBE_INTERRUPT_HANDLER_STATE_CYCLE1;
	PPUState ppuState = LIBGREBE_PPU_STATE_OAM_SCAN;

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
