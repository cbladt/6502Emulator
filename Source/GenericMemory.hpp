#pragma once
#include <cstdint>
#include "Log.hpp"

template <uint16_t Size, uint16_t Start, uint16_t End>
class GenericMemory
{
public:
    static const constexpr uint16_t AddressRangeStart = Start;
    static const constexpr uint16_t AddressRangeEnd = End;

    void Accept(uint16_t address, uint8_t data)
    {
        Log::Error() << address << "->" << data << Log::EndLine;
    }

private:

};
