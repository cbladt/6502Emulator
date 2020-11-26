#pragma once
#include <cstdint>
#include <array>

static constexpr const size_t RamSize = 0xFFFF;

class Ram
{
public:
    static const constexpr auto StackStart = 0x100;

    constexpr Ram() :
        _data({0}),
        _stackPointer(0)
    {};
    ~Ram() = default;

    using Data = uint8_t;
    using Address = uint16_t;

    constexpr Ram(const Ram&) = delete;
    constexpr Ram& operator=(const Ram&) = delete;

    constexpr Ram(Ram&&) = delete;
    constexpr Ram& operator=(Ram&&) = delete;

    constexpr Data Read(Address address)
    {
        return _data[address];
    }

    constexpr void Write(Address address, Data data)
    {
        _data[address] = data;
    }    

    constexpr void StackPush(Data value)
    {
        auto addr = StackStart - _stackPointer;
        _stackPointer++;
        Write(addr, value);
    }

    constexpr Data StackPop()
    {
        auto addr = StackStart - _stackPointer;
        _stackPointer--;
        return Read(addr);
    }

    template <typename Offset>
    constexpr Data StackPeek(Offset offset)
    {
        auto addr = StackStart - _stackPointer - offset;
        return Read(addr);
    }

private:
    std::array<Data, RamSize> _data;
    uint8_t _stackPointer;
};
