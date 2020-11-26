#pragma once

namespace SixFiveOhTwo::Opcodes::CMP
{
	namespace _private
	{
		#include "CMP.impl.hpp"
	}

	static const constexpr auto IndirectXOffsetOpCode = 193;
	template <typename Cpu, typename Ram, typename Cycles>
	void IndirectXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::CMP(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageOpCode = 197;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPage(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::CMP(cpu, value, cycles);

	}

	static const constexpr auto ImpliedOpCode = 201;
	template <typename Cpu, typename Ram, typename Cycles>
	void Implied(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Implied(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::CMP(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteOpCode = 205;
	template <typename Cpu, typename Ram, typename Cycles>
	void Absolute(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::NoOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::CMP(cpu, value, cycles);

	}

	static const constexpr auto IndirectYOffsetOpCode = 209;
	template <typename Cpu, typename Ram, typename Cycles>
	void IndirectYOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::YOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::CMP(cpu, value, cycles);

	}

	static const constexpr auto ZeroPageXOffsetOpCode = 213;
	template <typename Cpu, typename Ram, typename Cycles>
	void ZeroPageXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::ZeroPage::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::CMP(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteYOffsetOpCode = 217;
	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteYOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::YOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::CMP(cpu, value, cycles);

	}

	static const constexpr auto AbsoluteXOffsetOpCode = 221;
	template <typename Cpu, typename Ram, typename Cycles>
	void AbsoluteXOffset(Cpu& cpu, Ram& ram, Cycles cycles)
	{

		AddressingModes::Absolute::XOffset(cpu, ram);
		auto value = ram.Read(cpu.Temp);
		_private::CMP(cpu, value, cycles);

	}

}

