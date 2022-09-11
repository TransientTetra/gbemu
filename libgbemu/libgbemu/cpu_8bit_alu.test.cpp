#include <gtest/gtest.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconstant-conversion"
#define private public

#include <libgbemu/cpu.hpp>

class Opcodes8BitAluTest : public ::testing::Test
{
protected:
	CPU cpu;
	State state, expectedState;

	void SetUp() override
	{
	}

	void TearDown() override
	{
	}

	void testOpcode(Byte opcode)
	{
		// injecting opcode at pc
		state.memory.write(state.registers.pc, opcode);
		// saving cpu and memory state before executing the opcode
		expectedState.registers = state.registers;
		expectedState.memory = state.memory;
		// executing the opcode
		cpu.execute(state);
	}
};

TEST_F(Opcodes8BitAluTest, Test0x04)
{
	// 0x04 INC B
}

TEST_F(Opcodes8BitAluTest, Test0x14)
{
	// 0x14 INC D
}

TEST_F(Opcodes8BitAluTest, Test0x24)
{
	// 0x24 INC H
}

TEST_F(Opcodes8BitAluTest, Test0x34)
{
	// 0x34 INC (HL)
}

TEST_F(Opcodes8BitAluTest, Test0x0C)
{
	// 0x0C INC C
}

TEST_F(Opcodes8BitAluTest, Test0x1C)
{
	// 0x1C INC E
}

TEST_F(Opcodes8BitAluTest, Test0x2C)
{
	// 0x2C INC L
}

TEST_F(Opcodes8BitAluTest, Test0x3C)
{
	// 0x3C INC A
}

TEST_F(Opcodes8BitAluTest, Test0x05)
{
	// 0x05 DEC B
}

TEST_F(Opcodes8BitAluTest, Test0x15)
{
	// 0x15 DEC D
}

TEST_F(Opcodes8BitAluTest, Test0x25)
{
	// 0x25 DEC H
}

TEST_F(Opcodes8BitAluTest, Test0x35)
{
	// 0x35 DEC (HL)
}

TEST_F(Opcodes8BitAluTest, Test0x0D)
{
	// 0x0D DEC C
}

TEST_F(Opcodes8BitAluTest, Test0x1D)
{
	// 0x1D DEC E
}

TEST_F(Opcodes8BitAluTest, Test0x2D)
{
	// 0x2D DEC L
}

TEST_F(Opcodes8BitAluTest, Test0x3D)
{
	// 0x3D DEC A
}

TEST_F(Opcodes8BitAluTest, Test0x80)
{
	// 0x80 ADD B
}

TEST_F(Opcodes8BitAluTest, Test0x81)
{
	// 0x81 ADD C
}

TEST_F(Opcodes8BitAluTest, Test0x82)
{
	// 0x82 ADD D
}

TEST_F(Opcodes8BitAluTest, Test0x83)
{
	// 0x83 ADD E
}

TEST_F(Opcodes8BitAluTest, Test0x84)
{
	// 0x84 ADD H
}

TEST_F(Opcodes8BitAluTest, Test0x85)
{
	// 0x85 ADD L
}

TEST_F(Opcodes8BitAluTest, Test0x86)
{
	// 0x86 ADD (HL)
}

TEST_F(Opcodes8BitAluTest, Test0x87)
{
	// 0x87 ADD A
}

TEST_F(Opcodes8BitAluTest, Test0x88)
{
	// 0x88 ADC B
}

TEST_F(Opcodes8BitAluTest, Test0x89)
{
	// 0x89 ADC C
}

TEST_F(Opcodes8BitAluTest, Test0x8A)
{
	// 0x8A ADC D
}

TEST_F(Opcodes8BitAluTest, Test0x8B)
{
	// 0x8B ADC E
}

TEST_F(Opcodes8BitAluTest, Test0x8C)
{
	// 0x8C ADC H
}

TEST_F(Opcodes8BitAluTest, Test0x8D)
{
	// 0x8D ADC L
}

TEST_F(Opcodes8BitAluTest, Test0x8E)
{
	// 0x8E ADC (HL)
}

TEST_F(Opcodes8BitAluTest, Test0x8F)
{
	// 0x8F ADC A
}

TEST_F(Opcodes8BitAluTest, Test0x90)
{
	// 0x90 SUB B
}

TEST_F(Opcodes8BitAluTest, Test0x91)
{
	// 0x91 SUB C
}

TEST_F(Opcodes8BitAluTest, Test0x92)
{
	// 0x92 SUB D
}

TEST_F(Opcodes8BitAluTest, Test0x93)
{
	// 0x93 SUB E
}

TEST_F(Opcodes8BitAluTest, Test0x94)
{
	// 0x94 SUB H
}

TEST_F(Opcodes8BitAluTest, Test0x95)
{
	// 0x95 SUB L
}

TEST_F(Opcodes8BitAluTest, Test0x96)
{
	// 0x96 SUB (HL)
}

TEST_F(Opcodes8BitAluTest, Test0x97)
{
	// 0x97 SUB A
}

TEST_F(Opcodes8BitAluTest, Test0x98)
{
	// 0x98 SBC B
}

TEST_F(Opcodes8BitAluTest, Test0x99)
{
	// 0x99 SBC C
}

TEST_F(Opcodes8BitAluTest, Test0x9A)
{
	// 0x9A SBC D
}

TEST_F(Opcodes8BitAluTest, Test0x9B)
{
	// 0x9B SBC E
}

TEST_F(Opcodes8BitAluTest, Test0x9C)
{
	// 0x9C SBC H
}

TEST_F(Opcodes8BitAluTest, Test0x9D)
{
	// 0x9D SBC L
}

TEST_F(Opcodes8BitAluTest, Test0x9E)
{
	// 0x9E SBC (HL)
}

TEST_F(Opcodes8BitAluTest, Test0x9F)
{
	// 0x9F SBC A
}

TEST_F(Opcodes8BitAluTest, Test0xA0)
{
	// 0xA0 AND B
}

TEST_F(Opcodes8BitAluTest, Test0xA1)
{
	// 0xA1 AND C
}

TEST_F(Opcodes8BitAluTest, Test0xA2)
{
	// 0xA2 AND D
}

TEST_F(Opcodes8BitAluTest, Test0xA3)
{
	// 0xA3 AND E
}

TEST_F(Opcodes8BitAluTest, Test0xA4)
{
	// 0xA4 AND H
}

TEST_F(Opcodes8BitAluTest, Test0xA5)
{
	// 0xA5 AND L
}

TEST_F(Opcodes8BitAluTest, Test0xA6)
{
	// 0xA6 AND (HL)
}

TEST_F(Opcodes8BitAluTest, Test0xA7)
{
	// 0xA7 AND A
}

TEST_F(Opcodes8BitAluTest, Test0xA8)
{
	// 0xA8 XOR B
}

TEST_F(Opcodes8BitAluTest, Test0xA9)
{
	// 0xA9 XOR C
}

TEST_F(Opcodes8BitAluTest, Test0xAA)
{
	// 0xAA XOR D
}

TEST_F(Opcodes8BitAluTest, Test0xAB)
{
	// 0xAB XOR E
}

TEST_F(Opcodes8BitAluTest, Test0xAC)
{
	// 0xAC XOR H
}

TEST_F(Opcodes8BitAluTest, Test0xAD)
{
	// 0xAD XOR L
}

TEST_F(Opcodes8BitAluTest, Test0xAE)
{
	// 0xAE XOR (HL)
}

TEST_F(Opcodes8BitAluTest, Test0xAF)
{
	// 0xAF XOR A
}

TEST_F(Opcodes8BitAluTest, Test0xB0)
{
	// 0xB0 OR B
}

TEST_F(Opcodes8BitAluTest, Test0xB1)
{
	// 0xB1 OR C
}

TEST_F(Opcodes8BitAluTest, Test0xB2)
{
	// 0xB2 OR D
}

TEST_F(Opcodes8BitAluTest, Test0xB3)
{
	// 0xB3 OR E
}

TEST_F(Opcodes8BitAluTest, Test0xB4)
{
	// 0xB4 OR H
}

TEST_F(Opcodes8BitAluTest, Test0xB5)
{
	// 0xB5 OR L
}

TEST_F(Opcodes8BitAluTest, Test0xB6)
{
	// 0xB6 OR (HL)
}

TEST_F(Opcodes8BitAluTest, Test0xB7)
{
	// 0xB7 OR A
}

TEST_F(Opcodes8BitAluTest, Test0xB8)
{
	// 0xB8 CP B
}

TEST_F(Opcodes8BitAluTest, Test0xB9)
{
	// 0xB9 CP C
}

TEST_F(Opcodes8BitAluTest, Test0xBA)
{
	// 0xBA CP D
}

TEST_F(Opcodes8BitAluTest, Test0xBB)
{
	// 0xBB CP E
}

TEST_F(Opcodes8BitAluTest, Test0xBC)
{
	// 0xBC CP H
}

TEST_F(Opcodes8BitAluTest, Test0xBD)
{
	// 0xBD CP L
}

TEST_F(Opcodes8BitAluTest, Test0xBE)
{
	// 0xBE CP (HL)
}

TEST_F(Opcodes8BitAluTest, Test0xBF)
{
	// 0xBF CP A
}

TEST_F(Opcodes8BitAluTest, Test0xC6)
{
	// 0xC6 ADD n
}

TEST_F(Opcodes8BitAluTest, Test0xD6)
{
	// 0xD6 SUB n
}

TEST_F(Opcodes8BitAluTest, Test0xE6)
{
	// 0xE6 AND n
}

TEST_F(Opcodes8BitAluTest, Test0xF6)
{
	// 0xF6 OR n
}

TEST_F(Opcodes8BitAluTest, Test0xCE)
{
	// 0xCE ADC n
}

TEST_F(Opcodes8BitAluTest, Test0xDE)
{
	// 0xDE SBC n
}

TEST_F(Opcodes8BitAluTest, Test0xEE)
{
	// 0xEE XOR n
}

TEST_F(Opcodes8BitAluTest, Test0xFE)
{
	// 0xFE CP n
}

TEST_F(Opcodes8BitAluTest, Test0x27)
{
	// 0x27 DAA
}

TEST_F(Opcodes8BitAluTest, Test0x37)
{
	// 0x37 SCF
}

TEST_F(Opcodes8BitAluTest, Test0x2F)
{
	// 0x2F CPL
}

TEST_F(Opcodes8BitAluTest, Test0x3F)
{
	// 0x3F CCF
}
