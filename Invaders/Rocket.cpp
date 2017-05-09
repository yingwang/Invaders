//
//  Rocket.cpp
//  Invaders
//
//  Created by Ying Wang on 2017-03-26.
//  Copyright © 2017 Ying. All rights reserved.
//

#include "Rocket.hpp"

Rocket::Rocket(SDL_Renderer* r, const std::string path, const std::string name, const int x)
    :sprite(new Sprite(r, path, name))
{
    this->x = x;
    y = Config::Player_Y - 30;
    rowUpdated = false;
}

void Rocket::Draw() const
{
    sprite->Draw(x, y);
}

void Rocket::Update()
{
    y -= 20;
    if (((y - Config::Y_OFFSET) % 32) < 20)
    {
        rowUpdated = true;
    }
}

bool Rocket::OutOfScreen()
{
    if (y < 0) return true;
    else return false;
}

int Rocket::Row() const
{
    return (this->y - Config::Y_OFFSET) / 32;
}

int Rocket::Col() const
{
    return (this->x - Config::X_OFFSET + 16) / 32;
}
