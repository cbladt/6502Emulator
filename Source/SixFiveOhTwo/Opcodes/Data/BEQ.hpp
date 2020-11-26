#pragma once

namespace SixFiveOhTwo::Opcodes::BEQ
{
	namespace _private
	{
		#include "BEQ.impl.hpp"
	}

	static const constexpr auto ImpliedOpCode = 240;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::BEQ(cpu, value, cycles);

	}

}

