#pragma once
#include <cstdint>

#include <Log.hpp>
#include <Bus.hpp>
#include <SixFiveOhTwo/Flags.hpp>

namespace SixFiveOhTwo
{    
    class Cpu
    {
    public:               
        Cpu(Bus& bus) :
            _registerA(0),
            _registerX(0),
            _registerY(0),
            _stackPointer(0),
            _programCounter(0),
            _cyclesLeft(0),
            _bus(bus)
        {}
        ~Cpu() = default;

        Cpu(const Cpu&) = delete;
        Cpu& operator=(const Cpu&) = delete;

        Cpu(Cpu&&) = delete;
        Cpu& operator=(Cpu&&) = delete;

        void ClockEvent()
        {
            Log::Debug() << "Cpu::ClockEvent() ..." << Log::EndLine;

            Reset();
        }

        void Reset()
        {
            switch (_cyclesLeft)
            {
                case 0:
                {
                    Log::Debug() << "Reset" << Log::EndLine;
                    _cyclesLeft = 8;
                    break;
                }
                case 8:
                {
                    Log::Debug() << "address" << Log::EndLine;
                    _bus.SetAddress(DefaultAddress);
                    _cyclesLeft--;
                    break;
                }
                case 7:
                {
                    Log::Debug() << "upper" << Log::EndLine;
                    _registerX = _bus.GetData();
                    _bus.SetAddress(DefaultAddress + 1);
                    _cyclesLeft--;
                    break;
                }
                case 6:
                {
                    Log::Debug() << "lower" << Log::EndLine;
                    _registerY = _bus.GetData();
                    _programCounter = (_registerX << 8) | _registerY;
                    _cyclesLeft--;
                    break;
                }
                case 5:
                {
                    Log::Debug() << "stuff" << Log::EndLine;
                    _registerA = 0;
                    _registerX = 0;
                    _registerY = 0;
                    _stackPointer = DefaultStackPointer;

                    _flags = Flags();
                    _flags.SetUnused();

                    _cyclesLeft--;
                    break;
                }
                default:
                {
                    Log::Debug() << "default" << Log::EndLine;
                    _cyclesLeft--;
                    break;
                }
            }
        }

        void InterruptRequest()
        {
        }

        void NonMaskableInterruptRequest()
        {

        }

    private:
        uint8_t _registerA;
        uint8_t _registerX;
        uint8_t _registerY;
        uint8_t _stackPointer;
        uint16_t _programCounter;
        uint8_t _cyclesLeft;

        Bus& _bus;

        Flags _flags;

        static constexpr uint16_t DefaultAddress = 0x1FCC;
        static constexpr uint8_t DefaultStackPointer = 0xFD;
    };
}
