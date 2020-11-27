#pragma once
#include <cstdint>
#include <array>
#include <cstddef>

namespace Memory
{
    template <size_t size>
    class GenericMemory
    {
    public:
        constexpr GenericMemory() :
            _data({0})
        {};
        ~GenericMemory() = default;

        using Data = uint8_t;
        using Address = uint16_t;
        constexpr static const auto Size = size + 1;

        constexpr GenericMemory(const GenericMemory&) = delete;
        constexpr GenericMemory& operator=(const GenericMemory&) = delete;

        constexpr GenericMemory(GenericMemory&&) = delete;
        constexpr GenericMemory& operator=(GenericMemory&&) = delete;

        constexpr Data Read(Address address)
        {
            return _data.at(address);
        }

        constexpr void Write(Address address, Data data)
        {
            _data.at(address) = data;
        }

    private:
        std::array<Data, Size> _data;
    };

    template <typename Ram_t, size_t Start>
    class GenericStack
    {
    public:
        using Data = typename Ram_t::Data;
        using Address = typename Ram_t::Address;

        GenericStack(Ram_t& ram) :
            _ram(ram),
            _pointer(0)
        {}
        ~GenericStack() = default;

        constexpr GenericStack(const GenericStack&) = delete;
        constexpr GenericStack& operator=(const GenericStack&) = delete;

        constexpr GenericStack(GenericStack&&) = delete;
        constexpr GenericStack& operator=(GenericStack&&) = delete;

        constexpr void Push(Data value)
        {
            auto addr = GetAddress();
            _pointer++;
            _ram.Write(addr, value);
        }

        constexpr Data Pop()
        {
            _pointer--;
            auto addr = GetAddress();
            return _ram.Read(addr);
        }

        template <typename Offset = int>
        constexpr Data Peek(Offset offset = -1)
        {
            auto addr = GetAddress() - offset;
            return _ram.Read(addr);
        }

    private:
        Ram_t& _ram;
        size_t _pointer;

        constexpr size_t GetAddress() const
        {
            return Start - _pointer;
        }
    };

    using Ram = GenericMemory<0xFFFF>;
    using Stack = GenericStack<Ram, 0x100>;
}


































