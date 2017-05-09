//
//  Sprite.hpp
//  Invaders
//
//  Created by Ying Wang on 2017-03-25.
//  Copyright © 2017 Ying. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include <stdio.h>
#include "Header.hpp"
#include "Texture.hpp"

class Sprite : public Texture
{    
public:
    Sprite(SDL_Renderer* r, const std::string path, const std::string name);
    void Draw(const int x, const int y);
};

#endif /* Sprite_hpp */
