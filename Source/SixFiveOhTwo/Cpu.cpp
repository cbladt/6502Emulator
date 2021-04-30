#include "Cpu.hpp"
#include <Opcodes/Opcodes.hpp>

namespace SixFiveOhTwo
{       
    Cpu::Cpu() :
        _stack(_ram),
        _debug(false),
        _step(true)
    {
        Reset();
    }

    void Cpu::Reset()
    {

    }

    bool Cpu::InterruptRequest()
    {
        if (!_s.DisableInterrupt)
        {
            DoInterrupt(_s.ProgramCounterInterrupt);
            return true;
        }
        else
        {
            return false;
        }
    }

    void Cpu::Interrupt()
    {
        DoInterrupt(_s.ProgramCounterNonMaskInterrupt);
    }

    void Cpu::DoInterrupt(uint16_t address)
    {

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
