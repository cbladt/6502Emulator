#pragma once

namespace SixFiveOhTwo::Opcodes::TSX
{
	namespace _private
	{
		#include "TSX.impl.inc"
	}

	static const constexpr auto ImpliedOpCode = 186;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::TSX(cpu, value, cycles);

	}

}

