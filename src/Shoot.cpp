#include "Shoot.h"
#include <GL/gl.h>

namespace CG{
	Shoot::Shoot(float* vertices, int damage)
        : GameObject(vertices), // Call GameObject constructor
        m_damage(damage)
    { }

    Shoot::Shoot(float* vertices, const char* textureFile, int damage, float SpeedY, float SpeedX, float* texcoord)
        : GameObject(vertices,textureFile,SpeedY,SpeedX,texcoord), // Call GameObject constructor
        m_damage(damage)
    { }

	

	
	
	int Shoot::getDamage(){
		return m_damage;
	}

	void Shoot::setDamage(int damage){
		m_damage = damage;
	}
}