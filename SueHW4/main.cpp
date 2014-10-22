///
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
#include "playlist.h"
#include <vector>
#include <assert.h>
using namespace std;

const string filePath = "/Users/cj/Desktop/Metal2.txt";

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

vector <Song*> readFileByLine(string filename){
    
    vector <Song*> vectorOfSongs;
    
    ifstream infile(filename); //Open the file
    string str; //Declares a string and is used for temporary storage
    
    if (infile.is_open()){
        //While the file is open AND you can get line, loop
        while (getline(infile,str, '\r')){
            
            string title;
            string artist;
            int runtime;
            
            title = str;
            
            if (getline(infile,str,'\r')){
                artist = str;
            }
            if (getline(infile,str,'\r')){
                runtime = convertStringToInt(str);
            }
            
            //Store the song in the vector of songs
            Time* myRuntime = new Time();
            myRuntime->setUsingSeconds(runtime);
            Song* myNewSong = new Song(title,artist,myRuntime);
            vectorOfSongs.push_back(myNewSong);
            
        }
        infile.close();
    }else{
        cout << "Unable to open file" << endl << endl;
    }
    
    return vectorOfSongs;
    
}

void testReadAndPrint(vector<Song*> vectorOfSongs){
    //Check work by printing the information for songs objects
    
    for(int i = 0; i < vectorOfSongs.size(); i++){
        Song* songsInfo = vectorOfSongs[i];
        
        cout << i << ": " << endl;
        cout << "Title: " << songsInfo->getTitle() << endl;
        cout << "Artist: " << songsInfo->getArtist() << endl;
        Time* mySongTime = songsInfo->getTime();
        cout << "Runtime: " << mySongTime->getTotalSeconds() << endl << endl;
    }
}

void testReadCreateObjectAndPrint(){
    vector<Song*> vectorOfSongs = readFileByLine(filePath);
    testReadAndPrint(vectorOfSongs);    //read file and print
}

void testPlaylistAddAndListFunctions(){
    vector<Song*> vectorOfSongs = readFileByLine(filePath);
    
    Playlist* myPlaylist = new Playlist("MyPlaylist");
    
    myPlaylist->addSong(vectorOfSongs[0]);
    myPlaylist->addSong(vectorOfSongs[1]);
    myPlaylist->addSong(vectorOfSongs[2]);
    myPlaylist->addSong(vectorOfSongs[3]);
    myPlaylist->addSong(vectorOfSongs[4]);
    
    myPlaylist->listSongs();
    cout << "Number of songs: " << myPlaylist->getNumsongs() << endl;
    
    cout << endl;
    cout << "Test Playlist::findSongNode() function" << endl;
    SongNode* mySongNode = myPlaylist->findSongNode(vectorOfSongs[2]);
    Song* mySong = mySongNode->getSong();
    mySong->printInfo();
    cout << endl;
    
}

void testPlaylistRemoveSong(Playlist* myPlaylist, Song* song ){
    myPlaylist->removeSong(song);
    myPlaylist->listSongs();
    cout << "Number of songs: " << myPlaylist->getNumsongs() << endl;
    cout << "Total runtime: " << myPlaylist->getTotalRuntimeInSeconds()<< endl;
    cout << endl;
}

void testPlaylistAddRemoveListFunctions(){
    vector<Song*> vectorOfSongs = readFileByLine(filePath);
    Playlist* myPlaylist = new Playlist("MyPlaylist");
    int numSongs = 10;
    
    cout << "Total Number of songs in the test array: " << numSongs << endl;
    for(int i = 0; i < numSongs; i++){
        myPlaylist->addSong(vectorOfSongs[i]);
    }
    
    myPlaylist->listSongs();
    
    cout << "Number of songs: " << myPlaylist->getNumsongs() << endl;
    cout << "Total runtime: " << myPlaylist->getTotalRuntimeInSeconds() << endl<< endl;
    cout << "Remove second song from Playlist: " << endl;
    testPlaylistRemoveSong(myPlaylist, vectorOfSongs[1]);
    cout << "Remove first song from Playlist: " << endl;
    testPlaylistRemoveSong(myPlaylist, vectorOfSongs[0]);
    cout << "Remove last song from Playlist: " << endl;
    testPlaylistRemoveSong(myPlaylist, vectorOfSongs[numSongs-1]);
    
    cout << "Total Number of songs in the array " << vectorOfSongs.size() << endl;
    //testReadAndPrint(vectorOfSongs);
}


void testPlaylistInsertSongFunctions(){
    vector<Song*> vectorOfSongs = readFileByLine(filePath);
    
    Playlist* myPlaylist = new Playlist("MyPlaylist");
    int numSongs = 10;
    for(int i = 0; i < numSongs; i++){
        myPlaylist->addSong(vectorOfSongs[i]);
    }
    
    cout << "  Original Playlist before adding song at beginning, middle, and end:" << endl;
    cout << "***********************************************************************"<< endl;
    myPlaylist->listSongs();
    cout << "  ****Number of songs: " << myPlaylist->getNumsongs();
    cout << "        ****Total runtime: " << myPlaylist->getTotalRuntimeInSeconds()<< endl;
    
    
    //Insert at beginning
    myPlaylist->insertSongAtIndex(vectorOfSongs[100], 0);
    cout << endl;
    cout << "  Insert song at the beginning of the Playlist:" << endl;
    cout << "*************************************************"<< endl;
    myPlaylist->listSongs();
    cout << "Number of songs: " << myPlaylist->getNumsongs() << endl;
    cout << "Total runtime: " << myPlaylist->getTotalRuntimeInSeconds()<< endl;
    cout << "  ****Number of songs: " << myPlaylist->getNumsongs();
    cout << "        ****Total runtime: " << myPlaylist->getTotalRuntimeInSeconds()<< endl;
    
    
    //Insert at middle
    myPlaylist->insertSongAtIndex(vectorOfSongs[110], 8);
    cout << endl;
    cout << "  Insert song in the middle of the Playlist:" << endl;
    cout << "**********************************************"<< endl;
    myPlaylist->listSongs();
    cout << "  ****Number of songs: " << myPlaylist->getNumsongs();
    cout << "        ****Total runtime: " << myPlaylist->getTotalRuntimeInSeconds()<< endl;
    
    //Insert at end
    myPlaylist->insertSongAtIndex(vectorOfSongs[120], numSongs+2);
    cout << endl;
    cout << "  Insert song at the end of the Playlist:" << endl;
    cout << "*******************************************"<< endl;
    myPlaylist->listSongs();
    cout << "  ****Number of songs: " << myPlaylist->getNumsongs();
    cout << "        ****Total runtime: " << myPlaylist->getTotalRuntimeInSeconds()<< endl;
    cout << endl;
    
}

void testPlaylistSortFunctionArtist(){
    vector<Song*> vectorOfSongs = readFileByLine(filePath);
    Playlist* myPlaylist = new Playlist("MyPlaylist");
    int numSongs = 25;
    for(int i = 0; i < numSongs; i++){
        myPlaylist->addSong(vectorOfSongs[i]);
    }
    //cout << "Total Number of songs in the array " << vectorOfSongs.size() << endl;
    cout << "Total Number of songs in the test array " << numSongs << endl;
    cout << "  Songs unsorted by Artist:" << endl;
    cout << "*****************************" << endl;
    myPlaylist->listSongs();
    cout << endl;
    cout << "  Songs sorted by Artist:" << endl;
    cout << "***************************" << endl;
    myPlaylist->sortSongsByArtist();
    myPlaylist->listSongs();
    cout << endl << endl;
    
}

void testPlaylistSortFunctionTitle(){
    vector<Song*> vectorOfSongs = readFileByLine(filePath);
    
    Playlist* myPlaylist = new Playlist("MyPlaylist");
    int numSongs = 25;
    for(int i = 0; i < numSongs; i++){
        myPlaylist->addSong(vectorOfSongs[i]);
    }
    //cout << "Total Number of songs in the array " << vectorOfSongs.size() << endl;
    cout << "Total Number of songs in the test array " << numSongs << endl;
    cout << "  Songs unsorted by Title:" << endl;
    cout << "**************************" << endl;
    myPlaylist->listSongs();
    cout << endl;
    cout << "  Songs sorted by Title:" << endl;
    cout << "**************************" << endl;
    myPlaylist->sortSongsByTitle();
    myPlaylist->listSongs();
    cout << endl;
    
}


void testPlaylistShuffleFunction(){
    vector<Song*> vectorOfSongs = readFileByLine(filePath);
    
    Playlist* myPlaylist = new Playlist("MyPlaylist");
    int numSongs = 50;
    for(int i = 0; i < numSongs; i++){
        myPlaylist->addSong(vectorOfSongs[i]);
    }
    //cout << "Total Number of songs in the array " << vectorOfSongs.size() << endl;
    cout << "Total Number of songs in the test array " << numSongs << endl;
    cout << "   Playlist Sorted by Title:" << endl;
    cout << "**********************" << endl;
    myPlaylist->sortSongsByTitle();
    myPlaylist->listSongs();
    cout << endl;
    cout << "  Shuffled Playlist:" << endl;
    cout << "**********************" << endl;
    myPlaylist->shuffle();
    myPlaylist->listSongs();
    cout << endl;
}


int main(int argc, const char * argv[]){
    cout << "Lab 4, Parts 1, 2, and Extra Credit \n\n";
    //testPlaylistAddAndListFunctions();
    //testPlaylistAddRemoveListFunctions();
    //testPlaylistSortFunctionArtist();
    //testPlaylistSortFunctionTitle();
    //testPlaylistInsertSongFunctions();
    //testReadCreateObjectAndPrint();
    testPlaylistShuffleFunction();
    return 0;
}
