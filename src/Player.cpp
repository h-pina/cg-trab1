#include "Player.h"
#include "GameObject.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <vector>


namespace CG{
	
	// Player* Player::instance = nullptr;

	Player::Player( float* vertices, int healthP, const char* textureFile,float SpeedY, float SpeedX, float* texcoord, int damage)
		: GameObject(vertices, healthP, textureFile,SpeedY,SpeedX,texcoord)	
	{ 
		mouseButtonState = GLUT_UP;

        float* posPlayer = getPosition();
        float verticesShoot[4] = { posPlayer[0] - 34.0f / 2, posPlayer[0] + 34.0f / 2, posPlayer[1] - 54.0f / 2, posPlayer[1] + 54.0f / 2 };
        float textCoord[4] = { 0.0f, 1.0f, 0.0f, 1.0f };

		float posShoot[] = {posPlayer[0],posPlayer[1]+vertices[3]-vertices[2]};
        for (int i = 0; i < MAX_SHOOTS; i++) {
            m_shoots[i] = Shoot(verticesShoot,damage, "../textures/projetilPlayer.png", 5, SpeedY, SpeedX, textCoord);
			restoreShootPos(&m_shoots[i]);
        }
		// instance = this;
	}

	void Player::movePlayer(unsigned char key) {

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



	void Player::disparaProjetil(){
		for (int i = 0; i < MAX_SHOOTS; ++i) {
			if (m_shoots[i].getStatus() == false) {
				restoreShootPos(&m_shoots[i]);
				m_shoots[i].setStatus(true);
				break;
			}
		}
	}
	void Player::atualizaProjeteis(){
		for (int i = 0; i < MAX_SHOOTS; ++i) {
			if (m_shoots[i].getStatus() == true) {
				float* pos = m_shoots[i].getPosition();
				pos[1] += m_shoots[i].getSpeed()[1];
				m_shoots[i].setPosition(pos);
				if (pos[1] > 1000) { //// arranjar forma de obter o tamanho da tela aqui
					m_shoots[i].setStatus(false);
					restoreShootPos(&m_shoots[i]);
				}
			}
		}
	}
	

	void Player::frame(int value) {
        // Get current time in milliseconds
        int now_ms = get_current_milliseconds();
        
        // Example mouse state check (replace with actual state check)
        printf("miliseg %d\n", now_ms);
        // Check if the left mouse button is pressed and if seconds are even
        if (mouseButtonState == GLUT_DOWN && ((now_ms % 400) < 30)) {
            disparaProjetil(); // Dispara o projétil a partir da posição atual do avião
        }
        atualizaProjeteis(); // Atualiza a posição dos projéteis
        glutPostRedisplay(); // Redesenha a tela
        //glutTimerFunc(value, [](int v) { instance->frame(v); }, value); // Define o próximo frame
    }
	
	

	

// @@@@@@@@@@@@@@@@@@@@ 	Auxiliar 	@@@@@@@@@@@@@@@@@@@@


	int get_current_milliseconds() {
		struct timeval tv;
		gettimeofday(&tv, NULL);
		int milliseconds = (tv.tv_usec / 1000) % 1000;
		return milliseconds;
	}

	void Player::restoreShootPos(Shoot* shoot)
	{
		float* posPlayer = getPosition();
		float* vertices = getVertices();
		float posShoot[] = {posPlayer[0],posPlayer[1]+vertices[3]-vertices[2]};
		shoot->setPosition(posShoot);
	}


	// Player* Player::getInstance() {
	// 	if (instance == nullptr) {
	// 		float* vertices = new float[4]();
	// 		const char* textureFile = "";
	// 		float SpeedY = 0.0f;
	// 		float SpeedX = 0.0f;
	// 		float* texcoord = new float[4]();
	// 		instance = new Player(vertices, textureFile, SpeedY, SpeedX, texcoord);
	// 	}
	// 	return instance;
	// }
	
	// void Player::startTimer() {
    //     instance = this;
    //     glutTimerFunc(16, [](int v) { instance->frame(v); }, 16);
    // }
}

