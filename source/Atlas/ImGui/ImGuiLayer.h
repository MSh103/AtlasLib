#pragma once

#include "Atlas/Events/Event.h"
#include "Atlas/Layers/Layer.h"

namespace Atlas
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override {}

		void Begin();
		void End();
	};
}