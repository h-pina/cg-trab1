#include "Bullet.h"
#include <GL/gl.h>

namespace CG{
	

    Bullet::Bullet(float* vertices,int health, const char* textureFile, float SpeedY, float SpeedX, float* texcoord)
        : GameObject(vertices,health,textureFile,SpeedY,SpeedX,texcoord) // Call GameObject constructor
        
    { }

	void Bullet::detectColision(GameObject* obj){
        float* objPos = (*obj).getPosition();
        float* objVertices = (*obj).getVertices();
        float* BulletPos = this->getPosition();
        float* BulletVertices = this->getVertices();
        if(BulletPos[0] > objPos[0] && BulletPos[0] < objPos[0] + objVertices[0]){
            if(BulletPos[1] > objPos[1] && BulletPos[1] < objPos[1] + objVertices[1]){
                this->setStatus(false);
                (*obj).setHealth((*obj).getHealth() - this->getHealth());
            }
        }
    }
     

    
    
}