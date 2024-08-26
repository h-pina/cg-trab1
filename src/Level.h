#pragma once

#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <memory>
namespace CG {
    class Level {
        public:
            Level(int id);
            Level() = default; 
            
            void npcController(std::vector<std::shared_ptr<Enemy>> EnemyList);
            void npcSpawn(std::vector<std::shared_ptr<Enemy>> EnemyList);
            int getNEnemys();
            int getTotalEnemys();
            int getEnemysBaseHP();
            int getEnemysBaseDamage();
            int getPlayerHP();
            int getPlayerDamage();
            int getID();
            int getPoints();
            void setPoints(int Points);
            
            
           
        private:
            int m_id;
            int n_enemys;
            int total_enemys;
            int enemys_base_hp;
            int enemys_base_damage;
            int player_hp;
            int player_damage;
            int points;
            int Timer;
            
    };

}