#pragma once

#include "zepch.h"

#include "ZEngine/Core.h"
#include "ZEngine/Events/Event.h"

namespace ZEngine {
	struct WindowProps {
		int _width, _height;
		std::string _title;
		WindowProps(int width = 1280, int height = 720, const std::string& title = "ZEngine App")
			: _width(width), _height(height), _title(title) {}
	};
		
	// Interface for platform-agnostic window handling
	class ZENGINE_API Window {
	public:
		using EventCallbackFun = std::function<void(Event&)>;

		virtual int getWidth() const = 0;
		virtual int getHeight() const = 0;

		virtual void onUpdate() = 0;

		virtual void setEvCallback(EventCallbackFun& fn) = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual bool getVSync() const = 0;

		static Window* create(const WindowProps& props = WindowProps());

		virtual ~Window() {};
	};
}