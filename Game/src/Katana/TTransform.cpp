#include "TTransform.h"
#include "TEntity.h"


//Move the matrix position from one place to another x,y,z
void TTransform::translate(float x,float y,float z)
{
    matrix = glm::translate(matrix, glm::vec3(x,y,z));
}

//Rotate matrix position the parametre ang degree in x,y,z by putting = 1
void TTransform::rotate(float x,float y, float z, float ang)
{
    matrix = glm::rotate(matrix,ang, glm::vec3(x, y, z));

}

//Scale the matrix
void TTransform::scale(float x, float y, float z)
{
    matrix = glm::scale(matrix, glm::vec3(x,y,z));
}

//Swaps the lines and the columns of the matrix
void TTransform::transpose()
{
    matrix = glm::transpose(matrix);
}

//Divides each member of the matrix by the determinant of it
void TTransform::inverse()
{
    matrix = glm::inverse(matrix);
}

//Turn the main diagonal into 1's 
void TTransform::identity()
{
    matrix = glm::mat4(1.0f);
}

//Pushes the fathers matrix and multiplys the actual with the previous 
void TTransform::beginDraw()
{   
    glm::mat4& model = modelMatrix();
    stackMatrix().push(model);
    model = matrix * model;
}

//Sets the matrix of the fathers node
void TTransform::endDraw()
{
    glm::mat4& model = modelMatrix();
    model = stackMatrix().top();
    stackMatrix().pop();
}