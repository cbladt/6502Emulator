#pragma once
#include <cstdint>
#include <tuple>

#include <Generator.hpp>

#include <Log.hpp>

#include <Ram.hpp>
#include <CpuRegisters.hpp>
#include <CpuOpcodes.hpp>

namespace SixFiveOhTwo
{    
    class Cpu :
            public Clock::Generator<SixFiveOhTwo::Cpu, 10>,
            private CpuRegisters,
            private CpuOpcodes
    {
    public:               
        Cpu();
        ~Cpu() = default;

        Cpu(const Cpu&) = delete;
        Cpu& operator=(const Cpu&) = delete;

        Cpu(Cpu&&) = delete;
        Cpu& operator=(Cpu&&) = delete;        

        void Fire();

        void DoReset();
        bool MaybeInterrupt();
        void DoInterrupt();
        void DoEnable();
        void DoDisable();

    private:
        Ram _ram;

        void MaybeClock();
        void Clock();

        void ServiceUnknown();

        void ServiceReset();

        void ServiceInterrupt();

        void ServiceInstruction();
    };
}
