#pragma once
#include "Manager.h"

class GameObject;
class GPS;
class IAManager : public Manager{
    private:
        IAManager():Manager(){};
        GameObject* player;
        GPS* gps;
        int nivel;

        bool actionTime = false;
        int onAttack = 0;
       
    public:
        ~IAManager(){clear();}
        static IAManager* getInstance(){
            static IAManager only_instance;
            return &only_instance;
        }

        void init(int lv);
        void clear();
        void setPlayer(GameObject* player){this->player = player;}
        void createComponent(GameObject* owner);
        void updateAll(float dt);
        GameObject* getPlayer(){return player;}
        GPS* getGPS(){return gps;}
        void attacking(){onAttack++;}
        bool getActionTime(){return actionTime;}
};