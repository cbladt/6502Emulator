#pragma once

namespace SixFiveOhTwo::Opcodes::RORA
{
	namespace _private
	{
		#include "RORA.impl.inc"
	}

	static const constexpr auto ImpliedOpCode = 106;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::RORA(cpu, value, cycles);

	}

}

