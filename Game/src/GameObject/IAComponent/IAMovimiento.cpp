#include "IAMovimiento.h"
#include "BPhysicComponent.h"
#include <iostream>

bool MoveNone::run(){
  
  owner->getComponent<BPhysicComponent>()->setVelocity(0,0,0);

return true;
    
}

