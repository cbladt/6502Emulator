#pragma once
#include <thread>

template <typename Child_t, uint32_t Frequency, uint32_t FrequencyFactor = 1000000>
class Clock
{
public:
    constexpr Clock() :
        _frequency(FrequencyFactor / Frequency),
        _child(*static_cast<Child_t*>(this))
    {}
    ~Clock() = default;

    Clock(const Clock&) = default;
    Clock& operator=(const Clock&) = default;

    Clock(Clock&&) = default;
    Clock& operator=(Clock&&) = default;

    void Run()
    {
        while (true)
        {
            _child.Fire();
            std::this_thread::sleep_for(std::chrono::microseconds(_frequency));
        }
    }

private:
    uint32_t _frequency;
    Child_t& _child;
};
