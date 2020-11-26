#pragma once

namespace SixFiveOhTwo::Opcodes::RTS
{
	namespace _private
	{
		#include "RTS.impl.hpp"
	}

	static const constexpr auto ImpliedOpCode = 96;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::RTS(cpu, value, cycles);

	}

}

