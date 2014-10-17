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


    //Constructors
    Playlist(){} //Default constructor
    ~Playlist(){}
    //Member functions
    Playlist(string title, SongNode* head, SongNode* tail, int numsongs, Time* totalPlayTime){
        this->title = title;
        this->head  = head;
        this->tail = tail;
        this->numsongs = numsongs;
        this->totalPlayTime = totalPlayTime;
    }
    
    //Setters
    void setTitle(string title){
        this->title = title;
    }
    void setHead(SongNode* head){
        this->head = head;
    }
    void setTail(SongNode* tail){
        this->tail = tail;
    }
    void setNumsongs(int numsongs){
        this->numsongs = numsongs;
    }
    void setTime(Time* totalPlayTime){
        this->totalPlayTime = totalPlayTime;
    }

    //Getters
    string getTitle(string title){
        return this->title;
    }
    SongNode* getHead(SongNode* head){
        return this->head;
    }
    SongNode* getTail(SongNode* tail){
        return this->tail;
    }
    int getNumsongs(int numsongs){
        return this->numsongs;
    }
    Time* getTime(Time* totalPlayTime){
        return this->totalPlayTime;
    }

};

#endif /* defined(__SueHW4__playlist__) */
