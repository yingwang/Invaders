//
//  Player.hpp
//  Invaders
//
//  Created by Ying Wang on 2017-03-25.
//  Copyright © 2017 Ying. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include "Sprite.hpp"
#include "Rocket.hpp"

class Player
{
private:
    std::unique_ptr<Sprite> sprite;
    int x;
    int y;

public:
    Player(SDL_Renderer* r, const std::string path, const std::string name);
    void Draw() const;
    void MoveLeft();
    void MoveRight();
    int Col() const;
    std::shared_ptr<Rocket> Fire(SDL_Renderer* r);
    void Reset();
};

#endif /* Player_hpp */
