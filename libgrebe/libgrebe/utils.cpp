#include <libgrebe/utils.hpp>

Word toWord(const Byte& lsb, const Byte& msb)
{
    return (static_cast<const Word&>(msb) << 8) | lsb;
}

Byte lsb(const Word& word)
{
    return word & 0xff;
}

Byte msb(const Word& word)
{
    return word >> 8;
}