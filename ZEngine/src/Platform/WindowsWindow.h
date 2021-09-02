#pragma once

#include "zepch.h"
#include "ZEngine/Window.h"
#include <GLFW/glfw3.h>

namespace ZEngine {
	class WindowsWindow : public Window {
	private:
		struct WindowData {
			std::string title;
			int width, height;
			bool vsync;
			EventCallbackFun fn;
		};
		WindowData _wdata;
		GLFWwindow* _window;

		void init(const WindowProps& wp);
		void onUpdate() override;
		void shutdown();

		inline void setEvCallback(const EventCallbackFun& fn) override { _wdata.fn = fn; }
		void setVSync(bool enabled) override;
		inline bool getVSync() const override { return _wdata.vsync; }

	public:
		WindowsWindow(const WindowProps& wp);
		virtual ~WindowsWindow();

		inline int getWidth() const override { return _wdata.height; };
		inline int getHeight() const override { return _wdata.width; };
	};
}