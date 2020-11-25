#pragma once

namespace SixFiveOhTwo::Opcodes::LDX
{
	namespace _private
	{
		#include "LDX.impl.inc"
	}

	static const constexpr auto ImpliedOpCode = 162;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::LDX(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageOpCode = 166;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPage(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::LDX(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteOpCode = 174;
	template <typename Cpu, typename Ram, typename Cycles>
	void Absolute(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::LDX(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageYOffsetOpCode = 182;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPageYOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::YOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::LDX(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteYOffsetOpCode = 190;
	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteYOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::YOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::LDX(cpu, value, cycles);

	}

}

