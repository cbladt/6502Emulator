#pragma once

namespace SixFiveOhTwo::Opcodes::JMP
{
	namespace _private
	{
		#include "JMP.impl.hpp"
	}

	static const constexpr auto ImpliedOpCode = 76;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::JMP(cpu, value, cycles);

	}

}

