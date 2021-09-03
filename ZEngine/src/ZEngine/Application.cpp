#include "zepch.h"

#include "Application.h"
#include "ZEngine/Window.h"
#include "ZEngine/LayerStack.h"

#include <glad/glad.h>

namespace ZEngine {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::_instance = nullptr;

	bool Application::onWindowClose(WindowCloseEvent& e)
	{
		_running = false;
		return true;
	}

	Application::Application() 
		: _layers() {
		ZE_CORE_ASSERT(!_instance, "An application already exists!");
		_instance = this;

		WindowProps wp(512, 512, "Example App");
		_wptr = std::unique_ptr<Window>(Window::create(wp));
		_wptr->setEvCallback(BIND_EVENT_FN(onEvent));
	}

	Application::~Application() {
		
	}

	void Application::run() {
		while (_running) {

			// Draw something
			glClearColor(1.0, 0.0, 1.0, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);

			// Update layers
			for (auto l : _layers) {
				l->onUpdate();
			}

			// Update window
			_wptr->onUpdate();
		}
	}
	void Application::onEvent(Event& e)
	{
		EventDispatcher evd(e);
		evd.dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));
		ZE_CORE_TRACE("{0}", e);

		// Propagate event until it gets handled
		for (auto it = _layers.rbegin(); it != _layers.rend(); ++it) {
			if (e.handled) break;
			(*it)->onEvent(e);
		}
	}
	void Application::pushLayer(std::shared_ptr<Layer> layer)
	{
		_layers.pushLayer(layer);
	}
	void Application::popLayer(std::shared_ptr<Layer> layer)
	{
		_layers.popLayer(layer);
	}
	void Application::pushOverlay(std::shared_ptr<Layer> layer)
	{
		_layers.pushOverlay(layer);
	}
	void Application::popOverlay(std::shared_ptr<Layer> layer)
	{
		_layers.popOverlay(layer);
	}
}