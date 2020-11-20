#include "Cpu.hpp"

namespace SixFiveOhTwo
{
    Cpu::Cpu(Bus& bus) :        
        _bus(bus),
        _resetPin(false),
        _interruptRequestPin(false),
        _nonMaskableInterruptRequestPin(false),
        _state(State::Unknown),
        _tasksReset(_registers, _bus),
        _tasksInterrupt(_registers, _bus)
    {}

    void Cpu::ServiceUnknown()
    {
        if (_resetPin)
        {
            _state = State::Reset;
        }
        else if (_interruptRequestPin && (!_registers.GetRegisterStatusFlag(CpuRegisters::DisableInterrupt)) || 1)
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

        _registers.SetCyclesLeft(1);
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
        _tasksReset.ClockEvent();
    }

    void Cpu::ClockEvent()
    {        
        if (_registers.GetCyclesLeft() == 0)
        {
            _state = State::Unknown;
        }

        _registers.DecrementCyclesLeft();

        Log::Debug() << "Clock: " << _registers.GetCyclesLeft() << Log::EndLine;
        switch (_state)
        {
            case State::Unknown:             ServiceUnknown(); break;
            case State::Reset:               ServiceReset(); break;
            case State::Interrupt:           ServiceInterrupt(); break;
            case State::Instruction:         ServiceInstruction(); break;
        }
    }
}
