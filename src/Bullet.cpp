#include "Bullet.h"
#include <GL/gl.h>

namespace CG{
	

    Bullet::Bullet(float* vertices,int health, const char* textureFile, float SpeedY, float SpeedX, float* texcoord)
        : GameObject(vertices,health,textureFile,SpeedY,SpeedX,texcoord) // Call GameObject constructor
        
    { }

	int detectColision(Bullet* bul,GameObject* obj){
        float* objPos = (*obj).getPosition();
        float* objVertices = (*obj).getVertices();
        float* BulletPos = bul->getPosition();
        float* BulletVertices = bul->getVertices();
        if(BulletPos[0] > objPos[0] && BulletPos[0] < objPos[0] + objVertices[0]){
            if(BulletPos[1] > objPos[1] && BulletPos[1] < objPos[1] + objVertices[1]){
                bul->setStatus(false);
                (*obj).setHealth((*obj).getHealth() - bul->getHealth());
                if((*obj).getStatus() == false){
                    return (*obj).getHealth();
                }else{
                    return 0;
                }
            }
        }
    }
     

    
    
}