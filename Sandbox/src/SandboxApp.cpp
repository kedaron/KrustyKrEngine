#include "KrustyKrEngine.h"

class Sandbox : public KrustyKrEngine::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

KrustyKrEngine::Application* KrustyKrEngine::CreateApplication() {
	return new Sandbox();
}