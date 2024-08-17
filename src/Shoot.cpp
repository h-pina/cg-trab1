#include "Shoot.h"
#include <GL/gl.h>

namespace CG{
	

    Shoot::Shoot(float* vertices, int health, const char* textureFile, int damage, float SpeedY, float SpeedX, float* texcoord)
        : GameObject(vertices,health,textureFile,SpeedY,SpeedX,texcoord) // Call GameObject constructor
        
    { }

	void Shoot::detectColision(GameObject* obj){
        float* objPos = (*obj).getPosition();
        float* objVertices = (*obj).getVertices();
        float* shootPos = this->getPosition();
        float* shootVertices = this->getVertices();
        if(shootPos[0] > objPos[0] && shootPos[0] < objPos[0] + objVertices[0]){
            if(shootPos[1] > objPos[1] && shootPos[1] < objPos[1] + objVertices[1]){
                this->setStatus(false);
                (*obj).setHealth((*obj).getHealth() - this->getHealth());
            }
        }
    }
     

    
}