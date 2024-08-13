#include "Shoot.h"
#include <GL/gl.h>

namespace CG{
	Shoot::Shoot(float* vertices, int damage)
        : GameObject(vertices), // Call GameObject constructor
        m_damage(damage)
    { }

    Shoot::Shoot(float* vertices, const char* textureFile, int damage)
        : GameObject(vertices,textureFile), // Call GameObject constructor
        m_damage(damage)
    { }

	void Shoot::setVertices(float* vertices){
		m_vertices = vertices;
	}

	float* Shoot::getVertices(){
		return m_vertices;
	}

	int Shoot::getDamage(){
		return m_damage;
	}

	void Shoot::setDamage(int damage){
		m_damage = damage;
	}
}