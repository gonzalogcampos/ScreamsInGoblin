#pragma once
#include <iostream>
#include <vector>
#include "Render.h"
#include "KATMenu.h"
#include "FSprite.h"

class Button
{
    private:
        FSprite* sprite;
        float x, y;
        float sx, sy;
        char* pathnormal;
        char* pathfocus;
        int id;
    public:
        Button(int id, char* pathnormal, char* pathfocus, float x, float y);
        ~Button(){delete sprite;}
        int getID(){return id;}

        void focus();
        void unfocus();
        void setPosition(float x, float y);
        void setScale(float sx, float sy);
        void setColor(float r, float g, float b);
        void setRotation(float r);
        void update();

};


class Menu
{
    protected:
        FSprite* background;
        std::vector<Button*> buttons;
        std::size_t focus;
        float at;
    public:
        Menu(){focus = 0;}
        ~Menu(){clear();}
        void clear();
        void down();
        void up();
        void updateButtons();
        void setBackground(char* b);
        void update(float dt);

        int click();
};
