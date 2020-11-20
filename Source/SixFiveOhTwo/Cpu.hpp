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
            _enable = true;
        }

        constexpr void Disable()
        {
            _enable = false;
        }

    private:        
        Bus& _bus;

        bool _enable;
        bool _carryBit;
        bool _zero;
        bool _disableInterrupts;
        bool _decimalMode;
        bool _break;
        bool _unused;
        bool _overflow;
        bool _negative;

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

        static constexpr uint16_t DefaultAddress = 0x1FCC;
        static constexpr uint8_t DefaultStackPointer = 0xFD;

        void ServiceUnknown();

        void ServiceReset();

        void ServiceInterrupt();

        void ServiceInstruction();
    };
}
