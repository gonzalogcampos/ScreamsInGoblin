#include "Nodo.h"
#include "GameObject.h"


class MoveNone : public Nodo
{
    
    public:

    MoveNone(GameObject* o){owner = o;}
    virtual ~MoveNone(){}

    bool run() override;
    GameObject * owner;

};

