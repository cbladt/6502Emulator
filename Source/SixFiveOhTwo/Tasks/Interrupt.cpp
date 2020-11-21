#include "Interrupt.hpp"
#include <Log.hpp>

namespace SixFiveOhTwo::Tasks
{
    Interrupt::Interrupt(CpuRegisters& cpuRegisters, Bus& bus) :
        _cpu(cpuRegisters),
        _bus(bus)
    {}

    void Interrupt::PushToStackAsync(uint8_t value)
    {
        _bus.SetAddress(0x0100 + _cpu.StackPointer);
        _bus.SetData(value);
        _bus.SetOperation(Bus::Operation::Write);
        _cpu.StackPointer.Decr();
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
        switch (_cpu.CyclesLeft)
        {
            case 0:
            {
                _cpu.CyclesLeft = 8;
                break;
            }
            case 7:
            {                
                PushToStackAsync((_cpu.ProgramCounter >> 8) & 0x00FF);
                break;
            }
            case 6:
            {                
                PushToStackAsync(_cpu.ProgramCounter & 0x00FF);
                break;
            }
            case 5:
            {
                _cpu.SetFlag(CpuRegisters::Break, false);
                _cpu.SetFlag(CpuRegisters::Unused, true);
                _cpu.SetFlag(CpuRegisters::DisableInterrupt, true);

                PushToStackAsync(_cpu.Status);
                break;
            }
            case 4:
            {
                SetAddressLow(_bus);
                break;
            }
            case 3:
            {
                _cpu.X = _bus.GetData();
                SetAddressHigh(_bus);
                break;
            }
            case 2:
            {
                auto low = _cpu.X.Get();
                auto high = _bus.GetData();

                _cpu.ProgramCounter = (high << 8) | low;

                Log::Debug() << "Interrupting at " << _cpu.ProgramCounter.Get() << Log::EndLine;
                break;
            }
            default:
            {
                break;
            }
        }
    }
}
