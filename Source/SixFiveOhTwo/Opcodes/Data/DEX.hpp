#pragma once

namespace SixFiveOhTwo::Opcodes::DEX
{
	namespace _private
	{
		#include "DEX.impl.inc"
	}

	static const constexpr auto ImpliedOpCode = 202;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::DEX(cpu, value, cycles);

	}

}

