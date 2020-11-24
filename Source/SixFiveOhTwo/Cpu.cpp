#include "Cpu.hpp"
#include <Opcodes/Opcodes.hpp>

namespace SixFiveOhTwo
{       
    Cpu::Cpu()
    {
        Reset();
    }

    void Cpu::Reset()
    {
        auto low = _ram.Read(ProgramCounterDefault);
        auto high = _ram.Read(ProgramCounterDefault + 1);

        ProgramCounter = (high << 8) | low;

        RegisterReset();

        StackPointer = StackPointerDefault;        
        SetStatusFlag(Unused, true);

        CyclesLeft = 8;
    }

    bool Cpu::InterruptRequest()
    {
        if (!GetStatusFlag(DisableInterrupt))
        {
            DoInterrupt(ProgramCounterInterrupt);
            return true;
        }
        else
        {
            return false;
        }
    }

    void Cpu::Interrupt()
    {
        DoInterrupt(ProgramCounterNonMaskInterrupt);
    }

    void Cpu::DoInterrupt(uint16_t address)
    {
        _ram.PushToStack((ProgramCounter >> 8) & 0x00FF, StackPointer);
        _ram.PushToStack(ProgramCounter & 0x00FF, StackPointer);

        SetStatusFlag(Break, false);
        SetStatusFlag(Unused, true);
        SetStatusFlag(DisableInterrupt, true);

        _ram.PushToStack(Status, StackPointer);

        auto pcLow = _ram.Read(address);
        auto pcHigh = _ram.Read(address + 1);
        ProgramCounter = (pcHigh << 8) | pcLow;

        CyclesLeft = 7;
    }

    void Cpu::Clock()
    {
        Opcode = _ram.Read(ProgramCounter);
        ProgramCounter++;

        SetStatusFlag(Unused, true);

        Opcodes::Execute(*this);
    }

    void Cpu::MaybeClock()
    {
        if (CyclesLeft == 0)
        {
            Clock();
        }

        CyclesLeft--;
    }

    void Cpu::Fire()
    {        
        if (Enable)
        {
            MaybeClock();
        }
    }
}
