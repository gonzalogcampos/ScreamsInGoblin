#pragma once
#include "FCamera.h"


class NOCamera : public FCamera
{
    private:
    public:
        NOCamera(){};
        ~NOCamera(){};
        void update(float x, float y, float z, float rx, float ry, float rz, bool ortho);
        void setFOV(float fov);

};