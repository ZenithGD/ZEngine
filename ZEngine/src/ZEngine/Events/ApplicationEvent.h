#pragma once

#include "Event.h"

namespace ZEngine {
	class WindowResizeEvent : public Event {
	private:
		int _resX, _resY;
	public:
		WindowResizeEvent(int resX, int resY) 
			: _resX(resX), _resY(resY) {}
		inline int getResX () const { return _resX; }
		inline int getResY () const { return _resY; }

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowResize)
	};

	class WindowCloseEvent : public Event {
	public:

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowClose)
	};

	class AppTickEvent : public Event {
	public:
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppTick)
	};

	class AppRenderEvent : public Event {
	public:
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppRender)
	};

	class AppUpdateEvent : public Event {
	public:
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppUpdate)
	};
}