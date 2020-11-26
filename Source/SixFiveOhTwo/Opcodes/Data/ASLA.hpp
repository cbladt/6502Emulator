#pragma once

namespace SixFiveOhTwo::Opcodes::ASLA
{
	namespace _private
	{
		#include "ASLA.impl.hpp"
	}

	static const constexpr auto ImpliedOpCode = 10;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::ASLA(cpu, value, cycles);

	}

}

