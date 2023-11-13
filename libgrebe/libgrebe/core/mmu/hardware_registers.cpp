#include <libgrebe/core/mmu/hardware_registers.hpp>
#include <libgrebe/memory_locations.hpp>

bool HardwareRegisters::contains(std::uint16_t address) const
{
	// only dmg registers
	return address == LIBGREBE_REG_P1 || address == LIBGREBE_REG_SB || address == LIBGREBE_REG_SC ||
		   address == LIBGREBE_REG_DIV || address == LIBGREBE_REG_TIMA || address == LIBGREBE_REG_TMA ||
		   address == LIBGREBE_REG_TAC || address == LIBGREBE_REG_IF || address == LIBGREBE_REG_NR10 ||
		   address == LIBGREBE_REG_NR11 || address == LIBGREBE_REG_NR12 || address == LIBGREBE_REG_NR13 ||
		   address == LIBGREBE_REG_NR14 || address == LIBGREBE_REG_NR21 || address == LIBGREBE_REG_NR22 ||
		   address == LIBGREBE_REG_NR23 || address == LIBGREBE_REG_NR24 || address == LIBGREBE_REG_NR30 ||
		   address == LIBGREBE_REG_NR31 || address == LIBGREBE_REG_NR32 || address == LIBGREBE_REG_NR33 ||
		   address == LIBGREBE_REG_NR34 || address == LIBGREBE_REG_NR41 || address == LIBGREBE_REG_NR42 ||
		   address == LIBGREBE_REG_NR43 || address == LIBGREBE_REG_NR44 || address == LIBGREBE_REG_NR50 ||
		   address == LIBGREBE_REG_NR51 || address == LIBGREBE_REG_NR52 || address == LIBGREBE_REG_LCDC ||
		   address == LIBGREBE_REG_STAT || address == LIBGREBE_REG_SCY || address == LIBGREBE_REG_SCX ||
		   address == LIBGREBE_REG_LY || address == LIBGREBE_REG_LYC || address == LIBGREBE_REG_DMA ||
		   address == LIBGREBE_REG_BGP || address == LIBGREBE_REG_OBP0 || address == LIBGREBE_REG_OBP1 ||
		   address == LIBGREBE_REG_WY || address == LIBGREBE_REG_WX || address == LIBGREBE_REG_IE;
}

std::uint8_t HardwareRegisters::read(std::uint16_t address) const
{
	// https://gbdev.io/pandocs/Hardware_Reg_List.html
	switch (address)
	{
		case LIBGREBE_REG_P1:
			return P1;
			break;
		case LIBGREBE_REG_SB:
			return SB;
			break;
		case LIBGREBE_REG_SC:
			return SC;
			break;
		case LIBGREBE_REG_DIV:
			return DIV_WIDE >> 8;
			break;
		case LIBGREBE_REG_TIMA:
			return TIMA;
			break;
		case LIBGREBE_REG_TMA:
			return TMA;
			break;
		case LIBGREBE_REG_TAC:
			return TAC;
			break;
		case LIBGREBE_REG_IF:
			return IF;
			break;
		case LIBGREBE_REG_NR10:
			return defaultRead;
			break;
		case LIBGREBE_REG_NR11:
			return defaultRead;
			break;
		case LIBGREBE_REG_NR12:
			return defaultRead;
			break;
		case LIBGREBE_REG_NR13:
			return defaultRead;
			break;
		case LIBGREBE_REG_NR14:
			return defaultRead;
			break;
		case LIBGREBE_REG_NR21:
			return defaultRead;
			break;
		case LIBGREBE_REG_NR22:
			return defaultRead;
			break;
		case LIBGREBE_REG_NR23:
			return defaultRead;
			break;
		case LIBGREBE_REG_NR24:
			return defaultRead;
			break;
		case LIBGREBE_REG_NR30:
			return defaultRead;
			break;
		case LIBGREBE_REG_NR31:
			return defaultRead;
			break;
		case LIBGREBE_REG_NR32:
			return defaultRead;
			break;
		case LIBGREBE_REG_NR33:
			return defaultRead;
			break;
		case LIBGREBE_REG_NR34:
			return defaultRead;
			break;
		case LIBGREBE_REG_NR41:
			return defaultRead;
			break;
		case LIBGREBE_REG_NR42:
			return defaultRead;
			break;
		case LIBGREBE_REG_NR43:
			return defaultRead;
			break;
		case LIBGREBE_REG_NR44:
			return defaultRead;
			break;
		case LIBGREBE_REG_NR50:
			return defaultRead;
			break;
		case LIBGREBE_REG_NR51:
			return defaultRead;
			break;
		case LIBGREBE_REG_NR52:
			return defaultRead;
			break;
		case LIBGREBE_REG_LCDC:
			return defaultRead;
			break;
		case LIBGREBE_REG_STAT:
			return defaultRead;
			break;
		case LIBGREBE_REG_SCY:
			return defaultRead;
			break;
		case LIBGREBE_REG_SCX:
			return defaultRead;
			break;
		case LIBGREBE_REG_LY:
			return defaultRead;
			break;
		case LIBGREBE_REG_LYC:
			return defaultRead;
			break;
		case LIBGREBE_REG_DMA:
			return defaultRead;
			break;
		case LIBGREBE_REG_BGP:
			return defaultRead;
			break;
		case LIBGREBE_REG_OBP0:
			return defaultRead;
			break;
		case LIBGREBE_REG_OBP1:
			return defaultRead;
			break;
		case LIBGREBE_REG_WY:
			return defaultRead;
			break;
		case LIBGREBE_REG_WX:
			return defaultRead;
			break;
		case LIBGREBE_REG_IE:
			return IE;
			break;
		default:
			throw IllegalAddressableReadException();
	}
}

void HardwareRegisters::write(std::uint16_t address, std::uint8_t data)
{
	switch (address)
	{
		case LIBGREBE_REG_P1:
			P1 = (P1 & 0x0f) | (data & 0xf0);
			break;
		case LIBGREBE_REG_SB:
			SB = data;
			break;
		case LIBGREBE_REG_SC:
			SC = data;
			break;
		case LIBGREBE_REG_DIV:
			DIV_WIDE = 0;
			break;
		case LIBGREBE_REG_TIMA:
			TIMA = data;
			break;
		case LIBGREBE_REG_TMA:
			TMA = data;
			break;
		case LIBGREBE_REG_TAC:
			TAC = data;
			break;
		case LIBGREBE_REG_IF:
			IF = data;
			break;
		case LIBGREBE_REG_NR10:
			break;
		case LIBGREBE_REG_NR11:
			break;
		case LIBGREBE_REG_NR12:
			break;
		case LIBGREBE_REG_NR13:
			break;
		case LIBGREBE_REG_NR14:
			break;
		case LIBGREBE_REG_NR21:
			break;
		case LIBGREBE_REG_NR22:
			break;
		case LIBGREBE_REG_NR23:
			break;
		case LIBGREBE_REG_NR24:
			break;
		case LIBGREBE_REG_NR30:
			break;
		case LIBGREBE_REG_NR31:
			break;
		case LIBGREBE_REG_NR32:
			break;
		case LIBGREBE_REG_NR33:
			break;
		case LIBGREBE_REG_NR34:
			break;
		case LIBGREBE_REG_NR41:
			break;
		case LIBGREBE_REG_NR42:
			break;
		case LIBGREBE_REG_NR43:
			break;
		case LIBGREBE_REG_NR44:
			break;
		case LIBGREBE_REG_NR50:
			break;
		case LIBGREBE_REG_NR51:
			break;
		case LIBGREBE_REG_NR52:
			break;
		case LIBGREBE_REG_LCDC:
			break;
		case LIBGREBE_REG_STAT:
			break;
		case LIBGREBE_REG_SCY:
			break;
		case LIBGREBE_REG_SCX:
			break;
		case LIBGREBE_REG_LY:
			break;
		case LIBGREBE_REG_LYC:
			break;
		case LIBGREBE_REG_DMA:
			break;
		case LIBGREBE_REG_BGP:
			break;
		case LIBGREBE_REG_OBP0:
			break;
		case LIBGREBE_REG_OBP1:
			break;
		case LIBGREBE_REG_WY:
			break;
		case LIBGREBE_REG_WX:
			break;
		case LIBGREBE_REG_IE:
			IE = data;
			break;
		default:
			throw IllegalAddressableWriteException();
	}
}
