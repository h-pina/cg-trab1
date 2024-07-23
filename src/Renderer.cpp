#include "Renderer.h"
#include "GameObject.h"
#include "Primitives.h"

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <memory>

namespace CG {
	Renderer::Renderer(Scene* scene)
		:	m_scene(scene)
	{ 
		glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	}

	void Renderer::drawVertices(float* vertices, size_t len, int type){
		//type 0 = mesh
		//type 1 = tex 
		for(int i = 0; i<len; i+=2){
			type == 0 ? 
				glVertex3f( vertices[i], vertices[i+1],  0) 
			: glTexCoord2f( vertices[i], vertices[i+1]);
		}
	}


	void Renderer::render(){
		glClearColor(0.7, 0.7, 0.7, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		for(std::shared_ptr<GameObject> go : m_scene->getSceneObjects()){
			go->m_tex.use();	
			glPushMatrix();
				go->applyModelView();
				glBegin(GL_TRIANGLE_FAN);
					float* goVertices = go->getVertices();
					drawVertices(goVertices, 8, 0);
					float texVertices[] = {
						0, 0,
						100, 0,
						100, 100,
						0, 100,
					};
					drawVertices(texVertices, 8, 1);
				glEnd();
			glPopMatrix();
		}
		glutSwapBuffers();
	}

}
