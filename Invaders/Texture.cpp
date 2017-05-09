//
//  Texture.cpp
//  Invaders
//
//  Created by Ying Wang on 2017-03-25.
//  Copyright © 2017 Ying. All rights reserved.
//

#include <string>
#include "Texture.hpp"

Texture::Texture()
{
    texture = nullptr;
}

Texture::Texture(SDL_Renderer* r, const std::string path, const std::string name)
{
    renderer = r;
    SDL_Surface* loadedSurface = IMG_Load( (path + "/" + name).c_str() );
    assert(loadedSurface != nullptr);
    texture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
    assert(texture != nullptr);
    SDL_FreeSurface( loadedSurface );
}

Texture::~Texture()
{
    Free();
}

void Texture::SetRenderer(SDL_Renderer* r)
{
    renderer = r;
}

bool Texture::LoadFromFile(const std::string path, const std::string name)
{
    Free();
    SDL_Surface* loadedSurface = IMG_Load( (path + "/" + name).c_str() );
    assert(loadedSurface != nullptr);
    texture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
    assert(texture != nullptr);
    SDL_FreeSurface( loadedSurface );
    return texture != nullptr;
}

void Texture::Free()
{
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
    renderer = nullptr;
}

void Texture::Draw() const
{
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
}
