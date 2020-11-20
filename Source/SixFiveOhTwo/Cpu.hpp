#pragma once
#include <cstdint>
#include <tuple>

#include <Log.hpp>
#include <Bus.hpp>

#include <CpuState.hpp>

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

        uint8_t RegisterA;
        uint8_t RegisterX;
        uint8_t RegisterY;
        uint8_t StackPointer;
        uint16_t ProgramCounter;
        uint8_t CyclesLeft;
        bool Enable;
        bool CarryBit;
        bool Zero;
        bool DisableInterrupts;
        bool DecimalMode;
        bool Brk;
        bool Unused;
        bool Overflow;
        bool Negative;

        bool ResetPin;
        bool InterruptRequestPin;
        bool NonMaskableInterruptRequestPin;

    private:        
        Bus& _bus;

        enum class CpuState
        {
            None,
            Reset,
            Interrupt,
            DecodeInstruction,
            Instruction,
        };

        CpuState _state;
        uint8_t _currentOpCode;

        Tasks::Reset _tasksReset;
        Tasks::Interrupt _tasksInterrupt;

        static constexpr uint16_t DefaultAddress = 0x1FCC;
        static constexpr uint8_t DefaultStackPointer = 0xFD;

        void Foo();

        void Reset();

        void Interrupt();

        void DecodeInstruction();

        void Instruction();
    };
}
