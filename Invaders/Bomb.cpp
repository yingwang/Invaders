//
//  Bomb.cpp
//  Invaders
//
//  Created by Ying Wang on 2017-03-26.
//  Copyright © 2017 Ying. All rights reserved.
//

#include "Bomb.hpp"

Bomb::Bomb(SDL_Renderer* r, const std::string& path, const std::string& name, const int x, const int y)
{
    sprite = new Sprite(r, path, name);
    this->x = x;
    this->y = y + 30;
    rowUpdated = false;
}

void Bomb::Draw() const
{
    sprite->Draw(x, y);
}

void Bomb::Update()
{
    y += 10;
    if (((y - Config::Y_OFFSET) % 32) < 10)
    {
        rowUpdated = true;
    }
}

bool Bomb::OutOfScreen() const
{
    if (y > 400) return true;
    else return false;
}

int Bomb::Row() const
{
    return (this->y - Config::Y_OFFSET) / 32 + 1;
}

int Bomb::Col() const
{
    return (this->x - Config::X_OFFSET) / 32 + 1;
}
