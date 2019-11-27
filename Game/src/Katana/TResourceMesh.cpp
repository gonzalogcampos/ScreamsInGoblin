#include "TResourceMesh.h"
#include "TResourceMaterial.h"
#include "TResourceTexture.h"
#include <iostream>

TResourceMesh::~TResourceMesh()
{
    texture->setActivate(false);
    delete texture;
    glDeleteBuffers(4, buffer);
    glDeleteVertexArrays(1, &VAO);
}

void TResourceMesh::loadMesh(aiMesh* m)
{   
    nFaces = m->mNumFaces;
    int nVertex = m->mNumVertices;

    //Generate an array of 4 buffer identifiers
    buffer = (unsigned int *)malloc(sizeof(unsigned int) * 4);
    glGenBuffers(4, buffer);
    
    //Assig the datas needed each time
    bufferdata = new float[(sizeof(float) * nVertex * 3)];
    memcpy(&bufferdata[0], m->mVertices, 3 * sizeof(float) * nVertex);

    //Bind and pass data to OpenGL. Buffer[0] = VERTEX POSITION
    glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
    glBufferData(GL_ARRAY_BUFFER, nVertex*3*sizeof(float), bufferdata, GL_STATIC_DRAW);

    if(m->HasNormals())
    {

        memcpy(&bufferdata[0], m->mNormals, 3 * sizeof(float) * nVertex);

        //Bind and pass data to OpenGL. Buffer[1] = VERTEX NORMALS
        glBindBuffer(GL_ARRAY_BUFFER, buffer[1]);
        glBufferData(GL_ARRAY_BUFFER, nVertex*3*sizeof(float), bufferdata, GL_STATIC_DRAW);
    }

    //We assume we are always working with triangles
    IBO = (unsigned int *)malloc(sizeof(unsigned int) * nFaces * 3);
    unsigned int faceIndex = 0;

    for(int j = 0; j<nFaces; j++, faceIndex += 3)
    {
        //Assing each vertex index from each triangle
        IBO[0+faceIndex] = m->mFaces[j].mIndices[0];
        IBO[1+faceIndex] = m->mFaces[j].mIndices[1];
        IBO[2+faceIndex] = m->mFaces[j].mIndices[2];
    }

    if(m->HasTextureCoords(0))
    {
        for(int k = 0; k<nVertex;k++)
        {
            bufferdata[k*2] = m->mTextureCoords[0][k].x;
            bufferdata[k*2+1] = m->mTextureCoords[0][k].y;
        }
        //Bind and pass data to OpenGL. Buffer[2] = VERTEX TEXTURECOORD
        glBindBuffer(GL_ARRAY_BUFFER, buffer[2]);
        glBufferData(GL_ARRAY_BUFFER, nVertex*2*sizeof(float), bufferdata, GL_STATIC_DRAW);
    }

    //Generate an array of a vertex array identifier and bind
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);


    //Detach elements
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    //Bind and pass data to OpenGL. Buffer[3] = VERTEX INDICES
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer[3]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, nFaces*3*sizeof(unsigned int), IBO, GL_STATIC_DRAW);


    delete[] bufferdata;
    free(IBO);

}

void TResourceMesh::draw()
{
    if(texture!= nullptr && texture->getActive())
    texture->draw();

    if(material != nullptr)
    material->draw();
    //BIND VAO
    glBindVertexArray(VAO);
    
    //Bind and pass data to OpenGL. Buffer[0] = VERTEX POSITIONS
    glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);

    //Bind and pass data to OpenGL. Buffer[1] = VERTEX NORMALS
    glBindBuffer(GL_ARRAY_BUFFER,  buffer[1]);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);

    //Bind and pass data to OpenGL. Buffer[2] = VERTEX TEXTCOORDS
    glBindBuffer(GL_ARRAY_BUFFER,  buffer[2]);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);

    //Bind and pass data to OpenGL. Buffer[3] = VERTEX INDICES
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer[3]);

    //Draw in triangles
    glDrawElements(GL_TRIANGLES, nFaces*3, GL_UNSIGNED_INT, 0);

    
    //Detach elements
    glDisableVertexAttribArray(3);
    glDisableVertexAttribArray(2);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);


}