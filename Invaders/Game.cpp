//
//  Game.cpp
//  Invaders
//
//  Created by Ying Wang on 2017-03-25.
//  Copyright © 2017 Ying. All rights reserved.
//

#include "Game.hpp"
#include <bitset>
#include <string>

bool Game::quitGame = false;
bool Game::isGameOver = false;

Game::Game()
{
    Game::quitGame = false;
    Game::isGameOver = false;
}

Game::~Game()
{
}

void Game::Init()
{
    int ret;
    ret = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);
    assert(ret >= 0);
    window = SDL_CreateWindow("Invaders - Ying Wang", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    assert(window != nullptr);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    assert(renderer != nullptr);
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    int imgFlags = IMG_INIT_PNG;
    ret = IMG_Init(imgFlags) & imgFlags;
    assert(ret);
    ret = TTF_Init();
    assert(ret != -1);
    ret = Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    assert(ret >= 0);
    numOfRow = Config::ROWS;
    numOfCol = Config::COLS;
    frameCounter = 0;
    aliens.reset(new Aliens(renderer, "data", "enemy1.bmp"));
    player.reset(new Player(renderer, "data", "player.bmp"));
    rockets.reset(new Rockets());
    bombs.reset(new Bombs());
    aliens->Init();
    score = 0;
    numOfLives = 3;
}

void Game::LoadTextures()
{
    textTexture.push_back(std::make_shared<TextTexture>(renderer, "data", "FreeMono.ttf", "0"));
    textTexture.push_back(std::make_shared<TextTexture>(renderer, "data", "FreeMono.ttf", "0"));
    textTexture.push_back(std::make_shared<TextTexture>(renderer, "data", "FreeMono.ttf", "0"));
    textTexture.push_back(std::make_shared<TextTexture>(renderer, "data", "FreeMono.ttf", "0"));
}

void Game::RenderTextures()
{
    if (isGameOver)
    {
        textTexture[3]->Draw(Config::TEXT_X_OFFSET + 90, Config::TEXT_Y_OFFSET);
        textTexture[3]->Update("GAME OVER");
        return;
    }
    DrawBackground();
    aliens->Draw();
    player->Draw();
    rockets->Draw();
    bombs->Draw();
    textTexture[0]->Draw(Config::TEXT_X_OFFSET, Config::TEXT_Y_OFFSET);
    textTexture[1]->Draw(Config::TEXT_X_OFFSET + 60, Config::TEXT_Y_OFFSET);
    textTexture[2]->Draw(Config::TEXT_X_OFFSET + Config::TEXT_X_GAP, Config::TEXT_Y_OFFSET);
    textTexture[0]->Update(std::to_string(score));
    textTexture[1]->Update(std::to_string(numOfLives) + "/3");
    textTexture[2]->Update(timer.GetElapsedTime().c_str());
}

void Game::DrawBackground()
{
    SDL_SetRenderDrawColor( renderer, 255, 255, 0, 0 );
    SDL_Rect r;
    r.x = Config::X_OFFSET - 10;
    r.y = Config::Y_OFFSET - 10;
    r.w = 32 * Config::COLS + 20;
    r.h = 32 * Config::ROWS + 20;
    SDL_RenderDrawRect(renderer, &r);
}

void Game::Close()
{
    std::fill(textTexture.begin(), textTexture.end(), nullptr);
    delete event;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    event = nullptr;
    window = nullptr;
    renderer = nullptr;
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Game::Input()
{
    const Uint8* currentKeyStates = SDL_GetKeyboardState(nullptr);
    if(currentKeyStates[SDL_SCANCODE_UP])
    {
        rockets->Add(player->Fire(renderer));
    }
    else if(currentKeyStates[SDL_SCANCODE_LEFT ])
    {
        player->MoveLeft();
    }
    else if(currentKeyStates[SDL_SCANCODE_RIGHT])
    {
        player->MoveRight();
    }
}

void Game::DetectCollision()
{
    // Collision between player and Bombs
    const int playerCol = this->player->Col();

    if (BIT_CHECK(bombs->Positions()[numOfRow - 1], numOfCol - 1 - playerCol))
    {
        // there is collision
        if (numOfLives > 0)
        {
            numOfLives--;
            player->Reset();
        }
        else
        {
            isGameOver = true;
        }
        // Remove bomb
        bombs->Remove(Config::ROWS - 1, playerCol);
        BIT_CLEAR(bombs->Positions()[numOfRow - 1], numOfCol - 1 - playerCol);
    }
    
    // Aliens and Rockets
    for (int row = Config::ROWS - 1; row >= 0; row--)
    {
        if (aliens->Positions()[row] & rockets->Positions()[row])
        {
            int collisionPos = aliens->Positions()[row] & rockets->Positions()[row];
            for (int col = 0; col < numOfCol; col++)
            {
                if (BIT_CHECK(collisionPos, numOfCol - 1 - col))
                {
                    score += 10;
                    BIT_CLEAR(aliens->Positions()[row], numOfCol - 1 - col);
                    rockets->Remove(row, col);
                    BIT_CLEAR(rockets->Positions()[row], numOfCol - 1 - col);
                    if (aliens->IsCleared()) aliens->Init();
                }
            }
        }
    }

    // Detect collision between aliens and player
    // Aliens have not reached the bottom line
    if (aliens->Positions()[numOfRow - 1] == 0) return;

    if (BIT_CHECK(aliens->Positions()[numOfRow - 1], numOfCol - 1 - playerCol))
    {
        // When there is collision, update lives of player and reset player to initial position
        if (numOfLives > 0)
        {
            numOfLives--;
            player->Reset();
            if (aliens->IsCleared()) aliens->Init();
        }
        else
        {
            isGameOver = true;
        }
        // Remove alien
        BIT_CLEAR(aliens->Positions()[numOfRow - 1], numOfCol - 1 - playerCol);
    }
}

void Game::Update()
{
    frameCounter++;
    if (frameCounter % 10 == 0)
    {
        rockets->Update();
        bombs->Update();
        DetectCollision();
        if (frameCounter % 60 == 0)
        {
            aliens->Update();
            if (frameCounter % 120 == 0)
            {
                bombs->Add(aliens->Fire(renderer));
            }
        }
    }

}

void Game::MainLoop()
{
    Init();
    event = new SDL_Event();
    LoadTextures();
    timer.Start();
    //The frames per second cap timer
    Timer capTimer;
    //Start counting frames per second
    int countedFrames = 0;
    capTimer.Start();
    
    while(!quitGame)
    {
        SDL_PumpEvents();
        while(SDL_PollEvent(event) != 0)
        {
            if (event->type == SDL_QUIT) quitGame = true;
            if (!isGameOver) Input();
        }
        Update();
        //Calculate and correct fps
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(renderer);
        RenderTextures();
        SDL_RenderPresent(renderer);
        ++countedFrames;
        //If frame finished early
        int frameTicks = capTimer.GetTicks();
        if( frameTicks < SCREEN_TICKS_PER_FRAME )
        {
            //Wait remaining time
            SDL_Delay( SCREEN_TICKS_PER_FRAME - frameTicks );
        }
    }
    Close();
}

