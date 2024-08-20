#include "Enemy.h"
#include "GameObject.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <vector>


namespace CG{
	

	Enemy::Enemy( float* vertices, int health, const char* textureFile,float SpeedY, float SpeedX, float* texcoord, int damage)
		: GameObject(vertices, health, textureFile,SpeedY,SpeedX,texcoord)	
	{ 
		
		mouseButtonState = GLUT_UP;
        float* posEnemy = getPosition();
        float verticesBullet[4] = { posEnemy[0] - 34.0f / 2, posEnemy[0] + 34.0f / 2, posEnemy[1] - 54.0f / 2, posEnemy[1] + 54.0f / 2 };
        float textCoord[4] = { 0.0f, 1.0f, 0.0f, 1.0f };
		setStatus(false);
		float posBullet[] = {posEnemy[0],posEnemy[1]+vertices[3]-vertices[2]};
        for (int i = 0; i < MAX_BulletS; i++) {

			std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(verticesBullet, damage, "textures/projetilEnemy.png", SpeedY, SpeedX, textCoord);

            m_Bullets.push_back(bullet);
			restoreBulletPos(m_Bullets[i]);
        }
	}

	void Enemy::moveEnemy(unsigned char key) {

		float* speedGroup =getSpeed();
		float* texCoordinates = m_tex.getTexCrop(); 
		float* pos = getPosition();

        switch (key) {
            case 'w':

				pos[1] += speedGroup[1];
				texCoordinates[2]+=0.42;
				texCoordinates[3]+=0.42;
				break;

            case 's': 
				pos[2] -= speedGroup[1];
				texCoordinates[2]-=0.40;
				texCoordinates[3]-=0.40;
				break;

            case 'a': 
				pos[0] -= speedGroup[0];
				texCoordinates[0]-=0.2;
				texCoordinates[1]-=0.2;
				break;

            case 'd': 
				pos[0] += speedGroup[0];
				texCoordinates[0]+=0.2;
				texCoordinates[1]+=0.2;
				break;

            case 27: exit(0); break; // ESC
        }

		m_tex.remapTexCrop(texCoordinates);
		setPosition(pos);
		glutPostRedisplay();
	}



	void Enemy::disparaProjetil(){
		for (int i = 0; i < MAX_BulletS; ++i) {
			if (m_Bullets[i]->getStatus() == false) {
				restoreBulletPos(m_Bullets[i]);
				m_Bullets[i]->setStatus(true);
				break;
			}
		}
	}
	void Enemy::atualizaProjeteis(){
		for (int i = 0; i < MAX_BulletS; ++i) {
			if (m_Bullets[i]->getStatus() == true) {
				float* pos = m_Bullets[i]->getPosition();
				pos[1] += m_Bullets[i]->getSpeed()[1];
				m_Bullets[i]->setPosition(pos);
				
				if (pos[1] > 1000) { //// arranjar forma de obter o tamanho da tela aqui
					m_Bullets[i]->setStatus(false);
					restoreBulletPos(m_Bullets[i]);
				}
			}
		}
	}
	

	void Enemy::controlaDisparos() {
        // Get current time in milliseconds
        int now_ms = get_current_milliseconds();
        
        
        printf("miliseg %d\n", now_ms);
        // Check if the left mouse button is pressed and if seconds are even
        if (mouseButtonState == GLUT_DOWN && ((now_ms % 500) < 5)) {
            disparaProjetil(); // Dispara o projétil a partir da posição atual do avião
        }
        atualizaProjeteis(); // Atualiza a posição dos projéteis
        glutPostRedisplay(); // Redesenha a tela
    }
	
	

	std::vector<std::shared_ptr<Bullet>> Enemy::getBullets()
	{
		return m_Bullets;
	}

	

// @@@@@@@@@@@@@@@@@@@@ 	Auxiliar 	@@@@@@@@@@@@@@@@@@@@



	void Enemy::restoreBulletPos(std::shared_ptr<Bullet> bullet)
	{
		float* posEnemy = getPosition();
		float* vertices = getVertices();
		float posBullet[] = {posEnemy[0], posEnemy[1] + vertices[3] - vertices[2]};
		bullet->setPosition(posBullet);
	}


}

