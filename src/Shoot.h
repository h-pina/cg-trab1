#pragma once
#include "GameObject.h"

namespace CG {
	class Shoot : public GameObject { // Added 'public' keyword
		public:

			Shoot(
				float* vertices,
				int health,
				const char* textureFile,
                int damage, 
				float SpeedY, 
				float SpeedX, 
				float* texcoord
			);

			

			
			void detectColision(GameObject* obj);

		private:
			
			
			
	};
}