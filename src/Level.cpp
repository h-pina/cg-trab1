#include "Level.h"
#include <memory>
#include <math.h>

namespace CG {
    Level::Level(int id) {
        if(id==1){  // Define os parâmetros do Level 1
            m_id = id;
            n_enemys = 3;
            total_enemys = 5;
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
        Timer = -1;
        points = 0;
    }

    void Level::npcController(std::vector<std::shared_ptr<Enemy>> EnemyList) {
        int ms = get_current_milliseconds();
        for (int i = 0; i < n_enemys; i++) {
            
            float* vertices = EnemyList[i]->getVertices();
            if(EnemyList[i]->getStatus()==true){
                EnemyList[i]->keyboardDown('s',5,5);
                if(ms<500){
                    //EnemyList[i]->disparaProjetil();
                }
                
                if(EnemyList[i]->getStatus() == true && vertices[2]<=-450.0f){
                    EnemyList[i]->setStatus(false);
                }    
            }
            
        }
        

    }

    void Level::npcSpawn(std::vector<std::shared_ptr<Enemy>> EnemyList) {
        int secClock = get_current_seconds();
        int msClock = rand();
        int spawn = 0;
        for (int i = 0; i < n_enemys; i++) {
                   
            if((secClock % 3) == 0 && (Timer)!=(secClock/3)){
            
                if(EnemyList[i]->getStatus()==false and spawn==0){
                    //Exibe um novo inimigo
                    spawn=1;
                    int factor = pow(-1,secClock%2);
                    

                    float xDefault =msClock%800*factor;
                    float* enemyVertices = EnemyList[i]->getVertices();
                    //Garante que o inimigo va estar sempre a 10 pontos da margem direita ou esquerda 
                    if(xDefault<-740){
                        xDefault = -740;
                    }
                    else if(xDefault>740){
                        xDefault = 740;
                    }
                    float verticesEnemy[4] = {xDefault-(enemyVertices[1]-enemyVertices[0])/2,xDefault+(enemyVertices[1]-enemyVertices[0])/2,400.0f-(enemyVertices[3]-enemyVertices[2]),400.0f};
                    EnemyList[i]->setVertices(verticesEnemy);
                    EnemyList[i]->setHealth(enemys_base_hp);
                    
                    EnemyList[i]->setStatus(true);
                    EnemyList[i]->renderizar();
                    Timer = secClock/3;
                    
                    
                           
                }
                
            }
            
            EnemyList[i]->renderizar();
        }

    }

    void Level::killEnemy(){
        total_enemys--;
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
    int Level::getPoints(){
        return points;
    }
    void Level::setPoints(int Points){
        points = Points;
    }
    
}