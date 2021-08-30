#include "zepch.h"

#include "Application.h"
#include "ZEngine/Window.h"

namespace ZEngine {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	bool Application::onWindowClose(WindowCloseEvent& e)
	{
		_running = false;
		return true;
	}

	Application::Application() {
		_wptr = std::unique_ptr<Window>(Window::create());
		_wptr->setEvCallback(BIND_EVENT_FN(onEvent));
	}

	Application::~Application() {
		
	}

	void Application::run() {
		while (_running) {
			_wptr->onUpdate();
		}
	}
	void Application::onEvent(Event& e)
	{
		EventDispatcher evd(e);
		evd.dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));
		ZE_CORE_TRACE("{0}", e);
	}
}