#pragma once

#include "ZEngine/Core.h"

namespace ZEngine {
	// Events are blocking, so any event gets dispatched inmediately
	// and must be dealt with right after dispatching.

	// TODO: Consider a buffered event system and process them in one part of the
	// application update phase.

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory {
		Node = 0,
		EventCategoryApplication = MARK_BIT(0),
		EventCategoryInput		 = MARK_BIT(1),
		EventCategoryKeyboard	 = MARK_BIT(2),
		EventCategoryMouseButton = MARK_BIT(3),
		EventCategoryMouse		 = MARK_BIT(4)
	};
	
#define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return EventType::##type; }\
							   virtual EventType getEventType() const override { return getStaticType(); }\
							   virtual const char* getName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }

	class ZENGINE_API Event {
	private:
		friend class EventDispatcher;
	public:
		
		bool handled = false;

		// Returns the event type
		virtual EventType getEventType() const = 0;

		// Returns the name of the event
		virtual const char* getName() const = 0;

		// Get category bitset for current event
		virtual int getCategoryFlags() const = 0;

		// Return a string representation of the event's name
		virtual std::string to_string() const { return getName(); }

		// Returns true if the event is included in <category>
		inline bool isInCategory(ZEngine::EventCategory category) { return category & getCategoryFlags(); }
	};

	// Dispatcher for any kind of event
	class EventDispatcher {
	private:

		// Event handling function
		template <typename T>
		using EventFunc = std::function<bool(T&)>;
		Event& _event;
	public:
		EventDispatcher(Event& event)
			: _event(event) {}
		template <typename T>
		bool dispatch(EventFunc<T> func) {
			if (_event.getEventType() == T::getStaticType()) {
				_event.handled = func(*(T*)&_event);
				return true;
			}
			return false;
		}
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		os << e.to_string();
		return os;
	}
}