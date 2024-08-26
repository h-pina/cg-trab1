#pragma once
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Window.h"
#include "Level.h"


#include <memory>
#include <vector>

namespace CG {
	class Scene {
		public:
			Scene(Window* window, int lvl_id);
			std::shared_ptr<Player> getPlayer();
			std::vector<std::shared_ptr<Enemy>> getSceneObjects();
			void updateFrame(int value);
			void keyboardCallback(unsigned char key, int x, int y);
			Scene* getInstance();
			void startTimer();
			Level* getLevel();
			

		private:	
			Window* m_window;
			Level lvl_cfgs;
			std::shared_ptr<Player> m_player = nullptr;
			std::vector<std::shared_ptr<Enemy>> m_sceneEnemys;

			Scene* instanceGame;
	};
}
