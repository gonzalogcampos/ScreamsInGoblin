#include "TResourceOBJ.h"
#include "TResourceMaterial.h"
#include "TResourceTexture.h"

//Method to split the texture url taken from the Internet
std::vector<std::string> TResourceOBJ::split(std::string str,std::string sep){
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    std::vector<std::string> arr;
    current=strtok(cstr,sep.c_str());
    while(current!=NULL){
        arr.push_back(current);
        current=strtok(NULL,sep.c_str());
    }
    return arr;
}

//Load the whole obj and then load his meshes one by one
bool TResourceOBJ::loadResource()
{
    bool ret = false;
    Assimp::Importer importer;

    //Assimp uses an aiScene object to represent the loaded mesh.
    const aiScene* scene = importer.ReadFile(name, aiProcess_Triangulate | aiProcess_FlipUVs);
    
    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode){
        std::cout<< "Error: " << importer.GetErrorString() << std::endl;
    }   

    if(scene)
    {
        for(unsigned int i = 0; i < scene->mNumMeshes; i++)
        {
            //Load mesh as individual obj in order to manage their datas separetly
            TResourceMesh* mesh = new TResourceMesh();
            aiMesh* m = scene->mMeshes[i];
            mesh->loadMesh(m);
            //Push all meshes inside the scene
            meshes.push_back(mesh);
            ret = true;
            //if(!animation)
            //{
                //Get the obj path in order to make it relative and use it for the texture path
                std::vector<std::string> arr;
                arr=split(name,"/");
                std::string path;

                if(arr[0].compare("home") == 0)
                {  
                    path = "/";
                }

                for(size_t i=0;i<arr.size()-1;i++)
                {
                    path+=arr[i] + "/";
                }
                //Load meshs material
                aiMaterial* currentMaterial = scene->mMaterials[m->mMaterialIndex];
            
                TResourceMaterial* material = new TResourceMaterial();
                material->loadResource(currentMaterial);
                mesh->setMaterial(material);    
                aiString texturepath;

                if(currentMaterial->GetTexture(aiTextureType_DIFFUSE, 0, &texturepath) == AI_SUCCESS)
                {
                    //Assign to the texture their path and load it
                    TResourceTexture* texture = new TResourceTexture();
                    std::string completePath = path + texturepath.data;                
                    texture->setName(completePath.c_str());
                    texture->loadResource();
                    mesh->setTexture(texture);
                    mesh->setActivated(true);
                }
                else
                {
                    std::cout<< "Error: " << currentMaterial->GetTexture(aiTextureType_DIFFUSE, 0, &texturepath) << std::endl;
                }
            //}
        }
    }

    return ret;
}

void TResourceOBJ::draw()
{
    for(unsigned int i = 0; i < meshes.size(); i++)
    {
        meshes[i]->draw();
    }
}

void TResourceOBJ::setMaterial(TResourceMaterial* m)
{
    for(unsigned int i = 0; i < meshes.size(); i++)
    {
        meshes[i]->setMaterial(m);
    }
}

void TResourceOBJ::setTexture(TResourceTexture* t)
{
    for(unsigned int i = 0; i<meshes.size(); i++)
    {
        meshes[i]->setActivated(true);
        meshes[i]->setTexture(t);
    }
}