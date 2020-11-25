#pragma once

#include <Log>
#include <AddressingModes.hpp>
#include <Opcodes/Data/include.inc>

namespace SixFiveOhTwo::Opcodes
{
    template <typename Cpu_t, typename Ram_t>
    void Execute(Cpu_t& cpu, Ram_t& ram)
    {
        using namespace Opcodes;

        switch(cpu.Opcode)
        {
            default:
            {
                Log::Error() << "Illegal instruction: " << cpu.Opcode << Log::EndLine;
                throw "Illegal instruction";
                break;
            }

            #include <Opcodes/Data/cases.inc>
        }
    }
}
