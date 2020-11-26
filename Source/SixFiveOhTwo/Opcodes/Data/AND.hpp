#pragma once

namespace SixFiveOhTwo::Opcodes::AND
{
	namespace _private
	{
		#include "AND.impl.hpp"
	}

	static const constexpr auto IndirectXOffsetOpCode = 33;
	template <typename Cpu, typename Ram, typename Cycles>
	void IndirectXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::AND(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageOpCode = 37;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPage(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::AND(cpu, value, cycles);

	}

	static const constexpr auto ImpliedOpCode = 41;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::AND(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteOpCode = 45;
	template <typename Cpu, typename Ram, typename Cycles>
	void Absolute(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::AND(cpu, value, cycles);

	}

	static const constexpr auto IndirectYOffsetOpCode = 49;
	template <typename Cpu, typename Ram, typename Cycles>
	void IndirectYOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::YOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::AND(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageXOffsetOpCode = 53;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPageXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::AND(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteYOffsetOpCode = 57;
	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteYOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::YOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::AND(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteXOffsetOpCode = 61;
	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::AND(cpu, value, cycles);

	}

}

