#pragma once

namespace SixFiveOhTwo::Opcodes::BNE
{
	namespace _private
	{
		#include "BNE.impl.hpp"
	}

	static const constexpr auto ImpliedOpCode = 208;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::BNE(cpu, value, cycles);

	}

}

