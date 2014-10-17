//
//  playlist.cpp
//  SueHW4
//
//  Created by cj on 10/14/14.
//  Copyright (c) 2014 KickinEspresso. All rights reserved.
//

#include "playlist.h"


//Swaps the places of two songs in the linked list
void Playlist::swap(SongNode*firstSongNode, SongNode* secondSongNode){
    
}

//Adds song to the end of the list
//
void Playlist::addSong(Song* song){
    //what if this is the first song?
    if(this->head == NULL){
        //If head is ==  to NULL, it is the first song
        SongNode* newSongNode = new SongNode();
        newSongNode->setNext(NULL);
        newSongNode->setSong(song);
        this->setHead(newSongNode);
        this->setTail(newSongNode);
    }else{
        //If it is not the first song, we can assume it needs on the end
        if(this->tail == NULL){
            cout << "ERROR: Tail is empty" << endl;
        }
        
        //Get the last SongNode
        SongNode* lastSong = this->getTail();
        SongNode* newLastSongNode = new SongNode();
        newLastSongNode->setNext(NULL);
        newLastSongNode->setSong(song);
        lastSong->setNext(newLastSongNode); //Set the newLastSong to next
        this->setTail(newLastSongNode); // New last song;
    }
    this->numsongs++;
    this->totalPlayTime->addTime(song->getTime());
}
void Playlist::insertSong(Song* song){
    
}
void Playlist::removeSong(Song* song){
}
//Returns song if it is in the list
//Returns null if song is not in the list
Song* Playlist::findSong(Song* song){
    Song* mySong;
    return mySong;
}

void Playlist::listSongs(){
    //Loop through the songs and list them
    
    SongNode* myCurrentSongNode = this->head;
    while(myCurrentSongNode != NULL){
        Song* myCurrentSong = myCurrentSongNode->getSong(); //Getting the song out of the songNode
        myCurrentSong->printInfo();
        //Now get next song in the list
        
        if(myCurrentSongNode->getNext() == NULL){
            break;
        }else{
            myCurrentSongNode = myCurrentSongNode->getNext();
        }
    }
}
void Playlist::sortSongsByArtist(){
    
}
void Playlist::sortSongsByTitle(){
    
}

/**** EXTRA CREDIT ****/
void Playlist::shuffle(){
    
}
/**** EXTRA CREDIT ****/
