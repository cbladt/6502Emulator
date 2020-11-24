#pragma once

#include <Log>
#include <Opcodes/NoOperation.hpp>
#include <Opcodes/ADC.hpp>

namespace SixFiveOhTwo::Opcodes
{
    enum Id
    {
        Nop = 0,
        Adc = 1
    };

    template <typename Cpu_t, typename Ram_t>
    constexpr void Execute(Cpu_t& cpu, Ram_t& ram)
    {
        switch(static_cast<Id>(cpu.Opcode))
        {
            default:
            {
                Log::Error() << "Illegal instruction: " << cpu.Opcode << Log::EndLine;
                throw "Illegal instruction";
                break;
            }

            case Nop: Opcodes::ADC::Execute(cpu, ram); break;
            case Adc: Opcodes::ADC::Execute(cpu, ram); break;
        }
    }
}
