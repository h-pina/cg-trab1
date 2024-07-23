#pragma once

#include "Scene.h"


namespace CG {

	class Renderer {
		public:
			Renderer(Scene* scene);
			void render();

		private:
			Scene* m_scene;
			void drawVertices(float* vertices, size_t len, int type);
	};

}
