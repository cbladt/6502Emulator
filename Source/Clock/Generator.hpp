#pragma once
#include <thread>

namespace Clock
{
    template <typename Child_t, uint32_t Frequency, uint32_t FrequencyFactor = 1000000>
    class Generator
    {
    public:
        constexpr Generator() :
            _frequency(FrequencyFactor / Frequency),            
            _child(*static_cast<Child_t*>(this))
        {}
        ~Generator() = default;

        Generator(const Generator&) = default;
        Generator& operator=(const Generator&) = default;

        Generator(Generator&&) = default;
        Generator& operator=(Generator&&) = default;

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
}
