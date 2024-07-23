#pragma once
#include "GameObject.h"
#include "Player.h"
#include "Window.h"

#include <memory>
#include <vector>

namespace CG {
	class Scene {
		public:
			Scene(Window* window);
			std::shared_ptr<Player> getPlayer();
			std::vector<std::shared_ptr<GameObject>> getSceneObjects();
		private:	
			Window* m_window;
			std::shared_ptr<Player> m_player = nullptr;
			std::vector<std::shared_ptr<GameObject>> m_sceneObjects;
	};
}
