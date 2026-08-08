#pragma once

#include "Event.h"

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
		virtual void OnUpdate() {}
		virtual void OnRender() {}
		//virtual void OnImGuiRender() {} // TODO Msh103: add imgui and ImGuiLayer
		virtual void OnEvent(Event& e) {}

	private:
		std::string m_DebugName;
	};
}