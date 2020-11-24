#pragma once
#include <cstdint>

namespace SixFiveOhTwo
{
    class CpuState
    {
    public:
        enum Flags
        {
            CarryBit = (1 << 0),
            Zero = (1 << 1),
            DisableInterrupt = (1 << 2),
            DecimalMode = (1 << 3),
            Break = (1 << 4),
            Unused = (1 << 5),
            Overflow = (1 << 6),
            Negative = (1 << 7)
        };

        CpuState() :
            A(0),
            X(0),
            Y(0),
            Status(0),
            StackPointer(0),
            ProgramCounter(0),
            CyclesLeft(0),
            Opcode(0),
            AluTemp(0),
            AddressAbsolute(0),
            Enable(false)
        {
            RegisterReset();
        }
        ~CpuState() = default;

        CpuState(const CpuState&) = delete;
        CpuState& operator=(const CpuState&) = delete;

        CpuState(CpuState&&) = delete;
        CpuState& operator=(CpuState&&) = delete;

        constexpr auto GetStatusFlag(Flags flag) const
        {
            return Status & flag;
        }

        constexpr void SetStatusFlag(Flags flag, bool value)
        {
            if (value)
            {
                Status = Status | flag;
            }
            else
            {
                Status = Status & ~flag;
            }
        }

        constexpr void RegisterReset()
        {
            A = 0;
            X = 0;
            Y = 0;
            Status = 0;
            StackPointer = 0;
            ProgramCounter = 0;
            CyclesLeft = 0;
            Opcode = 0;
            AluTemp = 0;
            AddressAbsolute = 0;
            Enable = false;
        }

        uint8_t A;
        uint8_t X;
        uint8_t Y;
        uint8_t Status;
        uint8_t StackPointer;
        uint16_t ProgramCounter;
        uint8_t CyclesLeft;
        uint8_t Opcode;
        uint8_t AluTemp;
        uint16_t AddressAbsolute;
        bool Enable;
    };
}
