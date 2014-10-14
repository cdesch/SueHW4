//
//  time.cpp
//  SueHW4
//
//  Created by cj on 10/14/14.
//  Copyright (c) 2014 KickinEspresso. All rights reserved.
//

#include "time.h"

Time* Time::add(Time* time){

    //TOP PRIORITY FOR TIME
    //Your Job is to add:
    //this->hours; this->minutes; this->seconds;   //THIS
    //to
    //time->hours; time->minutes; time->seconds;   //TIME
    
    //YOUR CODE GOES HERE
    //int TotalSeconds = this->getTotalSeconds() + time->getTotalSeconds();
    
    
    
    //Convert "this->" and "time" objects to seconds
    //add them
    //divide by whatever to get hours, minutes and seconds
    
    //Create a new object

    Time* result = new Time();
    
    //result->hours = ....
    //result->minutes = ....
    //result->seconds = ...
    
    return result;
}

// Member Functions

// Prints time in seconds
// pre: hours, minutes seconds
// post: converts time into seconds and then sums to get time in seconds
void Time::printTime(){
    int totalTime = hours*3600 + minutes * 60 + seconds; //FIXME: to use "this->" for hours, minutes and seconds
    cout << "totalTime = " << totalTime << endl;
}

int Time::getTotalSeconds(){
    int totalTime; //Total time in seconds
    totalTime = (hours * 3600) + (minutes*60) + seconds; //FIXME: to use "this->" for hours, minutes and seconds
    return totalTime;
}


//Converts a total amount of seconds to hours, minutes and seconds
void Time::setUsingsSeconds(int seconds){
    
    //TODO: setting this->hours ,this->minutes, this->seconds
}


//GETTERS//
int Time::getHours(){
    return hours;  //FIXME: this->hours
}
int Time::getMinutes(){
    return minutes; //FIXME: add "this->"
}
int Time::getSeconds(){
    return seconds; //FIXME: this->
}

//SETTERS//
void Time::setHours(int hours){
    this->hours = hours; //FIXME: this->
}
void Time::setMinutes(int m){
    minutes = m;    //FIXME: this->
}
void Time::setSeconds(int s){
    seconds = s;    //FIXME: this->
}

