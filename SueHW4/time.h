//
//  time.h
//  SueHW4
//
//  Created by cj on 10/14/14.
//  Copyright (c) 2014 KickinEspresso. All rights reserved.
//

#ifndef __SueHW4__time__
#define __SueHW4__time__

#include <stdio.h>
#include <iostream>

using namespace std;

struct Time{
private:
    int hours;
    int minutes;
    int seconds;
    
public:
    //Functions
    Time* add(Time* time);              //Will add it to the object
    void printTime();
    int getTotalSeconds();
    void setUsingsSeconds(int seconds);
    
    //Setters//
    void setHours(int hours){
        this->hours = hours;
    }
    void setMinutes(int minutes){
        this->minutes = minutes;
    }
    void setSeconds(int seconds){
        this->seconds = seconds;
    }
    
    //Getters//
    int getHours(){
        return this->hours;
    }
    int getMinutes(){
        return this->minutes;
    }
    int getSeconds(){
        return this->seconds;
    }

};


#endif /* defined(__SueHW4__time__) */
