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
			
			void movePlayer();
			void keyboardDown(unsigned char key, int x, int y);
			void keyboardUp(unsigned char key, int x, int y);
			void disparaProjetil();
			void atualizaProjeteis();
			void desenhaDisparos();
			void shootController();
			
			void setTexCoordDefault(float* vertices);
			void renderizar();
			
			std::vector<std::shared_ptr<Bullet>> getBullets();


			void restoreBulletPos(std::shared_ptr<Bullet> bullet);
		private:
			
			std::vector<std::shared_ptr<Bullet>> m_Bullets;

			float TexCoordDefault[4];
			
	};
}
