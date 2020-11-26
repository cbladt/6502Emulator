#pragma once

namespace SixFiveOhTwo::Opcodes::PLA
{
	namespace _private
	{
		#include "PLA.impl.hpp"
	}

	static const constexpr auto ImpliedOpCode = 104;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::PLA(cpu, value, cycles);

	}

}

