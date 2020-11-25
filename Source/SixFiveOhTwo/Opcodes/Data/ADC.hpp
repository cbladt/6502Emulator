#pragma once

namespace SixFiveOhTwo::Opcodes::ADC
{
	namespace _private
	{
		#include "ADC.impl.inc"
	}

	static const constexpr auto IndirectXOffsetOpCode = 97;
	template <typename Cpu, typename Ram, typename Cycles>
	void IndirectXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::ADC(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageOpCode = 101;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPage(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::ADC(cpu, value, cycles);

	}

	static const constexpr auto ImpliedOpCode = 105;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::ADC(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteOpCode = 109;
	template <typename Cpu, typename Ram, typename Cycles>
	void Absolute(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::ADC(cpu, value, cycles);

	}

	static const constexpr auto IndirectYOffsetOpCode = 113;
	template <typename Cpu, typename Ram, typename Cycles>
	void IndirectYOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::YOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::ADC(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageXOffsetOpCode = 117;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPageXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::ADC(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteYOffsetOpCode = 121;
	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteYOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::YOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::ADC(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteXOffsetOpCode = 125;
	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::ADC(cpu, value, cycles);

	}

}

