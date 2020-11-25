#pragma once

namespace SixFiveOhTwo::Opcodes::CPY
{
	namespace _private
	{
		#include "CPY.impl.inc"
	}

	static const constexpr auto ImpliedOpCode = 192;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::CPY(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageOpCode = 196;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPage(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::CPY(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteOpCode = 204;
	template <typename Cpu, typename Ram, typename Cycles>
	void Absolute(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::CPY(cpu, value, cycles);

	}

}

