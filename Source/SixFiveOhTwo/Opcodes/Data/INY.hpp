#pragma once

namespace SixFiveOhTwo::Opcodes::INY
{
	namespace _private
	{
		#include "INY.impl.hpp"
	}

	static const constexpr auto ImpliedOpCode = 200;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::INY(cpu, value, cycles);

	}

}

