#pragma once

namespace SixFiveOhTwo::Opcodes::LDA
{
	namespace _private
	{
		#include "LDA.impl.hpp"
	}

	static const constexpr auto IndirectXOffsetOpCode = 161;
	template <typename Cpu, typename Ram, typename Cycles>
	void IndirectXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::LDA(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageOpCode = 165;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPage(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::LDA(cpu, value, cycles);

	}

	static const constexpr auto ImpliedOpCode = 169;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::LDA(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteOpCode = 173;
	template <typename Cpu, typename Ram, typename Cycles>
	void Absolute(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::LDA(cpu, value, cycles);

	}

	static const constexpr auto IndirectYOffsetOpCode = 177;
	template <typename Cpu, typename Ram, typename Cycles>
	void IndirectYOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::YOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::LDA(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageXOffsetOpCode = 181;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPageXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::LDA(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteYOffsetOpCode = 185;
	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteYOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::YOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::LDA(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteXOffsetOpCode = 189;
	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::LDA(cpu, value, cycles);

	}

}

