//
//  Player.cpp
//  Invaders
//
//  Created by Ying Wang on 2017-03-25.
//  Copyright © 2017 Ying. All rights reserved.
//

#include "Player.hpp"

Player::Player(SDL_Renderer* r, const std::string path, const std::string name)
    : sprite(new Sprite(r, path, name))
{
    x = Config::Player_X;
    y = Config::Player_Y;
}

void Player::Draw() const
{
    sprite->Draw(x, y);
}

void Player::MoveLeft()
{
    x -= 10;
    if (x < Config::X_OFFSET) x = Config::X_OFFSET;
}

void Player::MoveRight()
{
    x += 10;
    if (x > (Config::X_OFFSET + 480)) x = Config::X_OFFSET + 480;
}

int Player::Col() const
{
    return (x + 16 - Config::X_OFFSET) / 32 + 1;
}

std::shared_ptr<Rocket> Player::Fire(SDL_Renderer* r)
{
    return std::make_shared<Rocket>(r, "data", "rocket.bmp", this->x);
}

void Player::Reset()
{
    x = Config::Player_X;
}
