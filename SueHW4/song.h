//
//  song.h
//  SueHW4
//
//  Created by cj on 10/14/14.
//  Copyright (c) 2014 KickinEspresso. All rights reserved.
//

#ifndef __SueHW4__song__
#define __SueHW4__song__

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "time.h"

using namespace std;
//********
//Class Song
//******
class Song {
    
private:
    string title;
    string artist;
    Time* time;
    
public:
    //Constructor
    Song(); //Default Constructor
    Song(string t, string a, Time* rt); //This is the constructor
    
    //Deconstructor
    ~Song();
    
    //SETTERS//
    void setTitle(string t);
    void setArtist(string a);
    void setTime(Time* rt);
    
    //GETTERS//
    string getTitle();
    string getArtist();
    Time* getTime();
};

#endif /* defined(__SueHW4__song__) */
