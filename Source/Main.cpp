#include <cstdint>
#include <array>
#include <iostream>

#include "Bus.hpp"
#include "GenericMemory.hpp"

int main()
{    
    using RAM_t = GenericMemory<0x2000, 0x0000, 0x1FFF>;
    using RAM2_t = GenericMemory<0x2000, 0x2000, 0x3FFF>;
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
