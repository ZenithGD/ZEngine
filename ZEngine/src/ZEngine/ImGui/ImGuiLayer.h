#pragma once

#include "ZEngine/Layer.h"

#include "ZEngine/Events/ApplicationEvent.h"
#include "ZEngine/Events/KeyEvent.h"
#include "ZEngine/Events/MouseEvent.h"


namespace ZEngine {
	class ZENGINE_API ImGuiLayer : public Layer {
	private:
		bool onMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool onMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool onMouseMovedEvent(MouseMovedEvent& e);
		bool onMouseScrolledEvent(MouseScrolledEvent& e);
		bool onKeyPressedEvent(KeyPressedEvent& e);
		bool onKeyReleasedEvent(KeyReleasedEvent& e);
		bool onKeyTypedEvent(KeyTypedEvent& e);
		bool onWindowResizeEvent(WindowResizeEvent& e);
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