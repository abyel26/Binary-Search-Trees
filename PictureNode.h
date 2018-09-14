
//Abyel Romero
//PictureNode definition

#ifndef PICTURENODE_H
#define PICTURENODE_H


#include "Picture.h"


struct PictureNode{
    PictureNode * parent;
    PictureNode * right;
    PictureNode * left;
    Picture key;
    
    
    
    PictureNode(){
        right = nullptr;
        left = nullptr;
        parent = nullptr;
    }
    
};


#endif
