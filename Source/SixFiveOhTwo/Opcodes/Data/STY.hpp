#pragma once

namespace SixFiveOhTwo::Opcodes::STY
{
	namespace _private
	{
		#include "STY.impl.hpp"
	}

	static const constexpr auto ZeroPageOpCode = 132;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPage(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::STY(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteOpCode = 140;
	template <typename Cpu, typename Ram, typename Cycles>
	void Absolute(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::STY(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageXOffsetOpCode = 148;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPageXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::STY(cpu, value, cycles);

	}

}

