#pragma once

namespace SixFiveOhTwo::Opcodes::TXS
{
	namespace _private
	{
		#include "TXS.impl.inc"
	}

	static const constexpr auto ImpliedOpCode = 154;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::TXS(cpu, value, cycles);

	}

}

