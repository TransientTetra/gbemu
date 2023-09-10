#ifndef LIBGREBE_BOOTROM_HPP
#define LIBGREBE_BOOTROM_HPP

#include <array>
#include <libgrebe/common/addressable.hpp>

class Bootrom : public Addressable
{
private:
    std::array<Byte, 0xFF> rom;

public:
    // contains; returns whether address belongs to this addressable
    bool contains(const Word& address) const;
    // read; attempts to read a byte at a given address
    const Byte& read(const Word& address) const;
    // write; attempts to write a byte at a given address
    void write(const Word& address, const Byte& data);
};

#endif // LIBGREBE_BOOTROM_HPP
