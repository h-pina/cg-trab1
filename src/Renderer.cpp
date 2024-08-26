#include "Renderer.h"
#include "GameObject.h"


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

		int points = 0;
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		std::shared_ptr<Player> player = m_scene->getPlayer();
		std::vector<std::shared_ptr<Enemy>> enmeysList = m_scene->getSceneObjects();

		player->renderizar();

		m_scene->getLevel()->npcSpawn(enmeysList);


		// player->atualizaProjeteis();
		// std::vector<std::shared_ptr<Bullet>>  p_bul = player->getBullets();
		
		// //Detect colision between PLayer bullets and any Enemy
		// for(int i = 0; i < MAX_BulletS;i++){

		// 	if(p_bul[i]->getStatus()==true){
		// 		for (size_t j = 0; j < enmeysList.size(); ++j) {
		// 			points+=detectColision(p_bul[i].get(),enmeysList[j].get());
		// 		}
		// 	}
			
		// }

				
		glutSwapBuffers();
		
	}


	Scene* Renderer::getScene()
	{
		return m_scene;
	}

}
