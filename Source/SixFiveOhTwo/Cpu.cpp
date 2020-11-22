#include "Cpu.hpp"

namespace SixFiveOhTwo
{
    Cpu::Cpu(Bus& bus) :        
        _bus(bus),
        _resetPin(true),
        _interruptRequestPin(false),
        _nonMaskableInterruptRequestPin(false),
        _state(State::Unknown),
        _tasksReset(_reg, _bus),
        _tasksInterrupt(_reg, _bus),
        _tasksInstructionDecoding(_reg, _bus)
    {}

    void Cpu::ServiceUnknown()
    {
        if (_resetPin)
        {
            _state = State::Reset;
            _resetPin = false;
        }        
        else if ((_interruptRequestPin && (!_reg.GetFlag(CpuRegisters::DisableInterrupt))))
        {
            _state = State::Interrupt;
            _interruptRequestPin = false;
        }
        else if (_nonMaskableInterruptRequestPin)
        {
            _state = State::Interrupt;
            _nonMaskableInterruptRequestPin = false;
        }
        else
        {
            _state = State::Instruction;
        }

        ClockEvent();
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
        _tasksInstructionDecoding.ClockEvent();
    }

    void Cpu::ClockEvent()
    {        
        if (!_reg.Enable)
        {
            return;
        }

        Log::Debug() << "Clock: " << _reg.CyclesLeft.Get() << Log::EndLine;
        switch (_state)
        {
            case State::Unknown:             ServiceUnknown(); break;
            case State::Reset:               ServiceReset(); break;
            case State::Interrupt:           ServiceInterrupt(); break;
            case State::Instruction:         ServiceInstruction(); break;
        }

        _reg.CyclesLeft.Decr();

        if (_reg.CyclesLeft == 0)
        {
            _state = State::Unknown;
        }
    }
}
