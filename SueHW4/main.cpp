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
    
    //Adds time to the current object
    //Usage:
    
    myTime->setHours(1);
    myTime->setMinutes(2);
    myTime->setSeconds(3);
    
    myTime2->setHours(3);
    myTime2->setMinutes(4);
    myTime2->setSeconds(5);
    
    //This is the usage
    Time* resultTime = myTime->add(myTime2);
    resultTime->printTime();
}

void testSongObject(){
    Time* mySongtime = new Time();
    mySongtime->setHours(5);
    mySongtime->setMinutes(2);
    mySongtime->setSeconds(5);
    
    Time* mySongtime2 = new Time();
    mySongtime2->setHours(0);
    mySongtime2->setMinutes(5);
    mySongtime2->setSeconds(36);
    
    Song* myNewSong = new Song("MySongName","My Artist",mySongtime);
    
    myNewSong->setTitle("MyNewSongName"); //will set the title name on myNewSong to "MyNewSongName"
    cout << "Song title is " << myNewSong->getTitle() << endl;
    
    myNewSong->setArtist("MyNewArtistName"); //will set the artist name on myNewSong to "MyNewArtistName"
    cout << "Artist name is " << myNewSong->getArtist() << endl;
    
    myNewSong->setTime(mySongtime); //will set the runtime for myNewSong
    cout << "Runtime is  " << myNewSong->getTime() << endl << endl;

    Song* myNewSong2 = new Song("Piano Man","Billy Joel",mySongtime2);
    
    myNewSong2->setTitle("Piano Man"); //will set the title name on myNewSong2 to "Piano MAn"
    cout << "Song title is " << myNewSong2->getTitle() << endl;
    
    myNewSong2->setArtist("Billy Joel"); //will set the artist name on myNewSong to "Billy Joel"
    cout << "Artist name is " << myNewSong2->getArtist() << endl;
    
    myNewSong2->setTime(mySongtime2); //will set the runtime for Piano Man
    cout << "Runtime is  " << myNewSong2->getTime() << endl << endl;

}

int convertStringToInt(string myString){
    return atoi(myString.c_str());
}

//ReadFile reads database and creates the objects
Song* readFile(string filename){
    Song* songsInfo; //Vector of TYPE Songs named 'songsInfo'
    
    ifstream infile(filename); //Open the file
    string str; //Declares a string and is used for temporary storage
    
    if (infile.is_open()){
        while (getline(infile,str, '\r')){
            string title;
            string artist;
            Time* runtime;
            
            string token;
            stringstream stringStream(str);
            //Get title
            if (getline(stringStream, token, ' ')){
                title = token;
            }
            //Get Artist
            if (getline(stringStream, token, ' ')){
                artist = token;
            }
            //Get Runtime
            if (getline(stringStream, token, ' ')){
                Time* runtime = convertStringToInt(token);
            }
            
            //SongsVariable(title, artist, runtime);
            //songsInfo.push_back(SongsVariable);
        }
        infile.close();
    }
    else{
        cout << "Unable to open file" << endl << endl;
    }
    return songsInfo;
}

void testReadAndPrint(Song* songsInfo){
    //Check work by printing the information for songs objects
    for(int i = 0; i < 1000; i++){
        cout << i << ": " ;
        cout << "Title " << songsInfo->getTitle() << endl;
        cout << "Artist " << songsInfo->getArtist() << endl;
        cout << "Runtime " << songsInfo->getTime() << endl << endl;
        }
    }

void testReadCreateObjectAndPrint(){
    Song::Song* songsInfoVectorDB = readFile("/Users/susanchang/Desktop/metal2.txt");
    testReadAndPrint(songsInfoVectorDB);    //read file and print
}
 

int main(int argc, const char * argv[]){
    cout << "Lab 4, Parts 1, 2, and Extra Credit \n\n";
    
    testReadCreateObjectAndPrint();
    testSongObject();
    
    return 0;
}

