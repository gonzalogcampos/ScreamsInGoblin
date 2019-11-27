#include "Component.h"

class WoodComponent;
class WellComponent;
class BucketComponent : public Component
{
    private:
        bool water;

    public:
        BucketComponent(GameObject* owner, Manager* manager):Component(owner, manager){water = false;}
        ~BucketComponent(){}

        void setWater(bool water){this->water = water;}
        bool getWater(){return water;}

        void fillBucket(WellComponent* wc);
        void dropBucket(WoodComponent* wc);
};