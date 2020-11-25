#pragma once

namespace SixFiveOhTwo::Opcodes::ROLMEM
{
	namespace _private
	{
		#include "ROLMEM.impl.inc"
	}

	static const constexpr auto ZeroPageOpCode = 38;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPage(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::ROLMEM(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteOpCode = 46;
	template <typename Cpu, typename Ram, typename Cycles>
	void Absolute(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::ROLMEM(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageXOffsetOpCode = 54;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPageXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::ROLMEM(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteXOffsetOpCode = 62;
	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::ROLMEM(cpu, value, cycles);

	}

}

