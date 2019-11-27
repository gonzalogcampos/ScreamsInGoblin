#pragma once
#include "Manager.h"

class GameObject;
class InputManager : public Manager{
    private:
        InputManager():Manager(){}
        float cursorX, cursorY;
    public:
        ~InputManager(){}
        static InputManager* getInstance(){
            static InputManager only_instance;
            return &only_instance;
        }

        void createComponent(GameObject* owner);
        void setCursorPosition(float x, float y);
        void updateAll(float dt);
};