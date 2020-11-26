#pragma once

namespace SixFiveOhTwo::AddressingModes
{
    using Offset = unsigned char;

    template <typename Cpu, typename Ram>
    bool Implied(Cpu& cpu, Ram&)
    {
        cpu.Temp = cpu.A;

        return false;
    }

    template <typename Cpu, typename Ram>
    bool Immediate(Cpu& cpu, Ram&)
    {
        cpu.ProgramCounter++;

        cpu.Temp = cpu.ProgramCounter;

        return false;
    }

    template <typename Cpu, typename Ram>
    bool Relative(Cpu& cpu, Ram& ram)
    {
        cpu.ALUTemp = ram.ReadIncrement(cpu.ProgramCounter);

        if (cpu.Temp & 0x80)
        {
            cpu.Temp |= 0xFF00;
        }

        return false;
    }

    namespace ZeroPage
    {
        template <typename Cpu, typename Ram>
        bool NoOffset(Cpu& cpu, Ram& ram, Offset offset = 0)
        {
            cpu.Temp = ram.Read(cpu.ProgramCounter) + offset;
            cpu.ProgramCounter++;

            cpu.Temp &= 0x00F;

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
            auto low = ram.Read(cpu.ProgramCounter);
            cpu.ProgramCounter++;

            auto high = ram.Read(cpu.ProgramCounter);
            cpu.ProgramCounter++;

            cpu.Temp = (high << 8) | low;
            cpu.Temp += offset;

            if ((cpu.Temp  & 0xFF00) != (high << 8))
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

                cpu.ALUTemp = (high << 8) | low;
            }
            else
            {
                auto low = ram.Read(pointer);
                auto high = ram.Read(pointer + 1);

                cpu.ALUTemp = (high << 8) | low;
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

            cpu.ALUTemp = (high << 8) | low;

            return false;
        }

        template <typename Cpu, typename Ram>
        bool YOffset(Cpu& cpu, Ram& ram)
        {
            auto address = ram.ReadIncrement(cpu.ProgramCounter);

            auto low = ram.Read(address & 0x00FF);
            auto high = ram.Read((address + 1) & 0x00FF);

            cpu.ALUTemp = (high << 8) | low;
            cpu.ALUTemp += cpu.Y;

            if ((cpu.ALUTemp & 0xFF00) != (high << 8))
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

