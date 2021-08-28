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

ZEngine::Application* ZEngine::CreateApplication() {
	return new Sandbox();
}