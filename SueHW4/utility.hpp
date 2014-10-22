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
    int convertCharToInt(char c);
    char convertIntToChar(int i);
    std::vector<int> convertIntToVector( unsigned int value );
    int randomNumberUnder(unsigned long maxVal);
}

#endif /* defined(__SueHW4__utility__) */
