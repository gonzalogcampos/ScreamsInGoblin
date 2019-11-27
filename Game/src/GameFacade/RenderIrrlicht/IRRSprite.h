#include "FSprite.h"
class IRRSprite : public FSprite
{
private:
    
public:
    IRRSprite():FSprite(){};
    ~IRRSprite(){};

    void setPosition(float x, float y){};
    void setScale(float x, float y){};
    void setColor(float r, float g, float a){};
    void setRotation(float r){};
    void setTexture(char* t){};
    int getWidth(){return 1;}
    int getHeight(){return 1;}
};