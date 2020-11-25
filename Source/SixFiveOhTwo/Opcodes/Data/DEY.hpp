#pragma once

namespace SixFiveOhTwo::Opcodes::DEY
{
	namespace _private
	{
		#include "DEY.impl.inc"
	}

	static const constexpr auto ImpliedOpCode = 136;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::DEY(cpu, value, cycles);

	}

}

