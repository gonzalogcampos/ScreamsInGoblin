#include "Katana.h"
#include "../common/shader.cpp"
// Include GLM
#include "../../lib/glm/glm.hpp"
#define GLM_ENABLE_EXPERIMENTAL 
#include <iostream>
#include "GameValues.h"
//#include "resource_manager.h"
#include "SpriteRenderer.h"
#include "Texture2D.h"

//float Katana::dTime;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void MessageCallback( GLenum source,
                      GLenum type,
                      GLuint id,
                      GLenum severity,
                      GLsizei length,
                      const GLchar* message,
                      const void* userParam )
{
  fprintf( stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
           ( type == GL_DEBUG_TYPE_ERROR ? " GL ERROR " : "" ),
            type, severity, message );
}

GLFWwindow* Katana::initWindow()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    // --------------------
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
    window = glfwCreateWindow(mode->width, mode->height, "Screams In Goblin", monitor, NULL); //monitor

    //window = glfwCreateWindow(gv::SCR_WIDTH, gv::SCR_HEIGHT, "Screams In Goblin", monitor, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        //return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    return window;
}

void Katana::initRoot()
{
    scene = new TNode();
    manager = new TResourceManager();

    glm::mat4& Projection = scene->getEntity()->projectionMatrix();
    Projection = glm::mat4(1.0f);
    glm::mat4& View = scene->getEntity()->viewMatrix();
    View = glm::mat4(1.0f);
    glm::mat4& Model = scene->getEntity()->modelMatrix();
    Model = glm::mat4(1.0f);

}

bool Katana::openWindow(GLFWwindow* w)
{
    return !glfwWindowShouldClose(w);
}

void Katana::clear(GLFWwindow* w)
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(w);
    glfwPollEvents();
}
// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void Katana::processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

//We create all the branch with the 3 transformations in the order ROT - SCA - TRANS
TNode* Katana::createNodeMesh(TNode* f, glm::vec3 v, const char* m)
{
    if(f!= nullptr)
    {
        //Be sure that the father is a root or a transformation node
        if(f->getEntity() == nullptr || dynamic_cast<TTransform*>(f->getEntity()) != nullptr)
        {
            //Creates a 3 node branch with their respective transformations
            TNode* nodeRST = createBranch(f,v);
            
            //Mesh Leaf, load in memory mesh and assign it
            TMesh* mesh = new TMesh();
            TResourceOBJ* mm = manager->getResourceOBJ(m);
            mesh->setMesh((TResource*) mm);
            
            TNode* nodeMesh = new TNode(nodeRST,mesh);
            nodeMesh->setId(4);
            nodeRST->addChild(nodeMesh);

            return nodeMesh;
        }
    }
    return nullptr;
}

TNode* Katana::createNodeLigth(TNode* f, glm::vec3 v, glm::vec4 i)
{
    if(f->getEntity() == nullptr || dynamic_cast<TTransform*>(f->getEntity()) != nullptr)
    {
        //Creates a 3 node branch with their respective transformations
        TNode* nodeRST = createBranch(f,v);

        //light Leaf
        TLight* l = new TLight();
        l->setIntesity(i);
        l->setActivated(true);
        TNode* nodeLight = new TNode(nodeRST, l);
        nodeRST->addChild(nodeLight);

        return nodeLight;
    }
    return nullptr;
}

TNode* Katana::createNodeAnimation(TNode* f, glm::vec3 v, const char* name, int nf)
{
    if(f!= nullptr)
    {
        //Be sure that the father is a root or a transformation node
        if(f->getEntity() == nullptr || dynamic_cast<TTransform*>(f->getEntity()) != nullptr)
        {
            //Creates a 3 node branch with their respective transformations
            TNode* nodeRST = createBranch(f,v);
            
            //Mesh Leaf, load in memory mesh and assign it
            TAnimation* animation = new TAnimation();
            TResourceAnimation* an = manager->getResourceAnimation(name,nf);
            animation->setAnimation(an);
            
            TNode* nodeAnimation = new TNode(nodeRST,animation);
            nodeRST->addChild(nodeAnimation);

            return nodeAnimation;
        }
    }
    return nullptr;
}
TNode* Katana::createNodeCamera(TNode* f, glm::vec3 p, glm::vec3 v, float n,float ff)
{
    if(f->getEntity() == nullptr || dynamic_cast<TTransform*>(f->getEntity()) != nullptr)
    {
        TNode* nodeRST = createBranch(f,p);
        setCameraPosition(p.x, p.y, p.z);
        //Camera Leaf
        TCamera* c = new TCamera();
        TNode* nodeCamera = new TNode(nodeRST, c);
        nodeCamera->setId(10);
        nodeRST->addChild(nodeCamera);
        camera = nodeCamera;

        return camera;
    }
    return nullptr;
}


TNode* Katana::createBranch(TNode* f, glm::vec3 v)
{
    //Rotation node
    TTransform* tr = new TTransform();
    tr->identity();
    TNode* nodeRot = new TNode(f, tr);
    nodeRot->setId(1);

    f->addChild(nodeRot);

    //Scale node
    TTransform* ts = new TTransform();
    ts->identity();
    TNode* nodeSca = new TNode(nodeRot, ts);
    nodeSca->setId(2);
    nodeRot->addChild(nodeSca);

    //Translation node
    TTransform* tt = new TTransform();
    tt->identity();
    tt->translate(v.x,v.y,v.z);
    TNode* nodeTrans = new TNode(nodeSca, tt);
    nodeTrans->setId(3);

    nodeSca->addChild(nodeTrans);

    return nodeTrans;
}

void Katana::clean()
{
    delete manager;
    delete scene;
}

void Katana::initOpenGL()
{

    const char * vshader_path   = "src/Katana/shaders/defaultVertex.glsl";
    const char * fshader_path   = "src/Katana/shaders/defaultFragment.glsl";
    const char * vsprite_path   = "src/Katana/shaders/spriteVertex.glsl";
    const char * fsprite_path   = "src/Katana/shaders/spriteFragment.glsl";

    GLenum res = glewInit();
    if (res != GLEW_OK)
    {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
    }
    glEnable( GL_DEBUG_OUTPUT );
    //glDebugMessageCallback( (GLDEBUGPROC) MessageCallback, 0 );

    TResourceShader* vertexShader   = manager->getResourceShader(vshader_path, (GLenum)GL_VERTEX_SHADER);
	TResourceShader* fragmentShader = manager->getResourceShader(fshader_path, (GLenum)GL_FRAGMENT_SHADER);
    TResourceShader* vspriteShader  = manager->getResourceShader(vsprite_path, (GLenum)GL_VERTEX_SHADER);
    TResourceShader* fspriteShader  = manager->getResourceShader(fsprite_path, (GLenum)GL_FRAGMENT_SHADER);
 
    GLuint vertexID     = vertexShader->getId();
	GLuint fragmentID   = fragmentShader->getId();
    GLuint vspriteID    = vspriteShader->getId();
    GLuint fspriteID    = fspriteShader->getId();

    shaderProgram = glCreateProgram();
    spriteProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexID);
    glAttachShader(shaderProgram, fragmentID);
    glLinkProgram(shaderProgram);
    glValidateProgram(shaderProgram);


    glAttachShader(spriteProgram, vspriteID);
    glAttachShader(spriteProgram, fspriteID);
    glLinkProgram(spriteProgram);
    glValidateProgram(spriteProgram);
  

    glDetachShader(shaderProgram, vertexID);
	glDetachShader(shaderProgram, fragmentID);
    glDetachShader(spriteProgram, vspriteID);
	glDetachShader(spriteProgram, fspriteID);

    glDeleteShader(vertexID);
    glDeleteShader(fragmentID);
    glDeleteShader(vspriteID);
    glDeleteShader(fspriteID);


    GLint Result = GL_FALSE;
    int InfoLogLength;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &Result);
	glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> ProgramErrorMessage(InfoLogLength+1);
		glGetProgramInfoLog(shaderProgram, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
    }

    //Enable Z-Buffer 
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS); 
	glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    scene->getEntity()->setProgramID(shaderProgram);

    GLuint view         = glGetUniformLocation(shaderProgram, "view");
    GLuint model        = glGetUniformLocation(shaderProgram, "model");
    GLuint projection   = glGetUniformLocation(shaderProgram, "ProjectionMatrix");
	GLuint matrix       = glGetUniformLocation(shaderProgram, "MVP");
    GLuint TextureID    = glGetUniformLocation(shaderProgram, "myTextureSampler");

    scene->getEntity()->setviewID(view);
    scene->getEntity()->setmodelID(model);
    scene->getEntity()->setprojectionID(projection);
	scene->getEntity()->setMVPID(matrix);

    glUseProgram(shaderProgram);
	glUniform1i(TextureID, 0);

	glUniform1i(TextureID, 0);


    spriteRenderer = new SpriteRenderer(spriteProgram);
}

void Katana::deleteNodeBranch(TNode* n)
{
    if(n!=nullptr)
    {
        TNode* d = n->getFather()->getFather()->getFather();
        if(d != nullptr && dynamic_cast<TTransform*>(d->getEntity()) != nullptr)
            scene->remChild(d);            
    }
}

void Katana::renderCamera()
{
    
    glm::mat4 tm  = ((TTransform*) camera->getFather()->getEntity())->getMatrix();
    glm::mat4 sm  = ((TTransform*) camera->getFather()->getFather()->getEntity())->getMatrix();
    glm::mat4 rm  = ((TTransform*) camera->getFather()->getFather()->getFather()->getEntity())->getMatrix();

    glm::mat4 fm = tm * sm * rm;
    scene->getEntity()->viewMatrix() = glm::inverse(fm);


}

void Katana::drawAll(float dt)
{
    dTime = dt;
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(scene->getEntity()->getProgramID());
    renderCamera();
    renderLight();

    // Use our shader
    scene->draw();
    drawSprites();

    // Swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Katana::close()
{
    glfwSetWindowShouldClose(window, 1);
}

CursorXYZ Katana::cursorPosition()
{
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    float x = 2 * xpos/width -1;
    float y = 1 - 2 * ypos/height;
    float z = 1.0f;

    glm::vec3 ray_nds = glm::vec3(x, y, z);
    glm::vec4 ray_clip = glm::vec4(ray_nds.x, ray_nds.y, -1.0, 1.0);
    glm::vec4 ray_eye = glm::inverse(scene->getEntity()->projectionMatrix()) * ray_clip;
    ray_eye = glm::vec4(ray_eye.x, ray_eye.y, -1.0, 0.0);

    glm::vec3 ray_wor = (glm::inverse(scene->getEntity()->viewMatrix()) * ray_eye);

    x = cameraPos.x - ((cameraPos.z * ray_wor.x) / ray_wor.z);
    y = cameraPos.y - ((cameraPos.z * ray_wor.y) / ray_wor.z);

    return CursorXYZ{-x, y, 0.f};
}


void Katana::setCameraPosition(float x, float y, float z)
{
    cameraPos.x = x;
    cameraPos.y = y;
    cameraPos.z = z;
}

void Katana::renderLight()
{
    GLuint camID        = glGetUniformLocation(shaderProgram, "viewPos");
    GLuint lightpos     = glGetUniformLocation(shaderProgram, "lightPos");
    GLuint lightcol     = glGetUniformLocation(shaderProgram, "lightColor");
    GLuint objectcol    = glGetUniformLocation(shaderProgram, "objectColor");
    GLuint lightcoldif    = glGetUniformLocation(shaderProgram, "lightColordiffuse");

    glm::mat4 v         = scene->getEntity()->viewMatrix();

	glm::vec3 camPos    = glm::vec3(-v[3][2], -v[3][1], -v[3][0]);
    glm::vec3 lc        = glm::vec3(0.5,0.5,1.0);
    glm::vec3 dc        = glm::vec3(1.0,0.8,0.5);
    glm::vec3 oc        = glm::vec3(1.0,0.5,0.31);
    glm::vec3 lp        = glm::vec3(0.0,0.0,-25.0);

    glUniform3fv(camID,1,&camPos[0]);
    glUniform3fv(lightpos,1,&lp[0]);
    glUniform3fv(lightcol,1,&lc[0]);         

    glUniform3fv(objectcol,1,&oc[0]);   
    glUniform3fv(lightcoldif,1,&dc[0]);
}




void Katana::drawSprites(){
            int SCREEN_WIDTH;
            int SCREEN_HEIGHT;

            glfwGetWindowSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);
            glUseProgram(spriteProgram);
            glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(SCREEN_WIDTH), static_cast<GLfloat>(SCREEN_HEIGHT), 0.0f, -1.0f, 1.0f);
            GLuint imageID      = glGetUniformLocation(spriteProgram, "image");
            GLuint projectionID = glGetUniformLocation(spriteProgram, "projection");
            GLuint transp       = glGetUniformLocation(spriteProgram, "transparency");

            glUniform1i(transp, true);
            glUniformMatrix4fv(projectionID, 1, GL_FALSE, &projection[0][0]);
            glUniform1i(imageID, 0);

            SpriteRenderer renderer(spriteProgram);
            for(size_t i = sprites.size(); i>=1; i--)
            {
                if(sprites[i-1])
                {
                    Texture2D* texture = sprites[i-1]->getTexture();
                    renderer.DrawSprite(*texture, sprites[i-1]->position, sprites[i-1]->size, sprites[i-1]->rotation, sprites[i-1]->color);
                }
            }
}


TSprite* Katana::createSprite(char* path)
{
    TSprite* sprite = new TSprite(path);

    sprites.push_back(sprite);
    return sprite;
}


void Katana::removeSprite(TSprite* sprite)
{
    if(sprite)
    {
        for(std::vector<TSprite*>::iterator it = sprites.begin(); it!=sprites.end(); it++){
            if(sprite==*it)
            {
                sprites.erase(it);
                delete sprite;
                break;
            }
        }
    }
}

void Katana::getWindowSize(int &window_w,int &window_h)
{
    glfwGetWindowSize(window, &window_w, &window_h);
}

void Katana::initAnimations()
{
    manager->getResourceAnimation("res/animations/Goblin/Walk/Walk_Goblin_", 23);
    manager->getResourceAnimation("res/animations/Soldado/Walk/Walk_Soldier_",25);
    manager->getResourceAnimation("res/animations/Aldeana/Walk/Walk_Aldeana_",24);
}
