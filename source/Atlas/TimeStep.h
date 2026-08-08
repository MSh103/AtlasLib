#pragma once

namespace Atlas
{
	class TimeStep
	{
	public:
		TimeStep(float time = 0.0f)
			:m_Time(time)
		{}

		operator float() const { return m_Time; }
		
		float GetSeconds() const { return m_Time; }
		float GetMilliseconds() { return m_Time * 1000.f; }
	private:
		float m_Time;
	};
}
