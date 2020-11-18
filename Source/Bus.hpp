#pragma once
#include <cstdint>

class Bus
{
public:
    using AddressType = std::uint16_t;
    using DataType = std::uint8_t;

    enum class Operation
    {
        Read,
        Write
    };

    constexpr Bus() :
        _address(0),
        _data(0),
        _operation(Operation::Read)
    {}
    ~Bus() = default;

    constexpr Bus(const Bus&) = delete;
    constexpr Bus& operator=(const Bus&) = delete;

    constexpr Bus(Bus&&) = delete;
    constexpr Bus& operator=(Bus&&) = delete;

    constexpr void SetAddress(AddressType address)
    {
        _address = address;
    }

    constexpr AddressType GetAddress() const
    {
        return _address;
    }

    constexpr void SetData(DataType data)
    {
        _data = data;
    }

    constexpr DataType GetData() const
    {
        return _data;
    }

    constexpr void SetOperation(Operation operation)
    {
        _operation = operation;
    }

    constexpr Operation GetOperation() const
    {
        return _operation;
    }

private:    
    AddressType _address;
    DataType _data;
    Operation _operation;
};
