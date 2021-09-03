#pragma once

#include "ZEngine/Layer.h"

namespace ZEngine {
	class ZENGINE_API ImGuiLayer : public Layer {
	private:
		double _time = 0.0;
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void onAttach();
		void onDetach();
		void onUpdate();
		void onEvent(Event& event);
	};
}