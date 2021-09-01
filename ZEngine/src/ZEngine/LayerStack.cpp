#include "zepch.h"
#include "LayerStack.h"

namespace ZEngine {
	LayerStack::~LayerStack()
	{
		while (!_layers.empty()) {
			_layers.back()->onDetach();
			_layers.pop_back();
		}
	}
	void LayerStack::pushLayer(const std::shared_ptr<Layer>& layer)
	{
		_layers.emplace(_layers.begin() + _div++, layer);
		layer->onAttach();
	}
	void LayerStack::pushOverlay(const std::shared_ptr<Layer>& layer)
	{
		_layers.emplace_back(layer);
		layer->onAttach();
	}
	void LayerStack::popLayer(const std::shared_ptr<Layer>& layer)
	{
		auto pos = find(_layers.begin(), _layers.begin() + _div, layer);
		if (pos != _layers.end() + _div) {
			layer->onDetach();
		}
	}
	void LayerStack::popOverlay(const std::shared_ptr<Layer>& layer)
	{
		auto pos = find(_layers.begin() + _div, _layers.end(), layer);
		if (pos != _layers.end()) {
			layer->onDetach();
		}
	}
}