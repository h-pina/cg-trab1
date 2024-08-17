#include "Level.h"

namespace CG {
    Level::Level(int id) {
        if(id==1){  // Define os parâmetros do Level 1
            m_id = id;
            n_enemys = 3;
            total_enemys = 35;
            enemys_base_hp = 2;
            enemys_base_damage = 2;
            player_hp = 8;
            player_damage = 2;
        }
        else if(id==2){  // Define os parâmetros do Level 2
            m_id = id;
            n_enemys = 5;
            total_enemys = 27;
            enemys_base_hp = 4;
            enemys_base_damage = 2;
            player_hp = 8;
            player_damage = 2;
        }
        else if(id==3){  // Define os parâmetros do Level 3
            m_id = id;
            n_enemys = 4;
            total_enemys = 27;
            enemys_base_hp = 6;
            enemys_base_damage = 3;
            player_hp = 12;
            player_damage = 2;
        }
    }

    int Level::getNEnemys() {
        return n_enemys;
    }

    int Level::getTotalEnemys(){
        return total_enemys;
    }

    int Level::getEnemysBaseHP(){
        return enemys_base_hp;
    }
    int Level::getEnemysBaseDamage(){
        return enemys_base_damage;
    }
    int Level::getPlayerHP(){
        return player_hp;
    }
    int Level::getPlayerDamage(){
        return player_damage;
    }
    
}