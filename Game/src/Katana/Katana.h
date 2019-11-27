#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../../lib/GL/glew.h"
#define GLM_ENABLE_EXPERIMENTAL 

#include "../../lib/GLFW/glfw3.h"
#include "../../lib/glm/glm.hpp"

#include "TNode.h"
#include "TAnimation.h"
#include "TCamera.h"
#include "TLight.h"
#include "TMesh.h"
#include "TTransform.h"
#include "TResourceManager.h"
#include "TResourceOBJ.h"
#include "TResourceShader.h"
#include "TResourceAnimation.h"
#include "TSprite.h"

class SpriteRenderer;
struct CursorXYZ
{
    float x, y, z;
};

class Katana
{
    private: 
        float dTime = 0.1f;
        GLFWwindow* window;
        TNode* scene;
        TNode* camera;
        TNode* light;
        TResourceManager* manager;
        GLuint spriteProgram;
        GLuint shaderProgram;
        glm::vec3 cameraPos = glm::vec3(0, 0, 0);
        std::vector<TSprite*> sprites;

        SpriteRenderer* spriteRenderer;
        
    public:
        static Katana* getInstance(){
            static Katana only_instance;
            return &only_instance;
        }
        GLFWwindow* initWindow();
        bool openWindow(GLFWwindow* w);
        void processInput(GLFWwindow *window);
        void clear(GLFWwindow* w);
        void close();

        TResourceManager* getManager(){return manager;};
        void clean();
        void initOpenGL();
        void renderCamera();
        void drawAll(float dt);

        //TREE METHODS
        void initRoot();
        TNode* getSceneRoot() { return scene; }
        TNode* createNodeMesh(TNode* f, glm::vec3 v, const char* mesh);   
        TNode* createNodeLigth(TNode* f, glm::vec3 v, glm::vec4 i);
        TNode* createNodeAnimation(TNode* f, glm::vec3 v, const char* name, int nf);
        TNode* createNodeCamera(TNode* f, glm::vec3 m, glm::vec3 v, float n,float ff);
        TNode* getNodeCamera() {return camera;}
        void renderBillboards();
        void deleteNodeBranch(TNode* n);
        void initAnimations();

        TNode* createBranch(TNode* f, glm::vec3 v);
        CursorXYZ cursorPosition();

        void createNodeTexture(char* name, glm::vec3 p);
        void renderTexture();

        void setCameraPosition(float x, float y, float z);

        void renderLight();

        void drawSprites();
        TSprite* createSprite(char* path);
        void removeSprite(TSprite* sprite);
        void getWindowSize(int &window_w,int &window_h);
        float getTime(){return dTime;};
};
