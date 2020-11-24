#pragma once
#include <cstdint>
#include <tuple>

#include <Clock.hpp>
#include <Log.hpp>

#include <Ram.hpp>
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

    private:
        static const constexpr auto ProgramCounterDefault = 0xFFFC;
        static const constexpr auto ProgramCounterInterrupt = 0xFFFE;
        static const constexpr auto ProgramCounterNonMaskInterrupt = 0xFFFA;
        static const constexpr auto StackPointerDefault = 0xFD;

        CpuState _s;
        Ram _ram;

        void MaybeClock();
        void Clock();

        void DoInterrupt(uint16_t address);
    };
}
