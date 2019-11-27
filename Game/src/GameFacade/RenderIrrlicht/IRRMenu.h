#pragma once
#include "IRRRender.h"
#include "FMenu.h"

class IRRMenu : public FMenu
{
    private:
        irr::gui::IGUIEnvironment* env;
        irr::gui::IGUIImage* img;
        IRRMenu() : FMenu(){};
    public:
    static IRRMenu* getInstance(){
        static IRRMenu only_instance;
        return &only_instance;
    }
    


    ~IRRMenu() {}
    void setMenuBackground(char* t);
    irr::gui::IGUIButton* createButton(int x,int y,int xx,int xy, int id);
    void clearBackground();
    void update(){}
};