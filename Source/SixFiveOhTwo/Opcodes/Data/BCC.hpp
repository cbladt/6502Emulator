#pragma once

namespace SixFiveOhTwo::Opcodes::BCC
{
	namespace _private
	{
		#include "BCC.impl.hpp"
	}

	static const constexpr auto ImpliedOpCode = 144;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::BCC(cpu, value, cycles);

	}

}

