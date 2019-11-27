#pragma once
#include "FRender.h"

class NORender : public FRender{
    private:

        NORender();
        int loops = 0;
        bool toClose = false;
    public:
        
        static NORender* getInstance(){
            static NORender only_instance;
            return &only_instance;
        }
        
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//---------- - - - - - - COMMON FUNCTIONS - - - - - - - - - ----------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------          

        void drawAll(float dt);
        bool run();
        void drop();
        float getCursorX();
        float getCursorY();
        FMesh* createMesh(char* s);
        FMesh* createAnimation(char* s, int n);
        FCamera* createCamera();
        FHUD* getHUD();
        FMenu* getMenu();
        FSprite* getSprite(char* texture, float x, float y, float sx, float sy, float rot, float r, float g, float b);
        void getWindowSize(int &x, int &y){};
        void close();

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//---------- - - - - - - SPECIFIC FUNCTIONS - - - - - - - - - --------------
//--------------------------------------------------------------------------
//-------------------------------------------------------------------------- 

        void loop(){loops++;}
};