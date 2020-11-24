#pragma once
#include <cstdint>

namespace SixFiveOhTwo::AdressingModes
{
    using Offset = uint8_t;
    using Count = uint8_t;

    template <typename Cpu>
    bool Implied(Cpu& cpu)
    {
        cpu.AluTemp = cpu.A;

        return false;
    }

    template <typename Cpu>
    bool Immediate(Cpu& cpu)
    {
        cpu.ProgramCounter++;

        cpu.AddressAbsolute = cpu.ProgramCounter;

        return false;
    }

    template <typename Cpu, typename Ram>
    bool Relative(Cpu& cpu, Ram& ram)
    {
        cpu.AddressAbsolute = ram.ReadIncrement(cpu.ProgramCounter);

        if (cpu.AddressAbsolute & 0x80)
        {
            cpu.AddressAbsolute |= 0xFF00;
        }

        return false;
    }

    namespace ZeroPage
    {
        template <typename Cpu, typename Ram>
        bool NoOffset(Cpu& cpu, Ram& ram, Offset offset = 0)
        {
            cpu.AddressAbsolute = ram.ReadIncrement(cpu.ProgramCounter) + offset;

            cpu.AddressAbsolute &= 0x00F;

            return false;
        }

        template <typename Cpu, typename Ram>
        bool XOffset(Cpu& cpu, Ram& ram)
        {
            return NoOffset(cpu, ram, cpu.X);
        }

        template <typename Cpu, typename Ram>
        bool YOffset(Cpu& cpu, Ram& ram)
        {
            return NoOffset(cpu, ram, cpu.Y);
        }
    }

    namespace Absolute
    {
        template <typename Cpu, typename Ram>
        bool NoOffset(Cpu& cpu, Ram& ram, Offset offset = 0)
        {
            auto low = ram.ReadIncrement(cpu.ProgramCounter);

            auto high = ram.ReadIncrement(cpu.ProgramCounter);

            cpu.AddressAbsolute = (high << 8) | low;
            cpu.AddressAbsolute += offset;

            if ((cpu.AddressAbsolute  & 0xFF00) != (high << 8))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        template <typename Cpu, typename Ram>
        bool XOffset(Cpu& cpu, Ram& ram)
        {
            return NoOffset(cpu, ram, cpu.X);
        }

        template <typename Cpu, typename Ram>
        bool YOffset(Cpu& cpu, Ram& ram)
        {
            return NoOffset(cpu, ram, cpu.Y);
        }
    }

    namespace Indirect
    {
        template <typename Cpu, typename Ram>
        bool NoOffset(Cpu& cpu, Ram& ram)
        {
            auto low = ram.ReadIncrement(cpu.ProgramCounter);

            auto high = ram.ReadIncrement(cpu.ProgramCounter);

            auto pointer = (high << 8) | low;

            if (pointer == 0x00FF)
            {
                auto low = ram.Read(pointer);
                auto high = ram.Read(pointer & 0xFF00);

                cpu.AddressAbsolute = (high << 8) | low;
            }
            else
            {
                auto low = ram.Read(pointer);
                auto high = ram.Read(pointer + 1);

                cpu.AddressAbsolute = (high << 8) | low;
            }

            return false;
        }

        template <typename Cpu, typename Ram>
        bool XOffset(Cpu& cpu, Ram& ram)
        {
            auto address = ram.ReadIncrement(cpu.ProgramCounter);

            auto lowAddress = address + cpu.X & 0x00FF;
            auto HighAddress = address + cpu.X + 1 & 0x00FF;

            auto low = ram.Read(lowAddress);
            auto high = ram.Read(HighAddress);

            cpu.AddressAbsolute = (high << 8) | low;

            return false;
        }

        template <typename Cpu, typename Ram>
        bool YOffset(Cpu& cpu, Ram& ram)
        {
            auto address = ram.ReadIncrement(cpu.ProgramCounter);

            auto low = ram.Read(address & 0x00FF);
            auto high = ram.Read((address + 1) & 0x00FF);

            cpu.AddressAbsolute = (high << 8) | low;
            cpu.AddressAbsolute += cpu.Y;

            if ((cpu.AddressAbsolute & 0xFF00) != (high << 8))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

