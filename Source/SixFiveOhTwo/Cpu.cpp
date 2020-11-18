#include "Cpu.hpp"

namespace SixFiveOhTwo
{
    Cpu::Cpu(Bus& bus) :
        _registerA(0),
        _registerX(0),
        _registerY(0),
        _stackPointer(0),
        _programCounter(0),
        _cyclesLeft(0),
        _enable(false),
        _bus(bus)
    {}

    void Cpu::ClockEvent()
    {
        if (_enable)
        {
            Reset();
        }
    }

    void Cpu::Reset()
    {
        switch (_cyclesLeft)
        {
            case 0:
            {
                _cyclesLeft = 8;
                break;
            }
            case 8:
            {
                _bus.SetAddress(DefaultAddress);
                _cyclesLeft--;
                break;
            }
            case 7:
            {
                _registerX = _bus.GetData();
                _bus.SetAddress(DefaultAddress + 1);
                _cyclesLeft--;
                break;
            }
            case 6:
            {
                _registerY = _bus.GetData();
                _programCounter = (_registerY << 8) | _registerX;
                _cyclesLeft--;
                break;
            }
            case 5:
            {
                _registerA = 0;
                _registerX = 0;
                _registerY = 0;
                _stackPointer = DefaultStackPointer;

                _flags = Flags();
                _flags.SetUnused();

                _cyclesLeft--;
                break;
            }
            case 4:
            {
                Log::Debug() << "Resetting at " << _programCounter << Log::EndLine;
                _cyclesLeft--;
                break;
            }
            default:
            {
                _cyclesLeft--;
                break;
            }
        }
    }

    void Cpu::InterruptRequest()
    {
    }

    void Cpu::NonMaskableInterruptRequest()
    {

    }
}
