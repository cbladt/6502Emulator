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
            _registerA(0),
            _registerX(0),
            _registerY(0),
            _registerStatus(0),
            _stackPointer(0),
            _programCounter(0),
            _cyclesLeft(0),
            _enable(false)
        {}
        ~CpuRegisters() = default;

        CpuRegisters(const CpuRegisters&) = delete;
        CpuRegisters& operator=(const CpuRegisters&) = delete;

        CpuRegisters(CpuRegisters&&) = delete;
        CpuRegisters& operator=(CpuRegisters&&) = delete;

        constexpr auto GetRegisterA() const
        {
            return _registerA;
        }

        constexpr void SetRegisterA(uint8_t value)
        {
            _registerA = value;
        }


        constexpr auto GetRegisterX() const
        {
            return _registerX;
        }

        constexpr void SetRegisterX(uint8_t value)
        {
            _registerX = value;
        }


        constexpr auto GetRegisterY() const
        {
            return _registerY;
        }

        constexpr void SetRegisterY(uint8_t value)
        {
            _registerY = value;
        }


        constexpr auto GetRegisterStatus() const
        {
            return _registerStatus;
        }

        constexpr void SetRegisterStatus(uint8_t value)
        {
            _registerStatus = value;
        }

        constexpr auto GetRegisterStatusFlag(Flags flag) const
        {
            return _registerStatus & flag;
        }

        constexpr void SetRegisterStatusFlag(Flags flag, bool value)
        {
            if (value)
            {
                _registerStatus |= flag;
            }
            else
            {
                _registerStatus &= ~flag;
            }
        }


        constexpr auto GetStackPointer() const
        {
            return _stackPointer;
        }

        constexpr void SetStackPointer(uint8_t value)
        {
            _stackPointer = value;
        }

        constexpr void DecrementStackPointer(uint8_t value = 1)
        {
            _stackPointer -= value;
        }


        constexpr auto GetProgramCounter() const
        {
            return _programCounter;
        }

        constexpr void SetProgramCounter(uint16_t value)
        {
            _programCounter = value;
        }


        constexpr auto GetCyclesLeft() const
        {
            return _cyclesLeft;
        }

        constexpr void SetCyclesLeft(uint8_t value)
        {
            _cyclesLeft = value;
        }

        constexpr void DecrementCyclesLeft(uint8_t value = 1)
        {
            _cyclesLeft -= value;
        }

        constexpr void IncrementCyclesLeft(uint8_t value = 1)
        {
            _cyclesLeft += value;
        }


        constexpr auto GetEnable() const
        {
            return _enable;
        }

        constexpr void SetEnable(bool value)
        {
            _enable = value;
        }

    private:
        uint8_t _registerA;
        uint8_t _registerX;
        uint8_t _registerY;
        uint8_t _registerStatus;
        uint8_t _stackPointer;
        uint16_t _programCounter;
        uint8_t _cyclesLeft;
        bool _enable;
    };
}
