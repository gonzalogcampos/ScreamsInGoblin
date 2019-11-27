#pragma once
#include <vector>

class GameObject;
class GameResource{
    private:
        GameResource(){}
        std::vector<GameObject*> gameobjects;
        GameObject* player;
    public:
        static GameResource* getInstance(){
            static GameResource only_instance;
            return &only_instance;
        }
        virtual ~GameResource(){clear();};//Destructor calls the destructor of all the GameObjects
        GameObject* createGameObject(float x, float y, float z, float rz);//Returns new GameObject
        GameObject* createPlayer(float x, float y, float z, float rz);
        void updateAll(); //Calls the destructor of all the Game Objects wich toKill()
        void clear();
        GameObject* getPlayer(){return player;}
};