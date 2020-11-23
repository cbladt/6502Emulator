#pragma once

namespace Opcodes
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
    };
}

