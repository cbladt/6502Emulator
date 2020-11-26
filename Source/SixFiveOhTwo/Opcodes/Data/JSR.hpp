#pragma once

namespace SixFiveOhTwo::Opcodes::JSR
{
	namespace _private
	{
		#include "JSR.impl.hpp"
	}

	static const constexpr auto ImpliedOpCode = 32;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::JSR(cpu, value, cycles);

	}

}

