#include "game.h"
#include "surface.h"
// #include <iostream>

int speedDamp(int spd)
{
    return -(spd - 2);
}

namespace Tmpl8
{
    void Game::Init()
    {

    }

    void Game::Shutdown()
    {
    }

    constexpr int ScreenWidth = 800;
    constexpr int ScreenHeight = 512;

    Sprite theSprite(new Surface("assets/ball.png"), 1);
    static int frame = 0;

    int spriteX = 0;
    int spriteY = 100;
    int speedX = 3;
    int speedY = 4;
    int hitTimes = 0;

    void Game::Tick(float deltaTime)
    {
        screen->Clear(0);
        
        spriteX += speedX;
        speedX += 4;
        spriteY += speedY;
        speedY += 3;

        bool hitBottom = spriteY > ScreenHeight - theSprite.GetHeight();
        bool hitTop = spriteY < 0;
        bool hitSide = spriteX > ScreenWidth - theSprite.GetWidth() || spriteX < 0;

        if (hitBottom)
        {
            hitTimes++;
            if (hitTimes == 50)
                return;

            spriteY = ScreenHeight - theSprite.GetHeight();
            speedY = speedDamp(speedY);
        }

        if (hitTop)
        {
            spriteY = 0;
            speedY = speedDamp(speedY);
        }

        if (hitSide)
        {
            if (spriteX < 0)
            {
                spriteX = 0 + theSprite.GetWidth();
                speedX = speedDamp(speedX);
            }
            else
            {
                spriteX = ScreenWidth - theSprite.GetWidth();
                speedX = speedDamp(speedX);
            }
        }
        theSprite.Draw(screen, spriteX, spriteY);
    }
};
