#pragma once
#include <variant>
#include <Log>

#include <Opcodes/NoOperation.hpp>

class CpuOpcodes
{
protected:
    enum class Id
    {
        Nop,
    };

    using OpcodeType = std::variant<
    Opcodes::NoOperation*,
    int
    >;

    Opcodes::NoOperation _nop;

    template <typename Lookup_t>
    OpcodeType& GetOpcode(Lookup_t lookup)
    {
        auto id = static_cast<Id>(lookup);

        switch(id)
        {
            case Id::Nop: return _nop;
        }

        Log::Error() << "Invalid Opcode: " << byte << Log::EndLine;
    }

};
