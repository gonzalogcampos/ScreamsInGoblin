#include "FSprite.h"

class NOSprite : public FSprite
{
private:
    
public:
    NOSprite():FSprite(){};
    ~NOSprite(){};

    void setPosition(float x, float y){};
    void setScale(float x, float y){};
    void setColor(float r, float g, float a){};
    void setRotation(float r){};
    void setTexture(char* t){};
    int getWidth(){return 1;}
    int getHeight(){return 1;}

};