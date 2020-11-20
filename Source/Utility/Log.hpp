#pragma once
#include <iostream>

namespace Log
{
    namespace _private
    {
        struct EndLine_t
        {};

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
                    if constexpr(std::is_arithmetic_v<T>)
                    {
                        std::cout << std::to_string(message);
                    }
                    else if constexpr(std::is_same_v<typename std::remove_cv<T>::type, EndLine_t>)
                    {
                        std::cout << std::endl;
                    }
                    else
                    {
                        std::cout << message;
                    }
                }

                return *this;
            }                               
        };

        Logger<true> _realLogger;
        Logger<false> _fakeLogger;
        EndLine_t _endLine;
    }

    constexpr const auto EndLine = _private::_endLine;

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

    constexpr auto IsEnabled(const Level test)
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
