#pragma once

namespace SixFiveOhTwo::Opcodes::SEC
{
	namespace _private
	{
		#include "SEC.impl.hpp"
	}

	static const constexpr auto ImpliedOpCode = 56;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::SEC(cpu, value, cycles);

	}

}

