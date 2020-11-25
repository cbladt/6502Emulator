#pragma once

namespace SixFiveOhTwo::Opcodes::PHA
{
	namespace _private
	{
		#include "PHA.impl.inc"
	}

	static const constexpr auto ImpliedOpCode = 72;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::PHA(cpu, value, cycles);

	}

}

