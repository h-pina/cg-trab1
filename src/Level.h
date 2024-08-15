#pragma once

#include "Player.h"
#include "Enemy.h"
#include <vector>
namespace CG {
    class Level {
        public:
            Level(Player* player);
            ~Level();

            void Update();
            void Render();

            void AddEnemy(Enemy* enemy);
            void RemoveEnemy(Enemy* enemy);

        private:
            Player* m_player;
            std::vector<Enemy*> m_enemies;
    };

}