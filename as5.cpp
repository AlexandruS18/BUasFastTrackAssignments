#include "game.h"
#include "surface.h"
#include <cstdint>
#include <iostream>

namespace Tmpl8
{
    // -----------------------------------------------------------
    // Initialize the application
    // -----------------------------------------------------------
    void Game::Init()
    {
    }

    void Game::Shutdown()
    {
    }

    static Sprite theSprite(new Surface("assets/ball.png"), 1);
    static int frame = 0;
    int spriteX = 0;
    int spriteY = 100;
    int speedX = 1;
    int speedY = 1;
    int hitTimes = 0;

    // Main tick function
    void Game::Tick(float deltaTime)
    {
        // clear the graphics window
        screen->Clear(0);
        spriteX += speedX;
        speedX++;
        spriteY += speedY;
        speedY++;

        bool hitTop = (spriteY < 0 + 50);
        bool hitSideR = (spriteX > 800 - 50);
        bool hitSideL = (spriteX < 0 + 50);
        bool hitBottom = spriteY > 512 - 50;

        if (hitTop)
        {
            spriteY = 0 + 50;
            speedY = -speedY;
        }

        if (hitSideL)
        {
            spriteX = 0 + 50;
            speedX = -speedX;
        }
        else if (hitSideR)
        {
            spriteX--;
            speedX = -speedX;
        }

        if (hitBottom)
        {
            hitTimes++;
            if (hitTimes >= 50)
            {
                return;
            }
            spriteY = 512 - 50;
            speedY = -speedY;
            // std::cout << hitTimes << "\n";
        }

        theSprite.Draw(screen, spriteX, spriteY);
    }
}