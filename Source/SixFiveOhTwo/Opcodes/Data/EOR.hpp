#pragma once

namespace SixFiveOhTwo::Opcodes::EOR
{
	namespace _private
	{
		#include "EOR.impl.inc"
	}

	static const constexpr auto IndirectXOffsetOpCode = 65;
	template <typename Cpu, typename Ram, typename Cycles>
	void IndirectXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::EOR(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageOpCode = 69;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPage(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::EOR(cpu, value, cycles);

	}

	static const constexpr auto ImpliedOpCode = 73;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::EOR(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteOpCode = 77;
	template <typename Cpu, typename Ram, typename Cycles>
	void Absolute(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::EOR(cpu, value, cycles);

	}

	static const constexpr auto IndirectYOffsetOpCode = 81;
	template <typename Cpu, typename Ram, typename Cycles>
	void IndirectYOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::YOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::EOR(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageXOffsetOpCode = 85;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPageXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::EOR(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteYOffsetOpCode = 89;
	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteYOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::YOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::EOR(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteXOffsetOpCode = 93;
	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::EOR(cpu, value, cycles);

	}

}

