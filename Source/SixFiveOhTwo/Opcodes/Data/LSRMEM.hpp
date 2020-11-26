#pragma once

namespace SixFiveOhTwo::Opcodes::LSRMEM
{
	namespace _private
	{
		#include "LSRMEM.impl.hpp"
	}

	static const constexpr auto ZeroPageOpCode = 70;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPage(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::LSRMEM(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteOpCode = 78;
	template <typename Cpu, typename Ram, typename Cycles>
	void Absolute(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::LSRMEM(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageXOffsetOpCode = 86;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPageXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::LSRMEM(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteXOffsetOpCode = 94;
	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::LSRMEM(cpu, value, cycles);

	}

}

