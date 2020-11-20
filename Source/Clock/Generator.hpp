#pragma once
#include <thread>

namespace Clock::Generator
{
    template <typename Event_t, typename Duration_t>
    void Run(Event_t& event, Duration_t duration)
    {        
        while (true)
        {
            std::this_thread::sleep_for(duration);
            event.Fire();                        
        }
    }
}
