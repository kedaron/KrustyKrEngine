#pragma once

#ifdef KK_PLATFORM_WINDOWS

extern KrustyKrEngine::Application* KrustyKrEngine::CreateApplication();

int main(int argc, char** argv) {

	KrustyKrEngine::Log::Init();
	KK_CORE_WARN("Initialized Log!");
	int test = 1;
	KK_INFO("Hello there! Var={0}", test);

	auto app = KrustyKrEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif // KK_PLATFORM_WINDOWS