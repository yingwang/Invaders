//
//  Texture.hpp
//  Invaders
//
//  Created by Ying Wang on 2017-03-25.
//  Copyright © 2017 Ying. All rights reserved.
//

#ifndef Texture_hpp
#define Texture_hpp

#include <string>
#include "Header.hpp"

class Texture
{
private:
protected:
    SDL_Texture* texture;
    SDL_Renderer* renderer;
    
public:
    Texture();
    Texture(SDL_Renderer* r, const std::string& path, const std::string& name);
    ~Texture();
    bool LoadFromFile(const std::string& path, const std::string& name);
    void Free();
    void Draw() const;
    void SetRenderer(SDL_Renderer* renderer);
    SDL_Renderer* Renderer() const { return renderer; };
};


#endif /* Texture_hpp */
