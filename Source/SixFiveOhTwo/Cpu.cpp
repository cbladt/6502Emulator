#include "Cpu.hpp"

namespace SixFiveOhTwo
{
    Cpu::Cpu(Bus& bus) :        
        RegisterA(0),
        RegisterX(0),
        RegisterY(0),
        StackPointer(0),
        ProgramCounter(0),
        CyclesLeft(0),
        Enable(0),
        CarryBit(0),
        Zero(0),
        DisableInterrupts(0),
        DecimalMode(0),
        Brk(0),
        Unused(0),
        Overflow(0),
        Negative(0),
        ResetPin(0),
        InterruptRequestPin(0),
        NonMaskableInterruptRequestPin(0),
        _bus(bus),
        _state(CpuState::None)
    {}

    void Cpu::Foo()
    {
        if (ResetPin)
        {
            _state = CpuState::Reset;
        }
        else if (InterruptRequestPin && (!DisableInterrupts))
        {
            _state = CpuState::Interrupt;
        }
        else if (NonMaskableInterruptRequestPin)
        {
            _state = CpuState::Instruction;
        }
        else
        {
            _state = CpuState::DecodeInstruction;
        }

        CyclesLeft = 1;
    }

    void Cpu::Reset()
    {
        _tasksReset.ClockEvent();
    }

    void Cpu::Interrupt()
    {
        _tasksReset.ClockEvent();
    }

    void Cpu::DecodeInstruction()
    {

    }

    void Cpu::Instruction()
    {

    }

    void Cpu::ClockEvent()
    {
        if (CyclesLeft == 0)
        {
            _state = CpuState::None;
        }

        CyclesLeft--;

        switch (_state)
        {
            case CpuState::None:                Foo(); break;
            case CpuState::Reset:               Reset(); break;
            case CpuState::Interrupt:           Interrupt(); break;
            case CpuState::DecodeInstruction:   DecodeInstruction(); break;
            case CpuState::Instruction:         Instruction(); break;
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
