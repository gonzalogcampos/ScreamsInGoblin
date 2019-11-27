#pragma once
#include "FMenu.h"

class TSprite;
class KATMenu : public FMenu
{
    private:
        TSprite* background;
        KATMenu() : FMenu(){};
    public:

        static KATMenu* getInstance(){
            static KATMenu only_instance;
            return &only_instance;
        }
        

        ~KATMenu() {}
        void setMenuBackground(char* t);
        void clearBackground();
        void update();
};