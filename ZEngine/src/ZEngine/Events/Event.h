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
	
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
							   virtual EventType GetEventType() const override { return GetStaticType(); }\
							   virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class ZENGINE_API Event {
	private:
		friend class EventDispatcher;
	protected:
		// Represents whether this event was handled or not.
		bool _handled = false;
	public:
		// Returns the event type
		virtual EventType GetEventType() const = 0;

		// Returns the name of the event
		virtual const char* GetName() const = 0;

		// Get category bitset for current event
		virtual int GetCategoryFlags() const = 0;

		// Return a string representation of the event's name
		virtual std::string to_string() const { return GetName(); }

		// Returns true if the event is included in <category>
		inline bool IsInCategory(ZEngine::EventCategory category) { return category & GetCategoryFlags(); }
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
		bool Dispatch(EventFunc<T> func) {
			if (_event.GetEventType() == T::GetStaticType()) {
				_event._handled = func(*(T*)&_event);
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