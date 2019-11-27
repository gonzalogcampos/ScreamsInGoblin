#pragma once

class GameObject;
enum ItemTypes
{
    EMPTY,
    CROSSBOW,
    AXE,
    PEAK,
    POTION, 
    SHIELD
};

struct IType{
    ItemTypes type;
    char* mesh;
    char* texture;
};



class ItemFabric
{
    private:
        IType item_types [8] = 
        {
            {
                EMPTY,
                (char*)"res/ITEM.obj",
                (char*)"res/ITEM.bmp"

            },
            {
                CROSSBOW,
                (char*)"res/obj/BALLESTA.obj",
                (char*)"res/obj/Ballesta_Color.bmp"

            },
            {
                AXE,
                (char*)"res/obj/HACHA.obj",
                (char*)"res/obj/Hacha_Color.bmp"
            }, 
            {
                PEAK,
                (char*)"res/obj/PICO.obj",
                (char*)"res/obj/Pico_Color.bmp"
            },
            {
                POTION,
                (char*)"res/obj/POCION.obj",
                (char*)"res/obj/Pocion_Color.bmp"

            },
            {
                SHIELD,
                (char*)"res/obj/ESCUDO.obj",
                (char*)"res/obj/Escudo_Color.bmp"
            }
        };

    public:
        ItemFabric(){}
        virtual ~ItemFabric(){}

        void createItem(float x, float y, float z, float rz, ItemTypes type);
};


