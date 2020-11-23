#pragma once
#include <tuple>
#include <Log>

#include <Opcodes/NoOperation.hpp>

namespace SixFiveOhTwo
{
    class CpuOpcodes
    {
    protected:

        std::tuple<
            Opcodes::NoOperation
        > _opcodes;
    };
}
