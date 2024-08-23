#include "GameObject.h"
#include <GL/gl.h>
#include <iostream>

namespace CG{
	GameObject::GameObject(float* vertices)
		:	m_vertices(vertices)
	{ }

	GameObject::GameObject( float* vertices,int health, const char* textureFile,float SpeedY, float SpeedX, float* texcoord)
		:	m_tex(Tex2D(textureFile,texcoord)),
			m_health(health),
			speedX(SpeedX),
			speedY(SpeedY),
			m_position(new float[2]{((vertices[1]-vertices[0])/2)+vertices[0],((vertices[3]-vertices[2])/2)+vertices[2]}),
			m_status(true)
	{ 
		
		m_vertices = new float[4];
		m_vertices[0] = vertices[0];
		m_vertices[1] = vertices[1];
		m_vertices[2] = vertices[2];
		m_vertices[3] = vertices[3];
		
		
	}

	void GameObject::applyModelView(){
		glTranslatef(m_position[0], m_position[1], 0);
		glScalef(m_scale[0], m_scale[1], 0);
		glRotatef(m_rotation, 0, 0, 1);
	}
	void GameObject::draw(){

		int indices[4][2] = {
			{0, 0},
			{1, 0},
			{1, 1},
			{0, 1}
		};
		//glEnable(GL_TEXTURE_2D); // Garantir que a textura está ativada
    	// Redefinir a cor para branco antes de desenhar a textura
		
		glEnable(GL_TEXTURE_2D);
		m_tex.use();
		glColor3f(1.0f, 1.0f, 1.0f);
	
		glBegin(GL_QUADS);
			
			
			for(int i = 0; i < 4; i++) {
				int x_index = indices[i][0];
				int y_index = indices[i][1];
				m_tex.defineTexCrop(x_index,y_index);
				defineVertex(x_index,y_index);
				
			}


			
			
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	void GameObject::defineVertex(int x_index,int y_index){
		glVertex3f(m_vertices[x_index], m_vertices[y_index+2],1); 
		
	}

	float* GameObject::getSpeed() {
		static float speedGroup[2] = {speedX, speedY};
		return speedGroup;
	}

	void GameObject::setVertices(float* vertices){
		m_vertices[0] = vertices[0];
		m_vertices[1] = vertices[1];
		m_vertices[2] = vertices[2];
		m_vertices[3] = vertices[3];
	}
	void GameObject::setPosition(float* pos){
		m_position[0] = pos[0];
		m_position[1] = pos[1];
		
	}
	float* GameObject::getPosition()
	{
		return m_position;
	}
	float* GameObject::getVertices(){
		return m_vertices;
	}
	int GameObject::getHealth(){
        return m_health;
    }
    void GameObject::setHealth(int health){
        m_health = health;
		if(health<=0){
			m_health=0;
			m_status = false;
		}else{
			m_health = health;
		}

    }
	bool GameObject::getStatus(){
		return m_status;
	}
	void GameObject::setStatus(bool status){
		m_status = status;
	}
}
