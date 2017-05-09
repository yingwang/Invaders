//
//  Bomb.hpp
//  Invaders
//
//  Created by Ying Wang on 2017-03-26.
//  Copyright © 2017 Ying. All rights reserved.
//

#ifndef Bomb_hpp
#define Bomb_hpp

#include "Bomb.hpp"
#include "Sprite.hpp"

class Bomb
{
private:
    Sprite *sprite;
    int x;
    int y;
    bool rowUpdated;
public:
    Bomb(SDL_Renderer* r, const std::string path, const std::string name, const int x, const int y);
    void Draw() const;
    void Update();
    void ResetRowUpdated() { rowUpdated = false; }
    bool RowUpdated() const { return rowUpdated; }
    bool OutOfScreen() const;
    int Row() const;
    int Col() const;
};


#endif /* Bomb_hpp */
