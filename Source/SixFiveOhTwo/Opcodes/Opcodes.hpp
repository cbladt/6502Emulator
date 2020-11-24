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

            case 0x0: BRK::Execute(cpu, ram); break;
            case 0x1: ORA::Execute(cpu, ram); break;
            case 0x5: ORA::Execute(cpu, ram); break;
            case 0x6: ASL::Execute(cpu, ram); break;
            case 0x8: PHP::Execute(cpu, ram); break;
            case 0x9: ORA::Execute(cpu, ram); break;
            case 0xA: ASL::Execute(cpu, ram); break;
            case 0xD: ORA::Execute(cpu, ram); break;
            case 0xE: ASL::Execute(cpu, ram); break;
            case 0x10: BPL::Execute(cpu, ram); break;
            case 0x11: ORA::Execute(cpu, ram); break;
            case 0x15: ORA::Execute(cpu, ram); break;
            case 0x16: ASL::Execute(cpu, ram); break;
            case 0x18: CLC::Execute(cpu, ram); break;
            case 0x19: ORA::Execute(cpu, ram); break;
            case 0x1D: ORA::Execute(cpu, ram); break;
            case 0x1E: ASL::Execute(cpu, ram); break;
            case 0x20: JSR::Execute(cpu, ram); break;
            case 0x21: AND::Execute(cpu, ram); break;
            case 0x24: BIT::Execute(cpu, ram); break;
            case 0x25: AND::Execute(cpu, ram); break;
            case 0x26: ROL::Execute(cpu, ram); break;
            case 0x28: PLP::Execute(cpu, ram); break;
            case 0x29: AND::Execute(cpu, ram); break;
            case 0x2A: ROL::Execute(cpu, ram); break;
            case 0x2C: BIT::Execute(cpu, ram); break;
            case 0x2D: AND::Execute(cpu, ram); break;
        }
    }
}
