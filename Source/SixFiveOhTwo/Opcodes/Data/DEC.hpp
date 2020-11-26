#pragma once

namespace SixFiveOhTwo::Opcodes::DEC
{
	namespace _private
	{
		#include "DEC.impl.hpp"
	}

	static const constexpr auto ZeroPageOpCode = 198;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPage(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::DEC(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteOpCode = 206;
	template <typename Cpu, typename Ram, typename Cycles>
	void Absolute(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::DEC(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageXOffsetOpCode = 214;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPageXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::DEC(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteXOffsetOpCode = 222;
	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::DEC(cpu, value, cycles);

	}

}

