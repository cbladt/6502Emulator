#pragma once

namespace SixFiveOhTwo::Opcodes::NoOperation
{
    template <typename Cpu_t>
    void Execute(Cpu_t& cpu)
    {
        cpu.CyclesLeft += 2;
    }
}

