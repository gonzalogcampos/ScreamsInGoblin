#pragma once
#include "Menu.h"

class CreditsMenu : public Menu
{
    public:
        CreditsMenu() : Menu()
        {
            //Background
            setBackground((char*)"res/sprites/menus/C/C_B.png");
            
            //Buttons
            Button* button = new Button(1, (char*)"res/sprites/menus/C/C_V_S.png", 
                                                (char*)"res/sprites/menus/C/C_V_S.png",1581, 963);
            buttons.push_back(button);
        
            buttons[focus]->focus();
        }

        ~CreditsMenu(){}
};