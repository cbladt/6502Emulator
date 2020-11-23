#include "Cpu.hpp"
#include <OpcodeIdentifier.hpp>

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

        A = 0;
        X = 0;
        Y = 0;

        StackPointer = StackPointerDefault;
        Status = 0;
        SetFlag(Unused, true);

        CyclesLeft = 8;
    }

    bool Cpu::InterruptRequest()
    {
        if (!GetFlag(DisableInterrupt))
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
        PushToStack((ProgramCounter >> 8) & 0x00FF);
        PushToStack(ProgramCounter & 0x00FF);

        SetFlag(Break, false);
        SetFlag(Unused, true);
        SetFlag(DisableInterrupt, true);

        PushToStack(Status);

        auto pcLow = _ram.Read(address);
        auto pcHigh = _ram.Read(address + 1);
        ProgramCounter = (pcHigh << 8) | pcLow;

        CyclesLeft = 7;
    }

    void Cpu::Clock()
    {
        Opcode = _ram.Read(ProgramCounter);
        ProgramCounter++;

        SetFlag(Unused, true);

        HandleOpcode();
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
