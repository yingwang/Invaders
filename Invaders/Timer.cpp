//
//  Timer.cpp
//  Invaders
//
//  Created by Ying Wang on 2017-03-25.
//  Copyright © 2017 Ying. All rights reserved.
//

#include <sstream>
#include "Timer.hpp"

Timer::Timer()
{
    startTicks = 0;
}

void Timer::Start()
{
    started = true;
    startTicks = SDL_GetTicks();
}

void Timer::Stop()
{
    started = false;
    startTicks = 0;
}

Uint32 Timer::GetTicks()
{
    Uint32 time = 0;
    if (started)
    {
        time = SDL_GetTicks() - startTicks;
    }
    startTicks = SDL_GetTicks();
    return time;
}

std::string Timer::GetElapsedTime()
{
    int remainingTime = GetTicks() / 1000;
    std::stringstream timeText;
    timeText << remainingTime;
    return timeText.str();
}
