#pragma once

#include <Log>
#include <Opcodes/NoOperation.hpp>
#include <Opcodes/ADC.hpp>

namespace SixFiveOhTwo::Opcodes
{
    template <typename Cpu_t, typename Ram_t>
    constexpr void Execute(Cpu_t& cpu, Ram_t& ram)
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

            case 0x0: BRK::Execute(cpu, ram, 0);
            case 0x1: ORA::Execute(cpu, ram, 6);
        }
    }
}
