//
//  Timer.hpp
//  ConstructionPlus
//
//  Created by Salinas, Jesus on 2/5/19.
//  Copyright © 2019 Salinas, Jesus. All rights reserved.
//

#ifndef Timer_hpp
#define Timer_hpp

#include <stdio.h>

#include <time.h>
#include <assert.h>
#include <iostream>

class Timer
{
private:
    clock_t executionTime;
public:
    Timer();
    void startTimer();
    void stopTimer();
    void resetTimer();
    void displayInformation();
    long getTimeInMicroseconds();
};

#endif /* Timer_hpp */
