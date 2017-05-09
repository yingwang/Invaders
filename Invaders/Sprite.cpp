//
//  Sprite.cpp
//  Invaders
//
//  Created by Ying Wang on 2017-03-25.
//  Copyright © 2017 Ying. All rights reserved.
//

#include "Sprite.hpp"
#include "Texture.hpp"

Sprite::Sprite(SDL_Renderer* r, const std::string path, const std::string name)
{
    renderer = r;
    SDL_Surface* loadedSurface = IMG_Load( (path + "/" + name).c_str() );
    assert(loadedSurface != nullptr);
    texture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
    assert(texture != nullptr);
    SDL_FreeSurface( loadedSurface );
}

void Sprite::Draw(const int x, const int y)
{
    SDL_Rect renderQuad = {x, y, 32, 32};
    SDL_RenderCopy(renderer, texture, nullptr, &renderQuad);
}
