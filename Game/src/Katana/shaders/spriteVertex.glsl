#version 330 core
layout (location = 0) in vec4 vertices; // <vec2 position, vec2 texCoords>

out vec2 TexCoords;

uniform mat4 model;
uniform mat4 projection;

void main()
{
    TexCoords = vertices.zw;
    gl_Position = projection * model * vec4(vertices.xy, 0.0, 1.0);
}