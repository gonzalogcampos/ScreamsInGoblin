#include "TSprite.h"
#include "FSprite.h"
#include "KATRender.h"

class KATSprite : public FSprite
{
private:
    TSprite* sprite;
public:
    KATSprite(char* texture, float x, float y, float sx, float sy, float rot, float r, float g, float b);
    ~KATSprite(){KATRender::getInstance()->getKatana()->removeSprite(sprite);}

    void setPosition(float x, float y);
    void setScale(float x, float y);
    void setColor(float r, float g, float b);
    void setRotation(float r);
    void setTexture(char* t);
    int getWidth(){return sprite->getWidth();}
    int getHeight(){return sprite->getHeight();}

};