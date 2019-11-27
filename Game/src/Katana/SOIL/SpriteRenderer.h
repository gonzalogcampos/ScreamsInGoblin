/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#pragma once
#include <../../../lib/GL/glew.h>
#include "../../../lib/glm/glm.hpp"
#include <../../../lib/glm/gtc/matrix_transform.hpp>


class Texture2D;

class SpriteRenderer
{
public:
    // Constructor (inits shaders/shapes)
    SpriteRenderer(GLuint spriteProgram);
    // Destructor
    ~SpriteRenderer();
    // Renders a defined quad textured with given sprite
    void DrawSprite(Texture2D &texture, glm::vec2 position, glm::vec2 size = glm::vec2(10, 10), GLfloat rotate = 0.0f, glm::vec3 color = glm::vec3(1.0f));
private:
    // Render state
    GLuint program;
    //Shader2 shader; 
    GLuint quadVAO;
    // Initializes and configures the quad's buffer and vertex attributes
    void initRenderData();
};