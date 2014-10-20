//
//  playlist.h
//  SueHW4
//
//  Created by cj on 10/14/14.
//  Copyright (c) 2014 KickinEspresso. All rights reserved.
//

#ifndef __SueHW4__playlist__
#define __SueHW4__playlist__
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "time.h"
#include "SongNode.h"


using namespace std;

//***************
//Playlist Class
//***************

class Playlist {
    
private:
    string title;
    //<variable type><pointer *> <variable name>;
    SongNode* head;
    SongNode* tail;
    int numsongs;
    Time* totalPlayTime;
    
    void swap(SongNode*firstSongNode, SongNode* secondSongNode);
    //Traverse Linked List
    bool isEqual(Song* song1, Song* song2);
    
    //Helper Function
    bool isSongInPlaylist(Song* song){
        if(this->findSongNode(song) == NULL){
            return false;
        }else{
            return true;
        }
    }
    
    int indexForSong(Song* song);
    SongNode* getSongNodeAtIndex(int index);
    
public:


    //Constructors
    Playlist(){} //Default constructor
    ~Playlist(){
        //Destroy all SongNodes
    }
    //Member functions
    Playlist(string title){
        this->title = title;
        this->head  = NULL;
        this->tail = NULL;
        this->numsongs = 0;
        this->totalPlayTime = new Time();
        this->totalPlayTime->setUsingSeconds(0);
    }

    //Member functions
    void addSong(Song* song);
    void insertSongAtIndex(Song* song, int index);
    void removeSong(Song* song);
    Song* findSong(Song* song); //find by Title? find by artist
    SongNode* findSongNode(Song* song);
    void listSongs();
    void sortSongsByArtist();
    void sortSongsByTitle();
    int getTotalRuntimeInSeconds(){
        return this->totalPlayTime->getTotalSeconds();
    }

    
    /**** EXTRA CREDIT ****/
    void shuffle();
    /**** EXTRA CREDIT ****/
    
    //Setters
    void setTitle(string title){
        this->title = title;
    }
    void setHead(SongNode* head){
        this->head = head;
    }
    void setTail(SongNode* tail){
        this->tail = tail;
    }
    void setNumsongs(int numsongs){
        this->numsongs = numsongs;
    }
    void setTime(Time* totalPlayTime){
        this->totalPlayTime = totalPlayTime;
    }

    //Getters
    string getTitle(){
        return this->title;
    }
    SongNode* getHead(){
        return this->head;
    }
    SongNode* getTail(){
        return this->tail;
    }
    int getNumsongs(){
        return this->numsongs;
    }
    Time* getTime(){
        return this->totalPlayTime;
    }
    
};

#endif /* defined(__SueHW4__playlist__) */
