#include "Manager.h"

class GameObject;
class DropperManager : public Manager
{
    private:
        DropperManager():Manager(){};
        bool drop = true;
    public:
        ~DropperManager(){}
        static DropperManager* getInstance(){
            static DropperManager only_instance;
            return &only_instance;
        }
        void createComponent(GameObject* owner);
        void updateAll(float dt){};
        bool getDrop(){return drop;}
        void setDrop(bool t){drop = t;}
};