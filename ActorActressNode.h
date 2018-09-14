

//Abyel Romero
//Actor-Actress Node definition

#ifndef ACTORACTRESSNODE_H
#define ACTORACTRESSNODE_H


#include "ActorActress.h"


struct ActorActressNode{
    ActorActressNode * parent;
    ActorActressNode * right;
    ActorActressNode * left;
    ActorActress key;
    
    
    
    ActorActressNode(){
        right = nullptr;
        left = nullptr;
        parent = nullptr;
    }
    
};


#endif
