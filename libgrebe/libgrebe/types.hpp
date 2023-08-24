#ifndef LIBGREBE_TYPES_HPP
#define LIBGREBE_TYPES_HPP

#include <cstdint>
using Byte = std::uint8_t;
using Word = std::uint16_t;
using SignedByte = std::int8_t;
using SignedWord = std::int16_t;

#ifdef __BIG_ENDIAN__
#define LIBGREBE_BIG_ENDIAN
#else // __BIG_ENDIAN__
#ifdef __LITTLE_ENDIAN__
#define LIBGREBE_LITTLE_ENDIAN
#else // __LITTLE_ENDIAN__
#ifdef BSD
#include <sys/endian.h>
#else // BSD
#include <endian.h>
#endif // BSD
#if __BYTE_ORDER == __BIG_ENDIAN
#define LIBGREBE_BIG_ENDIAN
#else // __BYTE_ORDER == __BIG_ENDIAN
#define LIBGREBE_LITTLE_ENDIAN
#endif // __BYTE_ORDER == __BIG_ENDIAN
#endif // __LITTLE_ENDIAN__
#endif // __BIG_ENDIAN__

#endif // LIBGREBE_TYPES_HPP
