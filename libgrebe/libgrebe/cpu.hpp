#ifndef LIBGREBE_CPU_HPP
#define LIBGREBE_CPU_HPP

#include <libgrebe/types.hpp>
#include <libgrebe/state.hpp>

//Sharp LR35902 SOC
//Sharp SM83 CPU
class CPU
{
private:

	void handleUndefinedOpcode(State& state);

	void handleCB(State& state);

	static void opcodeINC(State& state, Byte& operand);
	static void opcodeDEC(State& state, Byte& operand);
	static void opcodeADD(State& state, const Byte& operand);
	static void opcodeADC(State& state, const Byte& operand);
	static void opcodeSUB(State& state, const Byte& operand);
	static void opcodeSBC(State& state, const Byte& operand);
	static void opcodeAND(State& state, const Byte& operand);
	static void opcodeXOR(State& state, const Byte& operand);
	static void opcodeOR(State& state, const Byte& operand);
	static void opcodeCP(State& state, const Byte& operand);

	static void opcodeRLC(Registers& registers, Byte& operand);
	static void opcodeRRC(Registers& registers, Byte& operand);
	static void opcodeRL(Registers& registers, Byte& operand);
	static void opcodeRR(Registers& registers, Byte& operand);
	static void opcodeSLA(Registers& registers, Byte& operand);
	static void opcodeSRA(Registers& registers, Byte& operand);
	static void opcodeSWAP(Registers& registers, Byte& operand);
	static void opcodeSRL(Registers& registers, Byte& operand);
	static void opcodeBIT(Registers& registers, const Byte& operand, Byte bit);
	static void opcodeRES(Byte& operand, Byte bit);
	static void opcodeSET(Byte& operand, Byte bit);
	static void opcodeBIThl(State& state, Byte bit);
	static void opcodeREShl(State& state, Byte bit);
	static void opcodeSEThl(State& state, Byte bit);


public:
	void execute(State& state);
};


#endif //LIBGREBE_CPU_HPP
