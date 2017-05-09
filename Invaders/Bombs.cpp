
//
//  Bombs.cpp
//  Invaders
//
//  Created by Ying Wang on 2017-03-26.
//  Copyright © 2017 Ying. All rights reserved.
//

#include "Bombs.hpp"

Bombs::Bombs()
{
    positions = std::vector<uint16_t>(Config::ROWS);
}

void Bombs::Add(std::shared_ptr<Bomb> bomb)
{
    if (bomb != nullptr)
    {
        bombList.push_back(bomb);
        positions[bomb->Row()] |= 1 << bomb->Col();
    }
}

void Bombs::Update()
{
    for (const auto& bomb : bombList)
    {
        if (bomb->OutOfScreen())
        {
            bombList.remove(bomb);
            BIT_CLEAR(positions[Config::ROWS - 1], 15 - (bomb)->Col());
            return;
        }
        bomb->Update();
        if (bomb->RowUpdated())
        {
            bomb->ResetRowUpdated();
            BIT_SET(positions[bomb->Row()], 15 - bomb->Col());
            BIT_CLEAR(positions[bomb->Row() - 1], 15 - bomb->Col());
        }
    }
}

void Bombs::Draw() const
{
    for (const auto& bomb : bombList)
    {
        bomb->Draw();
    }
}

std::vector<uint16_t>& Bombs::Positions()
{
    return positions;
}

void Bombs::Remove(const int row, const int col)
{
    for (auto it = bombList.begin(); it != bombList.end(); it++)
    {
        if (((*it)->Row() == row) && ((*it)->Col() == col))
        {
            bombList.erase(it);
        }
    }
}
