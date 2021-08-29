#pragma once

#include "Event.h"
namespace ZEngine {

	// Class for handling a mo
	class ZENGINE_API MouseButtonEvent : public Event {
	protected:
		int _button;
		MouseButtonEvent(int button)
			: _button(button) {}
	public:
		inline int getButton() const { return _button; }
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryMouseButton | EventCategoryInput)
	};

	class ZENGINE_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}
		std::string to_string() const override {
			std::ostringstream os;
			os << "MouseButtonPressedEvent: " << _button << " pressed.";
			return os.str();
		}
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class ZENGINE_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}
		std::string to_string() const override {
			std::ostringstream os;
			os << "MouseButtonReleasedEvent: " << _button << " released.";
			return os.str();
		}
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

	class ZENGINE_API MouseMovedEvent : public Event {
	private:
		float _posX, _posY;
	public:
		MouseMovedEvent(float posX, float posY) 
			: _posX(posX), _posY(posY) {}
		inline float getX() const { return _posX; }
		inline float getY() const { return _posY; }

		std::string to_string() const override {
			std::ostringstream os;
			os << "MouseMovedEvent: (" << _posX << ", " << _posY << ")";
			return os.str();
		}
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
		EVENT_CLASS_TYPE(MouseMoved)
	};

	class ZENGINE_API MouseScrolledEvent : public Event {
	private:
		float _offX, _offY;
	public:
		MouseScrolledEvent(float posX, float posY)
			: _offX(posX), _offY(posY) {}
		inline float getOffX() const { return _offX; }
		inline float getOffY() const { return _offY; }

		std::string to_string() const override {
			std::ostringstream os;
			os << "MouseScrolledEvent: (" << _offX << ", " << _offY << ")";
			return os.str();
		}
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
		EVENT_CLASS_TYPE(MouseScrolled)
	};
}