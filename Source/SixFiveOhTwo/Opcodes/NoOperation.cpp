#include "NoOperation.hpp"

#include <AddressingModes.hpp>

namespace SixFiveOhTwo::Opcodes::NoOperation
{
    uint8_t OpcodeExtraCycle(uint8_t opcode)
    {
        switch (opcode)
        {
        case 0x1C:
        case 0x3C:
        case 0x5C:
        case 0x7C:
        case 0xDC:
        case 0xFC:
            return 1;
            break;
        }

        return 0;
    }

    uint8_t AddressingExtraCycle()
    {
        return 1;
    }

    void Execute(CpuState& cpu)
    {
        auto addressing = AdressingModes::Implied(cpu);
        auto b = OpcodeExtraCycle(cpu.Opcode);
        auto c = (addressing & b) ? 1 : 0;

        cpu.CyclesLeft += c;        
    }
}

