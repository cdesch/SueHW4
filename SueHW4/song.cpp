//
//  song.cpp
//  SueHW4
//
//  Created by cj on 10/14/14.
//  Copyright (c) 2014 KickinEspresso. All rights reserved.
//

#include "song.h"



//Default Constructor
Song::Song(string t, string a, Time* rt){
    this->title = t;
    this->artist = a;
    this->time = rt;
}

//Deconstructor
Song::~Song(){
}


//SETTERS//
void Song::setTitle(string t){
    title = t;  //FIXME: add "this->"
}

void Song::setArtist(string a){
    artist = a; //FIXME: add "this->"
}

void Song::setTime(Time* rt){
    time = rt; //FIXME: add "this->"
}
//GETTERS//
string Song::getTitle(){
    return title; //FIXME: add "this->"
}

string Song::getArtist(){
    return artist; //FIXME: add "this->"
}

Time* Song::getTime(){
    return time; //FIXME: add "this->"
}

