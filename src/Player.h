#pragma once
#include "GameObject.h"
#include "Shoot.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

#define MAX_SHOOTS 5


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
			void disparaProjetil();
			void atualizaProjeteis();
			void frame(int value);


			void restoreShootPos(Shoot* shoot);
			static Player* getInstance();
			void startTimer();
			
			int mouseButtonState;
		private:
			Shoot* m_shoots;
			static Player* instance;
	};
}
