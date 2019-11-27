#pragma once
#include <vector>


class Component;

class GameObject{
    private:
        float x, y, z, rx, ry, rz;
        std::vector<Component*> components;
        bool kill = false;

    public:
    GameObject(float x, float y, float z, float rz);

    ~GameObject();
    

    float getX(){return x;}
    float getY(){return y;}
    float getZ(){return z;}
    float getRX(){return rx;}
    float getRY(){return ry;}
    float getRZ(){return rz;}
    bool getKill(){return kill;}
    

    void setX(float x){this->x = x;}
    void setY(float y){this->y = y;}
    void setZ(float z){this->z = z;}
    void setRX(float rx){this->rx = rx;}
    void setRY(float ry){this->ry = ry;}
    void setRZ(float rz){this->rz = rz;}
    void setKill(bool kill){this->kill = kill;}
	


	//Add component
    void addComponent(Component* c);
    


	template<typename T>
    T* getComponent() {
        for(auto& c : components){
            if(T* cm = dynamic_cast<T*>(c)){
                return cm;
            }
        }     
        return nullptr;
    }

};