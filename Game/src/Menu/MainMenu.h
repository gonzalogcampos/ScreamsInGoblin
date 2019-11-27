#pragma once
#include "Menu.h"

class MainMenu : public Menu
{
    public:
        MainMenu() : Menu()
        {
            //Background
            setBackground((char*)"res/sprites/menus/MP/MP_B.png");
            
            //Buttons
            Button* button = new Button(1, (char*)"res/sprites/menus/MP/MP_I_N.png", 
                                                (char*)"res/sprites/menus/MP/MP_I_S.png",756, 436);
            buttons.push_back(button);
            
            button = new Button(2, (char*)"res/sprites/menus/MP/MP_O_N.png", 
                                                (char*)"res/sprites/menus//MP/MP_O_S.png",729, 612);
            buttons.push_back(button);
            
            button = new Button(3, (char*)"res/sprites/menus//MP/MP_C_N.png", 
                                                (char*)"res/sprites/menus/MP/MP_C_S.png",746, 794);
            buttons.push_back(button);    

            button = new Button(4, (char*)"res/sprites/menus//MP/MP_S_N.png", 
                                                (char*)"res/sprites/menus/MP/MP_S_S.png",1665, 963);

            buttons.push_back(button);


            buttons[focus]->focus();

        }

        ~MainMenu(){}
};