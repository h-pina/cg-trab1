#pragma once
#include "Window.h"
#include "Renderer.h"

#include <memory>

namespace CG {
	class Application {
	public:
		Application(int* argc, char** argv);
		void run();

	private:
		std::unique_ptr<Window> m_window = nullptr;
		std::unique_ptr<Scene> m_scene = nullptr;
		std::unique_ptr<Renderer> m_renderer = nullptr;
		void setupCallbacks();
	};
}
