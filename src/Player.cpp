#include "Player.h"
#include "GameObject.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>


namespace CG{
	Player::Player( float* vertices, const char* textureFile,float SpeedY, float SpeedX, float* texcoord,float* pos)
		: GameObject(vertices, textureFile,SpeedY,SpeedX,texcoord,pos)	
	{ 
		mouseButtonState = GLUT_UP;

	}

	void Player::movePlayer(unsigned char key, int x, int y) {

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




	
	

	void frame(int value) {

		// Get current time in milliseconds
		int now_ms = get_current_milliseconds();
		
		// Example mouse state check (replace with actual state check)
		
		printf("miliseg %d\n", now_ms);
		// Check if the left mouse button is pressed and if seconds are even
		if (mouseButtonState == GLUT_DOWN && ((now_ms % 400)< 30)) {
			float* pos=getPosition();
			disparaProjetil(pos[0], pos[1] + 50); // Dispara o projétil a partir da posição atual do avião
			
		}
		atualizaProjeteis(); // Atualiza a posição dos projéteis
		glutPostRedisplay(); // Redesenha a tela
		glutTimerFunc(value, frame, value); // Define o próximo frame
	}

	


//Auxiliar
	int get_current_milliseconds() {
		struct timeval tv;
		gettimeofday(&tv, NULL);
		int milliseconds = (tv.tv_usec / 1000) % 1000;
		return milliseconds;
	}
}

