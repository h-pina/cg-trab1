#include "GameObject.h"
#include <GL/gl.h>

namespace CG{
	GameObject::GameObject(float* vertices)
		:	m_vertices(vertices)
	{ }

	GameObject::GameObject( float* vertices, const char* textureFile)
		:	m_tex(Tex2D(textureFile)),
			m_vertices(vertices)
	{ }

	void GameObject::applyModelView(){
		glTranslatef(m_position[0], m_position[1], 0);
		glScalef(m_scale[0], m_scale[1], 0);
		glRotatef(m_rotation, 0, 0, 1);
	}

	void GameObject::setVertices(float* vertices){
		m_vertices = vertices;
	}

	float* GameObject::getVertices(){
		return m_vertices;
	}
}
