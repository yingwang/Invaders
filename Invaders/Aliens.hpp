//
//  Aliens.hpp
//  Invaders
//
//  Created by Ying Wang on 2017-03-26.
//  Copyright © 2017 Ying. All rights reserved.
//

#ifndef Aliens_hpp
#define Aliens_hpp

#include "Header.hpp"
#include "Config.hpp"
#include "Sprite.hpp"
#include "Bomb.hpp"
#include <vector>

class Aliens
{
private:
    std::vector<uint16_t> positions;
    std::unique_ptr<Sprite> sprite;
    int numOfRow;
    int numOfCol;
    bool moveRight;
    bool changeDirection;
public:
    Aliens(SDL_Renderer* renderer, const std::string& path, const std::string& name);
    void Draw() const;
    void Update();
    void Init();
    std::unique_ptr<Bomb> Fire(SDL_Renderer* r);
    std::vector<uint16_t>& Positions() { return positions; }
    bool IsCleared() const;
};

#endif /* Aliens_hpp */
