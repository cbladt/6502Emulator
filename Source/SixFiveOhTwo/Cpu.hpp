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

        void Reset();
        bool InterruptRequest();
        void Interrupt();

        constexpr void SetEnable()
        {
            Enable = true;
        }

        constexpr void SetDisable()
        {
            Enable = false;
        }

    private:
        static const constexpr auto ProgramCounterDefault = 0xFFFC;
        static const constexpr auto ProgramCounterInterrupt = 0xFFFE;
        static const constexpr auto ProgramCounterNonMaskInterrupt = 0xFFFA;
        static const constexpr auto StackPointerStart = 0x100;
        static const constexpr auto StackPointerDefault = 0xFD;

        Ram _ram;
        constexpr void PushToStack(uint8_t value)
        {
            _ram.Write(StackPointerStart + StackPointer, value);
            StackPointer--;
        }

        void MaybeClock();
        void Clock();

        void DoInterrupt(uint16_t address);

        constexpr void HandleOpcode()
        {
            std::apply([this](auto&&... args) {(args.Execute(*this), ...);}, _opcodes);
        }
    };
}
