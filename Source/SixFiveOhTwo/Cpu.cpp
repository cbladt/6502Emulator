#include "Cpu.hpp"
#include <OpcodeIdentifier.hpp>

namespace SixFiveOhTwo
{    
    Cpu::Cpu()
    {}

    void Cpu::ServiceUnknown()
    {

        //ClockEvent();
    }

    void Cpu::ServiceReset()
    {
        //_tasksReset.ClockEvent();
    }

    void Cpu::ServiceInterrupt()
    {
        //_tasksInterrupt.ClockEvent();
    }

    void Cpu::ServiceInstruction()
    {
        //_tasksInstructionDecoding.ClockEvent();
    }

    void Cpu::Clock()
    {
        auto opcode = GetOpcode(_ram.Read(ProgramCounter));
        ProgramCounter++;

        SetFlag(Unused, true);



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
