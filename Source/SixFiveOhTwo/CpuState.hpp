#pragma once
#include <cstdint>

namespace SixFiveOhTwo
{
    class CpuState
    {
    public:
        CpuState() :
            CarryBit(false),
            Zero(false),
            DisableInterrupt(false),
            DecimalMode(false),
            Break(false),
            Unused(false),
            Overflow(false),
            Negative(false),
            A(0),
            X(0),
            Y(0),
            Status(0),
            StackPointer(0),
            ProgramCounter(0),
            CyclesLeft(0),
            Opcode(0),
            ALUTemp(0),
            Enable(false)
        {
            RegisterReset();
        }
        ~CpuState() = default;

        CpuState(const CpuState&) = delete;
        CpuState& operator=(const CpuState&) = delete;

        CpuState(CpuState&&) = delete;
        CpuState& operator=(CpuState&&) = delete;

        constexpr void RegisterReset()
        {
            CarryBit= false;
            Zero= false;
            DisableInterrupt= false;
            DecimalMode= false;
            Break= false;
            Unused= false;
            Overflow= false;
            Negative= false;
            A = 0;
            X = 0;
            Y = 0;
            Status = 0;
            StackPointer = 0;
            ProgramCounter = 0;
            CyclesLeft = 0;
            Opcode = 0;
            ALUTemp = 0;
            Enable = false;
        }

        bool CarryBit;
        bool Zero;
        bool DisableInterrupt;
        bool DecimalMode;
        bool Break;
        bool Unused;
        bool Overflow;
        bool Negative;
        uint8_t A;
        uint8_t X;
        uint8_t Y;
        uint8_t Status;
        uint8_t StackPointer;
        uint16_t ProgramCounter;
        uint8_t CyclesLeft;
        uint8_t Opcode;
        uint8_t ALUTemp;
        bool Enable;
    };
}
