#include "GameObject.h"
#include <GL/gl.h>

namespace CG{
	GameObject::GameObject(float* vertices)
		:	m_vertices(vertices)
	{ }

	GameObject::GameObject( float* vertices, const char* textureFile,float SpeedY, float SpeedX, float* texcoord)
		:	m_tex(Tex2D(textureFile,texcoord)),
			m_vertices(vertices),
			speedX(SpeedX),
			speedY(SpeedY),
			m_position(new float[2]{((vertices[1]-vertices[0])/2)+vertices[0],((vertices[3]-vertices[2])/2)+vertices[2]})
	{ }

	void GameObject::applyModelView(){
		glTranslatef(m_position[0], m_position[1], 0);
		glScalef(m_scale[0], m_scale[1], 0);
		glRotatef(m_rotation, 0, 0, 1);
	}
	void GameObject::draw(){
		glEnable(GL_TEXTURE_2D); // Garantir que a textura está ativada
    	// Redefinir a cor para branco antes de desenhar a textura
		glColor3f(1.0f, 1.0f, 1.0f);
		
		glBegin(GL_QUADS);
			m_tex.use();
			defineObjectBox();
		glEnd();
	}
	void GameObject::defineObjectBox(){
		glVertex2f(m_vertices[0], m_vertices[2]);
		glVertex2f(m_vertices[1], m_vertices[2]);
		glVertex2f(m_vertices[1], m_vertices[3]);
		glVertex2f(m_vertices[0], m_vertices[3]);
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
