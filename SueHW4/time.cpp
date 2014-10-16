//
//  time.cpp
//  SueHW4
//
//  Created by cj on 10/14/14.
//  Copyright (c) 2014 KickinEspresso. All rights reserved.
//

#include "time.h"

Time* Time::add(Time* runtime){

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
    int totalTime = this->getHours()*3600 + this->getMinutes() * 60 + this-> getSeconds(); //FIXME: to use "this->" for hours, minutes and seconds
    cout << "totalTime = " << totalTime << endl;

}

int Time::getTotalSeconds(){
    int totalTime; //Total time in seconds
    totalTime = (this->getHours() * 3600) + (this->getMinutes()*60) + this->getSeconds(); //FIXME: to use "this->" for hours, minutes and seconds
    return totalTime;
}


//Converts a total amount of seconds to hours, minutes and seconds
void Time::setUsingsSeconds(int seconds){
    this->hours = seconds/3600;
    this->minutes = (seconds - (this->getHours()*3600))/60;
    this->seconds = (seconds - (this->getHours()*3600)-(this->getMinutes()*60));
}



