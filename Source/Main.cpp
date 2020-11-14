#include <cstdint>
#include <array>
#include <iostream>

#include "Bus.hpp"

template <uint16_t Size, uint16_t Start, uint16_t End>
struct RAM
{
    std::array<uint8_t, Size> Data = {0};
    static const constexpr uint16_t AddressRangeStart = Start;
    static const constexpr uint16_t AddressRangeEnd = End;
    void Accept(uint16_t address, uint8_t data)
    {
        std::cout << address << "->" << std::to_string(data) << std::endl;
    }
};

int main()
{    
    using RAM_t = RAM<0x2000, 0x0000, 0x1FFF>;
    RAM_t ram;

    Bus<uint16_t, uint8_t, RAM_t> bus(ram);

    for (size_t n = RAM_t::AddressRangeStart; n < RAM_t::AddressRangeEnd; n++)
    {
        bus.Transmit(n, n);
    }
    return 0;
}
