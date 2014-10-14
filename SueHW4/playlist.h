//
//  playlist.h
//  SueHW4
//
//  Created by cj on 10/14/14.
//  Copyright (c) 2014 KickinEspresso. All rights reserved.
//

#ifndef __SueHW4__playlist__
#define __SueHW4__playlist__
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "time.h"
#include "SongNode.h"

using namespace std;

//***************
//Playlist Class
//***************

class Playlist {
    
private:
    string title;
    //<variable type><pointer *> <variable name>;
    SongNode* head;
    SongNode* tail;
    int numsongs;
    Time* totalPlayTime;
    
public:

    //TODO: Constructor, setters and getters
    //Constructors
    Playlist(); //Default constructor
    //
    ~Playlist();
    
    //Member functions
    
    //Setters

    //Getters
    
};



#endif /* defined(__SueHW4__playlist__) */
