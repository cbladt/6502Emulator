#pragma once
#include <cstdint>

namespace SixFiveOhTwo
{
    class CpuState
    {
    private:
        enum Flag_t
        {
            eCarryBit,
            eZero,
            eDisableInterrupt,
            eDecimalMode,
            eBreak,
            eUnused,
            eOverflow,
            eNegative,
        };

        template <Flag_t Flag>
        class FlagRegister
        {
        public:
            constexpr FlagRegister(uint8_t& reg) :
                _register(reg)
            {}
            ~FlagRegister() = default;

            constexpr FlagRegister(const FlagRegister&) = delete;
            constexpr FlagRegister& operator=(const FlagRegister&) = delete;

            constexpr FlagRegister(FlagRegister&&) = delete;
            constexpr FlagRegister& operator=(FlagRegister&&) = delete;

            constexpr void Set(bool value)
            {
                if (value)
                {
                    _register |= Flag;
                }
                else
                {
                    _register &= ~Flag;
                }
            }

            constexpr bool Get() const
            {
                return _register & Flag;
            }

            constexpr operator bool() const
            {
                return Get();
            }

            constexpr void operator=(bool value)
            {
                Set(value);
            }
        private:
            uint8_t& _register;
        };

    public:
        constexpr CpuState() :
            CarryBit(Status),
            Zero(Status),
            DisableInterrupt(Status),
            DecimalMode(Status),
            Break(Status),
            Unused(Status),
            Overflow(Status),
            Negative(Status),
            A(0),
            X(0),
            Y(0),
            StackPointer(0x01ff),
            Status(0),
            ProgramCounter(0),
            CyclesLeft(0),
            Opcode(0),
            Temp(0),
            Enable(false)
        {
            Reset(); // Redundant.
        }
        ~CpuState() = default;

        constexpr void Reset()
        {
            A = 0;
            X = 0;
            Y = 0;
            StackPointer = 0x01ff;
            Status = 0;
            ProgramCounter = 0;
            CyclesLeft = 0;
            Opcode = 0;
            Temp = 0;
            Enable = false;            
        }

        FlagRegister<eCarryBit> CarryBit;
        FlagRegister<eZero> Zero;
        FlagRegister<eDisableInterrupt> DisableInterrupt;
        FlagRegister<eDecimalMode> DecimalMode;
        FlagRegister<eBreak> Break;
        FlagRegister<eUnused> Unused;
        FlagRegister<eOverflow> Overflow;
        FlagRegister<eNegative> Negative;

        uint8_t A;
        uint8_t X;
        uint8_t Y;
        uint8_t Status;        
        uint16_t ProgramCounter;
        uint16_t StackPointer;
        uint8_t CyclesLeft;
        uint8_t Opcode;
        uint8_t Temp;
        bool Enable;

        static const constexpr auto ProgramCounterDefault = 0xFFFC;
        static const constexpr auto ProgramCounterInterrupt = 0xFFFE;
        static const constexpr auto ProgramCounterNonMaskInterrupt = 0xFFFA;
        static const constexpr auto StackPointerDefault = 0xFD;

    private:
        constexpr CpuState(const CpuState&) = delete;
        constexpr CpuState& operator=(const CpuState&) = delete;

        constexpr CpuState(CpuState&&) = delete;
        constexpr CpuState& operator=(CpuState&&) = delete;
    };
}
