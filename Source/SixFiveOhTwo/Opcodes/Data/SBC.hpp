#pragma once

namespace SixFiveOhTwo::Opcodes::SBC
{
	namespace _private
	{
		#include "SBC.impl.hpp"
	}

	static const constexpr auto IndirectXOffsetOpCode = 225;
	template <typename Cpu, typename Ram, typename Cycles>
	void IndirectXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::SBC(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageOpCode = 229;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPage(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::SBC(cpu, value, cycles);

	}

	static const constexpr auto ImpliedOpCode = 233;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::SBC(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteOpCode = 237;
	template <typename Cpu, typename Ram, typename Cycles>
	void Absolute(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::SBC(cpu, value, cycles);

	}

	static const constexpr auto IndirectYOffsetOpCode = 241;
	template <typename Cpu, typename Ram, typename Cycles>
	void IndirectYOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::YOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::SBC(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageXOffsetOpCode = 245;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPageXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::SBC(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteYOffsetOpCode = 249;
	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteYOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::YOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::SBC(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteXOffsetOpCode = 253;
	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::SBC(cpu, value, cycles);

	}

}

