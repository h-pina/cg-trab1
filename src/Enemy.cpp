#include "Enemy.h"
#include "GameObject.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <vector>


namespace CG{
	
	bool keyStatesEnemy[256] = { false }; // Array para rastrear o estado das teclas


	Enemy::Enemy( float* vertices, int health, const char* textureFile,float SpeedY, float SpeedX, float* texcoord, int damage)
		: GameObject(vertices, health, textureFile,SpeedY,SpeedX,texcoord)	
	{ 
		
		keyStatesEnemy['s']=true;
		keyStatesEnemy[' ']=true;
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

	void Enemy::movePlayer() {
        float* speedGroup = getSpeed();
        float* texCoordinates = m_tex.getTexCrop();
        float* vertices = getVertices();

        if (keyStatesEnemy['w']) {
            vertices[2] += speedGroup[1];
            vertices[3] += speedGroup[1];
            texCoordinates[2] = TexCoordDefault[2] + 0.42;
            texCoordinates[3] = TexCoordDefault[3] + 0.42;
        }
        if (keyStatesEnemy['s']) {
            vertices[2] -= speedGroup[1];
            vertices[3] -= speedGroup[1];
            texCoordinates[2] = TexCoordDefault[2] - 0.40;
            texCoordinates[3] = TexCoordDefault[3] - 0.40;
        }
        if (keyStatesEnemy['a']) {
            vertices[0] -= speedGroup[0];
            vertices[1] -= speedGroup[0];
            texCoordinates[0] = TexCoordDefault[0] - 0.2;
            texCoordinates[1] = TexCoordDefault[1] - 0.2;
        }
        if (keyStatesEnemy['d']) {
            vertices[0] += speedGroup[0];
            vertices[1] += speedGroup[0];
            texCoordinates[0] = TexCoordDefault[0] + 0.2;
            texCoordinates[1] = TexCoordDefault[1] + 0.2;
        }
		if(keyStatesEnemy[' ']){
			controlaDisparos();
		}

        m_tex.remapTexCrop(texCoordinates);
        setVertices(vertices);
        glutPostRedisplay();
    }

    void Enemy::keyboardDown(unsigned char key, int x, int y) {
        keyStatesEnemy[key] = true;
		movePlayer();
    }

    void Enemy::keyboardUp(unsigned char key, int x, int y) {
        keyStatesEnemy[key] = false;
        float texCoord[4] = { 0.4f, 0.6f, 0.42f, 0.55f };
        
        m_tex.remapTexCrop(texCoord);
        glutPostRedisplay();
    }
	
	



	void Enemy::disparaProjetil(){
		for (int i = 0; i < MAX_BulletS; ++i) {
			if (m_Bullets[i]->getStatus() == false) {
				restoreBulletPos(m_Bullets[i]);
				m_Bullets[i]->setStatus(true);
				m_Bullets[i]->draw();
				break;
			}
		}
	}
	void Enemy::atualizaProjeteis(){
		for (int i = 0; i < MAX_BulletS; ++i) {
			if (m_Bullets[i]->getStatus() == true) {
				float* verticesB = m_Bullets[i]->getVertices();
				verticesB[2] += m_Bullets[i]->getSpeed()[1];
				verticesB[3] += m_Bullets[i]->getSpeed()[1];
				m_Bullets[i]->setVertices(verticesB);
				if (verticesB[3] > 1000) { //// arranjar forma de obter o tamanho da tela aqui
					m_Bullets[i]->setStatus(false);
					restoreBulletPos(m_Bullets[i]);
				}
			}
		}
	}
	

	void Enemy::controlaDisparos() {
        // Get current time in milliseconds
        int now_ms = get_current_milliseconds();
        
        // Example mouse state check (replace with actual state check)
        
        // Check if the left mouse button is pressed and if seconds are even
        if (keyStatesEnemy[' '] == true && ((now_ms % 500) < 5)) {
			std::cout << "DISPAROU\n";
            disparaProjetil(); // Dispara o projétil a partir da posição atual do avião
        }
        atualizaProjeteis(); // Atualiza a posição dos projéteis
        glutPostRedisplay(); // Redesenha a tela
        
    }

	void Enemy::setTexCoordDefault(float* vertices){
		
		TexCoordDefault[0]=vertices[0];
		TexCoordDefault[1]=vertices[1];
		TexCoordDefault[2]=vertices[2];
		TexCoordDefault[3]=vertices[3];
		
	}
	
	void Enemy::renderizar(){
		draw();
		controlaDisparos();
	}

	std::vector<std::shared_ptr<Bullet>> Enemy::getBullets()
	{
		return m_Bullets;
	}


	

// @@@@@@@@@@@@@@@@@@@@ 	Auxiliar 	@@@@@@@@@@@@@@@@@@@@


	
	void Enemy::restoreBulletPos(std::shared_ptr<Bullet> bullet)
	{
		float* posPlayer = getPosition();
		float* vertices = getVertices();
		float posBullet[] = { posPlayer[0] - 34.0f / 2, posPlayer[0] + 34.0f / 2, (posPlayer[1]+((vertices[2]-vertices[3])/2)) - 54.0f / 2, (posPlayer[1]+((vertices[2]-vertices[3])/2)) + 54.0f / 2 };
		bullet->setPosition(posBullet);
	}
// Adicione esta função no Enemy.cpp ou em um arquivo de cabeçalho apropriado

}

