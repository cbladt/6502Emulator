#pragma once

namespace SixFiveOhTwo::Opcodes::NOP
{
	template <typename Cpu, typename Ram, typename Cycles>
    void Implied(Cpu& cpu, Ram&, Cycles cycles)
	{
        cpu.CyclesLeft += cycles;
	}

}
