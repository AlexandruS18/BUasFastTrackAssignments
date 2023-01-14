#include "game.h"
#include "surface.h"
#include "template.h"

namespace Tmpl8
{
    void Game::Init() {}
    void Game::Shutdown() {}

    Surface image("assets/wakka.png"); // use any image
    const int imgSize = 200;
    float alpha = 1.0f;
    int frame = 1;
    void Game::Tick(float deltaTime)
    {
        int red, green, blue, maskRed, maskGreen, maskBlue, rgb;
        maskRed = 255 << 16;
        maskGreen = 255 << 8;
        maskBlue = 255;
        screen->Clear(0);
        // credits to Sleepi
        for (int i = 0; i < imgSize; i++)
        {
            for (int j = 0; j < imgSize; j++)
            {
                Pixel imgAddress = image.GetBuffer()[i + j * imgSize];
                maskRed = 255 << 16;
                maskGreen = 255 << 8;
                maskBlue = 255;
                red = (imgAddress & maskRed) >> 16;
                green = (imgAddress & maskGreen) >> 8;
                blue = (imgAddress & maskBlue);
                red *= alpha;
                green *= alpha;
                blue *= alpha;
                rgb = (red << 16) + (green << 8) + blue;
                screen->Plot(i, j, rgb);
            }
        }
        if (alpha > 0)
        {
            if (frame % 2 == 0)
                alpha -= 1.0f / 255.0f;
        }
        frame++;
    }
};