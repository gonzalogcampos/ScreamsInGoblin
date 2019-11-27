#pragma once
class FSprite
{
private:
    

public:
    FSprite(){};
    virtual ~FSprite(){};

    virtual void setPosition(float x, float y) = 0;
    virtual void setScale(float x, float y) = 0;
    virtual void setColor(float r, float g, float a) = 0;
    virtual void setRotation(float r) = 0;
    virtual void setTexture(char* t) = 0;
    virtual int getWidth() = 0;
    virtual int getHeight() = 0;
};