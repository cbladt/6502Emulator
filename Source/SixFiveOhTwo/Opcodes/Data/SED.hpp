#pragma once

namespace SixFiveOhTwo::Opcodes::SED
{
	namespace _private
	{
		#include "SED.impl.hpp"
	}

	static const constexpr auto ImpliedOpCode = 248;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::SED(cpu, value, cycles);

	}

}

