#include <cstdint>
#include <array>
#include <iostream>
#include <mingw.thread.h>

#include "Bus.hpp"
#include "GenericMemory.hpp"
#include <SixFiveOhTwo/Cpu.hpp>
#include <Clock/Event.hpp>

using Ram_t = GenericMemory<0x2000, 0x0000, 0x1FFF>;

int main()
{        
    Bus bus;

    Ram_t ram(bus);    

    SixFiveOhTwo::Cpu cpu(bus);

    Clock::Event<Ram_t, SixFiveOhTwo::Cpu> clock(ram, cpu);

    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        clock.Fire();
    }

    return 0;
}
