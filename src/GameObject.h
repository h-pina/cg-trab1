#pragma once
#include "Tex2D.h"

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <array>

namespace CG {
	class GameObject {
		public:

			GameObject(
				float* vertices,
				const char* textureFile
			);

			//fill obj with default color and 
			//create at center
			GameObject(float* vertices);

			float* getVertices();
			void setVertices(float* vertices);
			void applyModelView();

			Tex2D m_tex;

		private:
			float m_position[2] = {0.0f, 0.0f};
			float m_scale[2] = {1.0f, 1.0f};
			float m_rotation = 0;
			float* m_vertices;
	};
}
