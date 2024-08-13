#include "GameObject.h"
#include <GL/gl.h>

namespace CG{
	GameObject::GameObject(float* vertices)
		:	m_vertices(vertices)
	{ }

	GameObject::GameObject( float* vertices, const char* textureFile,float SpeedY, float SpeedX, float* texcoord,float* position)
		:	m_tex(Tex2D(textureFile,texcoord)),
			m_vertices(vertices),
			speedX(SpeedX),
			speedY(SpeedY),
			m_position(position)
	{ }

	void GameObject::applyModelView(){
		glTranslatef(m_position[0], m_position[1], 0);
		glScalef(m_scale[0], m_scale[1], 0);
		glRotatef(m_rotation, 0, 0, 1);
	}

	float* GameObject::getSpeed(){
		float speedGroup[2] = {speedX,speedY};
		return speedGroup;
	}

	void GameObject::setVertices(float* vertices){
		m_vertices = vertices;
	}
	void GameObject::setPosition(float* pos){
		m_position = pos;
	}
	float* GameObject::getPosition()
	{
		return m_position;
	}
	float* GameObject::getVertices(){
		return m_vertices;
	}
}
