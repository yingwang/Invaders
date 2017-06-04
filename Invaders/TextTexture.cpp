//
//  TextTexture.cpp
//  Invaders
//
//  Created by Ying Wang on 2017-03-25.
//  Copyright © 2017 Ying. All rights reserved.
//

#include "TextTexture.hpp"

TextTexture::TextTexture(SDL_Renderer* r, const std::string& path, const std::string& name, const std::string& textToRender)
{
    renderer = r;
    font = TTF_OpenFont((path + "/" + name).c_str(), 20);
    SDL_Surface* textSurface = TTF_RenderText_Blended(font, textToRender.c_str(), textColor);
    texture = SDL_CreateTextureFromSurface(Renderer(), textSurface);
    width = textSurface->w;
    height = textSurface->h;
    SDL_FreeSurface(textSurface);
}

TextTexture::~TextTexture()
{
    TTF_CloseFont(font);
    font = nullptr;
}

void TextTexture::Draw(int x, int y)
{
    xOffset = x;
    yOffset = y;
    SDL_Rect renderQuad = {x, y, width, height};
    SDL_RenderCopy(renderer, texture, nullptr, &renderQuad);
}

void TextTexture::Update(const std::string& textToRender)
{
    SDL_Surface* textSurface = TTF_RenderText_Blended(font, textToRender.c_str(), textColor);
    texture = SDL_CreateTextureFromSurface(Renderer(), textSurface);
    width = textSurface->w;
    height = textSurface->h;
    SDL_FreeSurface(textSurface);
    this->Draw(xOffset, yOffset);
}
