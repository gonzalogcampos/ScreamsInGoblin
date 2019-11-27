#pragma once
#include <vector>
#include <iostream>
class TEntity;
class TNode
{
    private: 
        TNode*              father;
        TEntity*            entity;
        std::vector<TNode*> child;
        int id;

    public:
        //Constructors
        TNode();                                        //Node Root
        TNode(TNode* f) : father(f) {father = f;}       //Node no entity
        TNode(TNode* f, TEntity* e) : father(f), entity(e) { father = f; entity = e;}
        ~TNode();
    

        bool addChild(TNode* n);
        bool remChild(TNode* n);
        bool popChild(TNode* n);
        TNode* searchChild(unsigned int n);

        //GET & SET
        void setId(int d){id = d;};
        int getId(){return id;};
        void setFather(TNode* n){ father = n;};
        void setEntity(TEntity* e){ entity = e;};
        TEntity *getEntity(){ return entity;};
        TNode *getFather(){ return father;};
        
        void draw(); 
};