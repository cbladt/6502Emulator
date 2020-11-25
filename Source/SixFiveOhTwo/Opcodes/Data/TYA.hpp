#pragma once

namespace SixFiveOhTwo::Opcodes::TYA
{
	namespace _private
	{
		#include "TYA.impl.inc"
	}

	static const constexpr auto ImpliedOpCode = 152;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::TYA(cpu, value, cycles);

	}

}

