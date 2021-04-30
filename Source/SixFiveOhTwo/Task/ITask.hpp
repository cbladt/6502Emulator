#pragma once

namespace SixFiveOhTwo::Task
{
	class ITask
	{
	public:
		virtual ~ITask() = default;
		virtual void Service() = 0;
	};
}
