#pragma once
#include "FRender.h"

class Render
{
    private:
        FRender* render;
        Render();
    public:
        static Render* getInstance()
        {
            static Render only_instance;
            return &only_instance;
        }

        ~Render(){}
        //Draws all the scene, better at the end of loop
        void drawAll(float dt);

        //Returns true if cotinues the loop
        bool run();

        //Closes the device
        void drop();

        //Returns the position x, y of the cursor
        float getCursorX();
        float getCursorY();

        //Creates mesh and camera
        FMesh* createMesh(char* s);
        FMesh* createAnimation(char* s, int n);
        FCamera* createCamera();
        FHUD* getHUD();
        FMenu* getMenu();
        FSprite* getSprite(char* texture, float x, float y, float sx, float sy, float rot, float r, float g, float b);
        FRender* getRender(){return render;}
        void close(){render->close();}
};