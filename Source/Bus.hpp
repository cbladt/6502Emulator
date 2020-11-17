#pragma once
#include <tuple>

template <typename Address_t, typename Data_t, typename ... Device_t>
class Bus
{
public:
    using AddressType = Address_t;
    using DataType = Data_t;
    using DeviceType = Device_t;

    constexpr Bus(DeviceType ... devices) :
        _devices(devices...)
    {}
    ~Bus() = default;

    constexpr Bus(const Bus&) = delete;
    constexpr Bus& operator=(const Bus&) = delete;

    constexpr Bus(Bus&&) = delete;
    constexpr Bus& operator=(Bus&&) = delete;

    constexpr void Clock()
    {
        std::apply([this](auto&&... args) {(DoClock(args), ...);}, _devices);
    }

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

private:
    std::tuple<DeviceType ...> _devices;

    AddressType _address;
    DataType _data;

    template <typename T>
    constexpr void DoClock(T& t)
    {        
        t.ClockEvent();
    }
};
