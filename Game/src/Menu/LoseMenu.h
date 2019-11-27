#pragma once
#include "Menu.h"

class LoseMenu : public Menu
{
    public:
        LoseMenu() : Menu()
        {
            //Background
            setBackground((char*)"res/sprites/menus/L/L_B.png");
            
            //Buttons
            Button* button = new Button(1, (char*)"res/sprites/menus/L/L_VAM_S.png", 
                                                (char*)"res/sprites/menus/L/L_VAM_S.png",553, 816);
            buttons.push_back(button);
            
            buttons[focus]->focus();
        }

        ~LoseMenu(){}
};