#pragma once
#include <cstdint>
#include <tuple>

#include <Clock.hpp>
#include <Log.hpp>

#include <Memory.hpp>
#include <CpuState.hpp>

namespace SixFiveOhTwo
{    
    class Cpu :
            public Clock<SixFiveOhTwo::Cpu, 10>
    {
    public:               
        Cpu();
        ~Cpu() = default;

        Cpu(const Cpu&) = delete;
        Cpu& operator=(const Cpu&) = delete;

        Cpu(Cpu&&) = delete;
        Cpu& operator=(Cpu&&) = delete;        

        void Fire();

        void Reset();
        bool InterruptRequest();
        void Interrupt();

        constexpr void SetEnable()
        {
            _s.Enable = true;            
        }

        constexpr void SetDisable()
        {
            _s.Enable = false;
        }

        constexpr auto& GetRam()
        {
            return _ram;
        }

        constexpr auto& GetStack()
        {
            return _stack;
        }

#ifndef DoTest
    private:
#endif
        constexpr void SetDebug()
        {
            _debug = true;
        }

        constexpr void StopDebug()
        {
            _debug = false;
        }

        constexpr void Step()
        {
            _step = true;
        }

        constexpr auto& GetInternalState()
        {
            return _s;
        }

        static const constexpr auto ProgramCounterDefault = 0xFFFC;
        static const constexpr auto ProgramCounterInterrupt = 0xFFFE;
        static const constexpr auto ProgramCounterNonMaskInterrupt = 0xFFFA;
        static const constexpr auto StackPointerDefault = 0xFD;

    private:
        CpuState _s;
        Memory::Ram _ram;
        Memory::Stack _stack;

        bool _debug;
        bool _step;

        void MaybeClock();
        void Clock();

        void DoInterrupt(uint16_t address);
    };
}
