//
//  song.cpp
//  SueHW4
//
//  Created by cj on 10/14/14.
//  Copyright (c) 2014 KickinEspresso. All rights reserved.
//

#include "song.h"

//Default Constructor
Song::Song(string title, string artist, Time* runtime){
    this->title = title;
    this->artist = artist;
    this->runtime = runtime;
}

//Deconstructor
Song::~Song(){
}

//SETTERS//
void Song::setTitle(string title){
    this->title=title;  
}

void Song::setArtist(string artist){
    this->artist = artist;
}

void Song::setTime(Time* runtime){
    
    this->runtime = runtime;
}

//GETTERS//
string Song::getTitle(){
    return this->title;
}

string Song::getArtist(){
    return this->artist;
}

Time* Song::getTime(){
    return this->runtime;
}
