//
//  Rockes.cpp
//  Invaders
//
//  Created by Ying Wang on 2017-03-26.
//  Copyright © 2017 Ying. All rights reserved.
//

#include "Rockes.hpp"

Rockets::Rockets()
{
    positions = std::vector<uint16_t>(Config::ROWS);
}

void Rockets::Add(std::shared_ptr<Rocket> rocket)
{
    if (rocket != nullptr)
    {
        rocketList.push_back(rocket);
        positions[rocket->Row()] |= 1 << rocket->Col();
    }
}

void Rockets::Update()
{
    for (const auto& rocket : rocketList)
    {
        if (rocket->OutOfScreen())
        {
            rocketList.remove(rocket);
            BIT_CLEAR(positions[Config::ROWS - 1], 15 - rocket->Col());
            return;
        }
        rocket->Update();
        if (rocket->RowUpdated())
        {
            rocket->ResetRowUpdated();
            BIT_SET(positions[rocket->Row()], 15 - rocket->Col());
            BIT_CLEAR(positions[rocket->Row() + 1], 15 - rocket->Col());
        }
    }
}

void Rockets::Draw() const
{
    for (const auto& rocket : rocketList)
    {
        rocket->Draw();
    }
}

std::vector<uint16_t>& Rockets::Positions()
{
    return positions;
}

void Rockets::Remove(int row, int col)
{
    for (auto it = rocketList.begin(); it != rocketList.end(); it++)
    {
        if (((*it)->Row() == row) && ((*it)->Col() == col))
        {
            rocketList.erase(it);
        }
    }
}
