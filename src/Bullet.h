#pragma once
#include "GameObject.h"
#include "Primitives.h"

namespace CG {
	class Bullet : public GameObject { // Added 'public' keyword
		public:

			Bullet(
				float* vertices,
				int health,
				const char* textureFile, 
				float SpeedY, 
				float SpeedX, 
				float* texcoord
			);

			

		private:
			
			
			
	};

	int detectColision(Bullet* bul, GameObject* obj);
}