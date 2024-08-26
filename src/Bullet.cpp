#include "Bullet.h"
#include <GL/gl.h>
#include <iostream>

namespace CG{
	

    Bullet::Bullet(float* vertices,int health, const char* textureFile, float SpeedY, float SpeedX, float* texcoord)
        : GameObject(vertices,health,textureFile,SpeedY,SpeedX,texcoord) // Call GameObject constructor
        
    { 
        
    }

	int detectColision(Bullet* bul,GameObject* obj){
        float* objPos = (*obj).getPosition();
        float* objVertices = (*obj).getVertices();
        float* BulletPos = bul->getPosition();
        float* BulletVertices = bul->getVertices();
        if(obj->getStatus()==true && bul->getStatus()==true 
            && ((BulletVertices[0]>objVertices[0] && BulletVertices[0]<objVertices[1])
                || (BulletVertices[1]>objVertices[0] && BulletVertices[1]<objVertices[1]))
        ){
            if(
                ((BulletVertices[2]<objVertices[3] && BulletVertices[2]>objVertices[2])
                || (BulletVertices[3]<objVertices[3] && BulletVertices[3]>objVertices[2]))
            ){
                bul->setStatus(false);
                obj->setHealth(obj->getHealth() - bul->getHealth());
                if(obj->getStatus() == false){
                    
                    return obj->getHPbase();
                }else{
                    return 0;
                }
            }
        }
        return 0;
    }
     

    
    
}