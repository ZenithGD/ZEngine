#include "zepch.h"

#include "ZEngine/Events/Event.h"
#include "ZEngine/Events/MouseEvent.h"
#include "ZEngine/Events/KeyEvent.h"
#include "ZEngine/Events/ApplicationEvent.h"
#include "ZEngine/Window.h"
#include "WindowsWindow.h"

#include <glad/glad.h>

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
			glfwSetErrorCallback([](int err, const char* desc) {
				ZE_CORE_ERROR("GLFW Error ({0}): {1}", err, desc);
			});
			_GLFWInitialized = true;
		}

		// Now configure the window
		_window = glfwCreateWindow(_wdata.width, _wdata.height, _wdata.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(_window);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ZE_CORE_ASSERT(status, "Failed to initialize GLAD");

		glfwSetWindowUserPointer(_window, &_wdata);

		// Enable VSync by default
		setVSync(true);

		///////////////////////////////////////////////////////////
		// GLFW Callbacks
		///////////////////////////////////////////////////////////

		glfwSetWindowSizeCallback(_window, [](GLFWwindow* w, int width, int height) {
			WindowData& data = *((WindowData*)glfwGetWindowUserPointer(w));

			data.width = width;
			data.height = height;

			WindowResizeEvent event(width, height);
			data.fn(event);
		});

		glfwSetWindowCloseCallback(_window, [](GLFWwindow* w) {
			WindowData& data = *((WindowData*)glfwGetWindowUserPointer(w));
			WindowCloseEvent event;
			data.fn(event);
		});

		glfwSetKeyCallback(_window, [](GLFWwindow* w, int key, int scancode, int action, int mods) {
			WindowData& data = *((WindowData*)glfwGetWindowUserPointer(w));
			
			switch (action) {
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.fn(event);
				}
				break;
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.fn(event);
				}
				break;
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.fn(event);
				}
				break;
			}
		});

		glfwSetCharCallback(_window, [](GLFWwindow* w, unsigned int character) {
			WindowData& data = *((WindowData*)glfwGetWindowUserPointer(w));
			KeyTypedEvent event(character);
			data.fn(event);
		});

		glfwSetMouseButtonCallback(_window, [](GLFWwindow* w, int button, int action, int mods) {
			WindowData& data = *((WindowData*)glfwGetWindowUserPointer(w));

			switch (action) {
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.fn(event);
				}
				break;
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.fn(event);
				}
				break;
			}
		});

		glfwSetScrollCallback(_window, [](GLFWwindow* w, double xoff, double yoff) {
			WindowData& data = *((WindowData*)glfwGetWindowUserPointer(w));

			MouseScrolledEvent event(xoff, yoff);
			data.fn(event);
		});

		glfwSetCursorPosCallback(_window, [](GLFWwindow* w, double xpos, double ypos) {
			WindowData& data = *((WindowData*)glfwGetWindowUserPointer(w));

			MouseMovedEvent event(xpos, ypos);
			data.fn(event);
		});
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
