#include "NoOperation.hpp"

namespace SixFiveOhTwo::Opcodes
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

    void NoOperation::Execute(CpuRegisters& cpu)
    {
        auto a = AddressingExtraCycle();
        auto b = OpcodeExtraCycle(cpu.Opcode);
        auto c = (a & b);

        cpu.CyclesLeft += c;

        auto n = a;
    }
}

