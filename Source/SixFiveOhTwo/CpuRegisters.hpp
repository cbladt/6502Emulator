#pragma once
#include <cstdint>

namespace SixFiveOhTwo
{
    class CpuRegisters
    {
    public:
        CpuRegisters() :
            RegisterA(0),
            RegisterX(0),
            RegisterY(0),
            StackPointer(0),
            ProgramCounter(0),
            CyclesLeft(0)
        {}
        ~CpuRegisters() = default;

        CpuRegisters(const CpuRegisters&) = delete;
        CpuRegisters& operator=(const CpuRegisters&) = delete;

        CpuRegisters(CpuRegisters&&) = delete;
        CpuRegisters& operator=(CpuRegisters&&) = delete;

        uint8_t RegisterA;
        uint8_t RegisterX;
        uint8_t RegisterY;
        uint8_t StackPointer;
        uint16_t ProgramCounter;
        uint8_t CyclesLeft;
    };
}
