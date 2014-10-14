//
//  SongNode.cpp
//  SueHW4
//
//  Created by cj on 10/14/14.
//  Copyright (c) 2014 KickinEspresso. All rights reserved.
//

#include "SongNode.h"

//TODO: setters
//<return Type> <class/struct name>::<functionName>(<parameter list>){}
Song* SongNode::getSong(){
    return this->song;
}

SongNode* SongNode::getNext(){
    return this->next;
}
