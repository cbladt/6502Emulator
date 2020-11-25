#pragma once

namespace SixFiveOhTwo::Opcodes::TAY
{
	namespace _private
	{
		#include "TAY.impl.inc"
	}

	static const constexpr auto ImpliedOpCode = 168;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::TAY(cpu, value, cycles);

	}

}

