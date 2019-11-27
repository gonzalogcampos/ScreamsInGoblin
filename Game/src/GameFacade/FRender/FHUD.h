#pragma once

class FHUD
{
    public:
        FHUD(){}
        virtual ~FHUD(){}
        virtual void init() = 0;
        virtual void clear() = 0;
        virtual void updateValues(float life, float shield, float fps, int score, int spawns, int weapon) = 0;
};