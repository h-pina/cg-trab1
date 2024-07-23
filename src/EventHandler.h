#pragma once
#include "Window.h"
#include "Renderer.h"

namespace CG {
	namespace EventHandler{
		void setupCallbacks();
		void setInstances(Window* window, Renderer* renderer);
		void windowResizeCallback(int width, int height);
	}
}
