#pragma once

namespace SixFiveOhTwo::Opcodes::BVS
{
	namespace _private
	{
		#include "BVS.impl.hpp"
	}

	static const constexpr auto ImpliedOpCode = 112;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::BVS(cpu, value, cycles);

	}

}

