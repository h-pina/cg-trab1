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
			
			void movePlayer();
			void keyboardDown(unsigned char key, int x, int y);
			void keyboardUp(unsigned char key, int x, int y);
			void disparaProjetil();
			void atualizaProjeteis();
			void desenhaDisparos();
			
			void setTexCoordDefault(float* vertices);
			void renderizar();
			
			std::vector<std::shared_ptr<Bullet>> getBullets();


			void restoreBulletPos(std::shared_ptr<Bullet> bullet);
			
			

			
			
		private:
			float TexCoordDefault[4];
			std::vector<std::shared_ptr<Bullet>> m_Bullets;
	};
}
