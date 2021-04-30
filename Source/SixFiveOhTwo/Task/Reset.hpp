#pragma once

#include <Task/ITask.hpp>
#include <Log>

namespace SixFiveOhTwo::Task
{
	template <typename Bus, typename Cpu>
	class Reset :
			public ITask
	{
	public:
		Reset(Bus& bus, Cpu& cpu) :
			_bus(bus),
			_cpu(cpu)
		{
			_cpu.Reset();
			_cpu.CyclesLeft = 8;
		}
		~Reset() = default;

		void Service() final override
		{
			Log::Debug() << "Reset " << _cpu.CyclesLeft << Log::EndLine;

			switch (_cpu.CyclesLeft)
			{
				case 8:
				{
					_bus.SetAddress(_cpu.ProgramCounterDefault);
					break;
				}

				case 7:
				{
					_pcLow = _bus.Read();
					break;
				}

				case 6:
				{
					_bus.SetAddress(_cpu.ProgramCounterDefault + 1);
					break;
				}

				case 5:
				{
					_pcHigh = _bus.Read();
					break;
				}

				case 4:
				{
					 _cpu.ProgramCounter = (_pcHigh << 8) | _pcLow;
					 break;
				}

				case 3:
				{
					_cpu.Unused = true;
					¨break;
				}
			}
		}

	private:
		Bus& _bus;
		Cpu& _cpu;

		typename Bus::Data _pcLow;
		typename Bus::Data _pcHigh;
	};
}
