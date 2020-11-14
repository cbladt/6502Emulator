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
    using RAM2_t = RAM<0x2000, 0x2000, 0x3FFF>;
    RAM_t ram;
    RAM2_t ramB;

    Bus<uint16_t, uint8_t, RAM_t, RAM2_t> bus(ram, ramB);
    bus.Transmit(0x0000, 0x12);
    bus.Transmit(0x0001, 0x13);
    bus.Transmit(0x0002, 0x14);
    bus.Transmit(0x0003, 0x15);

    bus.Transmit(0x2000, 0x12);
    bus.Transmit(0x2001, 0x13);
    bus.Transmit(0x2002, 0x14);
    bus.Transmit(0x2003, 0x15);
    return 0;
}
