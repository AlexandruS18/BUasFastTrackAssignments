#include "game.h"
#include "surface.h"
#include "template.h"

#define MagicNumber (ScreenWidth / 2) // 400

namespace Tmpl8
{
    /*
    Pixel* address = screen->GetBuffer() + 100; // x = 0 + 100 = 100
    for (int i = NULL; i < MagicNumber - 1; i++) address[i * ScreenWidth] = i; // i * ScreenWidth -> overrides the X axis
    */
    void Game::Init() {}

    void Game::Shutdown() {}

    void Game::Tick(float deltaTime)
    {
        screen->Clear(0);
        // as8 part 1
        Pixel* address = screen->GetBuffer();
        for (int i = NULL; i < ScreenWidth * MagicNumber; i += ScreenWidth * 2 + 2) // thanks to Sleepi for the "i += ScreenWidth * 2 + 2" code!
        {
            address[i] = i;
            address[i] = 0xFF0000;
        }
    }
}