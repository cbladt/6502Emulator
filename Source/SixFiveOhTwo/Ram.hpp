#pragma once
#include <cstdint>
#include <array>

static constexpr const size_t RamSize = 0xFFFF;

class Ram
{
public:
    constexpr Ram() :
        _data({0})
    {};
    ~Ram() = default;

    constexpr Ram(const Ram&) = delete;
    constexpr Ram& operator=(const Ram&) = delete;

    constexpr Ram(Ram&&) = delete;
    constexpr Ram& operator=(Ram&&) = delete;

    constexpr uint8_t Read(uint16_t address)
    {
        return _data.at(address);
    }

    constexpr uint8_t ReadIncrement(uint16_t& address)
    {
        auto data = _data.at(address);
        address++;
        return data;
    }

    constexpr void Write(uint16_t address, uint8_t data)
    {
        _data.at(address) = data;
    }

    static const constexpr auto StackPointerStart = 0x100;

    constexpr void PushToStack(uint8_t value, uint8_t& stackPointer)
    {
        Write(StackPointerStart + stackPointer, value);
        stackPointer--;
    }

private:
    std::array<uint8_t, RamSize> _data;
};
