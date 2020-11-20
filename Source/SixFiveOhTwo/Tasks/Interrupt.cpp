#include "Interrupt.hpp"
#include <Log.hpp>

namespace SixFiveOhTwo::Tasks
{
    Interrupt::Interrupt(CpuRegisters& cpuRegisters, Bus& bus) :
        _cpuRegisters(cpuRegisters),
        _bus(bus)
    {}

    void Interrupt::PushToStackAsync(uint8_t value)
    {
        _bus.SetAddress(0x0100 + _cpuRegisters.GetStackPointer());
        _bus.SetData(value);
        _bus.SetOperation(Bus::Operation::Write);
        _cpuRegisters.DecrementStackPointer();
    }

    template <typename Bus>
    void SetAddressLow(Bus& bus)
    {
        bus.SetAddress(0xFFFE);
    }

    template <typename Bus>
    void SetAddressHigh(Bus& bus)
    {
        bus.SetAddress(0xFFFF);
    }

    void Interrupt::ClockEvent()
    {
        switch (_cpuRegisters.GetCyclesLeft())
        {
            case 0:
            {
                _cpuRegisters.IncrementCyclesLeft(8);
                break;
            }
            case 7:
            {
                auto pc = _cpuRegisters.GetProgramCounter();
                PushToStackAsync((pc >> 8) & 0x00FF);
                break;
            }
            case 6:
            {
                auto pc = _cpuRegisters.GetProgramCounter();
                PushToStackAsync(pc & 0x00FF);
                break;
            }
            case 5:
            {
                _cpuRegisters.SetRegisterStatusFlag(CpuRegisters::Break, false);
                _cpuRegisters.SetRegisterStatusFlag(CpuRegisters::Unused, true);
                _cpuRegisters.SetRegisterStatusFlag(CpuRegisters::DisableInterrupt, true);

                PushToStackAsync(_cpuRegisters.GetRegisterStatus());

                SetAddressLow(_bus);
                break;
            }
            case 4:
            {
                _cpuRegisters.SetRegisterX(_bus.GetData());
                SetAddressHigh(_bus);
                break;
            }
            case 3:
            {
                auto low = _cpuRegisters.GetRegisterX();
                auto high = _bus.GetData();

                _cpuRegisters.SetProgramCounter((high << 8) | low);

                Log::Debug() << "Interrupting at " << _cpuRegisters.GetProgramCounter() << Log::EndLine;
                break;
            }
            default:
            {
                break;
            }
        }
    }
}
