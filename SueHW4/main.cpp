#include <iostream>
#include <string>

using namespace std;

struct Time{
private:
    
    int hours;
    int minutes;
    int seconds;
    
public:
    //Functions
    void printTime();
    Time* add(Time* time);              //Will add it to the object
    Time* add(Time* time1,Time* time2); //Will add two objects to create a new one.
    //Setters//
    //void setHours(int h);
    //void setMinutes(int m);
    //void setSeconds(int s);
    
    //Getters//
    //int getHours();
    //int getMinutes();
    //int getSeconds();
    int getTime();
};

///Prints time in seconds
//pre: hours, minutes seconds
//post: converts time into seconds and then sums to get time in seconds
void Time::printTime(){
    //printf("%s %s\n",localtime);
}

//Adds time to the current object
/* Usage:
 Time* myTime = new Time();
 myTime->hours = 1;
 myTime->minutes = 2;
 myTime->seconds = 3;
 
 Time* myTime2 = new Time();
 myTime2->hours = 3;
 myTime2->minutes = 4;
 myTime2->seconds = 5;
 
 //This is the usage
 Time* resultTime = myTime->add(myTime2);
 
 */
Time* add(Time* time){
    Time* result = new Time();
    //TOP PRIORITY FOR TIME
    //Your Job is to add:
    //this->hours; this->minutes; this->seconds;
    //to
    //time->hours; time->minutes; time->seconds;
    
    //YOUR CODE GOES HERE
    
    //Convert this and time objects to seconds
    //add them
    //divide by whatever to get hours, minutes and seconds
    
    //result->hours = ....
    //result->minutes = ....
    //result->seconds = ...
    
    return result;
}

//Adds time to the current object
/* Usage:
 Time* myTime = new Time();
 myTime->hours = 1;
 myTime->minutes = 2;
 myTime->seconds = 3;
 
 Time* myTime2 = new Time();
 myTime2->hours = 3;
 myTime2->minutes = 4;
 myTime2->seconds = 5;
 
 //This is the usage
 Time* resultTime = myTime->add(myTime, myTime2);
 
 */
Time* add(Time* time1,Time* time2){
    
    Time* result = new Time();
    
    //Your Job is to add:
    //time1->hours; time1->minutes; time1->seconds;
    //to
    //time2->hours; time2->minutes; time2->seconds;
    
    return result;
}

//Setters//
/*
void Time::setHours(int h){
    this->hours = h;
}
*/

int Time::getTime(){
    int totalTime; //Total time in seconds
    totalTime = hours*3600 + minutes*60 + seconds;
    return totalTime;
}


//********
//Class Song
//******
class Song {
    
private:
    string title; // or should this be an array???
    string artist;
    int runtime;  //FIXME - Wrong type - Time object
    
    int day;
    
public:
    //Constructor
    Song(); //Default Constructor
    Song(string t, string a, int rt); //This is the constructor
    
    //Deconstructor
    ~Song();
    
    //Member functions//
    void printInfo();
    void addTime();
    
    //GETTERS//
    int getTitle();  //FIXME - Wrong type
    int getArtist(); //FIXME - Wrong type
    int getRuntime(); //FIXME - Wrong type
    
    //SETTERS//
    void setTitle(int t); //FIXME - Wrong type
    void setArtist(int a);//FIXME - Wrong type
    void setRuntime(int rt); //FIXME - Wrong type
};

//Default Constructor
Song::Song(){
    this->title = " ";
    this->artist = " ";
    this->runtime = 0;
}

//Constructor with params
////FIXME - Wrong type for parameter "rt"
Song::Song(string t, string a, int rt){
    //FIXME: add "this->"
    title = t;
    artist = a;
    runtime = rt;
}

struct SongNode{

private:
    
    //Attributes go here
    Song* song;
    SongNode* next;

public:
    
    //Member functions
    
    //setters
    //void setSong(Song* s);
    //void setNext(SongNode* s);
    
    //Getters
    //Song* getSong();
    //SongNode* getNext();
    
};


//***************
//Playlist Class

class Playlist {
    
private:
    //Attributes go here
    
    
public:
    
    //Constructors
    //Playlist(); //Default constructor
    //
    //~Playlist();
    
    //Member functions
    
    //setters
    
    //Getters
    
};

void Lab4(){
    // need to read file: readFile("/Users/susanchang/Desktop/Metal2.txt");
}

int main(int argc, const char * argv[]){
    cout << "Lab 4, Parts 1, 2, and Extra Credit \n";
    //labFour();
    
    return 0;
}

