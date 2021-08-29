#include "zepch.h"

#include "Application.h"
#include "ZEngine/Window.h"

namespace ZEngine {
	Application::Application() {
		_wptr = std::unique_ptr<Window>(Window::create());
	}

	Application::~Application() {
		
	}

	void Application::run() {
		
		while (_running) {
			_wptr->onUpdate();
		}
	}
}