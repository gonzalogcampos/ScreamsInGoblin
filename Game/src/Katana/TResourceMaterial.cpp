#include "TResourceMaterial.h"

TResourceMaterial::TResourceMaterial()
{
    //Resize the 3 array for r,g,b

    dif = (float *)malloc(sizeof(float) * 3);
    amb = (float *)malloc(sizeof(float) * 3);
    spe = (float *)malloc(sizeof(float) * 3);
    
    
}

void TResourceMaterial::loadResource(aiMaterial* m)
{
    aiColor3D c;

    if(m->Get(AI_MATKEY_COLOR_DIFFUSE, c))
    {
        dif[0] = c.r;
        dif[1] = c.g;
        dif[2] = c.b;
    }

    if(m->Get(AI_MATKEY_COLOR_SPECULAR, c))
    {
        spe[0] = c.r;
        spe[1] = c.g;
        spe[2] = c.b;
    }

    if(m->Get(AI_MATKEY_COLOR_AMBIENT, c))
    {
        amb[0] = c.r;
        amb[1] = c.g;
        amb[2] = c.b;
    }
    
    m->Get(AI_MATKEY_SHININESS, shine);
}

void TResourceMaterial::draw()
{
    //First we get all the uniform locations
    //GLuint diffuseID = glGetUniformLocation(TEntity::getProgramID(), "material.dif");
    //GLuint ambientID = glGetUniformLocation(TEntity::getProgramID(), "material.amb");
    //GLuint specularID = glGetUniformLocation(TEntity::getProgramID(), "material.spe");
    //GLuint shininessID = glGetUniformLocation(TEntity::getProgramID(), "material.shine");

    //And then we give the shader the material information
    //glUniform3fv(diffuseID, 1, dif);
    //glUniform3fv(ambientID, 1, amb);
    //glUniform3fv(specularID, 1, spe);
    //glUniform1f(shininessID, shine);
}