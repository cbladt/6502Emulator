#pragma once
#include <cstdint>

namespace SixFiveOhTwo
{
    template <typename T>
    class Register
    {
    public:
        Register() :
            _value(0)
        {}
        ~Register() = default;

        Register(const Register&) = delete;
        Register& operator=(const Register&) = delete;

        Register(Register&&) = delete;
        Register& operator=(Register&&) = delete;

        T Get() const
        {
            return _value;
        }

        void Set(T value)
        {
            _value = value;
        }

        void Incr(T value = 1)
        {
            _value += value;
        }

        void Decr(T value = 1)
        {
            _value -= value;
        }

        operator const T()
        {
            return _value;
        }

        void operator=(T value)
        {
            _value = value;
        }

    private:
        T _value;
    };

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
            return Status.Get() & flag;
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

        Register<uint8_t> A;
        Register<uint8_t> X;
        Register<uint8_t> Y;
        Register<uint8_t> Status;
        Register<uint8_t> StackPointer;
        Register<uint16_t> ProgramCounter;
        Register<uint8_t> CyclesLeft;
        bool Enable;
    };
}
