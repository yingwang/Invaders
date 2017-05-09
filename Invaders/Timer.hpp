//
//  Timer.hpp
//  Invaders
//
//  Created by Ying Wang on 2017-03-25.
//  Copyright © 2017 Ying. All rights reserved.
//

#ifndef Timer_hpp
#define Timer_hpp

#include "Header.hpp"

class Timer
{
private:
    Uint32 startTicks;
    bool paused;
    bool started;
    
public:
    Timer();
    void Start();
    void Stop();
    Uint32 GetTicks();
    std::string GetElapsedTime();
};

#endif /* Timer_hpp */
