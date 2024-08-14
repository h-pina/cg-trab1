#pragma once
#include "GameObject.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

namespace CG {
	class Player: public GameObject {
		public:
			Player(
				float* vertices,
				const char* textureFile,
				float SpeedY, 
				float SpeedX,
				float* texcoord
			);
			void movePlayer(unsigned char key, int x, int y);
			void frame(int value);
			
			int mouseButtonState;
	};
}
