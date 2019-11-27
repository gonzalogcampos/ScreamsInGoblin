
#pragma once
#include "../../lib/GL/glew.h"
#include "TEntity.h"

class TCamera : public TEntity
{
    private:
        //Parallel or perspective; true == persective, false == parallel
        bool perspective;
        float near, far, top, bot, right, left, zoom;
    public:
        TCamera();
        ~TCamera(){}

        //Get & Set
        void switchProyection(bool ortho);
        void setPerspective(){ perspective = true;};
        
        void changeCamera(bool c){ perspective = c;};

        void beginDraw(){}
        void endDraw(){}

};
