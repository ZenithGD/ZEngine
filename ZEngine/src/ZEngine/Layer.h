#pragma once

#include "ZEngine/Events/Event.h"

namespace ZEngine {

	// Interface for creating application layers
	class ZENGINE_API Layer {
	protected:
		std::string _debugName;
	public:
		Layer(const std::string& dbname);

		virtual ~Layer();

		inline std::string getName() const { return _debugName; }

		virtual void onAttach() {}
		virtual void onDetach() {}
		virtual void onEvent(Event& e) {}
		virtual void onUpdate() {}

		// enablelayer()
	};
}