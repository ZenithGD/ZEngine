#pragma once

#include "ZEngine/Core.h"
#include "ZEngine/Window.h"

#include "ZEngine/Events/ApplicationEvent.h"
#include "ZEngine/Events/KeyEvent.h"
#include "ZEngine/Events/MouseEvent.h"

#include "ZEngine/LayerStack.h"

namespace ZEngine {

	// Every application should inherit from this class
	class ZENGINE_API Application
	{
	private:
		std::unique_ptr<Window> _wptr;
		bool _running;
		LayerStack _layers;

		bool onWindowClose(WindowCloseEvent& e);

		// Application must be a singleton
		static Application* _instance;
		
	public:
		Application();
		virtual ~Application();

		void run();
	
		void onEvent(Event& e);
		void pushLayer(std::shared_ptr<Layer> layer);
		void popLayer(std::shared_ptr<Layer> layer);
		void pushOverlay(std::shared_ptr<Layer> layer);
		void popOverlay(std::shared_ptr<Layer> layer);

		inline Window& getWindow() { return *_wptr; }
		inline static Application& get() { return *_instance; }
	};

	// The client must define this function to create an app
	Application* createApplication();
}
