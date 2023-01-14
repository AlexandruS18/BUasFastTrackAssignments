#include "game.h"
#include "surface.h"
#include "template.h"

#define BLACK 0x000000
// #define RED 0xFF0000
#define GREEN 0x00FF00

namespace Tmpl8
{
    void Game::Init() {}
    void Game::Shutdown() {}

    Surface noise("assets/noise.png");
    int dotX = 400, dotY = 0;
    void Game::Tick(float deltaTime)
    {
        screen->Clear(0);
        noise.CopyTo(screen, 0, 0);
        Pixel address = *(screen->GetBuffer() + (screen->GetWidth() * (dotY + 1)) + dotX);
        if ((address * 0x00ffffff) == BLACK)
        {
            dotY++;
        }
        else if (dotY % 2 == BLACK)
        {
            dotX++;
        }
        else
        {
            dotX--;
        }

        if (dotY >= ScreenHeight)
        {
            dotY = NULL;
        }

        screen->Plot(dotX, dotY, GREEN);
    }
};