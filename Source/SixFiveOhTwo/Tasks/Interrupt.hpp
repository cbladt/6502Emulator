#pragma once

#include <CpuRegisters.hpp>
#include <Ram.hpp>

namespace SixFiveOhTwo::Tasks
{    
    class Interrupt
    {
    public:        
        Interrupt(CpuRegisters& cpuRegisters, Ram& ram);
        ~Interrupt() = default;

        Interrupt(const Interrupt&) = delete;
        Interrupt& operator=(const Interrupt&) = delete;

        Interrupt(Interrupt&&) = delete;
        Interrupt& operator=(Interrupt&&) = delete;

        void ClockEvent();

    private:
        CpuRegisters& _cpu;
        Ram& _ram;

        void PushToStackAsync(uint8_t value);
    };
}

