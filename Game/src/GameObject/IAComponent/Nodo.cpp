#include "Nodo.h"

void Nodo::clear()
{
    for(size_t i =0; i<children.size(); i++)
        delete children[i];

    children.clear();
}
bool Nodo::run()
{

    //std::cout << "Nodo ejecutado \n";
    return true;
}
bool Selector::run(){
    std::vector<Nodo*>::iterator iter;

    for(iter = children.begin(); iter!=children.end(); iter ++){

        if((*iter)->run()) return true;


        
    }
    
    return false;
}


bool Secuencia::run(){
    

    std::vector<Nodo*>::iterator iter;

    for(iter = children.begin(); iter!=children.end(); iter ++){

        if(!(*iter)->run()) return false;


        
    }
    
    return true;
}