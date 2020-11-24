#pragma once

#include <AddressingModes.hpp>

namespace SixFiveOhTwo::Opcodes::ADC
{
    namespace _private
    {
        template <typename Cpu, typename Cycles, typename Value>
        void Adc(Cpu& cpu, Cycles cycles, Value value)
        {
            auto a = static_cast<Value>(cpu.A);
            auto c = static_cast<Value>(cpu.CarryBit ? 1 : 0);

            auto sum = static_cast<Value>(a + c + value);

            cpu.CarryBit = sum > 255;

            cpu.Zero = (sum & 0x00FF) == 0;

            cpu.Overflow = (~(a ^ value) & (a ^ sum)) & 0x0080;

            cpu.Negative = sum & 0x80;

            cpu.A = sum & 0x00FF;

            cpu.CyclesLeft += cycles;
        }
    }

	template <typename Cpu, typename Ram, typename Cycles>
	void IndirectOffsetX(Cpu& cpu, Ram& ram, Cycles cycles)
	{
        AdressingModes::Indirect::XOffset(cpu, ram);
        auto value = ram.Read(cpu.ALUTemp);

        _private::Adc(cpu, cycles, value);
	}

	template <typename Cpu, typename Ram, typename Cycles>
	void Zero(Cpu& cpu, Ram& ram, Cycles cycles)
	{
        AdressingModes::ZeroPage::NoOffset(cpu, ram);
        auto value = ram.Read(cpu.ALUTemp);

        _private::Adc(cpu, cycles, value);
	}

	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{
        AdressingModes::Implied(cpu);
        auto value = ram.Read(cpu.ALUTemp);

        _private::Adc(cpu, cycles, value);

	}

	template <typename Cpu, typename Ram, typename Cycles>
	void Absolute(Cpu& cpu, Ram& ram, Cycles cycles)
	{
        AdressingModes::Absolute::NoOffset(cpu, ram);
        auto value = ram.Read(cpu.ALUTemp);

        _private::Adc(cpu, cycles, value);

	}

	template <typename Cpu, typename Ram, typename Cycles>
	void IndirectOffsetY(Cpu& cpu, Ram& ram, Cycles cycles)
	{
        AdressingModes::Indirect::YOffset(cpu, ram);
        auto value = ram.Read(cpu.ALUTemp);

        _private::Adc(cpu, cycles, value);

	}

	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroOffsetX(Cpu& cpu, Ram& ram, Cycles cycles)
	{
        AdressingModes::ZeroPage::XOffset(cpu, ram);
        auto value = ram.Read(cpu.ALUTemp);

        _private::Adc(cpu, cycles, value);

	}

	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteOffsetY(Cpu& cpu, Ram& ram, Cycles cycles)
	{
        AdressingModes::Absolute::YOffset(cpu, ram);
        auto value = ram.Read(cpu.ALUTemp);

        _private::Adc(cpu, cycles, value);

	}

	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteOffsetX(Cpu& cpu, Ram& ram, Cycles cycles)
	{
        AdressingModes::Absolute::XOffset(cpu, ram);
        auto value = ram.Read(cpu.ALUTemp);

        _private::Adc(cpu, cycles, value);

	}
}
