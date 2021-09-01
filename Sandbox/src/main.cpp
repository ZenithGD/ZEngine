#include "ZEngine.h"

class ExampleLayer : public ZEngine::Layer {
public:
	ExampleLayer(const std::string& n)
		: ZEngine::Layer(n) {}

	~ExampleLayer() {}

	void onAttach() override {
		ZE_INFO("{0} attached.", getName());
	}

	void onDetach() override {
		ZE_INFO("{0} detached.", getName());
	}

	void onUpdate() override {
		
	}

	void onEvent(ZEngine::Event& event) override {
		ZE_TRACE("{0}", event);

		event.setHandled();
	}
};

class Sandbox : public ZEngine::Application
{
public:
	Sandbox()
	{
		pushLayer(std::make_shared<ExampleLayer>("Layer A"));
		pushLayer(std::make_shared<ExampleLayer>("Layer B"));
		pushLayer(std::make_shared<ExampleLayer>("Layer C"));
		pushOverlay(std::make_shared<ExampleLayer>("Layer D"));
		pushOverlay(std::make_shared<ExampleLayer>("Layer E"));
	}
	~Sandbox() 
	{

	}
};

ZEngine::Application* ZEngine::createApplication() {
	return new Sandbox();
}