#pragma once
#include <cstdint>

namespace SixFiveOhTwo
{
    class CpuRegisters
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

        CpuRegisters() :
            Enable(false)
        {}
        ~CpuRegisters() = default;

        CpuRegisters(const CpuRegisters&) = delete;
        CpuRegisters& operator=(const CpuRegisters&) = delete;

        CpuRegisters(CpuRegisters&&) = delete;
        CpuRegisters& operator=(CpuRegisters&&) = delete;

        inline auto GetFlag(Flags flag) const
        {
            return Status & flag;
        }

        inline void SetFlag(Flags flag, bool value)
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

        uint8_t A;
        uint8_t X;
        uint8_t Y;
        uint8_t Status;
        uint8_t StackPointer;
        uint16_t ProgramCounter;
        uint8_t CyclesLeft;
        bool Enable;
    };
}
