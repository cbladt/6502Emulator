#pragma once

namespace SixFiveOhTwo
{
    class Flags
    {
    public:
        Flags() :
            CarryBit(false),
            Zero(false),
            DisableInterrupts(false),
            DecimalMode(false),
            Break(false),
            Unused(false),
            Overflow(false),
            Negative(false)
        {}

        bool CarryBit;
        bool Zero;
        bool DisableInterrupts;
        bool DecimalMode;
        bool Break;
        bool Unused;
        bool Overflow;
        bool Negative;
    };
}
