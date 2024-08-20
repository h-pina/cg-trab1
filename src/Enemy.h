#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <memory>
#include <time.h>
#include <sys/time.h>


#define MAX_BulletS 5


namespace CG {
	class Enemy: public GameObject {
		public:
			Enemy(
				float* vertices,
				int health,
				const char* textureFile,
				float SpeedY, 
				float SpeedX,
				float* texcoord,
				int damage
			);
			
			void moveEnemy(unsigned char key);
			void disparaProjetil();
			void atualizaProjeteis();
			void controlaDisparos();
			std::vector<std::shared_ptr<Bullet>> getBullets();
			

			void restoreBulletPos(std::shared_ptr<Bullet> bullet);
			
			int mouseButtonState;
		private:
			
			std::vector<std::shared_ptr<Bullet>> m_Bullets;
			
	};
}
