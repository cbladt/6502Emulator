#pragma once

namespace SixFiveOhTwo::Opcodes::BCS
{
	namespace _private
	{
		#include "BCS.impl.hpp"
	}

	static const constexpr auto ImpliedOpCode = 176;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::BCS(cpu, value, cycles);

	}

}

