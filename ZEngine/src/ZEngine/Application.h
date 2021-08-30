#pragma once

#include "ZEngine/Core.h"
#include "ZEngine/Window.h"

#include "ZEngine/Events/ApplicationEvent.h"
#include "ZEngine/Events/KeyEvent.h"
#include "ZEngine/Events/MouseEvent.h"

namespace ZEngine {

	// Every application should inherit from this class
	class ZENGINE_API Application
	{
	private:
		std::unique_ptr<Window> _wptr;
		bool _running;

		bool onWindowClose(WindowCloseEvent& e);

	public:
		Application();
		virtual ~Application();
		void run();
		void onEvent(Event& e);
	};

	// The client must define this function to create an app
	Application* createApplication();
}
