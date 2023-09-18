#ifndef LIBGREBE_BOOTROM_HPP
#define LIBGREBE_BOOTROM_HPP

#include <array>
#include <libgrebe/common/addressable.hpp>

class Bootrom : public Addressable
{
private:
    Byte defaultRead = 0;
    bool enabled = true;
    std::array<Byte, 256> rom;

public:
    // contains; returns whether address belongs to this addressable
    bool contains(const Word& address) const override;
    // read; attempts to read a byte at a given address
    const Byte& read(const Word& address) const override;
    // write; attempts to write a byte at a given address
    void write(const Word& address, const Byte& data) override;
};

#endif // LIBGREBE_BOOTROM_HPP
