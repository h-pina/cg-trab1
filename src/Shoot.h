#pragma once
#include "GameObject.h"

namespace CG {
	class Shoot : public GameObject { // Added 'public' keyword
		public:

			Shoot(
				float* vertices,
				const char* textureFile,
                int damage
			);

			//fill obj with default color and 
			//create at center
			Shoot(
                float* vertices,
                int damage
            ); 

			float* getVertices();
			void setVertices(float* vertices);
			void applyModelView();
			int getDamage(); // Getter for damage
			void setDamage(int damage); // Setter for damage

			Tex2D m_tex;

		private:
			float* m_vertices;
			int m_damage; // Added damage attribute
	};
}