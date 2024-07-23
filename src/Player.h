#pragma once
#include "GameObject.h"

namespace CG {
	class Player: public GameObject {
		public:
			Player(
				float* vertices,
				const char* textureFile
			);
			void movePlayer(); 
	};
}
