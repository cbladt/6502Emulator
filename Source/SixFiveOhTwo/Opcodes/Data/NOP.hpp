#pragma once

namespace SixFiveOhTwo::Opcodes::NOP
{
	namespace _private
	{
		#include "NOP.impl.hpp"
	}

	static const constexpr auto ImpliedOpCode = 234;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::NOP(cpu, value, cycles);

	}

}

