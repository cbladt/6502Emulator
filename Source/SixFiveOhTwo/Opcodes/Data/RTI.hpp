#pragma once

namespace SixFiveOhTwo::Opcodes::RTI
{
	namespace _private
	{
		#include "RTI.impl.inc"
	}

	static const constexpr auto ImpliedOpCode = 64;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::RTI(cpu, value, cycles);

	}

}

