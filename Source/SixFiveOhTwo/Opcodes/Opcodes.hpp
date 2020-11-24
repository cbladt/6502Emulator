#pragma once

#include <Log>
#include <Opcodes/NoOperation.hpp>

namespace SixFiveOhTwo::Opcodes
{
    enum Id
    {
        Nop = 0
    };

    template <typename Cpu_t, typename Ram_t>
    constexpr void Execute(Cpu_t& cpu, Ram_t&)
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
