#pragma once

#include "Atlas/Events/Event.h"

#include "Atlas/Core/TimeStep.h"

#include <string>

namespace Atlas
{
	class Layer
	{
	public:
		Layer(const std::string& name = "Layer")
			:m_DebugName(name)
		{}
		
		virtual ~Layer()
		{}

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(TimeStep ts) {}
		virtual void OnRender() {}
		//virtual void OnImGuiRender() {} // TODO Msh103: add imgui and ImGuiLayer
		virtual void OnEvent(Event& e) {}

		const std::string& GetName() const { return m_DebugName; }

	private:
		std::string m_DebugName;
	};
}