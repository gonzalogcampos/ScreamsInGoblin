#pragma once

class FMesh{
    public:
        //Constructor
        FMesh(){}

        //Destructor
        virtual ~FMesh(){}

        //Changes the position of the node
        virtual void setPosition(float x, float y, float z) = 0;

        //Changes the rotation of the node only in the z axis
        virtual void setRotation(float x, float y, float z) = 0;

        //Chages the visibility of the node to b
        virtual void setVisible(bool b) = 0;
        
        //Changes the texture of the node to the new path
        virtual void setTexture(char* s) = 0;

        virtual void isMap() = 0;

};