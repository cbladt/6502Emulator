#pragma once

#include <CpuRegisters.hpp>
#include <Bus.hpp>
#include <OpcodeIdentifier.hpp>

namespace SixFiveOhTwo::Tasks
{
    class InstructionDecoding
    {
    public:
        InstructionDecoding(CpuRegisters& cpu, Bus& bus);
        ~InstructionDecoding() = default;

        InstructionDecoding(const InstructionDecoding&) = delete;
        InstructionDecoding& operator=(const InstructionDecoding&) = delete;

        InstructionDecoding(InstructionDecoding&&) = delete;
        InstructionDecoding& operator=(InstructionDecoding&&) = delete;

        void ClockEvent();

    private:
        enum class State
        {
            OpcodeProbe,
            OpcodeGetAndHandle
        };

        CpuRegisters& _cpu;
        Bus& _bus;
        State _state;

        void OpcodeProbe();
        Opcode OpcodeGet();
        void OpcodeHandle(Opcode opcode);
    };
}
