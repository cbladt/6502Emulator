#pragma once

namespace SixFiveOhTwo::Tasks
{
    class Interrupt
    {
    public:
        Interrupt();
        ~Interrupt() = default;

        Interrupt(const Interrupt&) = delete;
        Interrupt& operator=(const Interrupt&) = delete;

        Interrupt(Interrupt&&) = delete;
        Interrupt& operator=(Interrupt&&) = delete;

        bool IsActive() const;
        void ClockEvent();
    };
}

