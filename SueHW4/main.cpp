//
//
//
// LAb 4
//
//

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "time.h"
#include "song.h"
using namespace std;



//Adds time to the current object
// Usage:
void testTimeObject(){
    Time* myTime = new Time();
    Time* myTime2 = new Time();
    
    //Adds time to the current object
    //Usage:
    
    //myTime->hours = 1;   //FIXME: myTime->setHours(1);
    //myTime->minutes = 2; //FIXME: Call Setter
    //myTime->seconds = 3; //FIXME: Call Setter
    
    //myTime2->hours = 3;  //FIXME: Call Setter
    //myTime2->minutes = 4;//FIXME: Call Setter
    //myTime2->seconds = 5;//FIXME: Call Setter
    
    //This is the usage
    Time* resultTime = myTime->add(myTime2);
    resultTime->printTime();
    
}

void testSongObject(){
    Time* mySongtime = new Time();
    mySongtime->setHours(5);
    mySongtime->setMinutes(2);
    mySongtime->setSeconds(5);
    
    Song* myNewSong = new Song("MySongName","My Artist",mySongtime);
    
    //TODO: test All song setters
    
    
    //TODO: test all song getters
    
    
    
    
}







int main(int argc, const char * argv[]){
    cout << "Lab 4, Parts 1, 2, and Extra Credit \n";
    labFour();
    
    return 0;
}

