#include <queue>

#include "Application.h"

#include "ZEngine/Log.h"
#include "ZEngine/Events/MouseEvent.h"
#include "ZEngine/Events/ApplicationEvent.h"
#include "ZEngine/Events/KeyEvent.h"

namespace ZEngine {
	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		
		
		std::vector<Event*> e_q;
		e_q.push_back(new KeyPressedEvent(50, 6));
		e_q.push_back(new KeyReleasedEvent(50));
		e_q.push_back(new MouseButtonPressedEvent(1));
		e_q.push_back(new MouseButtonReleasedEvent(1));
		e_q.push_back(new MouseMovedEvent(205.5f, 600.2f));
		e_q.push_back(new MouseScrolledEvent(-25.5f, 42.6f));
		e_q.push_back(new WindowResizeEvent(1280,720));
		e_q.push_back(new WindowCloseEvent);
		e_q.push_back(new AppTickEvent);
		e_q.push_back(new AppUpdateEvent);
		e_q.push_back(new AppRenderEvent);

		for (auto ev : e_q) {
			ZE_TRACE(ev->to_string() + "(" + std::to_string(ev->GetCategoryFlags()) + ")");
			delete ev;
		}
		while (true) {

		}
	}
}