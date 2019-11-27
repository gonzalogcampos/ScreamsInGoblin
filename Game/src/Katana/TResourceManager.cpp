#include "TResourceManager.h"
#include "TResourceOBJ.h"
#include "TResourceMaterial.h"
#include "TResourceTexture.h"
#include "TResourceShader.h"
#include "TResourceAnimation.h"

#include <string.h>
#include <iostream>
TResourceManager::~TResourceManager()
{
    //We must clean all of the vector of
    unsigned int i;
    for(i = 0; i < mesh.size(); i++)
    {
        delete mesh[i];
    }
    for(i = 0; i < material.size(); i++)
    {
        material[i] = nullptr;
    }
    for(i = 0; i < texture.size(); i++)
    {
        delete texture[i];
    }
    for(i = 0; i < shader.size(); i++)
    {
        delete shader[i];
    }
    for(i = 0; i < objs.size(); i++)
    {
        delete objs[i];
    }
    for(i = 0; i < animation.size(); i++)
    {
        delete animation[i];
    }
    mesh.clear();
    material.clear();
    texture.clear();
    shader.clear();
    objs.clear();
    animation.clear();
}

TResourceShader* TResourceManager::getResourceShader(const char* name, GLenum type)
{
    TResourceShader* res = nullptr;
    bool found = false; //We must read the resource as less as possible

    for(unsigned int i=0; i<shader.size() && found==false; i++)
    {
        if(strcmp(name,shader[i]->getName())==0)
        {
            found = true;
            res = shader[i];
        }
    }
    if(res == nullptr)
    {
        res = new TResourceShader();
        res->setName(name);
        res->setType(type);
        if(res->loadResource())
        {
            shader.push_back(res);
        }
        else
        {
            delete res;
        }
    }
    return res;
}

TResourceMesh* TResourceManager::getResourceMesh(const char* name)
{
    TResourceMesh* res = nullptr;
    bool found = false; //We must read the resource as less as possible

    for(unsigned int i=0; i<mesh.size() && found==false; i++)
    {
        if(strcmp(name,mesh[i]->getName())==0)
        {
            found = true;
            res = mesh[i];
        }
    }
    if(res == nullptr)
    {
        res = new TResourceMesh();
        res->setName(name);
        if(res->loadResource())
        {
            mesh.push_back(res);
        }
        else
        {
            delete res;
        }
    }
    return res;
}

TResourceOBJ* TResourceManager::getResourceOBJ(const char* name)
{
    
    TResourceOBJ* res = nullptr;
    bool found = false; //We must read the resource as less as possible

    for(unsigned int i=0; i<objs.size() && found==false; i++)
    {
        if(strcmp(name,objs[i]->getName())==0)
        {
            found = true;
            res = objs[i];
        }
    }
    if(res == nullptr)
    {
        res = new TResourceOBJ();
        res->setName(name);
        if(res->loadResource())
        {
            objs.push_back(res);
        }
        else
        {
            delete res;
        }
    }
    return res;
}


TResourceMaterial* TResourceManager::getResourceMaterial(const char* name)
{
    TResourceMaterial* res = nullptr;
    bool found = false; //We must read the resource as less as possible

    for(unsigned int i=0; i<material.size() && found==false; i++)
    {
        if(strcmp(name,material[i]->getName())==0)  // 0 = we've found a coincidence
        {
            found = true;
            res = material[i];
        }
    }
    //No res coincidence loaded before
    if(res == nullptr)                             
    {
        res = new TResourceMaterial();
        res->setName(name);
        if(res->loadResource())
        {
            //Load in vector for futures researches
            material.push_back(res);
        }
        else
        {
            delete res;
        }
    }
    return res;
}

TResourceTexture* TResourceManager::getResourceTexture(const char* name)
{
    TResourceTexture* res = nullptr;
    bool found = false; //We must read the resource as less as possible

    for(unsigned int i=0; i<texture.size() && found==false; i++)
    {
        if(strcmp(name,texture[i]->getName())==0)
        {
            found = true;
            res = texture[i];
        }
    }
    if(res == nullptr)
    {
        res = new TResourceTexture();
        res->setName(name);
        if(res->loadResource())
        {
            texture.push_back(res);
        }
        else
        {
            delete res;
        }
    }
    return res;
}

TResourceAnimation* TResourceManager::getResourceAnimation(const char* name, int nf)
{
    TResourceAnimation* res = nullptr;
    bool found = false; //We must read the resource as less as possible
    for(unsigned int i=0; i<animation.size() && found==false; i++)
    {
        if(strcmp(name,animation[i]->getName())==0)  // 0 = we've found a coincidence
        {
            found = true;
            res = animation[i];
        }
    }
    //No res coincidence loaded before
    if(res == nullptr)                             
    {
        res = new TResourceAnimation(nf);
        res->setName(name);
        if(res->loadResource())
        {
            //Load in vector for futures researches
            animation.push_back(res);
        }
        else
        {
            delete res;
        }
    }
    return res;
}


void TResourceManager::deleteOBJ(const char* n)
{
    TResourceOBJ* obj = NULL;
    bool found = false;

    for(unsigned int i=0; i<objs.size() && found==false; i++)
    {
        if(strcmp(n, objs[i]->getName()) == 0)
        {
            obj = objs[i];
            objs.erase(objs.begin()+i-1);
            delete obj;
            found = true;
        }
    }
}

void TResourceManager::deleteAnimation(const char* n)
{
    TResourceAnimation* anim = NULL;
    bool deleted = false;

    for(unsigned int i = 0; i < animation.size() && deleted == false; i++)
    {
        if(strcmp(n, animation[i]->getName()) == 0)
        {
            anim = animation[i];
            animation.erase(animation.begin()+i-1);
            delete anim;
            deleted = true;
        }
    }
}