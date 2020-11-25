#pragma once

namespace SixFiveOhTwo::Opcodes::INC
{
	namespace _private
	{
		#include "INC.impl.inc"
	}

	static const constexpr auto ZeroPageOpCode = 230;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPage(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::INC(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteOpCode = 238;
	template <typename Cpu, typename Ram, typename Cycles>
	void Absolute(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::INC(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageXOffsetOpCode = 246;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPageXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::INC(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteXOffsetOpCode = 254;
	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::INC(cpu, value, cycles);

	}

}

