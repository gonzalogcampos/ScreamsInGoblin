#include "TSprite.h"
#include "SOIL.h"

TSprite::TSprite(char* path)
{
    this->path = path;
    texture = new Texture2D();
    
    texture->Internal_Format = GL_RGBA;
    texture->Image_Format = GL_RGBA;
    
    // Load image
    unsigned char* image = SOIL_load_image(path, &width, &height, 0, texture->Image_Format == GL_RGBA ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);
    size = glm::vec2(width, height);
    // Now generate texture
    texture->Generate(width, height, image);
    // And finally free image data
    SOIL_free_image_data(image);
}

void TSprite::setTexture(char* t)
{ 
    this->path = path;
    delete texture;
    texture = new Texture2D();
    
    texture->Internal_Format = GL_RGBA;
    texture->Image_Format = GL_RGBA;
    
    // Load image
    unsigned char* image = SOIL_load_image(path, &width, &height, 0, texture->Image_Format == GL_RGBA ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);
    size = glm::vec2(width, height);
    // Now generate texture
    texture->Generate(width, height, image);
    // And finally free image data
    SOIL_free_image_data(image);
}