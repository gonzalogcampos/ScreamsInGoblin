#pragma once
#include "FHUD.h"

class NOHUD : public FHUD
{
    private:
        NOHUD() : FHUD(){}

    public:

        static NOHUD* getInstance()
        {
            static NOHUD only_instance;
            return &only_instance;
        }

        ~NOHUD(){}
        void init();
        void clear();
        void updateValues(float life, float shield, float fps, int score, int spawns, int weapon);
};