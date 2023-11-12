#ifndef LIBGREBE_CORE_HPP
#define LIBGREBE_CORE_HPP

#include <libgrebe/common/synchronous_component.hpp>
#include <libgrebe/core/cpu/cpu.hpp>
#include <libgrebe/core/ppu/ppu.hpp>
#include <string>

// Sharp LR35902 SOC models the whole system on a chip
class Core : public SynchronousComponent
{
private:
	CPU cpu;
	PPU ppu;
	void initCommon();

public:
	State state;
	// initialize Core without bootrom file
	Core();
	// initialize Core with bootrom file
	Core(const std::string& bootromPath);
	void tick() override;
	void run(bool& run);

	const State& getState() const;
};

#endif // LIBGREBE_CORE_HPP
