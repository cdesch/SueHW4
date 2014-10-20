//
//  utility.h
//  SueHW4
//
//  Created by cj on 10/20/14.
//  Copyright (c) 2014 KickinEspresso. All rights reserved.
//

#ifndef __SueHW4__utility__
#define __SueHW4__utility__

#include <stdio.h>
#include <vector>
#include <iostream>

namespace utility{
    //Simple char to int converter via ASCII indexs
    int convertCharToInt(char c){
        int myTempInt = (int)c;
        if(myTempInt < 48 || myTempInt > 57) {
            std::cout << "Error: Not an integer!\n";
            return -1; //Error checking
        }
        return myTempInt - 48;
    }
    //Simple int to char converter via ASCII indexes
    char convertIntToChar(int i){
        char c;
        c = (char)i;
        return c + 48;
    }
    
    std::vector<int> convertIntToVector( unsigned int value ){
        std::vector<int> digits;
        for( ; value > 0 ; value /= 10 ){
            digits.push_back( value % 10 );
        }
        reverse( digits.begin(), digits.end());
        return digits;
    }
    
    int randomNumberUnder(unsigned long maxVal){
        return  rand() % maxVal;
    }
}


#endif /* defined(__SueHW4__utility__) */
