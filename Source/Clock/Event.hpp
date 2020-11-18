#pragma once
#include <tuple>

namespace Clock
{
    template <typename ... Device_t>
    class Event
    {
    public:
        constexpr Event(Device_t& ... devices) :
                _devices(devices...)
            {}
        ~Event() = default;

        constexpr Event(const Event&) = delete;
        constexpr Event& operator=(const Event&) = delete;

        constexpr Event(Event&&) = delete;
        constexpr Event& operator=(Event&&) = delete;

        constexpr void Fire()
        {
            std::apply([this](auto&&... args) {(DoFire(args), ...);}, _devices);
        }

    private:
        std::tuple<Device_t& ...> _devices;

        template <typename T>
        constexpr void DoFire(T& t)
        {
            t.ClockEvent();
        }
    };
}
