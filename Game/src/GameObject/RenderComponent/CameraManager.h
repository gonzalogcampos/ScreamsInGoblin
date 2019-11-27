#pragma once
#include "Manager.h"



class GameObject;
class CameraManager : public Manager{
    private:
        CameraManager():Manager(){}
        float cx,cy,cz;
        
    public:
        ~CameraManager(){}
        static CameraManager* getInstance(){
            static CameraManager only_instance;
            return &only_instance;
        }

        void createComponent(GameObject* go);
        void updateAll(float dt);

    float getCX (){ return cx;}
    float getCY (){ return cy;}
    float getCZ (){ return cz;}

    void setCameraPosition(float x, float y, float z){ cx = x; cy = y; cz = z;}
};