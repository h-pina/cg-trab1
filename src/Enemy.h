#pragma once
#include "GameObject.h"
#include "Shoot.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

#define MAX_SHOOTS 5


namespace CG {
	class Enemy: public GameObject {
		public:
			Enemy(
				float* vertices,
				const char* textureFile,
				float SpeedY, 
				float SpeedX,
				float* texcoord
			);
			
			void moveEnemy(unsigned char key);
			void disparaProjetil();
			void atualizaProjeteis();
			void frame(int value);


			void restoreShootPos(Shoot* shoot);
			
			int mouseButtonState;
		private:
			Shoot* m_shoots;
			
	};
}
