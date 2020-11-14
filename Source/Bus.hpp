#pragma once
#include <tuple>

template <typename Address_t, typename Data_t, typename ... Device_t>
class Bus
{
public:
    Bus(Device_t ... devices) :
        _devices(devices...)
    {}
    ~Bus() = default;

    Bus(const Bus&) = delete;
    Bus& operator=(const Bus&) = delete;

    Bus(Bus&&) = delete;
    Bus& operator=(Bus&&) = delete;

    void Transmit(Address_t address, Data_t data)
    {
        std::apply([this, address, data](auto&&... args) {(DoTransmit(address, data, args), ...);}, _devices);
    }

private:
    std::tuple<Device_t ...> _devices;

    template <typename T>
    void DoTransmit(Address_t address, Data_t data, T& t)
    {
        if (address >= t.AddressRangeStart && address < t.AddressRangeEnd)
        {
            t.Accept(address, data);
        }
    }
};
