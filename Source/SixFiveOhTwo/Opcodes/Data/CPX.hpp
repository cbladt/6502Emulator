#pragma once

namespace SixFiveOhTwo::Opcodes::CPX
{
	namespace _private
	{
		#include "CPX.impl.hpp"
	}

	static const constexpr auto ImpliedOpCode = 224;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::CPX(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageOpCode = 228;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPage(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::CPX(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteOpCode = 236;
	template <typename Cpu, typename Ram, typename Cycles>
	void Absolute(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::CPX(cpu, value, cycles);

	}

}

