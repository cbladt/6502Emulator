#pragma once

namespace SixFiveOhTwo::Opcodes::CLI
{
	namespace _private
	{
		#include "CLI.impl.inc"
	}

	static const constexpr auto ImpliedOpCode = 88;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::CLI(cpu, value, cycles);

	}

}

