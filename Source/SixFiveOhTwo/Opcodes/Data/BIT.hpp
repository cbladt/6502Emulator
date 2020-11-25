#pragma once

namespace SixFiveOhTwo::Opcodes::BIT
{
	namespace _private
	{
		#include "BIT.impl.inc"
	}

	static const constexpr auto ZeroPageOpCode = 36;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPage(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::BIT(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteOpCode = 44;
	template <typename Cpu, typename Ram, typename Cycles>
	void Absolute(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::BIT(cpu, value, cycles);

	}

}

