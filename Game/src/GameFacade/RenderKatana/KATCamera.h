#pragma once
#include "FCamera.h"

class TNode;
class TCamera;
class KATCamera : public FCamera
{
    private:
        TNode* camera;
    public:
        KATCamera(){};
        ~KATCamera(){};
        void update(float x, float y, float z, float rx, float ry, float rz, bool ortho);
        void setFOV(float fov);

        void setCamera(TNode* n);
};