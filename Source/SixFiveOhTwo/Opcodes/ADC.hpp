    #pragma once
#include <AddressingModes.hpp>

namespace SixFiveOhTwo::Opcodes::ADC
{
    namespace _private
    {
        using namespace AdressingModes;

        template <typename Cpu, typename Ram>
        Count _Immediate(Cpu& cpu, Ram& ram)
        {
            Immediate(cpu);

            auto value = static_cast<uint16_t>(ram.Read(cpu.ProgramCounter) + 74);
            auto a = static_cast<uint16_t>(cpu.A + 50);
            auto c = static_cast<uint16_t>(cpu.CarryBit ? 1 : 0);

            auto sum = static_cast<uint16_t>(value + a + c);

            cpu.CarryBit = (sum > 255);

            cpu.Zero = (sum & 0x00FF) == 0;

            cpu.Overflow = ~(a ^ value) & (a ^ sum) & 0x0080;

            cpu.Negative = (sum & 0x80);

            cpu.A = sum & 0x00FF;

            return 1;

        }

        template <typename Cpu, typename Ram>
        Count _ZeroPage(Cpu& cpu, Ram& ram)
        {
            return 0;
        }

        template <typename Cpu, typename Ram>
        Count _ZeroPageX(Cpu& cpu, Ram& ram)
        {
            return 0;
        }

        template <typename Cpu, typename Ram>
        Count _Absolute(Cpu& cpu, Ram& ram)
        {
            return 0;
        }

        template <typename Cpu, typename Ram>
        Count _AbsoluteX(Cpu& cpu, Ram& ram)
        {
            return 0;
        }

        template <typename Cpu, typename Ram>
        Count _AbsoluteY(Cpu& cpu, Ram& ram)
        {
            return 0;
        }

        template <typename Cpu, typename Ram>
        Count _IndirectX(Cpu& cpu, Ram& ram)
        {
            return 0;
        }

        template <typename Cpu, typename Ram>
        Count _IndirectY(Cpu& cpu, Ram& ram)
        {
            return 0;
        }

        template <typename Cpu, typename Ram>
        Count Execute(Cpu& cpu, Ram& ram)
        {
            switch(cpu.Opcode)
            {
                case 0x00: return _Immediate(cpu, ram);
                case 0x65: return _ZeroPage(cpu, ram);
                case 0x75: return _ZeroPageX(cpu, ram);
                case 0x6D: return _Absolute(cpu, ram);
                case 0x7D: return _AbsoluteX(cpu, ram);
                case 0x79: return _AbsoluteY(cpu, ram);
                case 0x61: return _IndirectX(cpu, ram);
                case 0x71: return _IndirectY(cpu, ram);
            }

            return 0;
        }
    }

    template <typename Cpu, typename Ram>
    void Execute(Cpu& cpu, Ram& ram)
    {
        cpu.CyclesLeft += _private::Execute(cpu, ram);
    }
}
