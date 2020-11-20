#include "Reset.hpp"
#include <Log.hpp>

namespace SixFiveOhTwo::Tasks
{
    static constexpr uint16_t DefaultAddress = 0x1FCC;
    static constexpr uint8_t DefaultStackPointer = 0xFD;

    Reset::Reset(CpuRegisters& cpuRegisters, Bus& bus) :
        _cpuRegisters(cpuRegisters),
        _bus(bus)
    {}

    void Reset::ClockEvent()
    {
        switch (_cpuRegisters.GetCyclesLeft())
        {
            case 0:
            {
                _cpuRegisters.SetCyclesLeft(9);
                break;
            }
            case 8:
            {
                _bus.SetAddress(DefaultAddress);
                break;
            }
            case 7:
            {
                _cpuRegisters.SetRegisterX(_bus.GetData());
                _bus.SetAddress(DefaultAddress + 1);
                break;
            }
            case 6:
            {
                auto x = _cpuRegisters.GetRegisterX();
                auto y = _bus.GetData();
                _cpuRegisters.SetProgramCounter((y << 8) | x);
                break;
            }
            case 5:
            {
                _cpuRegisters.SetRegisterA(0);
                _cpuRegisters.SetRegisterX(0);
                _cpuRegisters.SetRegisterY(0);
                _cpuRegisters.SetStackPointer(DefaultStackPointer);

                _cpuRegisters.SetRegisterStatus(0);
                break;
            }
            case 4:
            {
                Log::Debug() << "Resetting at " << _cpuRegisters.GetProgramCounter() << Log::EndLine;
                break;
            }
            default:
            {
                break;
            }
        }
    }
}
