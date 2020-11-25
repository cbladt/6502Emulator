#pragma once

namespace SixFiveOhTwo::Opcodes::CLD
{
	namespace _private
	{
		#include "CLD.impl.inc"
	}

	static const constexpr auto ImpliedOpCode = 216;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::CLD(cpu, value, cycles);

	}

}

