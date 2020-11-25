#pragma once

namespace SixFiveOhTwo::Opcodes::BPL
{
	namespace _private
	{
		#include "BPL.impl.inc"
	}

	static const constexpr auto ImpliedOpCode = 16;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::BPL(cpu, value, cycles);

	}

}

