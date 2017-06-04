//
//  Aliens.cpp
//  Invaders
//
//  Created by Ying Wang on 2017-03-26.
//  Copyright © 2017 Ying. All rights reserved.
//

#include "Aliens.hpp"
#include <iostream>

Aliens::Aliens(SDL_Renderer* renderer, const std::string& path, const std::string& name)
    : sprite(new Sprite(renderer, path, name))
{
    numOfRow = Config::ROWS;
    numOfCol = Config::COLS;
    moveRight = true;
    changeDirection = false;
    positions = std::vector<uint16_t>(numOfRow);
}

void Aliens::Update()
{
    if (changeDirection)
    {
        moveRight = !moveRight;
        for (int i = numOfRow - 1; i >= 1; i--)
        {
            positions[i] = positions[i - 1];
        }
        positions[0] = 0;
        changeDirection = false;
        return;
    }
    if (!moveRight)
    {
        for (auto& position: positions)
        {
            {
                position <<= 1;
                if (position & 0x8000) changeDirection = true;
            }
        }
        
    }
    else
    {
        for (auto& position: positions)
        {
            position >>= 1;
            if (position & 1) changeDirection = true;
        }
    }
}

void Aliens::Init()
{
    // Initialze Aliens
    positions[0] = 0xFFF0;
    positions[1] = 0x7770;
    positions[2] = 0xFFF0;
    std::fill(positions.begin() + 3, positions.end(), 0);
}

void Aliens::Draw() const
{
    for (int row = 0; row < numOfRow; row++)
    {
        for (int col = 0; col < numOfCol; col++)
        {
            if (BIT_CHECK(positions[row], 15 - col))
            {
                sprite->Draw(Config::X_OFFSET + 32 * col, Config::Y_OFFSET + 32 * row);
            }
        }
    }
}

std::unique_ptr<Bomb> Aliens::Fire(SDL_Renderer* r)
{
    bool bombCreated = false;
    //while (!bombCreated)
    {
        srand((unsigned int)time(nullptr));
        int col = (rand() % 16);
        for (int row = numOfRow - 1; row >= 0; row--)
        {
            if (BIT_CHECK(positions[row], 15 - col))
            {
                bombCreated = true;
                return std::unique_ptr<Bomb> {new Bomb(r, "data", "bomb.bmp", Config::X_OFFSET + 32 * col, Config::Y_OFFSET + 32 * row)};
            }
        }
    }
    return nullptr;
}

bool Aliens::IsCleared() const
{
    if (std::adjacent_find(positions.begin(), positions.end(), std::not_equal_to<int>() ) == positions.end())
    {
        // all aliens destroyed
        return true;
    }
    return false;
}

