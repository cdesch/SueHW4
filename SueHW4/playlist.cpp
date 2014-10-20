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
    
    //get indexes
    int firstSongNodeIndex = this->indexForSongNode(firstSongNode);
    int secondSongNodeIndex = this->indexForSongNode(secondSongNode);
    
    Song* firstSong = firstSongNode->getSong();
    Song* secondSong = secondSongNode->getSong();
    //Remove one
    this->removeSong(firstSongNode);
    this->insertSongAtIndex(secondSong, firstSongNodeIndex);
    
    this->removeSong(secondSongNode);
    this->insertSongAtIndex(firstSong, secondSongNodeIndex);
    
}

bool Playlist::isEqual(Song* song1, Song* song2){
    /*
    if(song1 == song2){
    }
     */
    
    //Compare Title
    if((song1->getTitle() == song2->getTitle()) && (song1->getArtist() == song2->getArtist())){
        return true;
    }else{
        return false;
    }
}

int Playlist::indexForSongNode(SongNode* songNode){
    return this->indexForSong(songNode->getSong());
}

int Playlist::indexForSong(Song* song){
    int index = 0;
    SongNode* myCurrentSongNode = this->head;
    while(myCurrentSongNode != NULL){
        Song* myCurrentSong = myCurrentSongNode->getSong(); //Getting the song out of the songNode
        //Compare  "song" to "myCurrentSong"
        if(isEqual(myCurrentSong, song)){
            return index;
        }
        if(myCurrentSongNode->getNext() == NULL){
            return index;
        }else{
            index ++;
            myCurrentSongNode = myCurrentSongNode->getNext();
        }
    }
    
    return index;
}

SongNode* Playlist::getSongNodeAtIndex(int index){
    //Error Checking: Check bounds of index
    if(index < 0 || index >= this->numsongs){
        cout << "ERROR: Index is out of bounds" << endl;
        return NULL;
    }
    
    int currentIndex = 0;
    
    SongNode* myCurrentSongNode = this->head;
    while(myCurrentSongNode != NULL){
        if(currentIndex == index){
            return myCurrentSongNode;
        }
        if(myCurrentSongNode->getNext() == NULL){
            return myCurrentSongNode;
        }else{
            currentIndex ++;
            myCurrentSongNode = myCurrentSongNode->getNext();
        }
    }
    return myCurrentSongNode;
}

Song* Playlist::getSongAtIndex(int index){
    SongNode* mySongNode = this->getSongNodeAtIndex(index);
    return mySongNode->getSong();
}

void Playlist::addSong(SongNode* songNode){
    this->addSong(songNode->getSong());
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
void Playlist::insertSongAtIndex(Song* song, int index){
    
    //Check index for bounds
    if(index < 0 || index > this->numsongs){
        cout << "Error: Cannot insert song at index that is out of bounds" << endl;
        return;
    }

    //If inserting at the end of the linked-List, use the add function
    if(index == this->numsongs || this->numsongs == 0){
        this->addSong(song);
        return;
    }
    
    SongNode* mySongNodeToAdd = new SongNode();
    mySongNodeToAdd->setSong(song);
    
    //Find the next SongNode
    SongNode* myNextSongNode = this->getSongNodeAtIndex(index);
    mySongNodeToAdd->setNext(myNextSongNode);
    if(index == 0){
        this->head = mySongNodeToAdd;
        
    }else{
        //Find the previous SongNode
        SongNode* myPreviousSongNode = this->getSongNodeAtIndex(index-1);
        //set the songToAdd's "next" to the next song
        myPreviousSongNode->setNext(mySongNodeToAdd);
    }

    this->numsongs ++;    //Increment the number songs
    this->totalPlayTime->add(song->getTime()); //add song from total playing
}

void Playlist::removeSong(SongNode* songNode){
    this->removeSong(songNode->getSong());
}

void Playlist::removeSong(Song* song){
    
    //Use Case: If the linked list is empty?
    if(this->numsongs == 0){
        cout << "Error: cannot remove song from empty list" << endl;
        return;
    }
    
    //Use Case: If there is only one item in the list
    if (this->numsongs == 1){
        Song* currentSong = this->head->getSong();
        if(isEqual(currentSong, song)){
            //Can be removed
            
            delete this->head;  // Deletes the SongNode object
            this->head = NULL;  // Deletes the pointer
            this->tail = NULL;  // Detetes the pointer
            this->numsongs = 0; // Resets to 0
            this->totalPlayTime->setUsingSeconds(0); //Resets to 0;
        }else{
            //Cannot be removed
            cout << "Song cannot be removed because it is not in linked list " << endl;
            return;
        }
    }
    
    
    //The next Use Cases !!assume!! that there are atleast 2 or more SongNodes in the linked list
    //Use Case: Is the song even in the linked list?
    if(!this->isSongInPlaylist(song)){
        cout << "Song cannot be removed because it is not in linked list " << endl;
        return;
    }
    
    //at this point: We now know that the song is DEFINITELY in the linked somewhere
    
    //Use Case: If removing first song, delete the node and set the "head" pointer to the next
    //If the "head" is equal to the song, then we know the song that we are removing is the first song
    if(this->isEqual(this->head->getSong(), song)){

        //Remove that song
        SongNode* mySongNode = this->head;
        this->head = mySongNode->getNext();

        //**** THIS CODE IS KIND OF REPETITIVE, WE MAY WANT TO FIGURE A WAY TO MAKE IT "DRY" (Don't Repeat Yourself)
        this->numsongs --;
        Song* currentSong = mySongNode->getSong();
        this->totalPlayTime->subtract(currentSong->getTime()); //Subtract song from total playing
        
        
        delete mySongNode;
        return;
    }
    
    //Use Case: If removing the last song, delete the node and set the "tail" pointer to the previous song AND set the previous song's 'next' pointer to NULL
    //If the "tail" is equal to the song, then we know the song that we are removing is the last song
    if(this->isEqual(this->tail->getSong(), song)){
        // We need to get the previous song. We know how many songs are linked list
        SongNode* previousSongNode = this->getSongNodeAtIndex(this->numsongs - 2);
        SongNode* lastSongNode = this->tail;

        this->tail = previousSongNode; //Set a new tail
        
        this->numsongs --;
        Song* currentSong = lastSongNode->getSong();
        this->totalPlayTime->subtract(currentSong->getTime()); //Subtract song from total playing
        lastSongNode->prepareForDeletion();
        delete lastSongNode;
        
        previousSongNode->setNext(NULL);

        return;
    }
    
    //Use Case: If remove the middle  song, delete the node and set previous song's "next" pointer to the next song of the node being deleted.
    //We know the song is in the middle somewhere

    //Get the song to delete
    SongNode* mySongNodeToDelete = this->findSongNode(song);
    int indexForSongNodeToDelete = this->indexForSong(song);

    //Get the NEXT song node
    SongNode* myNextSongNode = this->getSongNodeAtIndex(indexForSongNodeToDelete +1);
    //get the PREVIOUS song node
    SongNode* myPreviousSongNode = this->getSongNodeAtIndex(indexForSongNodeToDelete -1);
    myPreviousSongNode->setNext(myNextSongNode);
    
    this->numsongs --;    //Decrement the number songs
    Song* currentSong = mySongNodeToDelete->getSong();    //Decrement total playtime by the song being removed
    this->totalPlayTime->subtract(currentSong->getTime()); //Subtract song from total playing
    delete mySongNodeToDelete;

}
//Returns song if it is in the list
//Returns null if song is not in the list
Song* Playlist::findSong(Song* song){
    Song* mySong;
    return mySong;
}

SongNode* Playlist::findSongNode(Song* song){
    
    SongNode* myCurrentSongNode = this->head;
    while(myCurrentSongNode != NULL){
        Song* myCurrentSong = myCurrentSongNode->getSong(); //Getting the song out of the songNode
        //Compare  "song" to "myCurrentSong"
        if(isEqual(myCurrentSong, song)){
            return myCurrentSongNode;
        }
        if(myCurrentSongNode->getNext() == NULL){
            return NULL;
        }else{
            myCurrentSongNode = myCurrentSongNode->getNext();
        }
    }
    
    return NULL;
}

void Playlist::listSongs(){
    //Loop through the songs and list them
    
    SongNode* myCurrentSongNode = this->head;
    while(myCurrentSongNode != NULL){
        Song* myCurrentSong = myCurrentSongNode->getSong(); //Getting the song out of the songNode
        if(myCurrentSong == NULL){
            cout << "NULL " << endl;
            break;
        }
        
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
    
    //Sorting using insertion sort
    for(int i = 0; i <= this->numsongs; i++ ){
        for(int j = i - 1 ; j > 0; j--){
            SongNode* previousSongNode = this->getSongNodeAtIndex(j-1);
            SongNode* currentSongNode = this->getSongNodeAtIndex(j);
            Song* previousSong = this->getSongAtIndex(j-1);
            Song* currentSong = this->getSongAtIndex(j);
            string previousSongString = previousSong->getArtist();
            string currentSongString = currentSong->getArtist();
            if(previousSongString.compare(currentSongString) > 0){
                this->swap(previousSongNode, currentSongNode);
            }

        }
    }
    
}
void Playlist::sortSongsByTitle(){
    
    for(int i = 0; i <= this->numsongs; i++ ){
        for(int j = i - 1 ; j > 0; j--){
            SongNode* previousSongNode = this->getSongNodeAtIndex(j-1);
            SongNode* currentSongNode = this->getSongNodeAtIndex(j);
            Song* previousSong = this->getSongAtIndex(j-1);
            Song* currentSong = this->getSongAtIndex(j);
            string previousSongString = previousSong->getTitle();
            string currentSongString = currentSong->getTitle();
            if(previousSongString.compare(currentSongString) > 0){
                this->swap(previousSongNode, currentSongNode);
            }
            
        }
    }
    
}

/*
int Playlist::compareStrings(string first, string second){
    return first.compare(second);
}
 */


//If the first string is greater than the second, return true
//if the second string is greater than the first, return false;

bool Playlist::greaterThan(string first, string second){
    return true;
}

bool Playlist::lessThan(string first, string second){
    return true;
}


/**** EXTRA CREDIT ****/
void Playlist::shuffle(){
    
    ///MAYBE... randomly choose a 2 indexes and swap those
    
    
    
    
}
/**** EXTRA CREDIT ****/
