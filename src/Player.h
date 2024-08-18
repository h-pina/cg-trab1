#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <memory>
#include <vector>
#include <iostream>
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


			void restoreBulletPos(std::shared_ptr<Bullet> bullet);
			
			std::vector<std::shared_ptr<Bullet>> getBullets();

			int mouseButtonState;
		private:
			std::vector<std::shared_ptr<Bullet>> m_Bullets;
	};
}
