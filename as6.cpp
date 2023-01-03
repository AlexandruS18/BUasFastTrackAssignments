#include "game.h"
#include "surface.h"
#include <iostream>
#include <algorithm>

namespace Tmpl8
{
    void Game::Init()
    {
    }

    void Game::Shutdown()
    {
    }

    constexpr float ScreenWidth = 800;
    constexpr float ScreenHeight = 512;

    Sprite theSprite(new Surface("assets/ball.png"), 1);
    static int frame = 0;
    float spriteY = 0.0f, speed = 1.0f;
    void Game::Tick(float deltaTime)
    {

        deltaTime /= 1000.0f; // dt to seconds
        deltaTime = std::min(deltaTime * 1.0f, 30.0f); //clamp
        std::cout << deltaTime << "\n";
        screen->Clear(0);
        spriteY += speed * deltaTime;
        speed += 3000.0f * deltaTime;
        if (spriteY > (static_cast<float>(ScreenHeight) - static_cast<float>(theSprite.GetHeight())))
        {
            spriteY = static_cast<float>(ScreenHeight - theSprite.GetHeight());
            speed = -speed * 0.8f;
        }
        theSprite.Draw(screen, 20, static_cast<int>(spriteY));
    }
};