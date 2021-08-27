#pragma once

#ifdef ZE_PLATFORM_WINDOWS

extern ZEngine::Application* ZEngine::CreateApplication();

int main(int argc, char** argv) {
	auto app = ZEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif