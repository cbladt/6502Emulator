#pragma once

namespace SixFiveOhTwo::Opcodes::BVC
{
	namespace _private
	{
		#include "BVC.impl.inc"
	}

	static const constexpr auto ImpliedOpCode = 80;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::BVC(cpu, value, cycles);

	}

}

