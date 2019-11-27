#include "TResourceTexture.h"
#include <iostream>
bool TResourceTexture::loadResource()
{
    //Image residing in normal ram allows it to be manipulated freely.
    sf::Image* texture = new sf::Image();
    bool aux = false;
    if(texture->loadFromFile(name))
    {
        active = true;
        int sizeX = texture->getSize().x;
        int sizeY = texture->getSize().y;   
        //generate an OpenGL texture object.
        glGenTextures(1, &textureID);

        //binding texture in a 2d
        glBindTexture(GL_TEXTURE_2D, textureID);

        // glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,img_data.GetWidth(), img_data.GetHeight(),0,GL_RGBA, GL_UNSIGNED_BYTE, img_data.GetPixelsPtr());
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, (GLsizei)sizeX, (GLsizei)sizeY, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture->getPixelsPtr());
        //Set all the parameters of the texture
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        aux = true;
    }
    delete texture;
    return aux;
}

void TResourceTexture::draw()
{
    if(active)
    {
        //Bind and enable the texture
        glBindTexture(GL_TEXTURE_2D, textureID);
        
    }
}