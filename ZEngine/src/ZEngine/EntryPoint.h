#pragma once

#ifdef ZE_PLATFORM_WINDOWS

extern ZEngine::Application* ZEngine::CreateApplication();

int main(int argc, char** argv) {

	ZEngine::Log::Init();
	ZE_CORE_WARN("Initialized core log!");
	ZE_INFO("Initialized client log!");

	// Allocate object on heap, as it will grow in size quite rapidly
	auto app = ZEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif