#pragma once
#include "Manager.h"

class GameObject;
class ScoreManager : public Manager
{
    private:
        ScoreManager():Manager(){score = 0.f;}
        int score;
        bool win = false;
    
    public:
        ~ScoreManager(){clear();}
        static ScoreManager* getInstance(){
            static ScoreManager only_instance;
            return &only_instance;
        }

        void clear(){components.clear(); score = 0.f;}
        void createComponent(GameObject* owner, int score);
        void updateAll(float dt){}
        void applyScore(int score);
        int getScore(){return score;};
        int resetScore();
        int getEnemies(){return static_cast<int>(components.size());}
        bool getWin();
        void setWin(bool w = true){win = w;}
};