#pragma once
#include <iostream>

namespace Log
{
    namespace _private
    {
        template <bool Enabled>
        class Logger
        {
        public:
            Logger() = default;
            ~Logger() = default;

            Logger(const Logger&) = delete;
            Logger& operator=(const Logger&) = delete;

            Logger(Logger&&) = delete;
            Logger& operator=(Logger&&) = delete;

            template <typename T>
            Logger<Enabled>& operator <<(T& message)
            {
                if constexpr(Enabled)
                {
                    std::cout << message;
                }

                return *this;
            }
        };

        Logger<true> _realLogger;
        Logger<false> _fakeLogger;
    }

    constexpr const auto EndLine = "\r\n";

    enum class Level
    {
        Debug,
        Error
    };

#ifdef LOG_DEBUG
    constexpr const Level LogLevel = Level::Debug;
#else
    constexpr const Level LogLevel = Level::Error;
#endif

    constexpr bool IsEnabled(const Level test)
    {
        return test >= LogLevel;
    }

    auto& Debug()
    {
        if constexpr(IsEnabled(Level::Debug))
        {
            return _private::_realLogger;
        }
        else
        {
            return _private::_fakeLogger;
        }
    }

    auto& Error()
    {
        if constexpr(IsEnabled(Level::Error))
        {
            return _private::_realLogger;
        }
        else
        {
            return _private::_fakeLogger;
        }
    }
}
