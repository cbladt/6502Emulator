#include "Cpu.hpp"
#include <Opcodes/Opcodes.hpp>

namespace SixFiveOhTwo
{       
    Cpu::Cpu() :
        _debug(false),
        _step(true)
    {
        Reset();
    }

    void Cpu::Reset()
    {
        Log::Debug() << "Reset!" << Log::EndLine;

        _s.RegisterReset();

        auto low = _ram.Read(ProgramCounterDefault);
        auto high = _ram.Read(ProgramCounterDefault + 1);

        _s.ProgramCounter = (high << 8) | low;        

        _s.Unused = true;

        _s.CyclesLeft = 8;
    }

    bool Cpu::InterruptRequest()
    {
        if (!_s.DisableInterrupt)
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
        _ram.StackPush((_s.ProgramCounter >> 8) & 0x00FF);
        _ram.StackPush(_s.ProgramCounter & 0x00FF);

        _s.Break = false;
        _s.Unused = true;
        _s.DisableInterrupt = true;

        _ram.StackPush(_s.Status);

        auto pcLow = _ram.Read(address);
        auto pcHigh = _ram.Read(address + 1);
        _s.ProgramCounter = (pcHigh << 8) | pcLow;

        _s.CyclesLeft = 7;
    }

    void Cpu::Clock()
    {
        _s.Opcode = _ram.Read(_s.ProgramCounter);
        _s.ProgramCounter++;

        _s.Unused = true;

        Opcodes::Execute(_s, _ram);
    }

    void Cpu::MaybeClock()
    {
        if (_s.CyclesLeft == 0)
        {
            Clock();
        }                

        _s.CyclesLeft--;
    }

    void Cpu::Fire()
    {        
        if (_s.Enable || (_debug && _step))
        {
            MaybeClock();
        }
    }
}
