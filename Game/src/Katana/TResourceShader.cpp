#include "TResourceShader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


//Method that reads a shader and compiles it taken from the Internet
bool TResourceShader::loadResource()
{
    bool ret = false;
    const GLchar* source;

    id = glCreateShader(type);
    
    std::string line, allLines;
    std::ifstream theFile(name);
    if (theFile.is_open())
    {
        while (std::getline(theFile, line))
        {
            allLines = allLines + line + "\n";
        }

        source = allLines.c_str();
        ret = true;
        theFile.close();
    }
    else
    {
    std::cout << "Unable to open file.";
    }

    glShaderSource(id, 1, &source, nullptr);
    glCompileShader(id);

    GLint Result = GL_FALSE;
	int InfoLogLength;
	// Check Vertex Shader
	glGetShaderiv(id, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(id, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> ShaderErrorMessage(InfoLogLength+1);
		glGetShaderInfoLog(id, InfoLogLength, NULL, &ShaderErrorMessage[0]);
		printf("%s\n", &ShaderErrorMessage[0]);
	}
    return ret;
}
