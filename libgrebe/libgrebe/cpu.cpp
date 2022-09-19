#include <libgrebe/cpu.hpp>

void CPU::handleUndefinedOpcode(State& state)
{

}

void CPU::execute(State& state)
{
	Memory& memory = state.memory;
	Registers& registers = state.registers;
	const Byte& current = memory.read(registers.pc);
	registers.pc += 1;
	switch(current)
	{
	// Undefined
		case 0xD3:
		case 0xE3:
		case 0xE4:
		case 0xF4:
		case 0xDB:
		case 0xDD:
		case 0xEB:
		case 0xEC:
		case 0xED:
		case 0xFC:
		case 0xFD:
			handleUndefinedOpcode(state);
			return;
	// Misc
		// 0x00 NOP
		case 0x00:
			break;
		// 0x10 STOP
		// 0xF3 DI
		// 0x76 HALT
		// 0xFB EI
	// 8-bit loads
		// 0x02 LD (BC), A
		case 0x02:
			memory.write(registers.bc, registers.a);
			break;
		// 0x06 LD B, n
		case 0x06:
			registers.b = memory.read(registers.pc);
			registers.pc += 1;
			break;
		// 0x0A LD A, (BC)
		case 0x0A:
			registers.a = memory.read(registers.bc);
			break;
		// 0x0E LD C, n
		case 0x0E:
			registers.c = memory.read(registers.pc);
			registers.pc += 1;
			break;
		// 0x12 LD (DE), A
		case 0x12:
			memory.write(registers.de, registers.a);
			break;
		// 0x16 LD D, n
		case 0x16:
			registers.d = memory.read(registers.pc);
			registers.pc += 1;
			break;
		// 0x1A LD A, (DE)
		case 0x1A:
			registers.a = memory.read(registers.de);
			break;
		// 0x1E LD E, n
		case 0x1E:
			registers.e = memory.read(registers.pc);
			registers.pc += 1;
			break;
		// 0x22 LD (HL+), A
		case 0x22:
			memory.write(registers.hl, registers.a);
			registers.hl += 1;
			break;
		// 0x26 LD H, n
		case 0x26:
			registers.h = memory.read(registers.pc);
			registers.pc += 1;
			break;
		// 0x2A LD A, (HL+)
		case 0x2A:
			registers.a = memory.read(registers.hl);
			registers.hl += 1;
			break;
		// 0x2E LD L, n
		case 0x2E:
			registers.l = memory.read(registers.pc);
			registers.pc += 1;
			break;
		// 0x32 LD (HL-), A
		case 0x32:
			memory.write(registers.hl, registers.a);
			registers.hl -= 1;
			break;
		// 0x36 LD (HL), n
		case 0x36:
			memory.write(registers.hl, memory.read(registers.pc));
			registers.pc += 1;
			break;
		// 0x3A LD A, (HL-)
		case 0x3A:
			registers.a = memory.read(registers.hl);
			registers.hl -= 1;
			break;
		// 0x3E LD A, n
		case 0x3E:
			registers.a = memory.read(registers.pc);
			registers.pc += 1;
			break;
		// 0x40 LD B, B
		case 0x40:
			break;
		// 0x41 LD B, C
		case 0x41:
			registers.b = registers.c;
			break;
		// 0x42 LD B, D
		case 0x42:
			registers.b = registers.d;
			break;
		// 0x43 LD B, E
		case 0x43:
			registers.b = registers.e;
			break;
		// 0x44 LD B, H
		case 0x44:
			registers.b = registers.h;
			break;
		// 0x45 LD B, L
		case 0x45:
			registers.b = registers.l;
			break;
		// 0x46 LD B, (HL)
		case 0x46:
			registers.b = memory.read(registers.hl);
			break;
		// 0x47 LD B, A
		case 0x47:
			registers.b = registers.a;
			break;
		// 0x48 LD C, B
		case 0x48:
			registers.c = registers.b;
			break;
		// 0x49 LD C, C
		case 0x49:
			break;
		// 0x4A LD C, D
		case 0x4A:
			registers.c = registers.d;
			break;
		// 0x4B LD C, E
		case 0x4B:
			registers.c = registers.e;
			break;
		// 0x4C LD C, H
		case 0x4C:
			registers.c = registers.h;
			break;
		// 0x4D LD C, L
		case 0x4D:
			registers.c = registers.l;
			break;
		// 0x4E LD C, (HL)
		case 0x4E:
			registers.c = memory.read(registers.hl);
			break;
		// 0x4F LD C, A
		case 0x4F:
			registers.c = registers.a;
			break;
		// 0x50 LD D, B
		case 0x50:
			registers.d = registers.b;
			break;
		// 0x51 LD D, C
		case 0x51:
			registers.d = registers.c;
			break;
		// 0x52 LD D, D
		case 0x52:
			break;
		// 0x53 LD D, E
		case 0x53:
			registers.d = registers.e;
			break;
		// 0x54 LD D, H
		case 0x54:
			registers.d = registers.h;
			break;
		// 0x55 LD D, L
		case 0x55:
			registers.d = registers.l;
			break;
		// 0x56 LD D, (HL)
		case 0x56:
			registers.d = memory.read(registers.hl);
			break;
		// 0x57 LD D, A
		case 0x57:
			registers.d = registers.a;
			break;
		// 0x58 LD E, B
		case 0x58:
			registers.e = registers.b;
			break;
		// 0x59 LD E, C
		case 0x59:
			registers.e = registers.c;
			break;
		// 0x5A LD E, D
		case 0x5A:
			registers.e = registers.d;
			break;
		// 0x5B LD E, E
		case 0x5B:
			break;
		// 0x5C LD E, H
		case 0x5C:
			registers.e = registers.h;
			break;
		// 0x5D LD E, L
		case 0x5D:
			registers.e = registers.l;
			break;
		// 0x5E LD E, (HL)
		case 0x5E:
			registers.e = memory.read(registers.hl);
			break;
		// 0x5F LD E, A
		case 0x5F:
			registers.e = registers.a;
			break;
		// 0x60 LD H, B
		case 0x60:
			registers.h = registers.b;
			break;
		// 0x61 LD H, C
		case 0x61:
			registers.h = registers.c;
			break;
		// 0x62 LD H, D
		case 0x62:
			registers.h =  registers.d;
			break;
		// 0x63 LD H, E
		case 0x63:
			registers.h = registers.e;
			break;
		// 0x64 LD H, H
		case 0x64:
			break;
		// 0x65 LD H, L
		case 0x65:
			registers.h = registers.l;
			break;
		// 0x66 LD H, (HL)
		case 0x66:
			registers.h = memory.read(registers.hl);
			break;
		// 0x67 LD H, A
		case 0x67:
			registers.h = registers.a;
			break;
		// 0x68 LD L, B
		case 0x68:
			registers.l = registers.b;
			break;
		// 0x69 LD L, C
		case 0x69:
			registers.l = registers.c;
			break;
		// 0x6A LD L, D
		case 0x6A:
			registers.l = registers.d;
			break;
		// 0x6B LD L, E
		case 0x6B:
			registers.l = registers.e;
			break;
		// 0x6C LD L, H
		case 0x6C:
			registers.l = registers.h;
			break;
		// 0x6D LD L, L
		case 0x6D:
			break;
		// 0x6E LD L, (HL)
		case 0x6E:
			registers.l = memory.read(registers.hl);
			break;
		// 0x6F LD L, A
		case 0x6F:
			registers.l = registers.a;
			break;
		// 0x70 LD (HL), B
		case 0x70:
			memory.write(registers.hl, registers.b);
			break;
		// 0x71 LD (HL), C
		case 0x71:
			memory.write(registers.hl, registers.c);
			break;
		// 0x72 LD (HL), D
		case 0x72:
			memory.write(registers.hl, registers.d);
			break;
		// 0x73 LD (HL), E
		case 0x73:
			memory.write(registers.hl, registers.e);
			break;
		// 0x74 LD (HL), H
		case 0x74:
			memory.write(registers.hl, registers.h);
			break;
		// 0x75 LD (HL), L
		case 0x75:
			memory.write(registers.hl, registers.l);
			break;
		// 0x77 LD (HL), A
		case 0x77:
			memory.write(registers.hl, registers.a);
			break;
		// 0x78 LD A, B
		case 0x78:
			registers.a = registers.b;
			break;
		// 0x79 LD A, C
		case 0x79:
			registers.a = registers.c;
			break;
		// 0x7A LD A, D
		case 0x7A:
			registers.a = registers.d;
			break;
		// 0x7B LD A, E
		case 0x7B:
			registers.a = registers.e;
			break;
		// 0x7C LD A, H
		case 0x7C:
			registers.a = registers.h;
			break;
		// 0x7D LD A, L
		case 0x7D:
			registers.a = registers.l;
			break;
		// 0x7E LD A, (HL)
		case 0x7E:
			registers.a = memory.read(registers.hl);
			break;
		// 0x7F LD A, A
		case 0x7F:
			registers.a = registers.a;
			break;
		// 0xE0 LDH (n), A
		case 0xE0:
			memory.write(0xFF00 | memory.read(registers.pc), registers.a);
			registers.pc += 1;
			break;
		// 0xE2 LDH (C), A
		case 0xE2:
			memory.write(0xFF00 | registers.c, registers.a);
			break;
		// 0xEA LD (nn), A
		case 0xEA:
			memory.write(memory.readWord(registers.pc), registers.a);
			registers.pc += 2;
			break;
		// 0xF0 LDH A, (n)
		case 0xF0:
			registers.a = memory.read(0xFF00 | memory.read(registers.pc));
			registers.pc += 1;
			break;
		// 0xF2 LDH A, (C)
		case 0xF2:
			registers.a = memory.read(0xFF00 | registers.c);
			break;
		// 0xFA LD A, (nn)
		case 0xFA:
			registers.a = memory.read(memory.readWord(registers.pc));
			registers.pc += 2;
			break;
	// 16-bit loads
		// 0x01 LD BC, nn
		case 0x01:
			registers.bc = memory.readWord(registers.pc);
			registers.pc += 2;
			break;
		// 0x08 LD (nn), SP
		case 0x08:
			memory.writeWord(memory.readWord(registers.pc), registers.sp);
			registers.pc += 2;
			break;
		// 0x11 LD DE, nn
		case 0x11:
			registers.de = memory.readWord(registers.pc);
			registers.pc += 2;
			break;
		// 0x21 LD HL, nn
		case 0x21:
			registers.hl = memory.readWord(registers.pc);
			registers.pc += 2;
			break;
		// 0x31 LD SP, nn
		case 0x31:
			registers.sp = memory.readWord(registers.pc);
			registers.pc += 2;
			break;
		// 0xC1 POP BC
		case 0xC1:
			registers.bc = memory.readWord(registers.sp);
			registers.sp += 2;
			break;
		// 0xD1 POP DE
		case 0xD1:
			registers.de = memory.readWord(registers.sp);
			registers.sp += 2;
			break;
		// 0xE1 POP HL
		case 0xE1:
			registers.hl = memory.readWord(registers.sp);
			registers.sp += 2;
			break;
		// 0xF1 POP AF
		case 0xF1:
			registers.af = memory.readWord(registers.sp);
			registers.sp += 2;
			break;
		// 0xC5 PUSH BC
		case 0xC5:
			registers.sp -= 2;
			memory.writeWord(registers.sp, registers.bc);
			break;
		// 0xD5 PUSH DE
		case 0xD5:
			registers.sp -= 2;
			memory.writeWord(registers.sp, registers.de);
			break;
		// 0xE5 PUSH HL
		case 0xE5:
			registers.sp -= 2;
			memory.writeWord(registers.sp, registers.hl);
			break;
		// 0xF5 PUSH AF
		case 0xF5:
			registers.sp -= 2;
			memory.writeWord(registers.sp, registers.af);
			break;
		// 0xF8 LD HL, SP+e
		case 0xF8: // this is highly sus
		{
			auto e = static_cast<SignedByte>(memory.read(registers.pc));
			registers.hl = registers.sp + e;
			registers.clearFlags();
			if (e >= 0)
			{
				if (((registers.sp & 0xf) + (e & 0xf)) > 0xf)
					registers.setHalfCarryFlag();
				if ((registers.sp & 0xff) + e > 0xff)
					registers.setCarryFlag();
			}
			else
			{
				if (((registers.sp + e) & 0xf) >= (registers.sp & 0xf))
					registers.setHalfCarryFlag();
				if (((registers.sp + e) & 0xff) >= (registers.sp & 0xff))
					registers.setCarryFlag();
			}
			registers.pc += 1;
			break;
		}
		// 0xF9 LD SP, HL
		case 0xF9:
			registers.sp = registers.hl;
			break;
	// 8-bit arithmetic
		// 0x04 INC B
		case 0x04:
			opcodeINC(state, registers.b);
			break;
		// 0x14 INC D
		case 0x14:
			opcodeINC(state, registers.d);
			break;
		// 0x24 INC H
		case 0x24:
			opcodeINC(state, registers.h);
			break;
		// 0x34 INC (HL)
		case 0x34:
		{
			registers.resetZeroFlag();
			registers.resetSubtractFlag();
			registers.resetHalfCarryFlag();
			const Byte& d8 = memory.read(registers.hl);
			if (((d8 & 0xf) + 1) > 0xf)
				registers.setHalfCarryFlag();
			memory.write(registers.hl, d8 + 1);
			if (d8 == 0)
				registers.setZeroFlag();
			break;
		}
		// 0x0C INC C
		case 0x0C:
			opcodeINC(state, registers.c);
			break;
		// 0x1C INC E
		case 0x1C:
			opcodeINC(state, registers.e);
			break;
		// 0x2C INC L
		case 0x2C:
			opcodeINC(state, registers.l);
			break;
		// 0x3C INC A
		case 0x3C:
			opcodeINC(state, registers.a);
			break;
		// 0x05 DEC B
		case 0x05:
			opcodeDEC(state, registers.b);
			break;
		// 0x15 DEC D
		case 0x15:
			opcodeDEC(state, registers.d);
			break;
		// 0x25 DEC H
		case 0x25:
			opcodeDEC(state, registers.h);
			break;
		// 0x35 DEC (HL)
		case 0x35:
		{
			const Byte& d8 = memory.read(registers.hl);
			registers.resetZeroFlag();
			registers.setSubtractFlag();
			registers.resetHalfCarryFlag();
			if ((((d8 & 0xf) - 1) & 0xf) >= (d8 & 0xf))
				registers.setHalfCarryFlag();
			memory.write(registers.hl, d8 - 1);
			if (d8 == 0)
				registers.setZeroFlag();
			break;
		}
		// 0x0D DEC C
		case 0x0D:
			opcodeDEC(state, registers.c);
			break;
		// 0x1D DEC E
		case 0x1D:
			opcodeDEC(state, registers.e);
			break;
		// 0x2D DEC L
		case 0x2D:
			opcodeDEC(state, registers.l);
			break;
		// 0x3D DEC A
		case 0x3D:
			opcodeDEC(state, registers.a);
			break;
		// 0x80 ADD B
		case 0x80:
			opcodeADD(state, registers.b);
			break;
		// 0x81 ADD C
		case 0x81:
			opcodeADD(state, registers.c);
			break;
		// 0x82 ADD D
		case 0x82:
			opcodeADD(state, registers.d);
			break;
		// 0x83 ADD E
		case 0x83:
			opcodeADD(state, registers.e);
			break;
		// 0x84 ADD H
		case 0x84:
			opcodeADD(state, registers.h);
			break;
		// 0x85 ADD L
		case 0x85:
			opcodeADD(state, registers.l);
			break;
		// 0x86 ADD (HL)
		case 0x86:
			opcodeADD(state, memory.read(registers.hl));
			break;
		// 0x87 ADD A
		case 0x87:
			opcodeADD(state, registers.a);
			break;
		// 0xC6 ADD n
		case 0xC6:
			opcodeADD(state, memory.read(registers.pc));
			registers.pc += 1;
			break;
		// 0x88 ADC B
		case 0x88:
			opcodeADC(state, registers.b);
			break;
		// 0x89 ADC C
		case 0x89:
			opcodeADC(state, registers.c);
			break;
		// 0x8A ADC D
		case 0x8A:
			opcodeADC(state, registers.d);
			break;
		// 0x8B ADC E
		case 0x8B:
			opcodeADC(state, registers.e);
			break;
		// 0x8C ADC H
		case 0x8C:
			opcodeADC(state, registers.h);
			break;
		// 0x8D ADC L
		case 0x8D:
			opcodeADC(state, registers.l);
			break;
		// 0x8E ADC (HL)
		case 0x8E:
			opcodeADC(state, memory.read(registers.hl));
			break;
		// 0x8F ADC A
		case 0x8F:
			opcodeADC(state, registers.a);
			break;
		// 0xCE ADC n
		case 0xCE:
			opcodeADC(state, memory.read(registers.pc));
			registers.pc += 1;
			break;
		// 0x90 SUB B
		case 0x90:
			opcodeSUB(state, registers.b);
			break;
		// 0x91 SUB C
		case 0x91:
			opcodeSUB(state, registers.c);
			break;
		// 0x92 SUB D
		case 0x92:
			opcodeSUB(state, registers.d);
			break;
		// 0x93 SUB E
		case 0x93:
			opcodeSUB(state, registers.e);
			break;
		// 0x94 SUB H
		case 0x94:
			opcodeSUB(state, registers.h);
			break;
		// 0x95 SUB L
		case 0x95:
			opcodeSUB(state, registers.l);
			break;
		// 0x96 SUB (HL)
		case 0x96:
			opcodeSUB(state, memory.read(registers.hl));
			break;
		// 0x97 SUB A
		case 0x97:
			opcodeSUB(state, registers.a);
			break;
		// 0xD6 SUB n
		case 0xD6:
			opcodeSUB(state, memory.read(registers.pc));
			registers.pc += 1;
			break;
		// 0x98 SBC B
		case 0x98:
			opcodeSBC(state, registers.b);
			break;
		// 0x99 SBC C
		case 0x99:
			opcodeSBC(state, registers.c);
			break;
		// 0x9A SBC D
		case 0x9A:
			opcodeSBC(state, registers.d);
			break;
		// 0x9B SBC E
		case 0x9B:
			opcodeSBC(state, registers.e);
			break;
		// 0x9C SBC H
		case 0x9C:
			opcodeSBC(state, registers.h);
			break;
		// 0x9D SBC L
		case 0x9D:
			opcodeSBC(state, registers.l);
			break;
		// 0x9E SBC (HL)
		case 0x9E:
			opcodeSBC(state, memory.read(registers.hl));
			break;
		// 0x9F SBC A
		case 0x9F:
			opcodeSBC(state, registers.a);
			break;
		// 0xDE SBC n
		case 0xDE:
			opcodeSBC(state, memory.read(registers.pc));
			registers.pc += 1;
			break;
		// 0xA0 AND B
		case 0xA0:
			opcodeAND(state, registers.b);
			break;
		// 0xA1 AND C
		case 0xA1:
			opcodeAND(state, registers.c);
			break;
		// 0xA2 AND D
		case 0xA2:
			opcodeAND(state, registers.d);
			break;
		// 0xA3 AND E
		case 0xA3:
			opcodeAND(state, registers.e);
			break;
		// 0xA4 AND H
		case 0xA4:
			opcodeAND(state, registers.h);
			break;
		// 0xA5 AND L
		case 0xA5:
			opcodeAND(state, registers.l);
			break;
		// 0xA6 AND (HL)
		case 0xA6:
			opcodeAND(state, memory.read(registers.hl));
			break;
		// 0xA7 AND A
		case 0xA7:
			opcodeAND(state, registers.a);
			break;
		// 0xE6 AND n
		case 0xE6:
			opcodeAND(state, memory.read(registers.pc));
			registers.pc += 1;
			break;
		// 0xA8 XOR B
		case 0xA8:
			opcodeXOR(state, registers.b);
			break;
		// 0xA9 XOR C
		case 0xA9:
			opcodeXOR(state, registers.c);
			break;
		// 0xAA XOR D
		case 0xAA:
			opcodeXOR(state, registers.d);
			break;
		// 0xAB XOR E
		case 0xAB:
			opcodeXOR(state, registers.e);
			break;
		// 0xAC XOR H
		case 0xAC:
			opcodeXOR(state, registers.h);
			break;
		// 0xAD XOR L
		case 0xAD:
			opcodeXOR(state, registers.l);
			break;
		// 0xAE XOR (HL)
		case 0xAE:
			opcodeXOR(state, memory.read(registers.hl));
			break;
		// 0xAF XOR A
		case 0xAF:
			opcodeXOR(state, registers.a);
			break;
		// 0xEE XOR n
		case 0xEE:
			opcodeXOR(state, memory.read(registers.pc));
			registers.pc += 1;
			break;
		// 0xB0 OR B
		case 0xB0:
			opcodeOR(state, registers.b);
			break;
		// 0xB1 OR C
		case 0xB1:
			opcodeOR(state, registers.c);
			break;
		// 0xB2 OR D
		case 0xB2:
			opcodeOR(state, registers.d);
			break;
		// 0xB3 OR E
		case 0xB3:
			opcodeOR(state, registers.e);
			break;
		// 0xB4 OR H
		case 0xB4:
			opcodeOR(state, registers.h);
			break;
		// 0xB5 OR L
		case 0xB5:
			opcodeOR(state, registers.l);
			break;
		// 0xB6 OR (HL)
		case 0xB6:
			opcodeOR(state, memory.read(registers.hl));
			break;
		// 0xB7 OR A
		case 0xB7:
			opcodeOR(state, registers.a);
			break;
		// 0xF6 OR n
		case 0xF6:
			opcodeOR(state, memory.read(registers.pc));
			registers.pc += 1;
			break;
		// 0xB8 CP B
		case 0xB8:
			opcodeCP(state, registers.b);
			break;
		// 0xB9 CP C
		case 0xB9:
			opcodeCP(state, registers.c);
			break;
		// 0xBA CP D
		case 0xBA:
			opcodeCP(state, registers.d);
			break;
		// 0xBB CP E
		case 0xBB:
			opcodeCP(state, registers.e);
			break;
		// 0xBC CP H
		case 0xBC:
			opcodeCP(state, registers.h);
			break;
		// 0xBD CP L
		case 0xBD:
			opcodeCP(state, registers.l);
			break;
		// 0xBE CP (HL)
		case 0xBE:
			opcodeCP(state, memory.read(registers.hl));
			break;
		// 0xBF CP A
		case 0xBF:
			opcodeCP(state, registers.a);
			break;
		// 0xBE CP n
		case 0xFE:
			opcodeCP(state, memory.read(registers.pc));
			registers.pc += 1;
			break;
		// 0x27 DAA
		case 0x27:
			if (registers.getSubtractFlag())
			{
				// after subtraction
				if (registers.getCarryFlag()) registers.a -= 0x60;
				if (registers.getHalfCarryFlag()) registers.a -= 0x6;
			}
			else
			{
				// after addition
				if (registers.getCarryFlag() || registers.a > 0x99)
				{ registers.a += 0x60; registers.setCarryFlag(); }
				if (registers.getHalfCarryFlag() || (registers.a & 0x0f) > 0x09) registers.a += 0x6;
			}
			if (registers.a == 0) registers.setZeroFlag();
			registers.resetHalfCarryFlag();
			break;
		// 0x37 SCF
		case 0x37:
			registers.resetSubtractFlag();
			registers.resetHalfCarryFlag();
			registers.setCarryFlag();
			break;
		// 0x2F CPL
		case 0x2F:
			registers.a = ~registers.a;
			registers.setSubtractFlag();
			registers.setHalfCarryFlag();
			break;
		// 0x3F CCF
		case 0x3F:
			registers.resetSubtractFlag();
			registers.resetHalfCarryFlag();
			if (registers.getCarryFlag())
				registers.resetCarryFlag();
			else
				registers.setCarryFlag();
			break;
	// Rotates, shifts, bit operations
		// 0x07 RLCA
		case 0x07:
			registers.clearFlags();
			if (registers.a & 0b10000000) registers.setCarryFlag();
			registers.a = registers.a << 1 | (registers.a >> 7);
			break;
		// 0x17 RLA
		case 0x17:
		{
			bool carry = registers.getCarryFlag();
			registers.clearFlags();
			if (registers.a & 0b10000000) registers.setCarryFlag();
			registers.a = registers.a << 1 | carry;
			break;
		}
		// 0x0F RRCA
		case 0x0F:
			registers.clearFlags();
			if (registers.a & 1) registers.setCarryFlag();
			registers.a = registers.a >> 1 | (registers.a << 7);
			break;
		// 0x1F RRA
		case 0x1F:
		{
			bool carry = registers.getCarryFlag();
			registers.clearFlags();
			if (registers.a & 1) registers.setCarryFlag();
			registers.a = registers.a >> 1 | carry << 7;
			break;
		}
		// 0xCB CB
		case 0xCB:
			handleCB(state);
			break;
		default:
			handleUndefinedOpcode(state);
			return;
	}
}

void CPU::handleCB(State& state)
{
	Memory& memory = state.memory;
	Registers& registers = state.registers;
	const Byte& current = memory.read(registers.pc);
	registers.pc += 1;
	switch(current)
	{
		// 0x00 RLC B
		case 0x00:
			opcodeRLC(registers, registers.b);
			break;
		// 0x01 RLC C
		case 0x01:
			opcodeRLC(registers, registers.c);
			break;
		// 0x02 RLC D
		case 0x02:
			opcodeRLC(registers, registers.d);
			break;
		// 0x03 RLC E
		case 0x03:
			opcodeRLC(registers, registers.e);
			break;
		// 0x04 RLC H
		case 0x04:
			opcodeRLC(registers, registers.h);
			break;
		// 0x05 RLC L
		case 0x05:
			opcodeRLC(registers, registers.l);
			break;
		// 0x06 RLC (HL)
		case 0x06:
		{
			const Byte& d = memory.read(registers.hl);
			state.registers.clearFlags();
			if (d & 0b10000000) state.registers.setCarryFlag();
			memory.write(registers.hl, d << 1 | (d >> 7));
			if (d == 0) state.registers.setZeroFlag();
			break;
		}
		// 0x07 RLC A
		case 0x07:
			opcodeRLC(registers, registers.a);
			break;
		// 0x08 RRC B
		case 0x08:
			opcodeRRC(registers, registers.b);
			break;
		// 0x09 RRC C
		case 0x09:
			opcodeRRC(registers, registers.c);
			break;
		// 0x0A RRC D
		case 0x0A:
			opcodeRRC(registers, registers.d);
			break;
		// 0x0B RRC E
		case 0x0B:
			opcodeRRC(registers, registers.e);
			break;
		// 0x0C RRC H
		case 0x0C:
			opcodeRRC(registers, registers.h);
			break;
		// 0x0D RRC L
		case 0x0D:
			opcodeRRC(registers, registers.l);
			break;
		// 0x0E RRC (HL)
		case 0x0E:
		{
			const Byte& d = memory.read(registers.hl);
			state.registers.clearFlags();
			if (d & 1) state.registers.setCarryFlag();
			memory.write(registers.hl, d >> 1 | (d << 7));
			if (d == 0) state.registers.setZeroFlag();
			break;
		}
		// 0x0F RRC A
		case 0x0F:
			opcodeRRC(registers, registers.a);
			break;
		// 0x10 RL B
		case 0x10:
			opcodeRL(registers, registers.b);
			break;
		// 0x11 RL C
		case 0x11:
			opcodeRL(registers, registers.c);
			break;
		// 0x12 RL D
		case 0x12:
			opcodeRL(registers, registers.d);
			break;
		// 0x13 RL E
		case 0x13:
			opcodeRL(registers, registers.e);
			break;
		// 0x14 RL H
		case 0x14:
			opcodeRL(registers, registers.h);
			break;
		// 0x15 RL L
		case 0x15:
			opcodeRL(registers, registers.l);
			break;
		// 0x16 RL (HL)
		case 0x16:
		{
			const Byte& d = memory.read(registers.hl);
			bool carry = state.registers.getCarryFlag();
			state.registers.clearFlags();
			if (d & 0b10000000) state.registers.setCarryFlag();
			memory.write(registers.hl, d << 1 | carry);
			if (d == 0) state.registers.setZeroFlag();
			break;
		}
		// 0x17 RL A
		case 0x17:
			opcodeRL(registers, registers.a);
			break;
		// 0x18 RR B
		case 0x18:
			opcodeRR(registers, registers.b);
			break;
		// 0x19 RR C
		case 0x19:
			opcodeRR(registers, registers.c);
			break;
		// 0x1A RR D
		case 0x1A:
			opcodeRR(registers, registers.d);
			break;
		// 0x1B RR E
		case 0x1B:
			opcodeRR(registers, registers.e);
			break;
		// 0x1C RR H
		case 0x1C:
			opcodeRR(registers, registers.h);
			break;
		// 0x1D RR L
		case 0x1D:
			opcodeRR(registers, registers.l);
			break;
		// 0x1E RR (HL)
		case 0x1E:
		{
			const Byte& d = memory.read(registers.hl);
			bool carry = state.registers.getCarryFlag();
			state.registers.clearFlags();
			if (d & 1) state.registers.setCarryFlag();
			memory.write(registers.hl, d >> 1 | carry << 7);
			if (d == 0) state.registers.setZeroFlag();
			break;
		}
		// 0x1F RR A
		case 0x1F:
			opcodeRR(registers, registers.a);
			break;
		// 0x20 SLA B
		case 0x20:
			opcodeSLA(registers, registers.b);
			break;
		// 0x21 SLA C
		case 0x21:
			opcodeSLA(registers, registers.c);
			break;
		// 0x22 SLA D
		case 0x22:
			opcodeSLA(registers, registers.d);
			break;
		// 0x23 SLA E
		case 0x23:
			opcodeSLA(registers, registers.e);
			break;
		// 0x24 SLA H
		case 0x24:
			opcodeSLA(registers, registers.h);
			break;
		// 0x25 SLA L
		case 0x25:
			opcodeSLA(registers, registers.l);
			break;
		// 0x26 SLA (HL)
		case 0x26:
		{
			const Byte& d = memory.read(registers.hl);
			state.registers.clearFlags();
			if (d & 0b10000000) state.registers.setCarryFlag();
			memory.write(registers.hl, d << 1);
			if (d == 0) state.registers.setZeroFlag();
			break;
		}
		// 0x27 SLA A
		case 0x27:
			opcodeSLA(registers, registers.a);
			break;
		// 0x28 SRA B
		case 0x28:
			opcodeSRA(registers, registers.b);
			break;
		// 0x29 SRA C
		case 0x29:
			opcodeSRA(registers, registers.c);
			break;
		// 0x2A SRA D
		case 0x2A:
			opcodeSRA(registers, registers.d);
			break;
		// 0x2B SRA E
		case 0x2B:
			opcodeSRA(registers, registers.e);
			break;
		// 0x2C SRA H
		case 0x2C:
			opcodeSRA(registers, registers.h);
			break;
		// 0x2D SRA L
		case 0x2D:
			opcodeSRA(registers, registers.l);
			break;
		// 0x2E SRA (HL)
		case 0x2E:
		{
			const Byte& d = memory.read(registers.hl);
			state.registers.clearFlags();
			if (d & 1) state.registers.setCarryFlag();
			memory.write(registers.hl, d >> 1 | d & 0b10000000);
			if (d == 0) state.registers.setZeroFlag();
			break;
		}
		// 0x2F SRA A
		case 0x2F:
			opcodeSRA(registers, registers.a);
			break;
		// 0x30 SWAP B
		case 0x30:
			opcodeSWAP(registers, registers.b);
			break;
		// 0x31 SWAP C
		case 0x31:
			opcodeSWAP(registers, registers.c);
			break;
		// 0x32 SWAP D
		case 0x32:
			opcodeSWAP(registers, registers.d);
			break;
		// 0x33 SWAP E
		case 0x33:
			opcodeSWAP(registers, registers.e);
			break;
		// 0x34 SWAP H
		case 0x34:
			opcodeSWAP(registers, registers.h);
			break;
		// 0x35 SWAP L
		case 0x35:
			opcodeSWAP(registers, registers.l);
			break;
		// 0x36 SWAP (HL)
		case 0x36:
		{
			const Byte& d = memory.read(registers.hl);
			state.registers.clearFlags();
			memory.write(registers.hl, d >> 4 | d << 4);
			if (d == 0) state.registers.setZeroFlag();
			break;
		}
		// 0x37 SWAP A
		case 0x37:
			opcodeSWAP(registers, registers.a);
			break;
		// 0x38 SRL B
		case 0x38:
			opcodeSRL(registers, registers.b);
			break;
		// 0x39 SRL C
		case 0x39:
			opcodeSRL(registers, registers.c);
			break;
		// 0x3A SRL D
		case 0x3A:
			opcodeSRL(registers, registers.d);
			break;
		// 0x3B SRL E
		case 0x3B:
			opcodeSRL(registers, registers.e);
			break;
		// 0x3C SRL H
		case 0x3C:
			opcodeSRL(registers, registers.h);
			break;
		// 0x3D SRL L
		case 0x3D:
			opcodeSRL(registers, registers.l);
			break;
		// 0x3E SRL (HL)
		case 0x3E:
		{
			const Byte& d = memory.read(registers.hl);
			state.registers.clearFlags();
			if (d & 1) state.registers.setCarryFlag();
			memory.write(registers.hl, d >> 1);
			if (d == 0) state.registers.setZeroFlag();
			break;
		}
		// 0x3F SRL A
		case 0x3F:
			opcodeSRL(registers, registers.a);
			break;
		// 0x40 BIT 0, B
		case 0x40:
			opcodeBIT(registers, registers.b, 0);
			break;
		// 0x41 BIT 0, C
		case 0x41:
			opcodeBIT(registers, registers.c, 0);
			break;
		// 0x42 BIT 0, D
		case 0x42:
			opcodeBIT(registers, registers.d, 0);
			break;
		// 0x43 BIT 0, E
		case 0x43:
			opcodeBIT(registers, registers.e, 0);
			break;
		// 0x44 BIT 0, H
		case 0x44:
			opcodeBIT(registers, registers.h, 0);
			break;
		// 0x45 BIT 0, L
		case 0x45:
			opcodeBIT(registers, registers.l, 0);
			break;
		// 0x46 BIT 0, (HL)
		case 0x46:
			opcodeBIThl(state, 0);
			break;
		// 0x47 BIT 0, A
		case 0x47:
			opcodeBIT(registers, registers.a, 0);
			break;
		// 0x48 BIT 1, B
		case 0x48:
			opcodeBIT(registers, registers.b, 1);
			break;
		// 0x49 BIT 1, C
		case 0x49:
			opcodeBIT(registers, registers.c, 1);
			break;
		// 0x4A BIT 1, D
		case 0x4A:
			opcodeBIT(registers, registers.d, 1);
			break;
		// 0x4B BIT 1, E
		case 0x4B:
			opcodeBIT(registers, registers.e, 1);
			break;
		// 0x4C BIT 1, H
		case 0x4C:
			opcodeBIT(registers, registers.h, 1);
			break;
		// 0x4D BIT 1, L
		case 0x4D:
			opcodeBIT(registers, registers.l, 1);
			break;
		// 0x4E BIT 1, (HL)
		case 0x4E:
			opcodeBIThl(state, 1);
			break;
		// 0x4F BIT 1, A
		case 0x4F:
			opcodeBIT(registers, registers.a, 1);
			break;
		// 0x50 BIT 2, B
		case 0x50:
			opcodeBIT(registers, registers.b, 2);
			break;
		// 0x51 BIT 2, C
		case 0x51:
			opcodeBIT(registers, registers.c, 2);
			break;
		// 0x52 BIT 2, D
		case 0x52:
			opcodeBIT(registers, registers.d, 2);
			break;
		// 0x53 BIT 2, E
		case 0x53:
			opcodeBIT(registers, registers.e, 2);
			break;
		// 0x54 BIT 2, H
		case 0x54:
			opcodeBIT(registers, registers.h, 2);
			break;
		// 0x55 BIT 2, L
		case 0x55:
			opcodeBIT(registers, registers.l, 2);
			break;
		// 0x56 BIT 2, (HL)
		case 0x56:
			opcodeBIThl(state, 2);
			break;
		// 0x57 BIT 2, A
		case 0x57:
			opcodeBIT(registers, registers.a, 2);
			break;
		// 0x58 BIT 3, B
		case 0x58:
			opcodeBIT(registers, registers.b, 3);
			break;
		// 0x59 BIT 3, C
		case 0x59:
			opcodeBIT(registers, registers.c, 3);
			break;
		// 0x5A BIT 3, D
		case 0x5A:
			opcodeBIT(registers, registers.d, 3);
			break;
		// 0x5B BIT 3, E
		case 0x5B:
			opcodeBIT(registers, registers.e, 3);
			break;
		// 0x5C BIT 3, H
		case 0x5C:
			opcodeBIT(registers, registers.h, 3);
			break;
		// 0x5D BIT 3, L
		case 0x5D:
			opcodeBIT(registers, registers.l, 3);
			break;
		// 0x5E BIT 3, (HL)
		case 0x5E:
			opcodeBIThl(state, 3);
			break;
		// 0x5F BIT 3, A
		case 0x5F:
			opcodeBIT(registers, registers.a, 3);
			break;
		// 0x60 BIT 4, B
		case 0x60:
			opcodeBIT(registers, registers.b, 4);
			break;
		// 0x61 BIT 4, C
		case 0x61:
			opcodeBIT(registers, registers.c, 4);
			break;
		// 0x62 BIT 4, D
		case 0x62:
			opcodeBIT(registers, registers.d, 4);
			break;
		// 0x63 BIT 4, E
		case 0x63:
			opcodeBIT(registers, registers.e, 4);
			break;
		// 0x64 BIT 4, H
		case 0x64:
			opcodeBIT(registers, registers.h, 4);
			break;
		// 0x65 BIT 4, L
		case 0x65:
			opcodeBIT(registers, registers.l, 4);
			break;
		// 0x66 BIT 4, (HL)
		case 0x66:
			opcodeBIThl(state, 4);
			break;
		// 0x67 BIT 4, A
		case 0x67:
			opcodeBIT(registers, registers.a, 4);
			break;
		// 0x68 BIT 5, B
		case 0x68:
			opcodeBIT(registers, registers.b, 5);
			break;
		// 0x69 BIT 5, C
		case 0x69:
			opcodeBIT(registers, registers.c, 5);
			break;
		// 0x6A BIT 5, D
		case 0x6A:
			opcodeBIT(registers, registers.d, 5);
			break;
		// 0x6B BIT 5, E
		case 0x6B:
			opcodeBIT(registers, registers.e, 5);
			break;
		// 0x6C BIT 5, H
		case 0x6C:
			opcodeBIT(registers, registers.h, 5);
			break;
		// 0x6D BIT 5, L
		case 0x6D:
			opcodeBIT(registers, registers.l, 5);
			break;
		// 0x6E BIT 5, (HL)
		case 0x6E:
			opcodeBIThl(state, 5);
			break;
		// 0x6F BIT 5, A
		case 0x6F:
			opcodeBIT(registers, registers.a, 5);
			break;
		// 0x70 BIT 6, B
		case 0x70:
			opcodeBIT(registers, registers.b, 6);
			break;
		// 0x71 BIT 6, C
		case 0x71:
			opcodeBIT(registers, registers.c, 6);
			break;
		// 0x72 BIT 6, D
		case 0x72:
			opcodeBIT(registers, registers.d, 6);
			break;
		// 0x73 BIT 6, E
		case 0x73:
			opcodeBIT(registers, registers.e, 6);
			break;
		// 0x74 BIT 6, H
		case 0x74:
			opcodeBIT(registers, registers.h, 6);
			break;
		// 0x75 BIT 6, L
		case 0x75:
			opcodeBIT(registers, registers.l, 6);
			break;
		// 0x76 BIT 6, (HL)
		case 0x76:
			opcodeBIThl(state, 6);
			break;
		// 0x77 BIT 6, A
		case 0x77:
			opcodeBIT(registers, registers.a, 6);
			break;
		// 0x78 BIT 7, B
		case 0x78:
			opcodeBIT(registers, registers.b, 7);
			break;
		// 0x79 BIT 7, C
		case 0x79:
			opcodeBIT(registers, registers.c, 7);
			break;
		// 0x7A BIT 7, D
		case 0x7A:
			opcodeBIT(registers, registers.d, 7);
			break;
		// 0x7B BIT 7, E
		case 0x7B:
			opcodeBIT(registers, registers.e, 7);
			break;
		// 0x7C BIT 7, H
		case 0x7C:
			opcodeBIT(registers, registers.h, 7);
			break;
		// 0x7D BIT 7, L
		case 0x7D:
			opcodeBIT(registers, registers.l, 7);
			break;
		// 0x7E BIT 7, (HL)
		case 0x7E:
			opcodeBIThl(state, 7);
			break;
		// 0x7F BIT 7, A
		case 0x7F:
			opcodeBIT(registers, registers.a, 7);
			break;
		// 0x80 RES 0, B
		case 0x80:
			opcodeRES(registers.b, 0);
			break;
		// 0x81 RES 0, C
		case 0x81:
			opcodeRES(registers.c, 0);
			break;
		// 0x82 RES 0, D
		case 0x82:
			opcodeRES(registers.d, 0);
			break;
		// 0x83 RES 0, E
		case 0x83:
			opcodeRES(registers.e, 0);
			break;
		// 0x84 RES 0, H
		case 0x84:
			opcodeRES(registers.h, 0);
			break;
		// 0x85 RES 0, L
		case 0x85:
			opcodeRES(registers.l, 0);
			break;
		// 0x86 RES 0, (HL)
		case 0x86:
			opcodeREShl(state, 0);
			break;
		// 0x87 RES 0, A
		case 0x87:
			opcodeRES(registers.a, 0);
			break;
		// 0x88 RES 1, B
		case 0x88:
			opcodeRES(registers.b, 1);
			break;
		// 0x89 RES 1, C
		case 0x89:
			opcodeRES(registers.c, 1);
			break;
		// 0x8A RES 1, D
		case 0x8A:
			opcodeRES(registers.d, 1);
			break;
		// 0x8B RES 1, E
		case 0x8B:
			opcodeRES(registers.e, 1);
			break;
		// 0x8C RES 1, H
		case 0x8C:
			opcodeRES(registers.h, 1);
			break;
		// 0x8D RES 1, L
		case 0x8D:
			opcodeRES(registers.l, 1);
			break;
		// 0x8E RES 1, (HL)
		case 0x8E:
			opcodeREShl(state, 1);
			break;
		// 0x8F RES 1, A
		case 0x8F:
			opcodeRES(registers.a, 1);
			break;
		// 0x90 RES 2, B
		case 0x90:
			opcodeRES(registers.b, 2);
			break;
		// 0x91 RES 2, C
		case 0x91:
			opcodeRES(registers.c, 2);
			break;
		// 0x92 RES 2, D
		case 0x92:
			opcodeRES(registers.d, 2);
			break;
		// 0x93 RES 2, E
		case 0x93:
			opcodeRES(registers.e, 2);
			break;
		// 0x94 RES 2, H
		case 0x94:
			opcodeRES(registers.h, 2);
			break;
		// 0x95 RES 2, L
		case 0x95:
			opcodeRES(registers.l, 2);
			break;
		// 0x96 RES 2, (HL)
		case 0x96:
			opcodeREShl(state, 2);
			break;
		// 0x97 RES 2, A
		case 0x97:
			opcodeRES(registers.a, 2);
			break;
		// 0x98 RES 3, B
		case 0x98:
			opcodeRES(registers.b, 3);
			break;
		// 0x99 RES 3, C
		case 0x99:
			opcodeRES(registers.c, 3);
			break;
		// 0x9A RES 3, D
		case 0x9A:
			opcodeRES(registers.d, 3);
			break;
		// 0x9B RES 3, E
		case 0x9B:
			opcodeRES(registers.e, 3);
			break;
		// 0x9C RES 3, H
		case 0x9C:
			opcodeRES(registers.h, 3);
			break;
		// 0x9D RES 3, L
		case 0x9D:
			opcodeRES(registers.l, 3);
			break;
		// 0x9E RES 3, (HL)
		case 0x9E:
			opcodeREShl(state, 3);
			break;
		// 0x9F RES 3, A
		case 0x9F:
			opcodeRES(registers.a, 3);
			break;
		// 0xA0 RES 4, B
		case 0xA0:
			opcodeRES(registers.b, 4);
			break;
		// 0xA1 RES 4, C
		case 0xA1:
			opcodeRES(registers.c, 4);
			break;
		// 0xA2 RES 4, D
		case 0xA2:
			opcodeRES(registers.d, 4);
			break;
		// 0xA3 RES 4, E
		case 0xA3:
			opcodeRES(registers.e, 4);
			break;
		// 0xA4 RES 4, H
		case 0xA4:
			opcodeRES(registers.h, 4);
			break;
		// 0xA5 RES 4, L
		case 0xA5:
			opcodeRES(registers.l, 4);
			break;
		// 0xA6 RES 4, (HL)
		case 0xA6:
			opcodeREShl(state, 4);
			break;
		// 0xA7 RES 4, A
		case 0xA7:
			opcodeRES(registers.a, 4);
			break;
		// 0xA8 RES 5, B
		case 0xA8:
			opcodeRES(registers.b, 5);
			break;
		// 0xA9 RES 5, C
		case 0xA9:
			opcodeRES(registers.c, 5);
			break;
		// 0xAA RES 5, D
		case 0xAA:
			opcodeRES(registers.d, 5);
			break;
		// 0xAB RES 5, E
		case 0xAB:
			opcodeRES(registers.e, 5);
			break;
		// 0xAC RES 5, H
		case 0xAC:
			opcodeRES(registers.h, 5);
			break;
		// 0xAD RES 5, L
		case 0xAD:
			opcodeRES(registers.l, 5);
			break;
		// 0xAE RES 5, (HL)
		case 0xAE:
			opcodeREShl(state, 5);
			break;
		// 0xAF RES 5, A
		case 0xAF:
			opcodeRES(registers.a, 5);
			break;
		// 0xB0 RES 6, B
		case 0xB0:
			opcodeRES(registers.b, 6);
			break;
		// 0xB1 RES 6, C
		case 0xB1:
			opcodeRES(registers.c, 6);
			break;
		// 0xB2 RES 6, D
		case 0xB2:
			opcodeRES(registers.d, 6);
			break;
		// 0xB3 RES 6, E
		case 0xB3:
			opcodeRES(registers.e, 6);
			break;
		// 0xB4 RES 6, H
		case 0xB4:
			opcodeRES(registers.h, 6);
			break;
		// 0xB5 RES 6, L
		case 0xB5:
			opcodeRES(registers.l, 6);
			break;
		// 0xB6 RES 6, (HL)
		case 0xB6:
			opcodeREShl(state, 6);
			break;
		// 0xB7 RES 6, A
		case 0xB7:
			opcodeRES(registers.a, 6);
			break;
		// 0xB8 RES 7, B
		case 0xB8:
			opcodeRES(registers.b, 7);
			break;
		// 0xB9 RES 7, C
		case 0xB9:
			opcodeRES(registers.c, 7);
			break;
		// 0xBA RES 7, D
		case 0xBA:
			opcodeRES(registers.d, 7);
			break;
		// 0xBB RES 7, E
		case 0xBB:
			opcodeRES(registers.e, 7);
			break;
		// 0xBC RES 7, H
		case 0xBC:
			opcodeRES(registers.h, 7);
			break;
		// 0xBD RES 7, L
		case 0xBD:
			opcodeRES(registers.l, 7);
			break;
		// 0xBE RES 7, (HL)
		case 0xBE:
			opcodeREShl(state, 7);
			break;
		// 0xBF RES 7, A
		case 0xBF:
			opcodeRES(registers.a, 7);
			break;
		// 0xC0 SET 0, B
		case 0xC0:
			opcodeSET(registers.b, 0);
			break;
		// 0xC1 SET 0, C
		case 0xC1:
			opcodeSET(registers.c, 0);
			break;
		// 0xC2 SET 0, D
		case 0xC2:
			opcodeSET(registers.d, 0);
			break;
		// 0xC3 SET 0, E
		case 0xC3:
			opcodeSET(registers.e, 0);
			break;
		// 0xC4 SET 0, H
		case 0xC4:
			opcodeSET(registers.h, 0);
			break;
		// 0xC5 SET 0, L
		case 0xC5:
			opcodeSET(registers.l, 0);
			break;
		// 0xC6 SET 0, (HL)
		case 0xC6:
			opcodeSEThl(state, 0);
			break;
		// 0xC7 SET 0, A
		case 0xC7:
			opcodeSET(registers.a, 0);
			break;
		// 0xC8 SET 1, B
		case 0xC8:
			opcodeSET(registers.b, 1);
			break;
		// 0xC9 SET 1, C
		case 0xC9:
			opcodeSET(registers.c, 1);
			break;
		// 0xCA SET 1, D
		case 0xCA:
			opcodeSET(registers.d, 1);
			break;
		// 0xCB SET 1, E
		case 0xCB:
			opcodeSET(registers.e, 1);
			break;
		// 0xCC SET 1, H
		case 0xCC:
			opcodeSET(registers.h, 1);
			break;
		// 0xCD SET 1, L
		case 0xCD:
			opcodeSET(registers.l, 1);
			break;
		// 0xCE SET 1, (HL)
		case 0xCE:
			opcodeSEThl(state, 1);
			break;
		// 0xCF SET 1, A
		case 0xCF:
			opcodeSET(registers.a, 1);
			break;
		// 0xD0 SET 2, B
		case 0xD0:
			opcodeSET(registers.b, 2);
			break;
		// 0xD1 SET 2, C
		case 0xD1:
			opcodeSET(registers.c, 2);
			break;
		// 0xD2 SET 2, D
		case 0xD2:
			opcodeSET(registers.d, 2);
			break;
		// 0xD3 SET 2, E
		case 0xD3:
			opcodeSET(registers.e, 2);
			break;
		// 0xD4 SET 2, H
		case 0xD4:
			opcodeSET(registers.h, 2);
			break;
		// 0xD5 SET 2, L
		case 0xD5:
			opcodeSET(registers.l, 2);
			break;
		// 0xD6 SET 2, (HL)
		case 0xD6:
			opcodeSEThl(state, 2);
			break;
		// 0xD7 SET 2, A
		case 0xD7:
			opcodeSET(registers.a, 2);
			break;
		// 0xD8 SET 3, B
		case 0xD8:
			opcodeSET(registers.b, 3);
			break;
		// 0xD9 SET 3, C
		case 0xD9:
			opcodeSET(registers.c, 3);
			break;
		// 0xDA SET 3, D
		case 0xDA:
			opcodeSET(registers.d, 3);
			break;
		// 0xDB SET 3, E
		case 0xDB:
			opcodeSET(registers.e, 3);
			break;
		// 0xDC SET 3, H
		case 0xDC:
			opcodeSET(registers.h, 3);
			break;
		// 0xDD SET 3, L
		case 0xDD:
			opcodeSET(registers.l, 3);
			break;
		// 0xDE SET 3, (HL)
		case 0xDE:
			opcodeSEThl(state, 3);
			break;
		// 0xDF SET 3, A
		case 0xDF:
			opcodeSET(registers.a, 3);
			break;
		// 0xE0 SET 4, B
		case 0xE0:
			opcodeSET(registers.b, 4);
			break;
		// 0xE1 SET 4, C
		case 0xE1:
			opcodeSET(registers.c, 4);
			break;
		// 0xE2 SET 4, D
		case 0xE2:
			opcodeSET(registers.d, 4);
			break;
		// 0xE3 SET 4, E
		case 0xE3:
			opcodeSET(registers.e, 4);
			break;
		// 0xE4 SET 4, H
		case 0xE4:
			opcodeSET(registers.h, 4);
			break;
		// 0xE5 SET 4, L
		case 0xE5:
			opcodeSET(registers.l, 4);
			break;
		// 0xE6 SET 4, (HL)
		case 0xE6:
			opcodeSEThl(state, 4);
			break;
		// 0xE7 SET 4, A
		case 0xE7:
			opcodeSET(registers.a, 4);
			break;
		// 0xE8 SET 5, B
		case 0xE8:
			opcodeSET(registers.b, 5);
			break;
		// 0xE9 SET 5, C
		case 0xE9:
			opcodeSET(registers.c, 5);
			break;
		// 0xEA SET 5, D
		case 0xEA:
			opcodeSET(registers.d, 5);
			break;
		// 0xEB SET 5, E
		case 0xEB:
			opcodeSET(registers.e, 5);
			break;
		// 0xEC SET 5, H
		case 0xEC:
			opcodeSET(registers.h, 5);
			break;
		// 0xED SET 5, L
		case 0xED:
			opcodeSET(registers.l, 5);
			break;
		// 0xEE SET 5, (HL)
		case 0xEE:
			opcodeSEThl(state, 5);
			break;
		// 0xEF SET 5, A
		case 0xEF:
			opcodeSET(registers.a, 5);
			break;
		// 0xF0 SET 6, B
		case 0xF0:
			opcodeSET(registers.b, 6);
			break;
		// 0xF1 SET 6, C
		case 0xF1:
			opcodeSET(registers.c, 6);
			break;
		// 0xF2 SET 6, D
		case 0xF2:
			opcodeSET(registers.d, 6);
			break;
		// 0xF3 SET 6, E
		case 0xF3:
			opcodeSET(registers.e, 6);
			break;
		// 0xF4 SET 6, H
		case 0xF4:
			opcodeSET(registers.h, 6);
			break;
		// 0xF5 SET 6, L
		case 0xF5:
			opcodeSET(registers.l, 6);
			break;
		// 0xF6 SET 6, (HL)
		case 0xF6:
			opcodeSEThl(state, 6);
			break;
		// 0xF7 SET 6, A
		case 0xF7:
			opcodeSET(registers.a, 6);
			break;
		// 0xF8 SET 7, B
		case 0xF8:
			opcodeSET(registers.b, 7);
			break;
		// 0xF9 SET 7, C
		case 0xF9:
			opcodeSET(registers.c, 7);
			break;
		// 0xFA SET 7, D
		case 0xFA:
			opcodeSET(registers.d, 7);
			break;
		// 0xFB SET 7, E
		case 0xFB:
			opcodeSET(registers.e, 7);
			break;
		// 0xFC SET 7, H
		case 0xFC:
			opcodeSET(registers.h, 7);
			break;
		// 0xFD SET 7, L
		case 0xFD:
			opcodeSET(registers.l, 7);
			break;
		// 0xFE SET 7, (HL)
		case 0xFE:
			opcodeSEThl(state, 7);
			break;
		// 0xFF SET 7, A
		case 0xFF:
			opcodeSET(registers.a, 7);
			break;
		default:
			handleUndefinedOpcode(state);
			break;
	}
}

void CPU::opcodeINC(State& state, Byte& operand)
{
	state.registers.resetZeroFlag();
	state.registers.resetSubtractFlag();
	state.registers.resetHalfCarryFlag();
	if (((operand & 0xf) + 1) & 0x10)
		state.registers.setHalfCarryFlag();
	operand += 1;
	if (operand == 0)
		state.registers.setZeroFlag();
}

void CPU::opcodeDEC(State& state, Byte& operand)
{
	state.registers.resetZeroFlag();
	state.registers.setSubtractFlag();
	state.registers.resetHalfCarryFlag();
	if (((operand & 0xf) - 1) & 0x10)
		state.registers.setHalfCarryFlag();
	operand -= 1;
	if (operand == 0)
		state.registers.setZeroFlag();
}

void CPU::opcodeADD(State& state, const Byte& operand)
{
	state.registers.clearFlags();
	if (((state.registers.a & 0xf) + (operand & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) + (operand & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a += operand;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
}

void CPU::opcodeADC(State& state, const Byte& operand)
{
	Byte carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	if (((state.registers.a & 0xf) + (operand & 0xf) + (carry & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) + (operand & 0xff) + (carry & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a += operand + carry;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
}

void CPU::opcodeSUB(State& state, const Byte& operand)
{
	state.registers.clearFlags();
	state.registers.setSubtractFlag();
	if (((state.registers.a & 0xf) - (operand & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) - (operand & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a -= operand;
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
}

void CPU::opcodeSBC(State& state, const Byte& operand)
{
	Byte carry = state.registers.getCarryFlag();
	state.registers.clearFlags();
	state.registers.setSubtractFlag();
	if (((state.registers.a & 0xf) - (operand & 0xf) - (carry & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) - (operand & 0xff) - (carry & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	state.registers.a -= (operand + carry);
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
}

void CPU::opcodeAND(State& state, const Byte& operand)
{
	state.registers.a &= operand;
	state.registers.clearFlags();
	state.registers.setHalfCarryFlag();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
}

void CPU::opcodeXOR(State& state, const Byte& operand)
{
	state.registers.a ^= operand;
	state.registers.clearFlags();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
}

void CPU::opcodeOR(State& state, const Byte& operand)
{
	state.registers.a |= operand;
	state.registers.clearFlags();
	if (state.registers.a == 0)
		state.registers.setZeroFlag();
}

void CPU::opcodeCP(State& state, const Byte& operand)
{
	state.registers.clearFlags();
	state.registers.setSubtractFlag();
	if (((state.registers.a & 0xf) - (operand & 0xf)) & 0x10)
		state.registers.setHalfCarryFlag();
	if (((state.registers.a & 0xff) - (operand & 0xff)) & 0x100)
		state.registers.setCarryFlag();
	if (state.registers.a - operand == 0)
		state.registers.setZeroFlag();
}

void CPU::opcodeRLC(Registers& registers, Byte& operand)
{
	registers.clearFlags();
	if (operand & 0b10000000) registers.setCarryFlag();
	operand = operand << 1 | (operand >> 7);
	if (operand == 0) registers.setZeroFlag();
}

void CPU::opcodeRRC(Registers& registers, Byte& operand)
{
	registers.clearFlags();
	if (operand & 1) registers.setCarryFlag();
	operand = operand >> 1 | (operand << 7);
	if (operand == 0) registers.setZeroFlag();
}

void CPU::opcodeRL(Registers& registers, Byte& operand)
{
	bool carry = registers.getCarryFlag();
	registers.clearFlags();
	if (operand & 0b10000000) registers.setCarryFlag();
	operand = operand << 1 | carry;
	if (operand == 0) registers.setZeroFlag();
}

void CPU::opcodeRR(Registers& registers, Byte& operand)
{
	bool carry = registers.getCarryFlag();
	registers.clearFlags();
	if (operand & 1) registers.setCarryFlag();
	operand = operand >> 1 | carry << 7;
	if (operand == 0) registers.setZeroFlag();
}

void CPU::opcodeSLA(Registers& registers, Byte& operand)
{
	registers.clearFlags();
	if (operand & 0b10000000) registers.setCarryFlag();
	operand = operand << 1;
	if (operand == 0) registers.setZeroFlag();
}

void CPU::opcodeSRA(Registers& registers, Byte& operand)
{
	registers.clearFlags();
	if (operand & 1) registers.setCarryFlag();
	operand = operand >> 1 | operand & 0b10000000;
	if (operand == 0) registers.setZeroFlag();
}

void CPU::opcodeSWAP(Registers& registers, Byte& operand)
{
	registers.clearFlags();
	operand = operand >> 4 | operand << 4;
	if (operand == 0) registers.setZeroFlag();
}

void CPU::opcodeSRL(Registers& registers, Byte& operand)
{
	registers.clearFlags();
	if (operand & 1) registers.setCarryFlag();
	operand = operand >> 1;
	if (operand == 0) registers.setZeroFlag();
}

void CPU::opcodeBIT(Registers& registers, const Byte& operand, Byte bit)
{
	registers.resetSubtractFlag();
	registers.setHalfCarryFlag();
	registers.setZeroFlag();
	if (operand & (1 << bit)) registers.resetZeroFlag();
}

void CPU::opcodeRES(Byte& operand, Byte bit)
{
	operand &= ~(1 << bit);
}

void CPU::opcodeSET(Byte& operand, Byte bit)
{
	operand |= 1 << bit;
}

void CPU::opcodeBIThl(State& state, Byte bit)
{
	const Byte& d = state.memory.read(state.registers.hl);
	state.registers.resetSubtractFlag();
	state.registers.setHalfCarryFlag();
	state.registers.setZeroFlag();
	if (d & (1 << bit)) state.registers.resetZeroFlag();
}

void CPU::opcodeREShl(State& state, Byte bit)
{
	state.memory.write(state.registers.hl, state.memory.read(state.registers.hl) & ~(1 << bit));
}

void CPU::opcodeSEThl(State& state, Byte bit)
{
	state.memory.write(state.registers.hl, state.memory.read(state.registers.hl) | 1 << bit);
}