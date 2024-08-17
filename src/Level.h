#pragma once

#include "Player.h"
#include "Enemy.h"
#include <vector>
namespace CG {
    class Level {
        public:
            Level(int id);
            Level() = default; 
            

           

        private:
            int m_id;
            int n_enemys;
            int total_enemys;
            int enemys_base_hp;
            int enemys_base_damage;
            int player_hp;
            int player_damage;
            
    };

}