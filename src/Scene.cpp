#include "GameObject.h"
#include "Player.h"
#include "Scene.h"
#include "Window.h"
#include <memory>
#include <iostream>

namespace CG {
	
	Scene* instance = nullptr;

	Scene::Scene(Window* window, int lvl_id) {
		//Create Player
		float playerVertices[] = {
			150.0f,150.0f,
			150.0f,-150.0f,
			-150.0f,-150.0f,
			-150.0f,150.0f,
		};
		float playerTexCoord[4] = {0.4f,0.42f,0.6f,0.55f};

		lvl_cfgs = Level(lvl_id);
		m_player = std::make_shared<Player>(
			playerVertices,lvl_cfgs.getPlayerHP(),"avioes.png",5,5,playerTexCoord,lvl_cfgs.getPlayerDamage()
		);
		//Create GameObjecks 
		float bgVertices[] = {
			1.0f,1.0f,
			1.0f,1.0f,
			1.0f,1.0f,
			1.0f,1.0f,
		};
		std::shared_ptr<Enemy> bg = std::make_shared<Enemy>(
			playerVertices,lvl_cfgs.getEnemysBaseHP(),"avioes.png",5,5,playerTexCoord,lvl_cfgs.getEnemysBaseDamage()
		);
		
		m_sceneEnemys.push_back(bg);
		instanceGame = this;
	}

	int Scene::updateFrame(int value){
		//Update Player
		m_player->controlaDisparos();
		for (size_t i = 0; i < m_sceneEnemys.size(); ++i) {
			m_sceneEnemys[i]->controlaDisparos();
		}
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




