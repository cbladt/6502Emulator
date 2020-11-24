#pragma once

namespace SixFiveOhTwo::Opcodes::BRK
{
	template <typename Cpu, typename Ram, typename Cycles>
    void Implied(Cpu&, Ram&, Cycles)
	{
        throw "Not implemented";
	}

}
