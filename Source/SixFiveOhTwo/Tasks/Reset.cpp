#include "Reset.hpp"
#include <Log.hpp>

namespace SixFiveOhTwo::Tasks
{
    static constexpr uint16_t DefaultAddress = 0x1FCC;
    static constexpr uint8_t DefaultStackPointer = 0xFD;

    Reset::Reset(CpuRegisters& cpuRegisters, Bus& bus) :
        _cpu(cpuRegisters),
        _bus(bus)
    {}

    void Reset::ClockEvent()
    {
        switch (_cpu.CyclesLeft)
        {
            case 0:
            {                
                _cpu.CyclesLeft = 9;
                break;
            }
            case 8:
            {
                _bus.SetAddress(DefaultAddress);
                break;
            }
            case 7:
            {                
                _cpu.X = _bus.GetData();
                _bus.SetAddress(DefaultAddress + 1);
                break;
            }
            case 6:
            {                
                auto y = _bus.GetData();
                _cpu.ProgramCounter = ((y << 8) | _cpu.X);
                break;
            }
            case 5:
            {
                _cpu.A = 0;
                _cpu.X = 0;
                _cpu.Y = 0;
                _cpu.StackPointer = DefaultStackPointer;

                _cpu.Status = 0;
                break;
            }
            case 4:
            {
                Log::Debug() << "Resetting at " << _cpu.ProgramCounter.Get() << Log::EndLine;
                break;
            }
            default:
            {
                break;
            }
        }
    }
}
