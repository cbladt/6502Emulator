#include "Bus.hpp"
#include "GenericMemory.hpp"
#include <SixFiveOhTwo/Cpu.hpp>
#include <Clock/Event.hpp>
#include <Clock/Generator.hpp>

using Ram_t = GenericMemory<0x2000, 0x0000, 0x1FFF>;

int main()
{        
    Bus bus;
    Ram_t ram(bus);    
    SixFiveOhTwo::Cpu cpu(bus);
    Clock::Event<Ram_t, SixFiveOhTwo::Cpu> clock(ram, cpu);    

    bus.SetAddress(0x1FCC);
    bus.SetData(0x39);
    bus.SetOperation(Bus::Operation::Write);
    clock.Fire();

    bus.SetAddress(0x1FCD);
    bus.SetData(0x05);
    bus.SetOperation(Bus::Operation::Write);
    clock.Fire();

    bus.SetOperation(Bus::Operation::Read);
    cpu.Enable();

    Clock::Generator::Run(clock, std::chrono::milliseconds(100));

    return 0;
}
