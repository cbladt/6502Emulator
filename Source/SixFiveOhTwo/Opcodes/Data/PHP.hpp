#pragma once

namespace SixFiveOhTwo::Opcodes::PHP
{
	namespace _private
	{
		#include "PHP.impl.inc"
	}

	static const constexpr auto ImpliedOpCode = 8;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::PHP(cpu, value, cycles);

	}

}

