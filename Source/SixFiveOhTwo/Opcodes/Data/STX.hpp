#pragma once

namespace SixFiveOhTwo::Opcodes::STX
{
	namespace _private
	{
		#include "STX.impl.hpp"
	}

	static const constexpr auto ZeroPageOpCode = 134;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPage(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::STX(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteOpCode = 142;
	template <typename Cpu, typename Ram, typename Cycles>
	void Absolute(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::STX(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageYOffsetOpCode = 150;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPageYOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::YOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::STX(cpu, value, cycles);

	}

}

