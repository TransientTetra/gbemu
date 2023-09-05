#ifndef LIBGREBE_MEMORY_HPP
#define LIBGREBE_MEMORY_HPP

#include <libgrebe/common/addressable.hpp>
#include <libgrebe/memory_locations.hpp>
#include <libgrebe/types.hpp>
#include <vector>

#define LIBGREBE_MEMORY_SIZE 0x10000

// Memory Management Unit; abstracts all memory accesses, including to memory mapped hardware
class MMU
{
private:
    // all mapped memory, includes ram and vram and rom
    std::vector<Addressable> addressables;

public:
    MMU();
    Byte read(const Word& address) const;
    void write(const Word& address, const Byte& data);
    bool operator==(const MMU& other) const;
    MMU& operator=(const MMU& other);
};

#endif // LIBGREBE_MEMORY_HPP
