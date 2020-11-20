#pragma once
#include <cstdint>
#include <tuple>

#include <Log.hpp>
#include <Bus.hpp>

#include <CpuRegisters.hpp>

#include <Tasks/Reset.hpp>
#include <Tasks/Interrupt.hpp>

namespace SixFiveOhTwo
{    
    class Cpu
    {
    public:               
        Cpu(Bus& bus);
        ~Cpu() = default;

        Cpu(const Cpu&) = delete;
        Cpu& operator=(const Cpu&) = delete;

        Cpu(Cpu&&) = delete;
        Cpu& operator=(Cpu&&) = delete;

        void ClockEvent();

        constexpr void Enable()
        {
            _registers.SetEnable(true);
        }

        constexpr void Disable()
        {
            _registers.SetEnable(false);
        }

    private:        
        Bus& _bus;

        bool _resetPin;
        bool _interruptRequestPin;
        bool _nonMaskableInterruptRequestPin;

        enum class State
        {
            Unknown,
            Reset,
            Interrupt,            
            Instruction,
        };
        State _state;

        CpuRegisters _registers;

        Tasks::Reset _tasksReset;
        Tasks::Interrupt _tasksInterrupt;

        void ServiceUnknown();

        void ServiceReset();

        void ServiceInterrupt();

        void ServiceInstruction();
    };
}
