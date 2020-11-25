#pragma once

namespace SixFiveOhTwo::Opcodes::RORMEM
{
	namespace _private
	{
		#include "RORMEM.impl.inc"
	}

	static const constexpr auto ZeroPageOpCode = 102;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPage(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::RORMEM(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteOpCode = 110;
	template <typename Cpu, typename Ram, typename Cycles>
	void Absolute(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::RORMEM(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageXOffsetOpCode = 118;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPageXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::RORMEM(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteXOffsetOpCode = 126;
	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::RORMEM(cpu, value, cycles);

	}

}

