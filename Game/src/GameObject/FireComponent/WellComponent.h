#include "Component.h"

class WellComponent : public Component
{
    public:
    WellComponent(GameObject* owner, Manager* manager):Component(owner, manager){}
    ~WellComponent(){}
};