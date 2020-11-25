#pragma once

namespace SixFiveOhTwo::Opcodes::CLC
{
	namespace _private
	{
		#include "CLC.impl.inc"
	}

	static const constexpr auto ImpliedOpCode = 24;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::CLC(cpu, value, cycles);

	}

}

