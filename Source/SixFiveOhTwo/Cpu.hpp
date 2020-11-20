#pragma once
#include <cstdint>

#include <Log.hpp>
#include <Bus.hpp>
#include <Flags.hpp>

namespace SixFiveOhTwo
{    
    class Cpu
    {
    public:               
        Cpu(Bus& bus);
        ~Cpu() = default;

        Cpu(const Cpu&) = delete;
        Cpu& operator=(const Cpu&) = delete;

        Cpu(Cpu&&) = delete;
        Cpu& operator=(Cpu&&) = delete;

        constexpr void Enable()
        {
            _enable = true;
        }

        constexpr void Disable()
        {
            _enable = false;
        }

        void ClockEvent();

        void Reset();

        void InterruptRequest();

        void NonMaskableInterruptRequest();

    private:
        uint8_t _registerA;
        uint8_t _registerX;
        uint8_t _registerY;
        uint8_t _stackPointer;
        uint16_t _programCounter;
        uint8_t _cyclesLeft;
        bool _enable;

        Bus& _bus;

        Flags _flags;

        static constexpr uint16_t DefaultAddress = 0x1FCC;
        static constexpr uint8_t DefaultStackPointer = 0xFD;
    };
}
