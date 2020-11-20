#pragma once

#include <CpuRegisters.hpp>
#include <Bus.hpp>

namespace SixFiveOhTwo::Tasks
{    
    class Interrupt
    {
    public:        
        Interrupt(CpuRegisters& cpuRegisters, Bus& bus);
        ~Interrupt() = default;

        Interrupt(const Interrupt&) = delete;
        Interrupt& operator=(const Interrupt&) = delete;

        Interrupt(Interrupt&&) = delete;
        Interrupt& operator=(Interrupt&&) = delete;

        void ClockEvent();

    private:
        CpuRegisters& _cpuRegisters;
        Bus& _bus;

        void PushToStackAsync(uint8_t value);
    };
}

