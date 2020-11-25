#pragma once

namespace SixFiveOhTwo::Opcodes::SEI
{
	namespace _private
	{
		#include "SEI.impl.inc"
	}

	static const constexpr auto ImpliedOpCode = 120;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::SEI(cpu, value, cycles);

	}

}

