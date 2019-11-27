#pragma once
#include "Menu.h"

class PauseMenu : public Menu
{
    public:
        PauseMenu() : Menu()
        {
            //Background
            setBackground((char*)"res/sprites/menus/P/P_B.png");
            
            //Buttons
            Button* button = new Button(1, (char*)"res/sprites/menus/P/P_C_N.png", 
                                                (char*)"res/sprites/menus/P/P_C_S.png",744, 667);
            buttons.push_back(button);
            
            button = new Button(2, (char*)"res/sprites/menus/P/P_VAM_N.png", 
                                                (char*)"res/sprites/menus/P/P_VAM_S.png",615, 859);
            buttons.push_back(button);

            buttons[focus]->focus();

        }
        
        ~PauseMenu(){}
};