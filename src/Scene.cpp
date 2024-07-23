#include "GameObject.h"
#include "Player.h"
#include "Scene.h"
#include "Window.h"
#include <memory>
#include <iostream>

namespace CG {
	Scene::Scene(Window* window) {
		//Create Player
		float playerVertices[] = {
			150.0f,150.0f,
			150.0f,-150.0f,
			-150.0f,-150.0f,
			-150.0f,150.0f,
		};
		m_player = std::make_shared<Player>(
			playerVertices,"avioes.png"
		);
		//Create GameObjecks 
		float bgVertices[] = {
			1.0f,1.0f,
			1.0f,1.0f,
			1.0f,1.0f,
			1.0f,1.0f,
		};
		std::shared_ptr<GameObject> bg = std::make_shared<GameObject>(
			bgVertices
		);
		m_sceneObjects.push_back(bg);
		m_sceneObjects.push_back(m_player);
	}

	std::shared_ptr<Player> Scene::getPlayer(){
		if (m_player != nullptr){
			return m_player;
		}
		std::cout << "[ERROR] Player is not defined" << std::endl;
		return nullptr;
	}

	std::vector<std::shared_ptr<GameObject>> Scene::getSceneObjects(){
		return m_sceneObjects;
	}
}


