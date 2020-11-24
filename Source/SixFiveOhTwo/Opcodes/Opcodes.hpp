#pragma once

#include <Log>

#include <CpuState.hpp>

#include <Opcodes/NoOperation.hpp>

namespace SixFiveOhTwo::Opcodes
{
    enum Id
    {
        Nop
    };

    constexpr void Execute(CpuState& cpu)
    {
        switch(static_cast<Id>(cpu.Opcode))
        {
            default:
            {
                Log::Error() << "Illegal instruction: " << cpu.Opcode << Log::EndLine;
                throw "Illegal instruction";
                break;
            }

            case Nop:
            {
                Opcodes::NoOperation::Execute(cpu);
                break;
            }

        }
    }
}
