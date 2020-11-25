#pragma once

namespace SixFiveOhTwo::Opcodes::BMI
{
	namespace _private
	{
		#include "BMI.impl.inc"
	}

	static const constexpr auto ImpliedOpCode = 48;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::BMI(cpu, value, cycles);

	}

}

