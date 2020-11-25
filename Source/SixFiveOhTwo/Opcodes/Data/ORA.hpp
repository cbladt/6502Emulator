#pragma once

namespace SixFiveOhTwo::Opcodes::ORA
{
	namespace _private
	{
		#include "ORA.impl.inc"
	}

	static const constexpr auto IndirectXOffsetOpCode = 1;
	template <typename Cpu, typename Ram, typename Cycles>
	void IndirectXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::ORA(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageOpCode = 5;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPage(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::ORA(cpu, value, cycles);

	}

	static const constexpr auto ImpliedOpCode = 9;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::ORA(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteOpCode = 13;
	template <typename Cpu, typename Ram, typename Cycles>
	void Absolute(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::ORA(cpu, value, cycles);

	}

	static const constexpr auto IndirectYOffsetOpCode = 17;
	template <typename Cpu, typename Ram, typename Cycles>
	void IndirectYOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::YOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::ORA(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageXOffsetOpCode = 21;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPageXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::ORA(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteYOffsetOpCode = 25;
	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteYOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::YOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::ORA(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteXOffsetOpCode = 29;
	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::ORA(cpu, value, cycles);

	}

}

