#pragma once

#include <Task/ITask.hpp>
#include <Log>

namespace SixFiveOhTwo::Task
{
	template <typename Bus, typename Cpu>
	class Interrupt :
			public ITask
	{
	public:
		Interrupt(Bus& bus, Cpu& cpu, uint16_t interruptAddress) :
			_bus(bus),
			_cpu(cpu),
			_interruptAddress(interruptAddress)
		{
			_s.CyclesLeft = 7;
		}
		~Interrupt() = default;

		void Service() final override
		{
			Log::Debug() << "Interrupt " << _cpu.CyclesLeft << Log::EndLine;

			switch (_cpu.CyclesLeft)
			{
				case 7:
				{
					_bus.SetAddress(_cpu.StackPointer);
					_cpu.StackPointer--;
					break;
				}

				case 6:
				{
					_bus.Write((_cpuProgramCounter >> 8) & 0x00FF);
					_bus.SetAddress(_cpu.StackPointer);
					_cpu.StackPointer--;
					break;
				}

				case 5:
				{
					_bus.Write(_s.ProgramCounter & 0x00FF);

					_s.Break = false;
					_s.Unused = true;
					_s.DisableInterrupt = true;

					_bus.SetAddress(_cpu.StackPointer);
					_cpu.StackPointer--;
					break;
				}

				case 4:
				{
					_bus.Write(_s.Status);

					_bus.SetAddress(_interruptAddress);
					break;
				}

				case 3:
				{
					_pcLow = _bus.Read();
					_bus.SetAddress(_interruptAddress + 1);
				}

				case 2:
				{
					_pcHigh = _bus.Read();
					_cpu.ProgramCounter = (_pcHigh << 8) | _pcLow;
				}


			}
		}

	private:
		Bus& _bus;
		Cpu& _cpu;
		uint16_t _interruptAddress;

		typename Bus::Data _pcLow;
		typename Bus::Data _pcHigh;
	};
}
