#ifndef LIBGREBE_ADDRESSABLE_HPP
#define LIBGREBE_ADDRESSABLE_HPP

#include <exception>
#include <libgrebe/types.hpp>

struct IllegalAddressableReadException : public std::exception
{
    [[nodiscard]] const char* what() const noexcept override
    {
        return "Illegal read on addressable";
    }
};

struct IllegalAddressableWriteException : public std::exception
{
    [[nodiscard]] const char* what() const noexcept override
    {
        return "Illegal write on addressable";
    }
};

class Addressable
{
private:
public:
    // contains; returns whether address belongs to this addressable
    virtual bool contains(const Word& address) const = 0;
    // read; attempts to read a byte at a given address
    virtual const Byte& read(const Word& address) const = 0;
    // write; attempts to write a byte at a given address
    virtual void write(const Word& address, const Byte& data) = 0;
};

#endif // LIBGREBE_ADDRESSABLE_HPP
