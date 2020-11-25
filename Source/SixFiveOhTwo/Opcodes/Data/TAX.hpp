#pragma once

namespace SixFiveOhTwo::Opcodes::TAX
{
	namespace _private
	{
		#include "TAX.impl.inc"
	}

	static const constexpr auto ImpliedOpCode = 170;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::TAX(cpu, value, cycles);

	}

}

