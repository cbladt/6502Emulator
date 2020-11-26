#pragma once

namespace SixFiveOhTwo::Opcodes::LSRA
{
	namespace _private
	{
		#include "LSRA.impl.hpp"
	}

	static const constexpr auto ImpliedOpCode = 74;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::LSRA(cpu, value, cycles);

	}

}

