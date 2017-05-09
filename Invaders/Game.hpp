//
//  Game.hpp
//  Invaders
//
//  Created by Ying Wang on 2017-03-25.
//  Copyright © 2017 Ying. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <vector>
#include <sstream>

#include "Header.hpp"
#include "Timer.hpp"
#include "Texture.hpp"
#include "TextTexture.hpp"
#include "Sprite.hpp"
#include "Player.hpp"
#include "Aliens.hpp"
#include "Rockes.hpp"
#include "Bombs.hpp"

static const int SCREEN_FPS = 60;
static const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

class Game
{
private:
    int score;
    int numOfLives;
    int numOfRow;
    int numOfCol;
    int frameCounter;
    Timer timer;
   
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event* event;
    
    std::unique_ptr<Aliens> aliens;
    std::unique_ptr<Player> player;
    std::unique_ptr<Rockets> rockets;
    std::unique_ptr<Bombs> bombs;
    std::vector<std::shared_ptr<TextTexture>> textTexture;
    
    void OnMouseButtonDown(const int xPos, const int yPos);
    void OnMouseButtonUp(const int xPos, const int yPos);
    void Init();
    void Update();
    void LoadTextures();
    void InitAliens();
    void RenderTextures();
    void Close();
    void Input();
    void DetectCollision();
    void DrawBackground();
    
public:
    static bool quitGame;
    static bool isGameOver;
    Game();
    ~Game();
    void MainLoop();
};

#endif /* Game_hpp */
