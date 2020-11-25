#pragma once

#include <AddressingModes.hpp>

namespace SixFiveOhTwo::Opcodes::AND
{
    namespace _private
    {
        template <typename Cpu, typename Value, typename Cycles>
        void And(Cpu& cpu, Value value, Cycles cycle)
        {
            cpu.A = (cpu.A & value);

            cpu.Zero = cpu.A == 0;

            cpu.Negative = sum & 0x80;
        }
    }

	template <typename Cpu, typename Ram, typename Cycles>
	void IndirectOffsetX(Cpu& cpu, Ram& ram, Cycles cycles)
	{
        AdressingModes::Indirect::XOffset(cpu, ram);
        auto value = ram.Read(cpu.ALUTemp);

        _private::And(cpu, value, cycles);
	}

	template <typename Cpu, typename Ram, typename Cycles>
	void Zero(Cpu& cpu, Ram& ram, Cycles cycles)
	{
        AdressingModes::

	}

	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{


	}

	template <typename Cpu, typename Ram, typename Cycles>
	void Absolute(Cpu& cpu, Ram& ram, Cycles cycles)
	{


	}

	template <typename Cpu, typename Ram, typename Cycles>
	void IndirectOffsetY(Cpu& cpu, Ram& ram, Cycles cycles)
	{


	}

	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroOffsetX(Cpu& cpu, Ram& ram, Cycles cycles)
	{


	}

	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteOffsetY(Cpu& cpu, Ram& ram, Cycles cycles)
	{


	}

	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteOffsetX(Cpu& cpu, Ram& ram, Cycles cycles)
	{


	}

}
