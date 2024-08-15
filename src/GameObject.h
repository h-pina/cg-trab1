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
				const char* textureFile,
				float SpeedY,
				float SpeedX, 
				float* texcoord
				
			);

			//fill obj with default color and 
			//create at center
			GameObject(float* vertices);

			
			void applyModelView();
			void draw();
			void defineObjectBox();
			float* getSpeed();
			void setVertices(float* vertices);
			void setPosition(float* pos);
			float* getPosition();
			float* getVertices();
			
			Tex2D m_tex;

		private:
			float* m_position;
			float m_scale[2] = {1.0f, 1.0f};
			float m_rotation = 0;
			float speedY = 0;
			float speedX = 0;
			float* m_vertices;
		
	};
}
