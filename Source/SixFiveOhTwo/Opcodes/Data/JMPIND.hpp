#pragma once

namespace SixFiveOhTwo::Opcodes::JMPIND
{
	namespace _private
	{
		#include "JMPIND.impl.inc"
	}

	static const constexpr auto ImpliedOpCode = 108;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::JMPIND(cpu, value, cycles);

	}

}

