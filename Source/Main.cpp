#include <Cpu.hpp>
#include <Generator.hpp>

int main()
{    
    SixFiveOhTwo::Cpu cpu;
    cpu.SetEnable();
    cpu.Run();



    /*bus.SetAddress(0x1FCC);
    bus.SetData(0x39);
    bus.SetOperation(Bus::Operation::Write);
    clock.Fire();

    bus.SetAddress(0x1FCD);
    bus.SetData(0x05);
    bus.SetOperation(Bus::Operation::Write);
    clock.Fire();

    bus.SetOperation(Bus::Operation::Read);
    cpu.Enable();

    Clock::Generator::Run(clock, std::chrono::milliseconds(100));*/
}
