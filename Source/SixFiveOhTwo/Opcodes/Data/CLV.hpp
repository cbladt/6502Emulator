#pragma once

namespace SixFiveOhTwo::Opcodes::CLV
{
	namespace _private
	{
		#include "CLV.impl.hpp"
	}

	static const constexpr auto ImpliedOpCode = 184;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::CLV(cpu, value, cycles);

	}

}

