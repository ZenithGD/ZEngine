#pragma once

#include "ZEngine/Core.h"
#include "ZEngine/Window.h"

namespace ZEngine {

	// Every application should inherit from this class
	class ZENGINE_API Application
	{
	private:
		std::unique_ptr<Window> _wptr;
		bool _running;
	public:
		Application();
		virtual ~Application();
		void run();
	};

	// The client must define this function to create an app
	Application* createApplication();
}
