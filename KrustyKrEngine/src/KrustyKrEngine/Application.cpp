#include "Application.h"

#include "KrustyKrEngine/Events/ApplicationEvent.h"
#include "KrustyKrEngine/Log.h"

namespace KrustyKrEngine {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			KK_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput)) {
			KK_TRACE(e);
		}

		while (true);
	}

}
