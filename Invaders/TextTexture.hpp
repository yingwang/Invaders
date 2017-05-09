//
//  TextTexture.hpp
//  Invaders
//
//  Created by Ying Wang on 2017-03-25.
//  Copyright © 2017 Ying. All rights reserved.
//

#ifndef TextTexture_hpp
#define TextTexture_hpp

#include "Header.hpp"
#include "Texture.hpp"

class TextTexture : Texture
{
private:
    int width;
    int height;
    TTF_Font* font;
    const SDL_Color textColor = {255, 255, 255, 255};
    int xOffset;
    int yOffset;
public:
    TextTexture(SDL_Renderer* r, const std::string path, const std::string name, const std::string textToRender);
    ~TextTexture();
    void Draw(int x, int y);
    void Update(const std::string textToRender);
};

#endif /* TextTexture_hpp */
