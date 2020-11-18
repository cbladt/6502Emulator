#pragma once
#include <cstdint>
#include <array>
#include "Log.hpp"
#include <Bus.hpp>

template <uint16_t Size, uint16_t Start, uint16_t End>
class GenericMemory
{
public:
    constexpr GenericMemory(Bus& bus) :
        _bus(bus)
    {}
    ~GenericMemory() = default;

    constexpr GenericMemory(const GenericMemory&) = delete;
    constexpr GenericMemory& operator=(const GenericMemory&) = delete;

    constexpr GenericMemory(GenericMemory&&) = delete;
    constexpr GenericMemory& operator=(GenericMemory&&) = delete;

    void ClockEvent()
    {
        auto address = _bus.GetAddress();
        if(WithinRange(address))
        {
            if (_bus.GetOperation() == Bus::Operation::Write)
            {
                Write(address);
            }
            else
            {
                Read(address);
            }
        }
    }

private:
    Bus& _bus;
    std::array<uint8_t, Size> _data;

    static constexpr bool WithinRange(uint16_t address)
    {
        return address >= Start && address < End;
    }

    void Read(uint16_t address)
    {
        auto value = _data[address];
        _bus.SetData(value);

        Log::Debug() << "Memory Read - Address: " << address << ", value: " << value << Log::EndLine;
    }

    void Write(uint16_t address)
    {
        auto value = _bus.GetData();
        _data[address] = value;

        Log::Debug() << "Memory Write - Address: " << address << ", value: " << value << Log::EndLine;
    }
};
