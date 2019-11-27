#include <vector>
#include <iostream>
#include "../../lib/GL/glew.h"

class TResource;
class TResourceMesh;
class TResourceOBJ;
class TResourceMaterial;
class TResourceTexture;
class TResourceShader;
class TResourceAnimation;
class TResourceManager
{
private:
    std::vector<TResourceMesh*> mesh;
    std::vector<TResourceMaterial*> material;
    std::vector<TResourceTexture*> texture;
    std::vector<TResourceShader*> shader;
    std::vector<TResourceOBJ*> objs;
    std::vector<TResourceAnimation*> animation;

public:
    TResourceManager(){}
    ~TResourceManager();
    std::vector<std::string> split(std::string str,std::string sep);

    TResourceMesh* getResourceMesh(const char* name);
    TResourceOBJ* getResourceOBJ(const char* name);
    TResourceMaterial* getResourceMaterial(const char* name);
    TResourceTexture* getResourceTexture(const char* name);
    TResourceShader* getResourceShader(const char* name, GLenum type);
    TResourceAnimation* getResourceAnimation(const char* n, int nf);

    void deleteOBJ(const char* n);
    void deleteAnimation(const char* n);
};
