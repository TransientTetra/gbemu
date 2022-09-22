#ifndef LIBGREBE_CPU_HPP
#define LIBGREBE_CPU_HPP

#include <libgrebe/types.hpp>
#include <libgrebe/state.hpp>
#include <exception>

struct UndefinedOpcodeException : public std::exception
{
	[[nodiscard]] const char* what() const noexcept override
	{
		return "Undefined opcode";
	}
};

//Sharp LR35902 SOC
//Sharp SM83 CPU
class CPU
{
private:

	static void handleUndefinedOpcode(State& state);

	static void decode(State& state, const Byte& opcode);
	static void decode8BitLoads(State& state, const Byte& opcode);
	static void decode16BitLoads(State& state, const Byte& opcode);
	static void decode8BitArithmetic(State& state, const Byte& opcode);
	static void decode16BitArithmetic(State& state, const Byte& opcode);
	static void decodeBitOperations(State& state, const Byte& opcode);
	static void decodeControlFlow(State& state, const Byte& opcode);
	static void decodeMisc(State& state, const Byte& opcode);
	static void decodeCB(State& state, const Byte& opcode);

	static void opcodeLD(Byte& op1, const Byte& op2);
	static void opcodeLDmem(Memory& memory, const Word& address, const Byte& op2);

	static void opcodeLD16(State& state, Word& op1, const Word& op2);
	static void opcodeLD16mem(State& state, const Word& address, const Word& op2);
	static void opcodeLD16spe(State& state);
	static void opcodeLD16sphl(State& state);
	static void opcodePUSH(State& state, const Word& operand);
	static void opcodePOP(State& state, Word& operand);

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
	static void opcodeDAA(State& state);
	static void opcodeSCF(State& state);
	static void opcodeCPL(State& state);
	static void opcodeCCF(State& state);
	static void opcodeINChl(State& state);
	static void opcodeDEChl(State& state);

	static void opcodeRLCA(State& state);
	static void opcodeRLA(State& state);
	static void opcodeRRCA(State& state);
	static void opcodeRRA(State& state);
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
	static void opcodeRLChl(State& state);
	static void opcodeRRChl(State& state);
	static void opcodeRLhl(State& state);
	static void opcodeRRhl(State& state);
	static void opcodeSLAhl(State& state);
	static void opcodeSRAhl(State& state);
	static void opcodeSWAPhl(State& state);
	static void opcodeSRLhl(State& state);
	static void opcodeBIThl(State& state, Byte bit);
	static void opcodeREShl(State& state, Byte bit);
	static void opcodeSEThl(State& state, Byte bit);

	static void opcodeJR(State& state, bool condition);
	static void opcodeJP(State& state, bool condition);
	static void opcodeJPhl(State& state);
	static void opcodeCALL(State& state, bool condition);
	static void opcodeRET(State& state, bool condition);
	static void opcodeRETI(State& state);
	static void opcodeRST(State& state, const Byte& address);

	static void opcodeNOP(State& state);
	static void opcodeDI(State& state);
	static void opcodeEI(State& state);
	static void opcodeSTOP(State& state);
	static void opcodeHALT(State& state);

public:
	static void execute(State& state);
};


#endif //LIBGREBE_CPU_HPP
