#include "Cpu.hpp"

namespace SixFiveOhTwo
{
    Cpu::Cpu(Bus& bus) :        
        _enable(0),
        _carryBit(0),
        _zero(0),
        _disableInterrupts(0),
        _decimalMode(0),
        _break(0),
        _unused(0),
        _overflow(0),
        _negative(0),
        _bus(bus),
        _resetPin(0),
        _interruptRequestPin(0),
        _nonMaskableInterruptRequestPin(0),
        _state(State::Unknown),
        _tasksReset(_registers),
        _tasksInterrupt(_registers)
    {}

    void Cpu::ServiceUnknown()
    {
        if (_resetPin)
        {
            _state = State::Reset;
        }
        else if (_interruptRequestPin && (!_disableInterrupts))
        {
            _state = State::Interrupt;
        }
        else if (_nonMaskableInterruptRequestPin)
        {
            _state = State::Interrupt;
        }
        else
        {
            _state = State::Instruction;
        }

        _registers.CyclesLeft = 1;
    }

    void Cpu::ServiceReset()
    {
        _tasksReset.ClockEvent();
    }

    void Cpu::ServiceInterrupt()
    {
        _tasksInterrupt.ClockEvent();
    }

    void Cpu::ServiceInstruction()
    {
        _tasksReset.ClockEvent();
    }

    void Cpu::ClockEvent()
    {
        if (_registers.CyclesLeft == 0)
        {
            _state = State::Unknown;
        }

        _registers.CyclesLeft--;

        switch (_state)
        {
            case State::Unknown:             ServiceUnknown(); break;
            case State::Reset:               ServiceReset(); break;
            case State::Interrupt:           ServiceInterrupt(); break;
            case State::Instruction:         ServiceInstruction(); break;
        }
    }

    /*void Cpu::Reset()
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

    }*/
}
