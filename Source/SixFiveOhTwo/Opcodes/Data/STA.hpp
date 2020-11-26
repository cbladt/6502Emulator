#pragma once

namespace SixFiveOhTwo::Opcodes::STA
{
	namespace _private
	{
		#include "STA.impl.hpp"
	}

	static const constexpr auto IndirectXOffsetOpCode = 129;
	template <typename Cpu, typename Ram, typename Cycles>
	void IndirectXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::STA(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageOpCode = 133;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPage(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::STA(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteOpCode = 141;
	template <typename Cpu, typename Ram, typename Cycles>
	void Absolute(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::STA(cpu, value, cycles);

	}

	static const constexpr auto IndirectYOffsetOpCode = 145;
	template <typename Cpu, typename Ram, typename Cycles>
	void IndirectYOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::YOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::STA(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageXOffsetOpCode = 149;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPageXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::STA(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteYOffsetOpCode = 153;
	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteYOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::YOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::STA(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteXOffsetOpCode = 157;
	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::STA(cpu, value, cycles);

	}

}

