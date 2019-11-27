#pragma once
#include "Menu.h"

class ToNextMenu : public Menu
{
    public:
        ToNextMenu() : Menu()
        {
            //Background
            setBackground((char*)"res/sprites/menus/N/N_B.png");
            
            //Buttons
            Button* button = new Button(1, (char*)"res/sprites/menus/N/N_SN_N.png", 
                                                (char*)"res/sprites/menus/N/N_SN_S.png",619, 667);
            buttons.push_back(button);
            
            button = new Button(2, (char*)"res/sprites/menus/N/N_VAM_N.png", 
                                                (char*)"res/sprites/menus/N/N_VAM_S.png",615, 859);
            buttons.push_back(button);

            buttons[focus]->focus();

        }
        
        ~ToNextMenu(){}
};