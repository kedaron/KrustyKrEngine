#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "KrustyKrEngine/Events/ApplicationEvent.h"
#include "Window.h"

namespace KrustyKrEngine {
	class KRUSTYKRENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in client
	Application* CreateApplication();
}

