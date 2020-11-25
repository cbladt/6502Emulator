#include <Cpu.hpp>

#include <fstream>
#include <iterator>
#include <vector>

template <typename T>
void LoadRom(std::string path, T& ram)
{
    std::ifstream input(path, std::ios::binary );
    std::vector<uint8_t> buffer(std::istreambuf_iterator<char>(input), {});

    for (uint16_t index = 0; index < buffer.size(); index++)
    {
        ram.Write(index, buffer.at(index));
    }
}

int main()
{    
    SixFiveOhTwo::Cpu cpu;

    LoadRom("", cpu.GetRam());

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
