#pragma once

#include "Event.h"

#include <sstream>

namespace ZEngine {
	// Class for key events (keyboard press/release)
	class ZENGINE_API KeyEvent : public Event {
	protected:
		int _keycode;
		KeyEvent(int keycode)
			: _keycode(keycode) {}

	public:
		inline int getKeyCode() const { return _keycode;  }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	};

	// Class for key pressing events
	class ZENGINE_API KeyPressedEvent : public KeyEvent {
	private:
		int _repeat_count;
	public:
		KeyPressedEvent(int keycode, int count)
			: KeyEvent(keycode), _repeat_count(count) {}

		inline int getRepeatCount() const { return _repeat_count; }

		std::string to_string() const override {
			std::ostringstream os;
			os << "KeyPressedEvent: " << _keycode << " (repeat_count: " << _repeat_count << ") ";
			return os.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	};

	// Class for key pressing events
	class ZENGINE_API KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode){}

		std::string to_string() const override {
			std::ostringstream os;
			os << "KeyReleasedEvent: " << _keycode;
			return os.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}