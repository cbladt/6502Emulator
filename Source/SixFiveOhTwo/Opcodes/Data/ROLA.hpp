#pragma once

namespace SixFiveOhTwo::Opcodes::ROLA
{
	namespace _private
	{
		#include "ROLA.impl.hpp"
	}

	static const constexpr auto ImpliedOpCode = 42;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::ROLA(cpu, value, cycles);

	}

}

