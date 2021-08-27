#pragma once
#include "Core.h"
namespace ZEngine {

	// Every application should inherit from this class
	class ZENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	// The client must define this function to create an app
	Application* CreateApplication();
}
