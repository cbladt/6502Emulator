#include "InstructionDecoding.hpp"
#include <Log>

namespace SixFiveOhTwo::Tasks
{
    InstructionDecoding::InstructionDecoding(CpuRegisters& cpu, Bus& bus) :
        _cpu(cpu),
        _bus(bus),
        _state(State::OpcodeProbe)
    {}

    void InstructionDecoding::ClockEvent()
    {
        switch(_state)
        {
            case State::OpcodeProbe:
            {
                OpcodeProbe();
                break;
            }

            case State::OpcodeGetAndHandle:
            {
                auto opcode = OpcodeGet();
                OpcodeHandle(opcode);
                break;
            }
        }
    }

    void InstructionDecoding::OpcodeProbe()
    {
        _bus.SetAddress(_cpu.ProgramCounter);
        _state = State::OpcodeGetAndHandle;
    }

    Opcode TranslateOpcode(uint8_t opcodeRaw)
    {
        return static_cast<Opcode>(opcodeRaw);
    }

    Opcode InstructionDecoding::OpcodeGet()
    {
        auto opcodeRaw = _bus.GetData();
        auto opcode = TranslateOpcode(opcodeRaw);

        return opcode;
    }

    void InstructionDecoding::OpcodeHandle(Opcode opcode)
    {
        switch (opcode)
        {
            default: // Fall-through to nop.
            case Opcode::NoOperation:
            {
                Log::Debug() << "Nop" << Log::EndLine;
                break;
            }
        }
    }
}
