#pragma once

namespace SixFiveOhTwo::Tasks
{    
    class Reset
    {
    public:        
        Reset(CpuRegisters& cpuRegisters) :
            _cpuRegisters(cpuRegisters)
        {}
        ~Reset() = default;

        Reset(const Reset&) = delete;
        Reset& operator=(const Reset&) = delete;

        Reset(Reset&&) = delete;
        Reset& operator=(Reset&&) = delete;

        void ClockEvent();

    private:
        CpuRegisters& _cpuRegisters;
    };
}

