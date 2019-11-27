#include "Component.h"

class Manager;
class ScoreComponent:public Component
{
    private:
        int score;
    public:
        ScoreComponent(GameObject* owner, Manager* manager, int score):Component(owner, manager){this->score = score;}
        virtual ~ScoreComponent();

        int getScore(){return score;};
        void setScore(int score){this->score = score;}
};