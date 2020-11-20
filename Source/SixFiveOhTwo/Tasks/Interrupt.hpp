#pragma once

#include <CpuRegisters.hpp>

namespace SixFiveOhTwo::Tasks
{    
    class Interrupt
    {
    public:        
        Interrupt(CpuRegisters& cpuRegisters) :
            _cpuRegisters(cpuRegisters)
        {}
        ~Interrupt() = default;

        Interrupt(const Interrupt&) = delete;
        Interrupt& operator=(const Interrupt&) = delete;

        Interrupt(Interrupt&&) = delete;
        Interrupt& operator=(Interrupt&&) = delete;

        bool IsActive() const;
        void ClockEvent();

    private:
        CpuRegisters& _cpuRegisters;
    };
}

