#pragma once

namespace SixFiveOhTwo::Opcodes::PLP
{
	namespace _private
	{
		#include "PLP.impl.hpp"
	}

	static const constexpr auto ImpliedOpCode = 40;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::PLP(cpu, value, cycles);

	}

}

