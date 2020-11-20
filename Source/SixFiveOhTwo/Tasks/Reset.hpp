#pragma once

namespace SixFiveOhTwo::Tasks
{
    class Reset
    {
    public:
        Reset();
        ~Reset() = default;

        Reset(const Reset&) = delete;
        Reset& operator=(const Reset&) = delete;

        Reset(Reset&&) = delete;
        Reset& operator=(Reset&&) = delete;

        void ClockEvent();
    };
}

