#pragma once
#include <cstdint>
#include "Log.hpp"

template <uint16_t Size, uint16_t Start, uint16_t End>
class GenericMemory
{
public:
    static constexpr bool BusWithinRange(uint16_t address)
    {
        return address >= Start && address < End;
    }

    void BusAccept(uint16_t address, uint8_t data)
    {
        Log::Debug() << address << "->" << data << Log::EndLine;
    }

private:

};
