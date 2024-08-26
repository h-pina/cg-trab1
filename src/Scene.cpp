#include "Player.h"
#include "Bullet.h"
#include "Scene.h"
#include "Window.h"
#include <memory>
#include <iostream>

namespace CG {
	
	

	Scene::Scene(Window* window, int lvl_id) {
		//Create Player
		float playerVertices[4] = {-50.0f,50.0f,-450.0f,-400.0f};
		float enemyVertices[4] = {-50.0f,50.0f,400.0f,450.0f};
		float playerTexCoord[4] = {0.4f,0.6f,0.42f,0.55f};
		float enemyTexCoord[4] = {0.4f,0.6f,0.55f,0.42f};
		
		lvl_cfgs = Level(lvl_id);
		m_player = std::make_shared<Player>(
			playerVertices,lvl_cfgs.getPlayerHP(),"textures/avioes.png",4.0f,4.0f,playerTexCoord,lvl_cfgs.getPlayerDamage()
		);
		
		//Create GameObjecks 
		float* speedGroup = m_player->getSpeed();
		for(int i = 0; i < lvl_cfgs.getNEnemys(); i++)
		{
			std::shared_ptr<Enemy> bg = std::make_shared<Enemy>(
				enemyVertices,lvl_cfgs.getEnemysBaseHP(),"textures/avioesE.png",1.0f,1.0f,enemyTexCoord,lvl_cfgs.getEnemysBaseDamage()
			);
			m_sceneEnemys.push_back(bg);
			float* speedGroupE = bg->getSpeed();
			
		}
		instanceGame = this;
	}

	void Scene::updateFrame(int value){
		int points = lvl_cfgs.getPoints();

		// //Update Enemy's Shoots, moves and spawn
		lvl_cfgs.npcController(m_sceneEnemys);

		// //Detect colision between Enemy bullets and Player
		for (size_t i = 0; i < m_sceneEnemys.size(); ++i) {
			m_sceneEnemys[i]->shootController();
			m_sceneEnemys[i]->atualizaProjeteis();
			std::vector<std::shared_ptr<Bullet>> e_bul = m_sceneEnemys[i]->getBullets();
			for(int j = 0; j < MAX_BulletS;j++){
				if(e_bul[j]->getStatus()==true){
					int lose = detectColision(e_bul[j].get(),m_player.get());
					if(m_player->getStatus() == false)
					{
						std::cout << "Game Over" << std::endl;
						exit(0);
					}
				}
			}
		}

		//Hit controller

		m_player->atualizaProjeteis();
		std::vector<std::shared_ptr<Bullet>>  p_bul = m_player->getBullets();
		
		//Detect colision between PLayer bullets and any Enemy
		for(int i = 0; i < MAX_BulletS;i++){

			if(p_bul[i]->getStatus()==true){
				for (size_t j = 0; j < m_sceneEnemys.size(); ++j) {
					if(m_sceneEnemys[i]->getStatus()==true)
					{
						points+=detectColision(p_bul[i].get(),m_sceneEnemys[j].get());
					}
				}
			}
			
		}
		lvl_cfgs.setPoints(points);
		
		//Definir função para add pontos @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		glutPostRedisplay();
		
	}

	std::shared_ptr<Player> Scene::getPlayer(){
		if (m_player != nullptr){
			return m_player;
		}
		std::cout << "[ERROR] Player is not defined" << std::endl;
		return nullptr;
	}

	std::vector<std::shared_ptr<Enemy>> Scene::getSceneObjects(){
		return m_sceneEnemys;
	}

	
	Scene* Scene::getInstance() {
		
		return instanceGame;
	}
	Level* Scene::getLevel(){
		return &lvl_cfgs;
	}
	
	
}




