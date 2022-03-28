#pragma once

#ifdef KK_PLATFORM_WINDOWS

extern KrustyKrEngine::Application* KrustyKrEngine::CreateApplication();

int main(int argc, char** argv) {
	auto app = KrustyKrEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif // KK_PLATFORM_WINDOWS