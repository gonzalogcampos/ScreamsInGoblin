#pragma once
#include <iostream>
#include <stack>
#define GLM_ENABLE_EXPERIMENTAL 
#include "../../lib/glm/gtx/string_cast.hpp"

#include "../../lib/GL/glew.h"
#include "../../lib/glm/ext.hpp"
#include <iostream>
class TEntity
{
    protected:
        static GLuint viewID;
        static GLuint projectionID;
        static GLuint modelID;
        static GLuint MVPID;
        static GLuint programID;
    public:
        TEntity(){}
        virtual ~TEntity(){}

        virtual void beginDraw() = 0;
        virtual void endDraw() = 0;

        static void setviewID(GLuint v){ viewID = v;};
        static void setprojectionID(GLuint p){ projectionID = p;};
        static void setmodelID(GLuint m){ modelID = m;};
        static void setMVPID(GLuint m){ MVPID = m;};
        static void setProgramID(GLuint pid){programID = pid;};
        static GLuint getProgramID(){return programID;};


        static GLuint getModelID(){ return modelID;};
        static GLuint getViewID(){ return viewID;};
        static GLuint getProjectionID(){ return projectionID;};
        static GLuint getMVPID(){ return MVPID;};


    //Static matrix in order to make the unique and global to their childs
    static glm::mat4& modelMatrix() 
    {
        static glm::mat4 matrix;
        return matrix;
    };
    static glm::mat4& viewMatrix() 
    {
        static glm::mat4 matrix;
        return matrix;
    };
    static glm::mat4& projectionMatrix() 
    {
        static glm::mat4 matrix;
        return matrix;
    };
    static std::stack<glm::mat4>& stackMatrix() 
    {
        static std::stack<glm::mat4> stackMatrix;
        return stackMatrix;
    };
};