#pragma once
#include "FHUD.h"
#include "IRRRender.h"


class IRRHUD : public FHUD
{
    private:
        irr::gui::IGUIEnvironment* env;
        irr::gui::IGUIImage* background;
        irr::gui::IGUIImage* life;
        irr::gui::IGUIImage* shield;
        
        IRRHUD() : FHUD(){}
    public:

        ~IRRHUD(){clear();}

        static IRRHUD* getInstance()
        {
            static IRRHUD only_instance;
            return &only_instance;
        }

        void init();
        void clear();
        void updateValues(float life, float shield, float fps, int score, int spawns, int weapon); 

};