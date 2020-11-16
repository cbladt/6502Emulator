#pragma once
#include <cstdint>

#include <Log.hpp>
#include <SixFiveOhTwo/Flags.hpp>

namespace SixFiveOhTwo
{    
    template <typename Bus_t>
    class Cpu
    {
    public:        
        using BusType = Bus_t;

        Cpu(BusType& bus) :
            _registerA(0),
            _registerX(0),
            _registerY(0),
            _stackPointer(0),
            _programCounter(0),
            _bus(bus),
            _cyclesLeft(0)
        {}
        ~Cpu() = default;

        Cpu(const Cpu&) = delete;
        Cpu& operator=(const Cpu&) = delete;

        Cpu(Cpu&&) = delete;
        Cpu& operator=(Cpu&&) = delete;                

        static constexpr bool BusWithinRange(uint16_t)
        {
            return true;
        }

        void BusAccept(uint16_t address, uint8_t data)
        {
            Log::Debug() << address << "->" << data << Log::EndLine;
        }

        uint16_t ReadAddressFromBus(uint16_t location)
        {
            auto low = _bus.Read(location);
            auto high = _bus.Read(location + 1);

            return (high << 8) | low;
        }

        void Reset()
        {                                    
            _stackPointer = ReadAddressFromBus(DefaultAddress);

            _registerA = 0;
            _registerX = 0;
            _registerY = 0;

            _stackPointer = DefaultStackPointer;

            _flags = Flags();
            _flags.Unused = true;

            _cyclesLeft = 8;
        }

        void InterruptRequest()
        {
            if (_flags.)
        }

        void NonMaskableInterruptRequest()
        {

        }

        void Clock()
        {

        }

    private:
        uint8_t _registerA;
        uint8_t _registerX;
        uint8_t _registerY;
        uint8_t _stackPointer;
        uint16_t _programCounter;
        uint8_t _cyclesLeft;

        BusType _bus;

        Flags _flags;

        static constexpr uint16_t DefaultAddress = 0xFFCC;
        static constexpr uint8_t DefaultStackPointer = 0xFD;
    };
}
