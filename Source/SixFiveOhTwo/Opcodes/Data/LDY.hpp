#pragma once

namespace SixFiveOhTwo::Opcodes::LDY
{
	namespace _private
	{
		#include "LDY.impl.hpp"
	}

	static const constexpr auto ImpliedOpCode = 160;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::LDY(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageOpCode = 164;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPage(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::LDY(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteOpCode = 172;
	template <typename Cpu, typename Ram, typename Cycles>
	void Absolute(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::LDY(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageXOffsetOpCode = 180;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPageXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::LDY(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteXOffsetOpCode = 188;
	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::LDY(cpu, value, cycles);

	}

}

