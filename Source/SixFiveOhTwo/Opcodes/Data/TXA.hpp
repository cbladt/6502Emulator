#pragma once

namespace SixFiveOhTwo::Opcodes::TXA
{
	namespace _private
	{
		#include "TXA.impl.hpp"
	}

	static const constexpr auto ImpliedOpCode = 138;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::TXA(cpu, value, cycles);

	}

}

