#pragma once

namespace SixFiveOhTwo::Opcodes::INX
{
	namespace _private
	{
		#include "INX.impl.hpp"
	}

	static const constexpr auto ImpliedOpCode = 232;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::INX(cpu, value, cycles);

	}

}

