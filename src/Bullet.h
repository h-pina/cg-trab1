#pragma once
#include "GameObject.h"

#define MAX_BulletS 5
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