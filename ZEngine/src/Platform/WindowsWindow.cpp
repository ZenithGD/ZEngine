#include "zepch.h"

#include "ZEngine/Window.h"
#include "WindowsWindow.h"

namespace ZEngine {
	static bool _GLFWInitialized = false;

	Window* Window::create(const WindowProps& wp) {
		return new WindowsWindow(wp);
	}

	WindowsWindow::WindowsWindow(const WindowProps& wp)
	{
		init(wp);
	}
	
	WindowsWindow::~WindowsWindow()
	{
		shutdown();
	}

	void WindowsWindow::init(const WindowProps& wp)
	{
		// Pass props to window data struct
		_wdata.width = wp._width;
		_wdata.height = wp._height;
		_wdata.title = wp._title;

		ZE_CORE_INFO("Creating window: (width={0}, height={1}), title='{2}'", _wdata.width, _wdata.height, _wdata.title);
	
		if (!_GLFWInitialized) {
			int success = glfwInit();
			ZE_CORE_ASSERT(success, "Can't initialize GLFW!");
		}

		// Now configure the window
		_window = glfwCreateWindow(_wdata.width, _wdata.height, _wdata.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(_window);
		glfwSetWindowUserPointer(_window, &_wdata);

		// Enable VSync by default
		setVSync(true);
	}

	void WindowsWindow::onUpdate()
	{
		// Poll incoming events
		glfwPollEvents();

		// Swap back and front buffers
		glfwSwapBuffers(_window);
	}

	void WindowsWindow::shutdown()
	{
		glfwDestroyWindow(_window);
	}

	void WindowsWindow::setVSync(bool enabled)
	{
		glfwSwapInterval((int)enabled);
		_wdata.vsync = enabled;
	}
}
