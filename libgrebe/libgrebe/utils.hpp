#ifndef LIBGREBE_UTILS_HPP
#define LIBGREBE_UTILS_HPP

#include <libgrebe/types.hpp>

Word toWord(const Byte& lsb, const Byte& msb);
Byte lsb(const Word& word);
Byte msb(const Word& word);

#endif //LIBGREBE_UTILS_HPP
