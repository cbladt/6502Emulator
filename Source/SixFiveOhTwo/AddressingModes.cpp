#include "AddressingModes.hpp"

namespace SixFiveOhTwo::AdressingModes
{
    bool Implied(CpuState& cpu)
    {
        cpu.AluTemp = cpu.A;

        return false;
    }

    bool Immediate(CpuState& cpu)
    {
        cpu.ProgramCounter++;

        cpu.AddressAbsolute = cpu.ProgramCounter;

        return false;
    }

    bool ZeroPage(CpuState& cpu, Ram& ram, uint8_t offset)
    {
        cpu.AddressAbsolute = ram.ReadIncrement(cpu.ProgramCounter) + offset;

        cpu.AddressAbsolute &= 0x00F;

        return false;
    }

    bool Relative(CpuState& cpu, Ram& ram)
    {
        cpu.AddressAbsolute = ram.ReadIncrement(cpu.ProgramCounter);

        if (cpu.AddressAbsolute & 0x80)
        {
            cpu.AddressAbsolute |= 0xFF00;
        }

        return false;
    }

    bool Absolute(CpuState& cpu, Ram& ram, uint8_t offset)
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

    bool Indirect(CpuState& cpu, Ram& ram)
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

    bool IndirectXOffset(CpuState& cpu, Ram& ram)
    {
        auto address = ram.ReadIncrement(cpu.ProgramCounter);

        auto lowAddress = static_cast<uint16_t>(address + cpu.X) & 0x00FF;
        auto HighAddress = static_cast<uint16_t>(address + cpu.X + 1) & 0x00FF;

        auto low = ram.Read(lowAddress);
        auto high = ram.Read(HighAddress);

        cpu.AddressAbsolute = (high << 8) | low;

        return false;
    }

    bool IndirectYOffset(CpuState& cpu, Ram& ram)
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
