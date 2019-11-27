#pragma once
#include "FMenu.h"

class NOMenu : public FMenu
{
    private:
        NOMenu() : FMenu(){};
    public:

        static NOMenu* getInstance(){
            static NOMenu only_instance;
            return &only_instance;
        }
        


        ~NOMenu() {}
        void setMenuBackground(char* t);
        void clearBackground();
        void update(){}
};