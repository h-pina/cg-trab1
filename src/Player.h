#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

#define MAX_BulletS 5


namespace CG {
	class Player: public GameObject {
		public:
			Player(
				float* vertices,
				int healthP,
				const char* textureFile,
				float SpeedY, 
				float SpeedX,
				float* texcoord,
				int damage
			);
			
			void movePlayer(unsigned char key);
			void disparaProjetil();
			void atualizaProjeteis();
			void controlaDisparos();


			void restoreBulletPos(Bullet* Bullet);
			
			
			int mouseButtonState;
		private:
			Bullet* m_Bullets;
	};
}
