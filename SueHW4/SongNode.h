//
//  SongNode.h
//  SueHW4
//
//  Created by cj on 10/14/14.
//  Copyright (c) 2014 KickinEspresso. All rights reserved.
//

#ifndef __SueHW4__SongNode__
#define __SueHW4__SongNode__

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "time.h"
#include "song.h"

using namespace std;

struct SongNode{
    
private:
    
    //Attributes go here
    Song* song;
    SongNode* next;
    
public:

    //Member functions
    
    //Setters
    void setSong(Song* song);    //TODO: create function implementation in SongNode.cpp
    void setNext(SongNode* next);   //TODO: create function implementation in SongNode.cpp
    
    //Getters
    Song* getSong();
    SongNode* getNext();
};


#endif /* defined(__SueHW4__SongNode__) */
