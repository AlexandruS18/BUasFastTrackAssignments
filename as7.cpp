#include "game.h"
#include "template.h"
#include "surface.h"
#include <cstdio>
#include <cassert>

// surface.cpp assignment code
/*
void Surface::Bar( int x1, int y1, int x2, int y2, Pixel c )
{
    Pixel* a = x1 + y1 * m_Pitch + m_Buffer;
    for ( int y = y1; y <= y2; y++ )
    {
        if (y <= ScreenHeight)
        {
            for (int x = 0; x <= (x2 - x1); x++)
            {
                if (x <= ScreenWidth)
                {
                    a[x] = c;
                }
            }
        }
        a += m_Pitch;
    }
}
*/

namespace Tmpl8
{
    void Game::Init() {}
    void Game::Shutdown() {}
    // use any image you want
    Surface image("assets/FF10_wakka.png"); // image is always has to be 50x50 or else its broken...
    const int bWidth = ScreenWidth / image.GetWidth();
    const int bHeight = ScreenHeight / image.GetHeight();
    const int imgSize = image.GetPitch();


    void Game::Tick(float deltaTime)
    {
        screen->Clear(0);

        for (int x = 15; x < ScreenWidth; x += bWidth)
        {
            for (int y = 6; y < ScreenHeight; y += bHeight)
            {
                if (y + bHeight - 1 > ScreenHeight - 1) break;

                Pixel p = image.GetBuffer()[(x / bWidth) + (y / bHeight) * imgSize];
                int red = p & 0xff0000;
                int green = p & 0x00ff00;
                int blue = p & 0x0000ff;
                screen->Bar(x, y, x + 12, y + 2, red);
                screen->Bar(x, y + 4, x + 12, y + 6, green);
                screen->Bar(x, y + 8, x + 12, y + 10, blue);
            }
        }
    }
};