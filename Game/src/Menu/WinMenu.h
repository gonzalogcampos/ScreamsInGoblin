#pragma once
#include "Menu.h"

class WinMenu : public Menu
{
    public:
        WinMenu() : Menu()
        {
            //Background
            setBackground((char*)"res/sprites/menus/W/W_B.png");
            
            //Buttons
            Button* button = new Button(1, (char*)"res/sprites/menus/W/W_VAM_S.png", 
                                                (char*)"res/sprites/menus/W/W_VAM_S.png",553, 816);
            buttons.push_back(button);

            buttons[focus]->focus();

        }
        
        ~WinMenu(){}
};