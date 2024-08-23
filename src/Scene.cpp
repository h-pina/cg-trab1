#include "Player.h"
#include "Bullet.h"
#include "Scene.h"
#include "Window.h"
#include <memory>
#include <iostream>

namespace CG {
	
	Scene* instance = nullptr;

	Scene::Scene(Window* window, int lvl_id) {
		//Create Player
		float playerVertices[4] = {0.0f,100.0f,0.0f,50.0f};
		float playerTexCoord[4] = {0.4f,0.6f,0.42f,0.55f};
		
		lvl_cfgs = Level(lvl_id);
		m_player = std::make_shared<Player>(
			playerVertices,lvl_cfgs.getPlayerHP(),"textures/avioes.png",5,5,playerTexCoord,lvl_cfgs.getPlayerDamage()
		);
		
		//Create GameObjecks 
		float bgVertices[] = {
			1.0f,1.0f,
			1.0f,1.0f,
			1.0f,1.0f,
			1.0f,1.0f,
		};
		std::shared_ptr<Enemy> bg = std::make_shared<Enemy>(
			playerVertices,lvl_cfgs.getEnemysBaseHP(),"textures/avioesE.png",5,5,playerTexCoord,lvl_cfgs.getEnemysBaseDamage()
		);
		
		m_sceneEnemys.push_back(bg);
		instanceGame = this;
	}

	void Scene::updateFrame(int value){
		int points = 0;

		//Update Enemy's Shoots, moves and spawn
		lvl_cfgs.npcController(m_sceneEnemys);

		//Detect colision between Enemy bullets and Player
		for (size_t i = 0; i < m_sceneEnemys.size(); ++i) {
			m_sceneEnemys[i]->controlaDisparos();
			std::vector<std::shared_ptr<Bullet>> e_bul = m_sceneEnemys[i]->getBullets();
			for(int j = 0; j < MAX_BulletS;j++){
				int lose = detectColision(e_bul[j].get(),m_player.get());
				if(lose == 0)
				{
					//MOrreu o player
				}
			}
		}

		//Hit controller

		m_player->controlaDisparos();
		std::vector<std::shared_ptr<Bullet>>  p_bul = m_player->getBullets();
		
		//Detect colision between PLayer bullets and any Enemy
		for(int i = 0; i < MAX_BulletS;i++){

			for (size_t j = 0; j < m_sceneEnemys.size(); ++j) {
				points+=detectColision(p_bul[i].get(),m_sceneEnemys[j].get());
			}
			
		}
		
		//Definir função para add pontos @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

		glutTimerFunc(value, [](int v) { instance->updateFrame(v); }, value); // Define o próximo frame
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
	
	
}




