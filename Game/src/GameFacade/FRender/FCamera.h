#pragma once

class FCamera
{
    public:
        FCamera(){};
        virtual ~FCamera(){};
        virtual void update(float x, float y, float z, float rx, float ry, float rz, bool ortho) = 0;
        virtual void setFOV(float fov) = 0;
};