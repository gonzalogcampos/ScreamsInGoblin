#pragma once
class FMesh;
class FCamera;
class FHUD;
class FMenu;
class FSprite;
class FRender
{
    protected:
        FRender(){};
    public:
        virtual ~FRender(){}
        //Draws all the scene, better at the end of loop
        virtual void drawAll(float dt) = 0;

        //Returns true if cotinues the loop
        virtual bool run() = 0;

        //Closes the device
        virtual void drop() = 0;

        //Returns the position x, y of the cursor
        virtual float getCursorX() = 0;
        virtual float getCursorY() = 0;

        //Creates mesh and camera
        virtual FMesh* createMesh(char* s) = 0;
        virtual FMesh* createAnimation(char* s, int n) = 0;
        virtual FCamera* createCamera() = 0;
        virtual FHUD* getHUD() = 0;
        virtual FMenu* getMenu() = 0;
        virtual FSprite* getSprite(char* texture, float x, float y, float sx, float sy, float rot, float r, float g, float b) = 0; 
        virtual void getWindowSize(int &x, int &y) = 0;       
        virtual void close() = 0; 
        
};