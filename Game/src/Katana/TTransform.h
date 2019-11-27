#pragma once
#include "../../lib/GL/glew.h"
#include "../../lib/glm/ext.hpp"
#include "TEntity.h"

class TTransform : public TEntity
{
    private:
        glm::mat4 matrix;
    public:
        TTransform(){}
        ~TTransform(){}

        //Get & Set
        void setMatrix(glm::mat4 m){ matrix = m;};
        glm::mat4 getMatrix(){ return matrix;};

        
        //Basic Transformations
        void translate(float x,float y,float z);
        void rotate(float x,float y,float z, float ang);
        void scale(float x, float y, float z);
        
        //Advance Transformations
        void transpose();
        void inverse();
        void identity();

        void beginDraw();
        void endDraw();
};
