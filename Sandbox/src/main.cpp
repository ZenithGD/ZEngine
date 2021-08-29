#include "ZEngine.h"

class Sandbox : public ZEngine::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox() 
	{

	}
};

ZEngine::Application* ZEngine::createApplication() {
	return new Sandbox();
}