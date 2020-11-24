#pragma once

#include <Ram.hpp>
#include <CpuState.hpp>

namespace SixFiveOhTwo::AdressingModes
{
    bool Implied(CpuState& cpu);

    bool Immediate(CpuState& cpu);

    bool ZeroPage(CpuState& cpu, Ram& ram, uint8_t offset = 0);

    template <typename T1, typename T2>
    bool ZeroPageXOffset(T1& cpu, T2& ram)
    {
        return ZeroPage(cpu, ram, cpu.X);
    }

    template <typename T1, typename T2>
    bool ZeroPageYOffset(T1& cpu, T2& ram)
    {
        return ZeroPage(cpu, ram, cpu.Y);
    }

    bool Relative(CpuState& cpu, Ram& ram);

    bool Absolute(CpuState& cpu, Ram& ram, uint8_t offset = 0);

    template <typename T1, typename T2>
    bool AbsoluteXOffset(T1& cpu, T2& ram)
    {
        return Absolute(cpu, ram, cpu.X);
    }

    template <typename T1, typename T2>
    bool AbsoluteYOffset(T1& cpu, T2& ram)
    {
        return Absolute(cpu, ram, cpu.Y);
    }

    bool Indirect(CpuState& cpu, Ram& ram);

    bool IndirectXOffset(CpuState& cpu, Ram& ram);
}

