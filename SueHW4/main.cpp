//
//
// Lab 4
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
    
    myTime->setHours(1);
    myTime->setMinutes(2);
    myTime->setSeconds(3);
    
    myTime2->setHours(3);
    myTime2->setMinutes(4);
    myTime2->setSeconds(5);
    
    Time* resultTime = myTime->add(myTime2);
    resultTime->printTime();
    
}

void testSongObject(){
    Time* mySongtime = new Time();
    mySongtime->setHours(5);
    mySongtime->setMinutes(2);
    mySongtime->setSeconds(5);
    
    Song* myNewSong = new Song("MySongName","My Artist",mySongtime);
    
    myNewSong->setArtist("MyNewArtistName"); //will set the artist name on myNewSong to "MyNewArtistName"
    cout << "artist name " << myNewSong->getArtist() << endl;
    
    string myTitle = myNewSong->getTitle();
    cout << "title name " << myTitle << endl;
    
    
    //Test All song Setters
    /*
    string myTitle = this->setTitle();
    string myArtist = this->setArtist(); //Incorrect Doesnt return anything
 
    //Testing GETTERS//
    string myTitle = this->getTitle(myNewSong); //Incorrect: getTitle doesnt take a parameter
    string myArtist = this->getArtist(); // Correct
    Time* myRuntime = this->getTime();  //Correct
    cout << "Title is " << myTitle << endl;
    cout << "Artist is " << myArtist << endl;
    cout << "Runtime is " << myRuntime << endl;
     */

    
    //TODO: test all song getters

}

void testReadAndPrint(){
    
    //read file and print
    
    
    
}

void testReadCreateObjectAndPrint(){
    
    //read file and print
    
}

int main(int argc, const char * argv[]){
    cout << "Lab 4, Parts 1, 2, and Extra Credit \n";

    
    return 0;
}

