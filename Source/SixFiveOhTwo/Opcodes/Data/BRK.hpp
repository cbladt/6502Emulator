#pragma once

namespace SixFiveOhTwo::Opcodes::BRK
{
	namespace _private
	{
		#include "BRK.impl.inc"
	}

	static const constexpr auto ImpliedOpCode = 0;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::BRK(cpu, value, cycles);

	}

}

