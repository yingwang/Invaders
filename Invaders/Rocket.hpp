//
//  Rocket.hpp
//  Invaders
//
//  Created by Ying Wang on 2017-03-26.
//  Copyright © 2017 Ying. All rights reserved.
//

#ifndef Rocket_hpp
#define Rocket_hpp

#include "Rocket.hpp"
#include "Sprite.hpp"

class Rocket
{
private:
    std::unique_ptr<Sprite> sprite;
    int x;
    int y;
    bool rowUpdated;
public:
    Rocket(SDL_Renderer* r, const std::string& path, const std::string& name, const int x);
    void Draw() const;
    void Update();
    bool OutOfScreen();
    int Row() const;
    int Col() const;
    bool RowUpdated() const { return rowUpdated; }
    void ResetRowUpdated() { rowUpdated = false; }
};

#endif /* Rocket_hpp */
