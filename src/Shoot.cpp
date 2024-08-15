#include "Shoot.h"
#include <GL/gl.h>

namespace CG{
	Shoot::Shoot(float* vertices, int damage)
        : GameObject(vertices), // Call GameObject constructor
        m_damage(damage)
    { }

    Shoot::Shoot(float* vertices, const char* textureFile, int damage, float SpeedY, float SpeedX, float* texcoord)
        : GameObject(vertices,textureFile,SpeedY,SpeedX,texcoord), // Call GameObject constructor
        m_damage(damage),
        m_active(int(0))
    { }

	

	
	
	int Shoot::getDamage(){
		return m_damage;
	}

	void Shoot::setDamage(int damage){
		m_damage = damage;
	}

    int Shoot::getStatus()
    {
        return m_active;
    }

    void Shoot::changeStatus()
    {
        if(m_active == 0){
            m_active = 1;
        }else{
            m_active = 0;
        }
    }
}