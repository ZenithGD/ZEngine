#pragma once

#include "zepch.h"

#include "ZEngine/Layer.h"

namespace ZEngine {

	/* Application layer stack.
	 * Overlays are always drawn before layers, and events are always handled by overlays first,
	 * Events will get propagated through the layer stack until a layer marks it as handled.
	 */
	class ZENGINE_API LayerStack {
	private:
		std::vector<std::shared_ptr<Layer>> _layers;
		unsigned int _div = 0U;
	public:
		LayerStack() = default;
		~LayerStack();

		// Adds a layer into the stack
		void pushLayer(const std::shared_ptr<Layer>& layer);
		// Adds an overlay into the stack
		void pushOverlay(const std::shared_ptr<Layer>& layer);

		// Pops <layer> from the layer stack
		void popLayer(const std::shared_ptr<Layer>& layer);
		// Pops <layer> the overlay stack
		void popOverlay(const std::shared_ptr<Layer>& layer);

		std::vector<std::shared_ptr<Layer>>::iterator begin() { return _layers.begin(); }
		std::vector<std::shared_ptr<Layer>>::iterator end() { return _layers.end(); }
		std::vector<std::shared_ptr<Layer>>::reverse_iterator rbegin() { return _layers.rbegin(); }
		std::vector<std::shared_ptr<Layer>>::reverse_iterator rend() { return _layers.rend(); }

		std::vector<std::shared_ptr<Layer>>::const_iterator begin() const { return _layers.begin(); }
		std::vector<std::shared_ptr<Layer>>::const_iterator end()	const { return _layers.end(); }
		std::vector<std::shared_ptr<Layer>>::const_reverse_iterator rbegin() const { return _layers.rbegin(); }
		std::vector<std::shared_ptr<Layer>>::const_reverse_iterator rend() const { return _layers.rend(); }
	};
}