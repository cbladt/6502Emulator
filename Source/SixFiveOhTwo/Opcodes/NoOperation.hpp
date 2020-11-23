#pragma once
#include <CpuRegisters.hpp>

namespace SixFiveOhTwo::Opcodes
{
    class NoOperation
    {
    public:
        NoOperation() = default;
        ~NoOperation() = default;

        NoOperation(const NoOperation&) = delete;
        NoOperation& operator=(const NoOperation&) = delete;

        NoOperation(NoOperation&&) = delete;
        NoOperation& operator=(NoOperation&&) = delete;

        void Execute(CpuRegisters& cpu);
    };
}

