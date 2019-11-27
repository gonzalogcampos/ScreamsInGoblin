#pragma once
#include "FRender.h"
#include "Katana.h"

class GLFWwindow;
class KATRender : public FRender{
    private:
        GLFWwindow* window;
        Katana* katana;
        TNode* scene;
        KATRender();
    public:
        
        static KATRender* getInstance(){
            static KATRender only_instance;
            return &only_instance;
        }
        
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//---------- - - - - - - COMMON FUNCTIONS - - - - - - - - - ----------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------          

        void drawAll(float dt);
        void getWindowSize(int &x, int &y);
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
        void close();
        
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//---------- - - - - - - SPECIFIC FUNCTIONS - - - - - - - - - --------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------  

        TNode* getScene(){return scene;}
        void setCamera(float x,float y,float z);
        void deleteNode(TNode* n);
        Katana* getKatana(){return katana;}

};