#pragma once

namespace SixFiveOhTwo
{
    class Flags
    {
    public:
        constexpr Flags() :
            _carryBit(false),
            _zero(false),
            _disableInterrupts(false),
            _decimalMode(false),
            _break(false),
            _unused(false),
            _overflow(false),
            _negative(false)
        {}
        ~Flags() = default;

        constexpr Flags(const Flags&) = default;
        constexpr Flags& operator=(const Flags&) = default;

        constexpr Flags(Flags&&) = default;
        constexpr Flags& operator=(Flags&&) = default;

        constexpr void SetCarryBit(bool value = true)
        {
            _carryBit = value;
        }

        constexpr bool GetCarryBit() const
        {
            return _carryBit;
        }


        constexpr void SetZero(bool value = true)
        {
            _zero = value;
        }

        constexpr bool GetZero() const
        {
            return _zero;
        }


        constexpr void SetDisableInterrupts(bool value = true)
        {
            _disableInterrupts = value;
        }

        constexpr bool GetDisableInterrupts()
        {
            return _disableInterrupts;
        }


        constexpr void SetDecimalMode(bool value = true)
        {
            _decimalMode = value;
        }

        constexpr bool GetDecimalMode()
        {
            return _decimalMode;
        }


        constexpr void SetBreak(bool value = true)
        {
            _break = value;
        }

        constexpr bool GetBreak()
        {
            return _break;
        }


        constexpr void SetUnused(bool value = true)
        {
            _unused = value;
        }

        constexpr bool GetUnused()
        {
            return _unused;
        }


        constexpr void SetOverflow(bool value = true)
        {
            _overflow = value;
        }

        constexpr bool GetOverflow()
        {
            return _overflow;
        }


        constexpr void SetNegative(bool value = true)
        {
            _negative = value;
        }

        constexpr bool GetNegative()
        {
            return _negative;
        }

    private:
        bool _carryBit;
        bool _zero;
        bool _disableInterrupts;
        bool _decimalMode;
        bool _break;
        bool _unused;
        bool _overflow;
        bool _negative;
    };
}
